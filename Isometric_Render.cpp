#include "Header.h"


void Isometric_Render::create_image(World_Map world)
{

}


void Isometric_Render::place_cube(World_Map world, int x, int y, int z) {


}

int * Isometric_Render::get_x() {
	int result[2];
	result[0] = this->x_l;
	result[1] = this->x_u;
	return result;
}

void Isometric_Render::set_face_height(int height) {
	this->face_height = height;
}

int Isometric_Render::get_face_height()
{
	return this->face_height;
}

int * Isometric_Render::get_y() {
	int result[2];
	result[0] = this->y_l;
	result[1] = this->y_u;
	return result;
}

int * Isometric_Render::get_z() {
	int result[2];
	result[0] = this->z_l;
	result[1] = this->z_u;
	return result;
}

void Isometric_Render::set_x(int x_l, int x_u) {
	this->x_l = x_l;
	this->x_u = x_u;
}

void Isometric_Render::set_y(int y_l, int y_u) {
	this->y_l = y_l;
	this->y_u = y_u;
}

void Isometric_Render::set_z(int z_l, int z_u) {
	this->z_l = z_l;
	this->z_u = z_u;
}
