#include "Header.h"


void Isometric_Render::initialize_render_check()
{
	int size = (x_u - x_l)*(y_u - y_l)*(z_u - z_l) - 1;
	int numChars = size / 8;
	isRendered = (char*)calloc(sizeof(char), numChars);
}

void Isometric_Render::set_Render(int x, int y, int z) {
	int loc = x + ((x_u - x_l) * (y + (y_u - y_l) * z));

	isRendered[loc / 8] ^= (-(1) ^ isRendered[loc / 8]) & (1 << (loc % 8));
}

bool Isometric_Render::is_rendered(int x, int y, int z) {

	int loc = x + ((x_u - x_l) * (y + (y_u - y_l) * z));
	return (isRendered[loc / 8] >> (loc % 8)) % 2;
}

void Isometric_Render::BFS_place(int x, int y, int z) {
	queue<coord*> *the_queue = new queue < coord* >;

	coord* first = new coord;
	first->x = x;
	first->y = y;
	first->z = z;
	//printf("%d,%d,%d\n", first->x, first->y, first->z);
	the_queue->push(first);
	set_Render(first->x, first->y, first->z);

	call_pixel(first->x, first->y, first->z);

	while (!the_queue->empty()) {
		coord* current = the_queue->front();
		the_queue->pop();
		int curr_x = current->x;
		int curr_y = current->y;
		int curr_z = current->z;
		//printf("%d,%d,%d\n", curr_x, curr_y, curr_z);
		delete current;

		if (curr_x < x_u && curr_x > x_l &&
			curr_y < y_u && curr_y > y_l &&
			curr_z < z_u && curr_z > z_l) {

			set_Render(curr_x, curr_y, curr_z);

			call_pixel(curr_x, curr_y, curr_z);

		}
		for (int child_count = 0; child_count < 3; child_count++) {
			int modx = curr_x + !(child_count - 0);
			int mody = curr_y + !(child_count - 1);
			int modz = curr_z + !(child_count - 2);
			if (modx < x_u && modx > x_l &&
				mody < y_u && mody > y_l &&
				modz < z_u && modz > z_l &&
				!is_rendered(modx, mody,
					modz)) {
				coord* child = new coord;
				child->x = modx;
				child->y = mody;
				child->z = modz;
				set_Render(child->x, child->y, child->z);

				the_queue->push(child);
			}
		}

	}
}

void Isometric_Render::call_pixel(int x, int y, int z) {
	int newx = x_u - x;
	int newy = y_u - y;
	int newz = (*map_2d)[newx][newy];
	RGBApixel * pixel = new RGBApixel;
	pixel->Alpha = 127;
	pixel->Red = 192;
	pixel->Blue = 192;
	pixel->Green = 192;

	if (z == newz) {
		//std::cerr << "found pixel: " << 100 * (double)(x + y + z) / (((x_u - 1) + (y_u - 1) + (z_u - 1) - 3)) << "%" << std::endl;
		//printf("");
		place_cube(newx, newy, newz, pixel);
	}
	else if (z <= newz) {
		pixel->Red = 255 / (x_u - 1)*x % 255;
		pixel->Green = 255 / (y_u - 1)*y % 255;
		pixel->Blue = 255 / (z_u - 1)*z % 255;
		place_cube(newx, newy, z, pixel);
	}
	delete pixel;
}
void Isometric_Render::draw_line(int *x, int *y, RGBApixel * pixel) {
	int x1 = x[0];
	int x2 = y[0];
	int y1 = x[1];
	int y2 = y[1];
	bool isPos = (x1 > x2) ? 1 : 0;
	int right = 1;
	//float brightness = 1.0;
	if (y2 - y1 < 0) {
		right = 0;
	}
	const bool steep = (fabs((double)y2 - y1) > fabs((double)x2 - x1));
	if (steep) {
		std::swap(x1, y1);
		std::swap(x2, y2);
	}

	if (x1 > x2) {
		std::swap(x1, x2);
		std::swap(y1, y2);
	}

	const float dx = (float)(x2 - x1);
	const float dy = (float)fabs((double)y2 - y1);

	float error = dx / 2.0f;
	const int ystep = (y1 < y2) ? 1 : -1;
	int y_new = y1;

	int maxX = (int)x2 + 0;
	const int y_orig = (int)y1;
	for (int x_new = (int)x1; x_new < maxX; x_new++) {
		int deltay = abs(y_new - y_orig);
		if (steep)
		{
			RGBApixel* tpixel = new RGBApixel;
			pixel->Alpha = 127;
			pixel->Red = 50;
			pixel->Green = 50;    //SILVER
			pixel->Blue = 50;
			this->bmp_image->SetPixel(y_new, x_new, *tpixel);
			delete[] tpixel;
		}
		else
		{
			if (x_new == (int)x1)
				maxX++;
			int i;
			if (isPos) {
				for (i = y_new; i < y_new + FACE_HEIGHT - (FACE_HEIGHT - deltay * 2 - 1); i++) {
					this->bmp_image->SetPixel(x_new, i, *pixel);
				}
				for (i = y_new; i > y_new - FACE_HEIGHT; i--) {
					RGBApixel* tpixel = new RGBApixel;
					tpixel->Alpha = pixel->Alpha;
					tpixel->Red = pixel->Red * 0.8;
					tpixel->Green = pixel->Green * 0.8;
					tpixel->Blue = pixel->Blue * 0.8;
					this->bmp_image->SetPixel(x_new + 1, i, *tpixel);
					delete[] tpixel;
				}
			}
			else {
				for (i = y_new; i < y_new + FACE_HEIGHT - deltay * 2; i++) {
					this->bmp_image->SetPixel(x_new, i, *pixel);
				}
				for (i = y_new; i > y_new - FACE_HEIGHT; i--) {
					RGBApixel* tpixel = new RGBApixel;
					tpixel->Alpha = pixel->Alpha;
					tpixel->Red = pixel->Red * 0.6;
					tpixel->Green = pixel->Green * 0.6;
					tpixel->Blue = pixel->Blue * 0.6;
					this->bmp_image->SetPixel(x_new, i, *tpixel);
					delete[] tpixel;
				}
			}

			/*int y_f = 0;
			for (int y_f = y_new; y_f < FACE_HEIGHT - (dy * 2) - 1; y_f++) {
			this->bmp_image->SetPixel(x_new, y_f, *pixel);
			}
			for (y_f = y_new; y_f > -FACE_HEIGHT * dx; y_f--) {
			this->bmp_image->SetPixel(x_new, y_f, *pixel);
			}
			*/
		}

		error -= dy;
		if (error < 0)
		{
			y_new += ystep;
			error += dx;
		}
	}
}



void Isometric_Render::place_cube(int x, int y, int z) {
	int * xy = find_xy(x, y, z);
	RGBApixel * pixel = new RGBApixel;
	pixel->Alpha = 127;
	pixel->Red = this->the_map->get_point(x, y, z)->r;
	pixel->Blue = this->the_map->get_point(x, y, z)->b;
	pixel->Green = this->the_map->get_point(x, y, z)->g;

	int * point_start = (int *)malloc(sizeof(int) * 2);
	int * point_end_r = (int *)malloc(sizeof(int) * 2);
	int * point_end_l = (int *)malloc(sizeof(int) * 2);
	int * point_bottom = (int *)malloc(sizeof(int) * 2);
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
	point_end_l[0] = xy[0] - h_root;
	point_end_l[1] = xy[1] + h_half;
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
	free(point_start);
	free(point_end_r);
	free(point_end_l);
	free(point_bottom);
	free(xy);
	delete[] pixel;

}

void Isometric_Render::place_cube(int x, int y, int z, RGBApixel *pix) {
	int * xy = find_xy(x, y, z);
	times_called++;
	RGBApixel * pixel = new RGBApixel;
	pixel->Alpha = 127;
	pixel->Red = pix->Red;
	pixel->Blue = pix->Blue;
	pixel->Green = pix->Green;

	int * point_start = (int *)malloc(sizeof(int) * 2);
	int * point_end_r = (int *)malloc(sizeof(int) * 2);
	int * point_end_l = (int *)malloc(sizeof(int) * 2);
	int * point_bottom = (int *)malloc(sizeof(int) * 2);
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
	point_end_l[0] = xy[0] - h_root;
	point_end_l[1] = xy[1] + h_half;
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
	free(point_start);
	free(point_end_r);
	free(point_end_l);
	free(point_bottom);
	free(xy);
	delete[] pixel;

}
int* Isometric_Render::find_xy(int x, int y, int z) {
	int *x_y = (int*)malloc(sizeof(int) * 2);
	int h = FACE_HEIGHT;
	int h_root = (int)(h * sqrt(3)) / 2;
	int h_half = h / 2;
	//inititalize to 0,0,0
	x_y[0] = (y_u - y_l + 1)*(h_root - 1) + 0;
	x_y[1] = h - 1;
	//printf("initial: x:%d,y:%d\n", x_y[0], x_y[1]);

	//add x components
	if (x) {
		x_y[0] += x*(h_root - 1);
		x_y[1] += x*h_half;
		//printf("x components: x:%d,y:%d\n", x_y[0], x_y[1]);
	}
	//add y components
	if (y) {
		x_y[0] -= y*(h_root - 1);
		x_y[1] += y*h_half;
		//printf("y components: x:%d,y:%d\n", x_y[0], x_y[1]);
	}//add z components
	if (z) {
		x_y[0] += 0;
		x_y[1] += z*(h - 1);
		//printf("final/z components: x:%d,y:%d\n", x_y[0], x_y[1]);
	}
	//printf("point_xyz (%d,%d,%d) moved to point_xy(%d,%d)\n",x,y,z,x_y[0],x_y[1]);
	return x_y;
}

int * Isometric_Render::get_x() {
	int* result = static_cast<int*>(malloc(sizeof(int) * 2));
	result[0] = this->x_l;
	result[1] = this->x_u;
	return result;
}

int * Isometric_Render::get_y() {
	int* result = static_cast<int*>(malloc(sizeof(int) * 2));
	result[0] = this->y_l;
	result[1] = this->y_u;
	return result;
}

int * Isometric_Render::get_z() {
	int* result = static_cast<int*>(malloc(sizeof(int) * 2));
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
	this->width = ((xu - xl + 1) + (xu - xl + 1))*(h_root - 1) + 1;
	this->height = dimensions[1] - h + 1;
	initialize_render_check();
	times_called = 0;
	free(dimensions);

}

Isometric_Render::Isometric_Render() {}