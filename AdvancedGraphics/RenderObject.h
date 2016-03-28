#pragma once

struct Material
{
private:
public:
	Color diffuse;
	Color specular;
	float reflection;
	Image* texture;
	Image* normalMap;
	Material();
	void setTexture(sf::Image* newTexture);
	Color getColorByTexture(const vec2& UVcoordinates);
	Color GetColor() { return diffuse; }
	void setNormalMap(sf::Image* newNormalMap);
	float getNormalByNormalMap(const vec2& UVcoordinates);
};


struct Vertex3D
{
private:
public:
	vec3 position;
	vec2 UVposition;
	Vertex3D();
};

class Ray
{
protected:
	vec3 origin;
	vec3 direction;
	float t0;
public:
	Ray() { origin = vec3(0.0f); direction = vec3(0.0f); t0 = INFINITY; }
	Ray(vec3 o, vec3 d, float nt) { origin = o; direction = d; t0 = nt; }
	inline void SetOrigin(vec3 &v) { origin = v; }
	inline const vec3 &GetOrigin() const { return origin; }

	inline void SetDirection(vec3 &v) { direction = glm::normalize(v); }
	inline const vec3 &GetDirection() const { return direction; }

	inline void SetT0(float nt) { t0 = nt; }
	inline float GetT0() { return t0; }

private:

};

class Renderer;

class RenderObject
{
protected:
	Transform transform;
	Material material;
public:
	RenderObject();
	RenderObject(Material& newMaterial);

	virtual int Intersect(const vec3& origin, const vec3& direction, vec3& hitPosition, vec2& UVCoordinates) = 0;
	virtual const vec3 &getNormal(const vec3 &point) = 0;
	virtual const vec3 &getNormal() = 0;

	void setTransform(const Transform& newTransform);
	Transform&  getTransform();

	void setMaterial(const Material& newMaterial);
	Material& getMaterial();

	virtual  Color GetColor() = 0;
};