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
			Scene scene = Scene();
			GameObject* newGo = new GameObject();
			newGo->SetTag("TestTag");
			scene.AddGO(newGo);
			auto value1 = scene.FindObjectsWithTag("TestTag");
			auto value2 = scene.FindObjectsWithTag("NotATag");
			Assert::IsTrue(value1.size() == 1);
			Assert::IsTrue(value2.size() == 0);
		}
	};
}
