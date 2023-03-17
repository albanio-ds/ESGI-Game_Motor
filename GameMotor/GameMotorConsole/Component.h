#pragma once
namespace Core
{
	namespace Data
	{
		enum class ComponentType { eTransform };

		class Component
		{
		public:
			ComponentType m_ComponentType;

			Component()
			{
				m_ComponentType = ComponentType::eTransform;
			}

			Component(ComponentType componentType)
			{
				m_ComponentType = componentType;
			}

			virtual void Update()
			{

			}

			bool operator==(const Component& other)
			{
				return other.m_ComponentType == this->m_ComponentType;
			}
		};
		class Transform : public Component
		{
		private:
			const ComponentType m_ComponentType = ComponentType::eTransform;

		public:
			Transform() : Component(m_ComponentType)
			{

			}
		};
		class Behavior : public Component
		{
		public:
			__event void OnUpClicked();

			void ClickUp()
			{
				OnUpClicked();
			}
		};
	}
}

