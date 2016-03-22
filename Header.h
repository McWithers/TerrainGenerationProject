//Header Guard~~~~~~~~~~~~~~~~~~~~~~~~~
#ifndef Header_H
#define Header_H

#define _CRT_SECURE_NO_WARNINGS

//Forward Declared Dependencies~~~~~~~~~~~~~~~~~~~~~~~~~

//Included Dependencies~~~~~~~~~~~~~~~~~~~~~~~~~
#include <stdio.h>
#include <stdlib.h>	
#include <string>
#include <iostream>
#include <random>
//#include <math.h>
#include <math.h>
#include <stdint.h>
#include "EasyBMP.h"
#include "EasyBMP_BMP.h"
#include "EasyBMP_DataStructures.h"
#include "EasyBMP_VariousBMPutilities.h"
#define FACE_HEIGHT 21
#define ARRAY_SIZE 9
#define DEBUGGING_WIDTH 0//1000
#define DEBUGGING_HEIGHT 0//1000
#define PI 3.14159265

using namespace std;

struct voxel {
	bool isSet;
	unsigned char r;
	unsigned char g;
	unsigned char b;
};

struct pixel {
	int x;
	int y;
	unsigned char r;
	unsigned char g;
	unsigned char b;
};

class World_Map {
private:

	int x;
	int y;
	int z;

public:

	voxel**** map;
	void allocate_memory();
	int get_x();
	int get_y();
	int get_z();
	struct voxel **** get_map();
	struct voxel * get_point(int x, int y, int z);
	void set_x(int);
	void set_y(int);
	void set_z(int);
	void set_point(int x, int y , int z);
	World_Map(int x, int y, int z);
	World_Map();
	~World_Map();
};


class Isometric_Render {
private:
	int x_l;
	int x_u;
	int y_l;
	int y_u;
	int z_l;
	int z_u;
	//pixel** image;
	//World_Map *map;
public:
	int width;
	World_Map *the_map;
	int height;
	BMP *bmp_image;
	int * get_x();
	int * get_y();
	int * get_z();
	int * find_xy(int, int, int);
	void set_x(int, int);
	void set_y(int, int);
	void set_z(int, int);
	void recursive_place(int, int, int);
	void create_image(World_Map);
	void place_cube(int, int, int);
	void draw_line(int * , int *, RGBApixel *);
	Isometric_Render(World_Map*,BMP*,int,int,int,int,int,int);
	Isometric_Render();
};

class Diamond_Square {
private:
	int **array2d;
	int x;
	int y;
	int size;
	int max_height;
	void set_x(int value);
	void set_y(int value);
   void set_array2d(int x, int y); 
   int find_midpoint(int value1, int value2);
public:
	void Diamond_Square::square(int *, int *, int *, int *);
   int** get_array2d();
	int get_x();
	int get_y();
	int get_size();
	int get_max_height();
	Diamond_Square(int size, int max_height);
	Diamond_Square();
};

class Generate_Shapes {
private:
	int a;
public:
	void make2dterrainimage(int**);
	Generate_Shapes();
	Generate_Shapes(int);
};

class DS {
private:
	double **the_grid;
public:
	DS();
	void set_array2d(int x, int y);
	//void DiamondSquare(float siz, float roughness, int maxx);
	void DiamondSquare();
	~DS() {
		// Test
		cout << "Destructor works fine" << endl;
	};
};
#endif // header file inclusion if ~~~~~~~~~~~~~~~~~~~~~~~~~
