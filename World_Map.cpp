#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct voxel {
	bool isSet = false;
	unsigned char r = 0;
	unsigned char g = 0;
	unsigned char b = 0;
};

class World_Map {
private:
	
	int x;
	int y;
	int z;
	
public:
	
	voxel*** map;
	void allocate_memory();
	int get_x();
	int get_y();
	int get_z();
	voxel *** get_map();
	voxel get_point(int, int, int);
	void set_x(int);
	void set_y(int);
	void set_z(int);
	World_Map(int, int, int);
	void set_point(int, int, int);
	~World_Map();
};

void World_Map::allocate_memory() {
	int x_i;
	int y_i;
	int z_i;
	
	this -> map = (voxel ***) calloc(x, sizeof(voxel));
	for (x_i = 0; x_i < this->x; x_i++) {
		map[x_i] = (voxel **) calloc(y, sizeof(voxel));
		for (y_i = 0; y_i < this->y; y_i++) {
			map[x_i][y_i] = (voxel *) calloc(z, sizeof(voxel));
		}
	}
}

voxel *** World_Map::get_map() {
	return this->map;
}

voxel World_Map::get_point(int c_x, int c_y, int c_z) {
	voxel *** m = get_map();
	return m[c_x][c_y][c_z];
}

void World_Map::set_point(int n_x, int n_y, int n_z) {
	voxel *** m = get_map();
	m[n_x][n_y][n_z] = 1;
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

World_Map::World_Map(int x, int y, int z) {
	cout << "The value for x is:" << x << endl;
	cout << "The value for y is:" << y << endl;
	cout << "The value for z is:" << z << endl;
	this->set_x(x);
	this->set_y(y);
	this->set_z(z);
	this->allocate_memory();

}

World_Map::~World_Map() {
	int i;
	int j;
	for (i = 0; i < this->x; i++) {
		for (j = 0; j < this->y; j++) {
			free(map[i][j]);
		}
		free(map[i]);
	}
	free(map);
}

