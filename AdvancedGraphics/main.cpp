#ifdef ON_A_MAC
#include "ResourcePath.hpp"
#endif // ON_A_MAC

#include "precomp.h"

inline unsigned int GetFrameRate(void)
{
	
	
}

int main(int, char const**)
{
	//for measuring
	Clock fpsClock;
	fpsClock.restart();
	static float elapsed = 0.0f, fpsF = 0.0f;
    // Create the render context
	Renderer* rdrer = new Renderer();
	RenderWindow window(VideoMode(SCRWIDTH, SCRHEIGHT), "Raytracer");
	Texture renderResult;
	Image image;
	renderResult.create(SCRWIDTH, SCRHEIGHT);
	image.create(SCRWIDTH, SCRHEIGHT, sf::Color::Black);
	Font font;
	if (!font.loadFromFile("sansation.ttf")) {
		return EXIT_FAILURE;
	}
	Text text("Insert FPS counter here", font, 15);
	text.setColor(sf::Color::Yellow);
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

		//calculate fps
		elapsed = fpsClock.getElapsedTime().asMilliseconds();
		fpsClock.restart();
		fpsF = 1000.0f / elapsed;
		stringstream stream;
		stream << fixed << setprecision(2) << fpsF;
		string fpsS = stream.str();
		string fps = "FPS: " + fpsS;
		text.setString(fps);
		window.draw(text);

		window.display();
	}
    return EXIT_SUCCESS;
}
