#include "precomp.h"

Scene::Scene()
{
	InitScene();
	//std::vector<std::unique_ptr<Primitive>> sceneObject;
}
void Scene::InitScene()
{
	//Create a default scene with some stuff in it
	mainCamera = new Camera();

	vec3 light_position(0.0f, -2.0f, -1.0f);
	lightSource = new Light(light_position, Color(255.0f,255.0f,255.0f), 1.0f);

	//Sphere *scene_sphere = new Sphere(vec3(-1.5f, -0.2f, 2.0f), 0.4f, sphereMaterial1);//green
	//Sphere *scene_sphere2 = new Sphere(vec3(-0.7f, -0.8f, 4.0f), 0.5f, sphereMaterial2);//maroon
	//Plane *ground_plane = new Plane(vec3(0.0f, 1.0f, 0.0f),-1.0f,planeMaterial);//gray
	//Triangle *big_triangle = new Triangle(vec3(1.0f,0.0f,2.5f), vec3(0.0f, -1.0f, 2.5f), vec3(-1.0f, 0.0f, 2.5f),triangleMat);//gray

	//sceneObject.push_back(scene_sphere);
	//sceneObject.push_back(scene_sphere2);
	//sceneObject.push_back(ground_plane);
	////sceneObject.push_back(std::unique_ptr<Triangle>(big_triangle));
	
	
}
void Scene::addRenderObject(RenderObject* renderObject)
{
	sceneObject.push_back(renderObject);
}

void Scene::deleteRenderObject(RenderObject* renderObject)
{
	for (std::vector<RenderObject*>::iterator itRenderObjects(sceneObject.begin()), itEnd(sceneObject.end());
	itRenderObjects != itEnd;
		)
	{
		if (*itRenderObjects == renderObject)
		{
			delete(*itRenderObjects);
			itRenderObjects = sceneObject.erase(itRenderObjects);
			itEnd = sceneObject.end();
		}
		else
		{
			++itRenderObjects;
		}
	}
}

void Scene::ClearRenderObjects()
{
	for (std::vector<RenderObject*>::iterator itRenderObjects(sceneObject.begin()), itEnd(sceneObject.end());
	itRenderObjects != itEnd;
		)
	{
		delete(*itRenderObjects);
		itRenderObjects = sceneObject.erase(itRenderObjects);
		itEnd = sceneObject.end();
	}
}