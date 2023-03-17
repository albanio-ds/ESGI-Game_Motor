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
		
		TEST_METHOD(SceneFindGameObjectWithTagTest)
		{
			//GameObject::GameObjectCreated = 0;
			Scene* scene = new Scene();
			GameObject* newGo = new GameObject();
			newGo->SetTag("ValidTag");
			scene->AddGO(newGo);
			scene->AddGO(newGo);
			auto value1 = scene->FindObjectsWithTag("ValidTag");
			auto value2 = scene->FindObjectsWithTag("InvalidTag");
			Assert::IsTrue(value1.size() == 2);
			Assert::IsTrue(value2.size() == 0);
			scene->~Scene();
		}

		TEST_METHOD(GameObjectGetAndSetTagTest)
		{
			GameObject* obj = new GameObject();
			obj->SetTag("TestTag");
			std::string val = obj->GetTag();
			Assert::IsTrue(val == "TestTag");
			obj->~GameObject();
		}
		TEST_METHOD(TestComponent)
		{
			Component newComp = Component();
			Transform transfo = Transform();
			Assert::IsTrue(newComp.m_ComponentType == transfo.m_ComponentType);
			//Assert::IsTrue(transfo == static_cast<Component&>(newComp));
			//Assert::IsTrue(transfo == newComp);
		}
	};
}
