#pragma once


class RenderObject;
 
class Renderer
{
private:
        
        Color backgroundColor;
		Scene* scene;
		Uint8 *pixels;
		Font font;
		Text text;
public:
        Renderer();
		Uint8* Render();
 
};