#pragma once

#include <functional>
#include <list>
#include <mutex>
#include <atomic>
#include <algorithm>

template <typename... Args> class event_handler
{
public:
    typedef std::function<void(Args...)> handler_func_type;
    typedef unsigned int handler_id_type;

    explicit event_handler(const handler_func_type& handlerFunc)
        : m_handlerFunc(handlerFunc)
    {
        m_handlerId = ++m_handlerIdCounter;
    }

    bool operator==(const event_handler& other) const
    {
        return m_handlerId == other.m_handlerId;
    }

    handler_id_type id() const
    {
        return m_handlerId;
    }

    void operator()(Args... params) const
    {
        if (m_handlerFunc)
        {
            m_handlerFunc(params...);
        }
    }

private:
    handler_id_type m_handlerId;
    handler_func_type m_handlerFunc;

    static std::atomic_uint m_handlerIdCounter;
};

template <typename... Args> std::atomic_uint event_handler<Args...>::m_handlerIdCounter(0);

template <typename... Args> class event
{
public:
    typedef event_handler<Args...> handler_type;

    typename handler_type::handler_id_type add(const handler_type& handler)
    {
        std::lock_guard<std::mutex> lock(m_handlersLocker);

        m_handlers.push_back(handler);
        return handler.id();
    }

    typename handler_type::handler_id_type add(const typename handler_type::handler_func_type& handlerFunc)
    {
        return add(handler_type(handlerFunc));
    }

    bool remove(const handler_type& handler)
    {
        std::lock_guard<std::mutex> lock(m_handlersLocker);

        auto it = std::find(m_handlers.begin(), m_handlers.end(), handler);
        if (it != m_handlers.end())
        {
            m_handlers.erase(it);
            return true;
        }

        return false;
    }

    bool remove_id(const typename handler_type::handler_id_type& handlerId)
    {
        std::lock_guard<std::mutex> lock(m_handlersLocker);

        auto it = std::find_if(m_handlers.begin(), m_handlers.end(),
            [handlerId](const handler_type& handler) { return handler.id() == handlerId; });
        if (it != m_handlers.end())
        {
            m_handlers.erase(it);
            return true;
        }

        return false;
    }

    void call(Args... params) const
    {
        handler_collection_type handlersCopy = get_handlers_copy();
        call_impl(handlersCopy, params...);
    }

private:
    typedef std::list<handler_type> handler_collection_type;

    mutable std::mutex m_handlersLocker;
    handler_collection_type m_handlers;

    handler_collection_type get_handlers_copy() const
    {
        std::lock_guard<std::mutex> lock(m_handlersLocker);
        return m_handlers;
    }

    void call_impl(const handler_collection_type& handlers, Args... params) const
    {
        for (const auto& handler : handlers)
        {
            handler(params...);
        }
    }
};
