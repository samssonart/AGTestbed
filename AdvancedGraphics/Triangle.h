#pragma once

class Triangle : public RenderObject
{
protected:
	glm::vec3 A, B, C;
	glm::vec3 normal;
	float distance;
	Material mat;
	AABB bounds;

public:
	Triangle() {
		distance = 0.0f;  normal = glm::vec3(0.0f, 1.0f, 0.0f);  mat = Material(); A = glm::vec3(1.0f, 0.0f, 0.0f);
		B = glm::vec3(0.0f, 1.0f, 0.0f); C = glm::vec3(0.0f, 0.0f, 1.0f); bounds = ComputeBB(); ComputeNormal();
	}
	Triangle(glm::vec3 a, glm::vec3 b, glm::vec3 c, Material mater) { mat = mater; A = a; B = b; C = c; bounds = ComputeBB(); ComputeNormal(); }
	inline void SetDistance(float distance_arg) { distance = distance_arg; }
	inline float GetDistance() const { return distance; }

	virtual glm::vec3 NormalAtSurfacePoint(const glm::vec3 &p);
	virtual bool Intersection(Ray &ray);
	glm::vec3 GetOrigin() const { return normal; }
	virtual  Color GetColor() { return mat.GetColor(); }
	Material GetMaterial() const { return mat; }
	void SetOrigin(glm::vec3 p) { distance = glm::length(p); };
	void ComputeNormal();
	AABB ComputeBB();
	void UpdateBB();
	AABB GetBB() { return bounds; }
};