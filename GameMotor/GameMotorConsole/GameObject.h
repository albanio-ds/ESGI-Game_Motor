#pragma once
#include <vector>
#include "LogClass.h"
#include "Component.h"


namespace Core
{
	namespace Data
	{

		class GameObject
		{
		protected:
			static uint16_t GameObjectCreated;
		private:
			std::vector<std::unique_ptr<Component>> m_Components = std::vector<std::unique_ptr<Component>>();
			uint16_t* m_Id;
			std::string* m_Tag;
		public:

			GameObject()
			{
				*m_Id = GameObjectCreated;
				GameObjectCreated++;
				std::unique_ptr<Transform> transform = std::make_unique<Transform>();
				m_Components.push_back(std::move(transform));
				m_Tag == nullptr;
			}

			std::string GetTag() const { return *m_Tag; };
			void SetTag(std::string value) { *m_Tag = value; }

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


			std::unique_ptr<Component> GetComponent(ComponentType ctype)
			{
				for (size_t i = 0; i < m_Components.size(); i++)
				{
					if (m_Components[i]->m_ComponentType == ctype)
					{
						return m_Components[i];
					}
				}
				return nullptr;
			}

			void AddComponent(std::unique_ptr<Component> component)
			{
				m_Components.push_back(std::move(component));
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
		};
	}
}

