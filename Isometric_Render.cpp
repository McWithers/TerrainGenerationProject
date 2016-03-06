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

void Isometric_Render::draw_line(int *x, int *y, RGBApixel * pixel) {
	int x1 = x[0];
	int x2 = x[1];
	int y1 = y[0];
	int y2 = y[1];
	const bool steep = (fabs(y2 - y1) > fabs(x2 - x1));
	if (steep)
	{
		std::swap(x1, y1);
		std::swap(x2, y2);
	}

	if (x1 > x2)
	{
		std::swap(x1, x2);
		std::swap(y1, y2);
	}

	const float dx = (float)(x2 - x1);
	const float dy = (float)fabs(y2 - y1);

	float error = dx / 2.0f;
	const int ystep = (y1 < y2) ? 1 : -1;
	int y_new = (int)y1;

	const int maxX = (int)x2;

	for (int x_new = (int)x1; x_new<maxX; x_new++)
	{
		if (steep)
		{
			RGBApixel* pixel = new RGBApixel;
			pixel->Alpha = 127;
			pixel->Red = 192;
			pixel->Green = 192;    //SILVER
			pixel->Blue = 192;
			this->bmp_image->SetPixel(y_new,x_new,*pixel);
			int x_f = 0;
			for ( x_f = x_new; x_f < FACE_HEIGHT - (dx * 2); x_f++) {


			}
			for (x_f = x_new; x_f > -FACE_HEIGHT * dx; x_f--) {


			}
		}
		else
		{
			RGBApixel* pixel = new RGBApixel;
			pixel->Alpha = 127;
			pixel->Red = 192;
			pixel->Green = 192;    //SILVER
			pixel->Blue = 192;
			this->bmp_image->SetPixel(x_new, y_new, *pixel);
			int y_f = 0;
			for (int y_f = y_new; y_f < FACE_HEIGHT - (dy * 2) - 1; y_f++) {


			}
			for (y_f = y_new; y_f > -FACE_HEIGHT * dx; y_f--) {


			}
		}

		error -= dy;
		if (error < 0)
		{
			y += ystep;
			error += dx;
		}
	}
}


void Isometric_Render::place_cube(int x, int y, int z) {
	int * xy = find_xy(x, y, z);
	RGBApixel * pixel = new RGBApixel;
	pixel->Alpha = 127;
	pixel->Red = this->the_map->get_point->r;
	pixel->Blue = this->the_map->get_point->b;
	pixel->Green = this->the_map->get_point->g;

	int point_start[2];
	int point_end_r[2];
	int point_end_l[2];
	int point_bottom[2];
	int h = FACE_HEIGHT;
	int h_root = (int)(h * sqrt(3)) / 2;
	int h_half = h / 2;
	for (int i = 0; i < 2; i++) {
		point_start[i] = xy[i];
	}
	//point_bottom[0] = xy[0];
	//point_bottom[1] = xy[1] - h;
	//draw_line(point_start, point_bottom);
	point_end_r[0] = xy[0] + h_root;
	point_end_r[1] = xy[1] + h_half;
	point_end_l[0] = -point_end_r[0];
	point_end_l[1] = point_end_r[1];
	draw_line(point_start, point_end_r, pixel);
	draw_line(point_start, point_end_l, pixel);
	//point_start[1] = point_start[1] + h;
	//draw_line(point_start, point_end_r);
	//draw_line(point_start, point_end_l);
	//point_bottom[0] = point_end_r[0];
	//point_bottom[1] = point_end_r[1] - h;
	//draw_line(point_bottom, point_end_r);
	//point_end_r[0] = xy[0];
	//point_end_r[1] = xy[1] - h;
	//draw_line(point_end_r, point_bottom);
	//point_bottom[0] = point_end_l[0];
	//point_bottom[1] = point_end_l[1] - h;
	//draw_line(point_bottom, point_end_l);
	//draw_line(point_end_r, point_bottom);
	free(xy);

}

int* Isometric_Render::find_xy(int x, int y, int z) {
	int *x_y = (int*)malloc(sizeof(int)*2);
	int h = FACE_HEIGHT;
	int h_root = (int)(h * sqrt(3)) / 2;
	int h_half = h / 2;
	//inititalize to 0,0,0
	x_y[0] = (this->get_y()[1] - this->get_y()[0] + 1)*(h_root-1) + 0;
	x_y[1] = h-1;
	printf("initial: x:%d,y:%d\n", x_y[0], x_y[1]);

	//add x components
	if (x) {
		x_y[0] += x*(h_root-1);
		x_y[1] += x*h_half;
		printf("x components: x:%d,y:%d\n", x_y[0], x_y[1]);
	}
	//add y components
	if (y) {
		x_y[0] -=y*(h_root-1);
		x_y[1] += y*h_half;
		printf("y components: x:%d,y:%d\n", x_y[0], x_y[1]);
	}//add z components
	if (z) {
		x_y[0] += 0;
		x_y[1] += z*(h-1);
		printf("final/z components: x:%d,y:%d\n", x_y[0], x_y[1]);
	}
	printf("point_xyz (%d,%d,%d) moved to point_xy(%d,%d)\n",x,y,z,x_y[0],x_y[1]);
	return x_y;
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

Isometric_Render::Isometric_Render(World_Map* _map, BMP *the_bmp_image, int xl, int xu, int yl, int yu, int zl, int zu) {
	set_x(xl, xu);
	set_y(yl, yu);
	this->the_map = _map;
	set_z(zl, zu);
	int h = FACE_HEIGHT;
	int h_root = (int)(h * sqrt(3)) / 2;
	this->bmp_image = the_bmp_image;
	//int h_half = h / 2;
	//int max_xy = (xu - xl + 1) > (yu - yl + 1) ? (xu - xl + 1) : (yu - yl + 1);
	int * dimensions = this->find_xy((xu - xl + 1), (yu - yl + 1), (zu - zl + 1));
	this->width = ((xu - xl + 1)+ (xu - xl + 1))*(h_root-1) + 1;
	this->height = dimensions[1] - h + 1;
	free(dimensions);

}

Isometric_Render::Isometric_Render() {}