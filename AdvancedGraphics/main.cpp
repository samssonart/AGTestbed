#ifdef ON_A_MAC
#include "ResourcePath.hpp"
#endif // ON_A_MAC

#include "precomp.h"

int main(int, char const**)
{
    // Create the render context
	Renderer* rdrer = new Renderer();
	RenderWindow window(VideoMode(SCRWIDTH, SCRHEIGHT), "Raytracer");
	Texture renderResult;
	Image image;
	renderResult.create(SCRWIDTH, SCRHEIGHT);
	image.create(SCRWIDTH, SCRHEIGHT, sf::Color::Black);

	while (window.isOpen())
	{
		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Close window: exit
			if (event.type == sf::Event::Closed) {
				window.close();
			}

			// Escape pressed: exit
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
				window.close();
			}
		}

		// Clear screen
		window.clear();
		image.create(SCRWIDTH, SCRHEIGHT, rdrer->Render());
		renderResult.update(image);
		Sprite sprite(renderResult);
		window.draw(sprite);
		window.display();
	}
    return EXIT_SUCCESS;
}
