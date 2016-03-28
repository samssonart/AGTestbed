#include "precomp.h"

Renderer::Renderer() {

	
	scene = new Scene();
	pixels = new Uint8[SCRWIDTH * SCRHEIGHT * 4];
	backgroundColor = Color::Cyan;
}

Uint8* Renderer::Render()
{
	
	for (unsigned int y = 0; y < SCRHEIGHT; y++)
		for (unsigned int x = 0; x < SCRWIDTH; x++)
		{

			pixels[(y*SCRWIDTH + x) * 4] = backgroundColor.r;//R
			pixels[(y*SCRWIDTH + x) * 4 + 1] = backgroundColor.g;//G
			pixels[(y*SCRWIDTH + x) * 4 + 2] = backgroundColor.b;//B
			pixels[(y*SCRWIDTH + x) * 4 + 3] = backgroundColor.a;//A

		}
	return pixels;
}


// Create a graphical text to display
/*sf::Font font;
if (!font.loadFromFile("sansation.ttf")) {
return EXIT_FAILURE;
}
sf::Text text("Insert FPS counter here", font, 15);
text.setColor(sf::Color::Yellow);*/

// Load a music to play
//sf::Music music;
//if (!music.openFromFile("nice_music.ogg")) {
//    return EXIT_FAILURE;
//}
// Play the music
//music.play();