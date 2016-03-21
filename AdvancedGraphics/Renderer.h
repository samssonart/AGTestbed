#pragma once


class RenderObject;
 
class Renderer
{
private:
        sf::RenderWindow& window;
        std::vector<RenderObject*> renderObjects;
        sf::Vector3f position;
        sf::Vector3f direction;
        sf::Texture renderResult;
        sf::Color backgroundColor;
        sf::Vector3f lightPos;
        float lightRadius;
public:
        Renderer(sf::RenderWindow& newWindow);
        void render();
 
        void addRenderObject(RenderObject* renderObject);
        void deleteRenderObject(RenderObject* renderObject);
        void deleteAllRenderObjects();
 
};