#include "pch.h"
#include "CppUnitTest.h"
#include "../GameMotorConsole/Scene.h"
using namespace Core::Data;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GameMotorTest
{
	TEST_CLASS(ComponentOperationTest)
	{
	public:

		TEST_METHOD(ComponentOperationTestMethod)
		{
			//GameObject::GameObjectCreated = 0;
			Scene* scene = new Scene();
			GameObject* newGo = new GameObject();

			scene->AddGO(newGo);
			Component compo = Component();


			Assert::IsFalse(newGo->AddComponent(compo));

			//newGo->DeleteComponent(ComponentType::eTransform);
			scene->~Scene();
		}
	};
}
