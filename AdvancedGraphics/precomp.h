#define SCRWIDTH		1280
#define SCRHEIGHT		720
#define ARATIO          1.777777778
#define FOV             1.0471975511965977461542144610932
//921600 pixels!!
#define DEG2RAD 0.01745329251994329576923690768489f
// #define FULLSCREEN
#define GLM_FORCE_RADIANS
// #define OLDTEMPLATESTYLE

#include <inttypes.h>
#include "io.h"
#include <ios>
#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;				

#include <vector>
#include <memory>
#include <ppl.h>
#include "fcntl.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/ext.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

using namespace glm;