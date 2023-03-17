#pragma once

#include "Event.h"

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
			struct Point {
			public:
				float X;
				float Y;
				float Z;
				Point()
				{
					X = 0;
					Y = 0;
					Z = 0;
				}
			};
			Transform() : Component(ComponentType::eTransform) {}
			void UpdatePosition(Point newPt)
			{
				currPos = newPt;
				//OnPositionChanged.call(newPt);
			}
		private:
			//event<Point> OnPositionChanged;
			Point currPos = Point();
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

