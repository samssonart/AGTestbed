#pragma once

class Ray;

class AABB
{
protected:
	glm::vec3 pMin, pMax;
public:
	AABB(){ pMin = glm::vec3(0.0f); pMax = glm::vec3(0.0f); }
	AABB(glm::vec3 &p) { pMin = p; pMax = p; }
	AABB(glm::vec3 &p1, glm::vec3 &p2) { pMin = glm::min(p1,p2); pMax = glm::max(p1,p2); }
	AABB Union(AABB &b, glm::vec3 &p);
	AABB Union(AABB &b, AABB &b2);
	glm::vec3 GetCentroid();
	bool Overlaps(AABB &b);
	bool Intersect(Ray &ray);
	bool Contains(glm::vec3 &pt){return (pt.x >= pMin.x && pt.x <= pMax.x && pt.y >= pMin.y && pt.y <= pMax.y && pt.z >= pMin.z && pt.z <= pMax.z);}
	~AABB();

	inline void SetPMin(glm::vec3 &v) { pMin = v; }
	inline void SetPMax(glm::vec3 &v) { pMax = v; }
	inline glm::vec3 GetPMin() { return pMin; }
	inline glm::vec3 GetPMax() { return pMax; }
	float SurfaceArea() const {glm::vec3 d = pMax - pMin; return 2.f * (d.x * d.y + d.x * d.z + d.y * d.z);}

private:

};