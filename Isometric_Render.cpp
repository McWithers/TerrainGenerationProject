#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Resources.h"

class Isometric_Render {
private:
	int x_l;
	int x_u;
	int y_l;
	int y_u;
	int z_l;
	int z_u;
public:
	int * get_x();
	int * get_y();
	int * get_z();
	void set_x(int, int);
	void set_y(int, int);
	void set_z(int, int);
	void create_image(World_Map);
	place_cube(World_Map, int, int, int);
};

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
