#pragma once
namespace Core
{
	namespace Data
	{
		enum class ComponentType { eTransform, eBehavior, eBoundary };

		class Component
		{
		public:
			ComponentType m_ComponentType;

			Component()
			{
				m_ComponentType = ComponentType::eTransform;
			}

			virtual void Update()
			{

			}

			bool operator==(const Component& other)
			{
				return other.m_ComponentType == this->m_ComponentType;
			}

		protected:
			Component(ComponentType componentType)
			{
				m_ComponentType = componentType;
			}
		};
		class Transform : public Component
		{
		public:
			Transform() : Component(ComponentType::eTransform) {}
		};


		class Behavior : public Component
		{
		public:
			Behavior() : Component(ComponentType::eBehavior) {}
		};


		class Boundary : public Component
		{
		public:
			Boundary() : Component(ComponentType::eBoundary) {}
		};
	}
}

