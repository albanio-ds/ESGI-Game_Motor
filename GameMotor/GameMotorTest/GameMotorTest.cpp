#include "pch.h"
#include "CppUnitTest.h"
#include "../GameMotorConsole/Scene.h"
using namespace Core::Data;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GameMotorTest
{
	TEST_CLASS(GameMotorTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			//GameObject::GameObjectCreated = 0;
			Scene scene = Scene();
			GameObject* newGo = new GameObject();
			newGo->SetTag("TestTag");
			scene.AddGO(newGo);
			auto value1 = scene.FindObjectsWithTag("TestTag");
			auto value2 = scene.FindObjectsWithTag("NotATag");
			Assert::IsTrue(value1.size() == 1);
			Assert::IsTrue(value2.size() == 0);
		}

		TEST_METHOD(GameObjectTest)
		{
			GameObject obj = GameObject();
			obj.SetTag("TestTag");
			std::string val = obj.GetTag();
			Assert::IsTrue(val == "TestTag");
		}
		TEST_METHOD(TestComponent)
		{
			Component* newComp = new Component();
			Transform* transfo = dynamic_cast<Transform*>(newComp);
			Assert::IsNotNull(transfo);
		}
	};
}
