#pragma once

class Light {
	vec3 position;
	Color color;
	float brightness;

public:

	Light() { position = vec3(0, 0, 0); color = Color(255,255,255); brightness = 0.5f; }
	Light(vec3 p, Color c, float b) { position = p; color = c; brightness = b; }

	inline vec3 getLightPosition() { return position; }
	inline Color getLightColor() { return color; }
	inline int getLightBright() { return brightness; }

};

class Camera {

protected:
	vec3 campos, camdir, camright, camup;
public:
	Camera() { campos = vec3(0.0f, 0.0f, 0.0f); camdir = vec3(0.0f, 0.0f, 1.0f); camright = vec3(1.0f, 0.0f, 0.0f); camup = vec3(0.0f, 1.0f, 0.0f); }

	Camera(vec3 pos, vec3 dir, vec3 right, vec3 up) { campos = pos; camdir = dir; camright = right; camup = up; }

	//void initCamera();

	inline vec3 getCameraPosition() { return campos; }
	inline vec3 getCameraDirection() { return camdir; }
	inline vec3 getCameraRight() { return camright; }
	inline vec3 getCameraUp() { return camup; }

};

class Scene
{
public:
	Scene();
	void InitScene();
	Camera *mainCamera;
	Light *lightSource;
	std::vector<RenderObject*> sceneObject;

	void addRenderObject(RenderObject* renderObject);
	void deleteRenderObject(RenderObject* renderObject);
	void ClearRenderObjects();

};
