#include "precomp.h"

AABB AABB::Union(AABB &b, glm::vec3 &p)
{
	AABB ret = b;
	float minx = glm::min(b.pMin.x, p.x);
	float miny = glm::min(b.pMin.y, p.y);
	float minz = glm::min(b.pMin.z, p.z);
    vec3 tempPmin(minx, miny, minz);
	ret.SetPMin(tempPmin);
	float maxx = glm::max(b.pMax.x, p.x);
	float maxy = glm::max(b.pMax.y, p.y);
	float maxz = glm::max(b.pMax.z, p.z);
    vec3 tempPmax(maxx, maxy, maxz);
	ret.SetPMax(tempPmax);
	return ret;

}

AABB AABB::Union(AABB &b, AABB &b2)
{
	AABB ret = b;
	float minx = glm::min(b.pMin.x, b2.pMin.x);
	float miny = glm::min(b.pMin.y, b2.pMin.y);
	float minz = glm::min(b.pMin.z, b2.pMin.z);
    vec3 tempPmin(minx, miny, minz);
	ret.SetPMin(tempPmin);
	float maxx = glm::max(b.pMax.x, b2.pMax.x);
	float maxy = glm::max(b.pMax.y, b2.pMax.y);
	float maxz = glm::max(b.pMax.z, b2.pMax.z);
    vec3 tempPmax(maxx, maxy, maxz);
	ret.SetPMax(tempPmax);
	return ret;

}

bool AABB::Overlaps(AABB &b)
{

	bool inx = (pMax.x >= b.pMin.x) && (pMin.x <= b.pMax.x);
	bool iny = (pMax.y >= b.pMin.y) && (pMin.y <= b.pMax.y);
	bool inz = (pMax.z >= b.pMin.z) && (pMin.z <= b.pMax.z);
	return (inx && iny && inz);

}

AABB::~AABB()
{
}

glm::vec3 AABB::GetCentroid()
{

	return (0.5f*GetPMin() + 0.5f*GetPMax());

}

bool AABB::Intersect(Ray &ray)
{
	glm::vec3 invDir = 1.0f / ray.GetDirection();
	float tmin = (pMin.x - ray.GetOrigin().x) * invDir.x;
	float tmax = (pMax.x - ray.GetOrigin().x) * invDir.x;

	if (tmin > tmax) swap(tmin, tmax);

	float tymin = (pMin.y - ray.GetOrigin().y) * invDir.y;
	float tymax = (pMax.y - ray.GetOrigin().y) * invDir.y;

	if (tymin > tymax) swap(tymin, tymax);

	if ((tmin > tymax) || (tymin > tmax))
		return false;

	if (tymin > tmin)
		tmin = tymin;

	if (tymax < tmax)
		tmax = tymax;

	float tzmin = (pMin.z - ray.GetOrigin().z) * invDir.z;
	float tzmax = (pMax.z - ray.GetOrigin().z) * invDir.z;

	if (tzmin > tzmax) swap(tzmin, tzmax);

	if ((tmin > tzmax) || (tzmin > tmax))
		return false;

	if (tzmin > tmin)
		tmin = tzmin;

	if (tzmax < tmax)
		tmax = tzmax;

	return true;
}
