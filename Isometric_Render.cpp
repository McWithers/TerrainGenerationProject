#include "Header.h"


void Isometric_Render::create_image(World_Map world)
{

}

void Isometric_Render::recursive_place(int curr_x, int curr_y, int curr_z) {
	if (curr_x <= this->get_x()[1] && curr_x >= this->get_x()[0] &&
		curr_y <= this->get_y()[1] && curr_y >= this->get_y()[0] &&
		curr_z <= this->get_z()[1] && curr_z >= this->get_z()[0]) {
		place_cube(curr_x, curr_y, curr_z);
		this->recursive_place(curr_x + 1, curr_y, curr_z);
		this->recursive_place(curr_x, curr_y + 1, curr_z);
		this->recursive_place(curr_x, curr_y, curr_z + 1);
		cout << "rec: curr_x: " << curr_x << "  curr_y: " << curr_y << "  curr_z: " << curr_z << "  sum: " << curr_x+curr_y+curr_z<< endl;
	}
}

void Isometric_Render::draw_line(int *x, int *y) {



}


void Isometric_Render::place_cube(int x, int y, int z) {
	int * xy = find_xy(x, y, z);
	int * point_start;
	int * point_end_r;
	int * point_end_l;
	int * point_bottom;
	int h = this->get_face_height();
	int h_root = (h * sqrt(3)) / 2;
	int h_half = h / 2;
	for (int i = 0; i < 2; i++) {
		point_start[i] = xy[i];
	}
	point_bottom[0] = xy[0];
	point_bottom[1] = xy[1] - h;
	draw_line(point_start, point_bottom);
	point_end_r[0] = xy[0] + h_root;
	point_end_r[1] = xy[1] + h_half;
	point_end_l[0] = -point_end_r[0];
	point_end_l[1] = point_end_r[1];
	draw_line(point_start, point_end_r);
	draw_line(point_start, point_end_l);
	point_start[1] = point_start[1] + h;
	draw_line(point_start, point_end_r);
	draw_line(point_start, point_end_l);
	point_bottom[0] = point_end_r[0];
	point_bottom[1] = point_end_r[1] - h;
	draw_line(point_bottom, point_end_r);
	point_end_r[0] = xy[0];
	point_end_r[1] = xy[1] - h;
	draw_line(point_end_r, point_bottom);
	point_bottom[0] = point_end_l[0];
	point_bottom[1] = point_end_l[1] - h;
	draw_line(point_bottom, point_end_l);
	draw_line(point_end_r, point_bottom);


}

int* Isometric_Render::find_xy(int x, int y, int z) {
	int * x_y = (int *)malloc(sizeof(4) * 2);
		return x_y;
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

Isometric_Render::Isometric_Render(World_Map the_map, int xl, int xu, int yl, int yu, int zl, int zu) {
	set_x(xl, xu);
	set_y(yl, yu);
	set_z(zl, zu);

}

Isometric_Render::Isometric_Render() {}