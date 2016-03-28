#include "precomp.h"
#define TINYOBJLOADER_IMPLEMENTATION
#include "tiny_obj_loader.h"


void Mesh::LoadOBJ(glm::vec3 pos, char* filepath, Material mater, Scene* sc)
{
	std::string errors;
	std::vector<tinyobj::shape_t> sh;
	std::vector<tinyobj::material_t> mat;

	//call the library to load the obj
	bool succes = LoadObj(sh, mat, errors, filepath);

	//if there are errors, report 
	if (!errors.empty())
	{
		std::cout << "There was an error loading the model:\n";
		std::cout << errors.c_str() << "\n";
	}

	if (!succes) return;

	int counter = 0;
	//for each shape...
	for (int i = 0; i < sh.size(); i++)
	{
		assert(sh[i].mesh.indices.size() % 3 == 0);
		//for all faces
		for (int k = 0; k < sh[i].mesh.indices.size() / 3; k++)
		{
			int idx = sh[i].mesh.indices[k * 3];
			glm::vec3 v1 = pos + glm::vec3(sh[i].mesh.positions[3 * idx], sh[i].mesh.positions[3 * idx + 1], sh[i].mesh.positions[3 * idx + 2]);
			idx = sh[i].mesh.indices[k * 3 + 1];
			glm::vec3 v2 = pos + glm::vec3(sh[i].mesh.positions[3 * idx], sh[i].mesh.positions[3 * idx + 1], sh[i].mesh.positions[3 * idx + 2]);
			idx = sh[i].mesh.indices[k * 3 + 2];
			glm::vec3 v3 = pos + glm::vec3(sh[i].mesh.positions[3 * idx], sh[i].mesh.positions[3 * idx + 1], sh[i].mesh.positions[3 * idx + 2]);

			//for the normal we can take the normal of any of the vertices, since they should all be the same
			//glm::vec3 normal = glm::vec3(sh[i].mesh.normals[3 * idx], sh[i].mesh.normals[3 * idx + 1], sh[i].mesh.normals[3 * idx + 2]);

			counter++;
			Triangle *triangle = new Triangle(v1, v2, v3, mater);
			tris.push_back(std::unique_ptr<Triangle>(triangle));
			sc->sceneObject.push_back(triangle);
		}
	}
}

Mesh::Mesh(glm::vec3 pos, char* filepath, Material mater, Scene* sc)
{
	LoadOBJ(pos, filepath, mater, sc);

}