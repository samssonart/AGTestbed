#include "precomp.h"

glm::vec3 Triangle::NormalAtSurfacePoint(const glm::vec3 &p)
{
	return normal;
}

bool Triangle::Intersection(Ray &ray)
{
	//if (!bounds.Intersect(ray)) return false;
	float det, invDet, u, v, t;
	glm::vec3 edge1, edge2, tvec, pvec, qvec;
	edge1 = B - A;
	edge2 = C - A;
	pvec = glm::cross(ray.GetDirection(), edge2);
	det = glm::dot(edge1, pvec);
	if (fabs(det) < 0.0001f) return false;
	invDet = 1.0f / det;
	tvec = ray.GetOrigin() - A;
	u = glm::dot(tvec, pvec)*invDet;
	if (u < 0.0f || u > 1.0f) return false;
	qvec = glm::cross(tvec, edge1);
	v = glm::dot(ray.GetDirection(), qvec)*invDet;
	if (v < 0.0f || u + v > 1.0f) return false;
	t = glm::dot(edge2, qvec)*invDet;
	if ((t >= ray.GetT0()) || (t < 0.0f)) return false;
	ray.SetT0(t);
	return true;

}

void Triangle::ComputeNormal()
{
	glm::vec3 CA = C - A;
	glm::vec3 AB = A - B;
	normal = glm::cross(CA, AB);


}

AABB Triangle::ComputeBB()
{
	float minx, miny, minz, maxx, maxy, maxz;
	minx = A.x;
	miny = A.y;
	minz = A.z;
	maxx = A.x;
	maxy = A.y;
	maxz = A.z;
	if (B.x < minx)minx = B.x;
	else if (C.x < minx) minx = C.x;
	if (B.y < miny)miny = B.y;
	else if (C.y < miny) miny = C.y;
	if (B.z < minz)minz = B.z;
	else if (C.z < minz) minz = C.z;

	if (B.x > maxx)maxx = B.x;
	else if (C.x > maxx) maxx = C.x;
	if (B.y > maxy)maxy = B.y;
	else if (C.y > maxy) maxy = C.y;
	if (B.z > maxz)maxz = B.z;
	else if (C.z > maxz) maxz = C.z;

	glm::vec3 minimum(minx, miny, minz);
	glm::vec3 maximum(maxx, maxy, maxz);

	return AABB(minimum, maximum);

}

void Triangle::UpdateBB()
{

	bounds = ComputeBB();
}