#pragma once
#include <string>
namespace Core
{
	namespace Data
	{
		class Component
		{
		public:
			std::string Name;

			Component(std::string name)
			{
				Name = name;
			}
		};
		class Transform : Component
		{
		public:
			Transform() : Component("Transform")
			{

			}
		};


		class GameObject
		{

		};
	}
}

