#pragma once
namespace Core
{
	namespace Data
	{
		enum ComponentType { eTransform };

		class Component
		{
		public:
			ComponentType m_ComponentType;

			Component(ComponentType componentType)
			{
				m_ComponentType = componentType;
			}

			virtual void Update()
			{

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

	}
}

