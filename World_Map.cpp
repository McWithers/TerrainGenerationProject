#include "Header.h"

using namespace std;

void World_Map::allocate_memory() {
	int x_i;
	int y_i;
	int z_i;//*/
	//this->map = new voxel[this->x][this->y][this->z];
	this->map = (voxel****)malloc(sizeof(voxel***)*this->z);
	for (x_i = 0; x_i < this->x; x_i++) {
		voxel *** v_yz = (voxel***)malloc(sizeof(voxel**)*this->y);
		for (y_i = 0; y_i < this->y; y_i++) {
			voxel ** v_z = (voxel**)malloc(sizeof(voxel*)*this->z);
			for (z_i = 0; z_i < this->z; z_i++) {
				voxel *v = (voxel*)malloc(sizeof(voxel) * 1);
				v->isSet = 0;
				v->r = 255 / this->x*x_i % 255;
				v->g = 255 / this->y*y_i % 255;
				v->b = 255 / this->z*z_i % 255;
				v_z[z_i] = v;
			}
			v_yz[y_i] = v_z;
		}
		this->map[x_i] = v_yz;
	}//*/
	/*this -> map = (voxel ***) calloc(x, sizeof(voxel));
	for (x_i = 0; x_i < this->x; x_i++) {
		map[x_i] = (voxel **) calloc(y, sizeof(voxel));
		for (x_i = 0; x_i < this->x; x_i++) {
		map[x_i][y_i] = (voxel *) calloc(this->z, sizeof(voxel));
		}
	}//*/
	cout << "done allocating!" << endl;
	cout << "test: " << (int)this->map[3][3][3]->g << endl;

}

voxel **** World_Map::get_map() {
	return this->map;
}

voxel * World_Map::get_point(int c_x, int c_y, int c_z) {
	voxel **** m = get_map();
	return m[c_x][c_y][c_z];
}

void World_Map::set_point(int n_x, int n_y, int n_z) {
	voxel **** m = this->map;
	m[n_x][n_y][n_z]->isSet=1;
}

int World_Map::get_x() {

	return this->x;
}

int World_Map::get_y() {

	return this->y;
}

int World_Map::get_z() {

	return this->z;
}

void World_Map::set_x(int new_x) {
	this->x = new_x;
}

void World_Map::set_y(int new_y) {
	this->y = new_y;
}

void World_Map::set_z(int new_z) {
	this->z = new_z;
}

void World_Map::convert_to_3d(double ** map_2d) {
	int i;
	int j;
	for (i = 0; i < this->x-1; i++) {
		for (j = 0; j < this->y-1; j++) {
			int newk = (int)map_2d[i][j];
			this->map[i][j][newk]->isSet = 1;
			this->map[i][j][newk]->r = 50;
			this->map[i][j][newk]->g = 50;
			this->map[i][j][newk]->b = 50;
			for (int tempk = 0; tempk <= (int)map_2d[i][j]; tempk++)// {}
				this->map[i][j][tempk]->isSet = 1;
		}
	}
}

World_Map::World_Map(int xBound, int yBound, int zBound) {
	cout << "The value for x is:" << xBound << endl;
	cout << "The value for y is:" << yBound << endl;
	cout << "The value for z is:" << zBound << endl;
	this->set_x(xBound);
	this->set_y(yBound);
	this->set_z(zBound);
	this->allocate_memory();

}

World_Map::World_Map() {}

World_Map::~World_Map() {
	int x_i;
	int y_i;
	int z_i;

	for (x_i = 0; x_i < this->x; x_i++) {
		for (y_i = 0; y_i < this->y; y_i++) {
			for (z_i = 0; z_i < this->z; z_i++) {
				free(map[x_i][y_i][z_i]);
			}
			free(map[x_i][y_i]);
		}
		free(map[x_i]);
	}
	//free(map);
}

