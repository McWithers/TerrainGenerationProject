#include "Header.h"


void Isometric_Render::create_image(World_Map world)
{

}


void Isometric_Render::place_cube(World_Map world, int x, int y, int z) {


}


void Isometric_Render::set_face_height(int height) {
	this->face_height = height;
}

int Isometric_Render::get_face_height()
{
	return this->face_height;
}

int * Isometric_Render::get_x() {
	int* result = static_cast<int*>(malloc(sizeof(int)*2));
	result[0] = this->x_l;
	result[1] = this->x_u;
	return result;
}

int * Isometric_Render::get_y() {
	int* result = static_cast<int*>(malloc(sizeof(int)*2));
	result[0] = this->y_l;
	result[1] = this->y_u;
	return result;
}

int * Isometric_Render::get_z() {
	int* result = static_cast<int*>(malloc(sizeof(int)*2));
	result[0] = this->z_l;
	result[1] = this->z_u;
	return result;
}

void Isometric_Render::set_x(int low, int up) {
	this->x_l = low;
	this->x_u = up;
}

void Isometric_Render::set_y(int low, int up) {
	this->y_l = low;
	this->y_u = up;
}

void Isometric_Render::set_z(int low, int up) {
	this->z_l = low;
	this->z_u = up;
}
