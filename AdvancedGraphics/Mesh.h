#pragma once

class Mesh 
{
public:
	void LoadOBJ(glm::vec3 pos, char* filepath, Material mater, Scene* sc);
	Mesh(glm::vec3 pos, char* filepath, Material mater, Scene* sc);
	AABB boundingBox;
	std::vector<std::unique_ptr<Triangle>> tris;
	
};
