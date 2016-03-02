//Header Guard~~~~~~~~~~~~~~~~~~~~~~~~~
#ifndef Header_NEAT_H_Included_
#define Header_NEAT_H_Included_
#define _CRT_SECURE_NO_WARNINGS

//Forward Declared Dependencies~~~~~~~~~~~~~~~~~~~~~~~~~
class First_Person;
class Isometric;
class Pool;
class Network;
class Neuron;
class Species;

//Included Dependencies~~~~~~~~~~~~~~~~~~~~~~~~~
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <random>
#include <math.h>
#include <stdint.h>
#define BMP_HEADER_SIZE 54
#define DIB_HEADER_SIZE 40
#define TRUE 1
#define FALSE 0
#define RED_MASK 0x7C00
#define GREEN_MASK 0x03E0
#define BLUE_MASK 0x001F
#define RED_BIT 10
#define GREEN_BIT 5
#define BLUE_BIT 0


using namespace std;
struct BMP_Header {
	uint16_t type;			// Magic identifier
	uint32_t size;			// File size in bytes
	uint16_t reserved1;			// Not used
	uint16_t reserved2;			// Not used
	uint32_t offset;			// Offset to image data in bytes from beginning of file (54 bytes)
	uint32_t DIB_header_size;		// DIB Header size in bytes (40 bytes)
	int32_t  width;			// Width of the image
	int32_t  height;			// Height of image
	uint16_t planes;			// Number of color planes
	uint16_t bits;			// Bits per pixel
	uint32_t compression;		// Compression type
	uint32_t imagesize;			// Image size in bytes
	int32_t  xresolution;		// Pixels per meter
	int32_t  yresolution;		// Pixels per meter
	uint32_t ncolours;			// Number of colors  
	uint32_t importantcolours;		// Important colors
};

struct BMP_Image {
	BMP_Header header;
	unsigned char *data;
};


struct voxel {
	bool isSet;
	unsigned char r;
	unsigned char g;
	unsigned char b;
};

struct pixel {
	unsigned char r;
	unsigned char g;
	unsigned char b;
};

class bmp
{
private:
	BMP_Image* the_image;
	BMP_Image* example;
public:
	bmp(int width, int height, char*);
	bmp();
	~bmp();
	void save();

private:
	char* filename;
	// Read BMP_Image from a given file
	//
	BMP_Image *Read_BMP_Image();
	BMP_Image *Read_BMP_Image(char*);

	// Check the validity of the header with the file from which the header is read
	//
	int Is_BMP_Header_Valid(BMP_Header *bmp_hdr);

	// Write BMP_Image to a given file
	//
	void Write_BMP_Image();

	// Free memory in a given image
	//
	void Free_BMP_Image(BMP_Image* image);





	// Given a BMP_Image, create a new image that retains the image in the
	// box specified by left_x, right_x, bottom_y, top_y
	//
	BMP_Image *Crop_BMP_Image(BMP_Image *image, int left_x, int right_x,
		int bottom_y, int top_y);
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
	int face_height;
	pixel** image;
	World_Map map;
public:
	int * get_x();
	int * get_y();
	int * get_z();
	void set_x(int, int);
	void set_y(int, int);
	void set_z(int, int);
	void set_face_height(int);
	int get_face_height();
	void recursive_place(int, int, int);
	void create_image(World_Map);
	void place_cube(int, int, int);
	Isometric_Render(World_Map map, int xl, int xu, int yl, int yu, int zl, int zu);
	Isometric_Render();
};

#endif // NeatZombies header file inclusion if ~~~~~~~~~~~~~~~~~~~~~~~~~
