#pragma once
#include <vector>
#include "GameObject.h"
#include <string>
namespace Core
{
	namespace Data
	{
		class Scene
		{
			// liste dynamique de GO
			// add/delete GO
			// update scene -> foreach GO
			// delete scene -> foreach GO + scene

			std::vector<GameObject*> SceneObj;
			std::string SceneName;

		public:

			Scene(std::string sceneN = "Scene") : SceneName(sceneN)
			{
				SceneName = sceneN;
				//GameObject::GameObjectCreated = 0;
			}


			~Scene() {
				for (GameObject* go : SceneObj)
				{
					go->~GameObject();
				}
				SceneObj.clear();
			}


			void AddGO(GameObject* go)
			{
				SceneObj.push_back(go);
			}

			void RemoveGO(GameObject* go)
			{
				SceneObj.erase(std::remove(SceneObj.begin(), SceneObj.end(), go), SceneObj.end());
			}

			std::vector<GameObject*> FindObjectsWithTag(std::string tag)
			{
				std::vector<GameObject*> ObjectsWithTag;
				for (GameObject* go : SceneObj)
				{
					if (go->GetTag() == tag) ObjectsWithTag.push_back(go);
				}
				return ObjectsWithTag;
			}

			void Update()
			{
				for (GameObject* go : SceneObj)
				{
					go->Update();
				}
			}
		};
	}
}

