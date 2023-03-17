#pragma once
#include <vector>
#include "LogClass.h"
#include "Component.h"


namespace Core
{
	using namespace Utilities;
	namespace Data
	{

		class GameObject
		{
		private:
			std::vector<std::unique_ptr<Component>> m_Components = std::vector<std::unique_ptr<Component>>();
			std::unique_ptr<uint16_t> m_Id = std::make_unique<uint16_t>();
			std::unique_ptr<cString> m_Tag = std::make_unique<cString>();
		public:
			//static uint16_t GameObjectCreated = 0;

			GameObject()
			{
				*m_Id = 0;
				//GameObjectCreated++;
				std::unique_ptr<Transform> transform = std::make_unique<Transform>();
				m_Components.push_back(std::move(transform));
			}

			std::string GetTag() const { return m_Tag->Get(); };
			void SetTag(std::string value) { m_Tag->Set(value); }

			void Update()
			{
				for (size_t i = 0; i < m_Components.size(); i++)
				{
					m_Components[i]->Update();
				}
			}

			std::vector<std::unique_ptr<Component>>& GetComponents()
			{
				return m_Components;
			}


			Component* GetComponent(ComponentType ctype)
			{
				for (size_t i = 0; i < m_Components.size(); i++)
				{
					if (m_Components[i]->m_ComponentType == ctype)
					{
						return m_Components[i].get();
					}
				}
				return nullptr;
			}

			bool AddComponent(Component component)
			{
				for (size_t i = 0; i < m_Components.size(); i++)
				{
					if (component.m_ComponentType == m_Components[i].get()->m_ComponentType)
					{
						return false;
					}
				}
				std::unique_ptr<Component> toAdd = std::make_unique<Component>(component);
				m_Components.push_back(std::move(toAdd));
				return true;
			}

			bool DeleteComponent(ComponentType ctype)
			{
				uint16_t index = -1;
				for (size_t i = 0; i < m_Components.size(); i++)
				{
					if (m_Components[i]->m_ComponentType == ctype)
					{
						index = i;
					}
				}
				if (index == -1)
				{
					Core::Utilities::LogClass::Print("nothing to delete");
					return false;
				}
				else 
				{
					Core::Utilities::LogClass::Print("delete " + index);
					return true;
				}
			}

			void operator~()
			{
				m_Id.release();
				m_Tag.release();
				for (size_t i = 0; i < m_Components.size(); i++)
				{
					m_Components[i].release();
				}
				m_Components.clear();
			}
		};
	}
}

