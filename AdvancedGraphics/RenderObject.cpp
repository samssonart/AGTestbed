#include "precomp.h"

Material::Material()
	:diffuse(Color::White),specular(Color::White),reflection(0.0f),texture(),normalMap(){}

void Material::setTexture(sf::Image* newTexture)
{
	texture = newTexture;
}

Color Material::getColorByTexture(const vec2& UVcoordinates)
{
	if (texture)
	{
		return diffuse*texture->getPixel(static_cast<int>(UVcoordinates.x * texture->getSize().x), static_cast<int>(UVcoordinates.y * texture->getSize().y));
	}
	else
	{
		return diffuse;
	}
}

void Material::setNormalMap(sf::Image* newNormalMap)
{
	normalMap = newNormalMap;
}

float Material::getNormalByNormalMap(const vec2& UVcoordinates)
{
	if (normalMap)
	{
		Color color = normalMap->getPixel(static_cast<int>(UVcoordinates.x * normalMap->getSize().x), static_cast<int>(UVcoordinates.y * normalMap->getSize().y));
		return (color.r / 255 + color.g / 255 + color.b / 255) / 3.0f;
	}
	else
	{
		return 1.0f;
	}
}

Vertex3D::Vertex3D():position(0.0f, 0.0f, 0.0f),UVposition(0.0f, 0.0f){}


RenderObject::RenderObject()
	:transform(),material(){}

RenderObject::RenderObject( Material& newMaterial)
	:transform(),material(newMaterial){}

void RenderObject::setTransform(const Transform& newTransform){transform = newTransform;}
Transform& RenderObject::getTransform(){return transform;}

void RenderObject::setMaterial(const Material& newMaterial){material = newMaterial;}
Material& RenderObject::getMaterial(){return material;}