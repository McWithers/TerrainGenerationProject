#include "Header.h"

GUI_Variables::GUI_Variables(int size, int depth, int color1R, int color1G, int color1B, int color2R, int color2G, int color2B, int gradient) {
	this->size = size;
	this->depth = depth;
	this->color1R = color1R;
	this->color1G = color1G;
	this->color1B = color1B;
	this->color2R = color2R;
	this->color2G = color2G;
	this->color2B = color2B;
	this->gradient = gradient;
}

GUI_Variables::GUI_Variables() {
	size = 6;
	depth = 4;
	color1R = 255;
	color1G = 255;
	color1B = 255;
	color2R = 0;
	color2G = 0;
	color2B = 0;
	gradient = 1;
}