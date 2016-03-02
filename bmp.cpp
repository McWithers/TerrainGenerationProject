#include "Header.h"


/* check whether a header is valid
 * assume that header has been read from fptr
 * the position of the indicator of fptr is not certain
 * could be at the beginning of the file, end of the file or 
 * anywhere in the file
 * note that the check is only for this exercise/assignment
 * in general, the format is more complicated
 */
int bmp::Is_BMP_Header_Valid(BMP_Header* header) {
  // Make sure this is a BMP file
  if (header->type != 0x4d42) {
	  printf("type\n");
     return FALSE;
  }
  // skip the two unused reserved fields

  // check the offset from beginning of file to image data
  // essentially the size of the BMP header
  // BMP_HEADER_SIZE for this exercise/assignment
  if (header->offset != BMP_HEADER_SIZE) {
	  printf("offset\n");
	  return FALSE;
  }
      
  // check the DIB header size == DIB_HEADER_SIZE
  // For this exercise/assignment
  if (header->DIB_header_size != DIB_HEADER_SIZE) {
	  printf("DIB_header_size\n");
	  return FALSE;
  }

  // Make sure there is only one image plane
  if (header->planes != 1) {
	  printf("planes\n");
	  return FALSE;
  }
  // Make sure there is no compression
  if (header->compression != 0) {
	  printf("compression\n");
	  return FALSE;
  }

  // skip the test for xresolution, yresolution

  // ncolours and importantcolours should be 0
  if (header->ncolours != 0) {
	  printf("ncolours\n");
	  return FALSE;
  }
  if (header->importantcolours != 0) {
	  printf("importantcolours\n");
	  return FALSE;
  }
  
  // Make sure we are getting 24 bits per pixel
  // or 16 bits per pixel
  // only for this assignment
  if (header->bits != 24 && header->bits != 16) {
	  printf("bits\n");
	  return FALSE;
  }

  // fill in extra to check for file size, image size
  // based on bits, width, and height

  int bits = header->bits/8;
  int pad = 0;
  if ((bits * header->width) % 4 != 0) {
	  pad = 4 - ((bits * header->width) % 4);
  }
  int imageSize = (header->width * bits +pad)*header->height;
  if ((int)header->imagesize != imageSize) {
	  fprintf(stderr, "Input file not in expected format: Data\n");
	  return FALSE;
  }
  
  if ((int)header->size != imageSize + 54) {
	  fprintf(stderr, "Input file not in expected format: Whole filesize\n");
	  return FALSE;
  }
  return TRUE;
}

/* The input argument is the source file pointer. 
 * The function returns an address to a dynamically allocated BMP_Image only 
 * if the file * contains a valid image file 
 * Otherwise, return NULL
 * If the function cannot get the necessary memory to store the image, also 
 * return NULL
 * Any error messages should be printed to stderr
 */
BMP_Image *bmp::Read_BMP_Image() {
  // go to the beginning of the file
	FILE* fptr = fopen("airplane.bmp", "r");
	fseek(fptr, 0, SEEK_SET);
   BMP_Image *bmp_image = NULL;
  //Allocate memory for BMP_Image*;
	bmp_image = (BMP_Image*)calloc(sizeof(BMP_Image), 1);
	if (bmp_image == NULL) {
		fprintf(stderr, "Error allocating memory\n");
		return NULL;
	}
	//Read the first 54 bytes of the source into the header
	fread(bmp_image, sizeof(BMP_Header), 1, fptr);
	if (&(bmp_image->header) == NULL) {
		fprintf(stderr, "Can't read image from file\n");
		return NULL;
	}
	// if read successful, check validity of header
	if (!Is_BMP_Header_Valid(&(bmp_image->header))) {
		fprintf(stderr, "Input file not in expected format\n");
		return NULL;
	}
	// Allocate memory for image data
	bmp_image->data = (unsigned char *)calloc(bmp_image->header.imagesize, 1);
	if (bmp_image->data == NULL) {
		fprintf(stderr, "Error allocating memory\n");
		return NULL;
	}
   // read in the image data
	fread(bmp_image->data, bmp_image->header.imagesize, 1, fptr);
	return bmp_image;
}


BMP_Image *bmp::Read_BMP_Image(char * name) {
	// go to the beginning of the file
	FILE* fptr = fopen(name, "r");
	fseek(fptr, 0, SEEK_SET);
	BMP_Image *bmp_image = NULL;
	//Allocate memory for BMP_Image*;
	bmp_image = (BMP_Image*)calloc(sizeof(BMP_Image), 1);
	if (bmp_image == NULL) {
		fprintf(stderr, "Error allocating memory\n");
		return NULL;
	}
	//Read the first 54 bytes of the source into the header
	fread(bmp_image, sizeof(BMP_Header), 1, fptr);
	if (&(bmp_image->header) == NULL) {
		fprintf(stderr, "Can't read image from file\n");
		return NULL;
	}
	// if read successful, check validity of header
	if (!Is_BMP_Header_Valid(&(bmp_image->header))) {
		fprintf(stderr, "Input file not in expected format\n");
		return NULL;
	}
	// Allocate memory for image data
	bmp_image->data = (unsigned char *)calloc(bmp_image->header.imagesize, 1);
	if (bmp_image->data == NULL) {
		fprintf(stderr, "Error allocating memory\n");
		return NULL;
	}
	// read in the image data
	fread(bmp_image->data, bmp_image->header.imagesize, 1, fptr);
	return bmp_image;
}

/*
BMP_Image *bmp::Read_BMP_Image() {
	// go to the beginning of the file
	char* filename = this->filename;
	FILE* fptr = fopen(filename, "r");
	fseek(fptr, 0, SEEK_SET);
	BMP_Image *bmp_image = NULL;
	//Allocate memory for BMP_Image*;
	bmp_image = (BMP_Image*)calloc(sizeof(BMP_Image), 1);
	if (bmp_image == NULL) {
		fprintf(stderr, "Error allocating memory\n");
		return NULL;
	}
	//Read the first 54 bytes of the source into the header
	fread(bmp_image, sizeof(BMP_Header), 1, fptr);
	if (&(bmp_image->header) == NULL) {
		fprintf(stderr, "Can't read image from file\n");
		fclose(fptr);
		return NULL;
	}
	// if read successful, check validity of header
	if (!Is_BMP_Header_Valid(&(bmp_image->header))) {
		fclose(fptr);
		fprintf(stderr, "Input file not in expected format\n");
		return NULL;
	}
	// Allocate memory for image data
	bmp_image->data = (unsigned char*)(calloc(bmp_image->header.imagesize, 1));
	if (bmp_image->data == NULL) {
		fclose(fptr);
		fprintf(stderr, "Error allocating memory\n");
		return NULL;
	}
	// read in the image data
	fread(bmp_image->data, bmp_image->header.imagesize, 1, fptr);
	fclose(fptr);
	return bmp_image;
}

/* The input arguments are the destination file pointer, BMP_Image *image.
 * The function write the header and image data into the destination file.
 * return TRUE if write is successful
 * FALSE otherwise
 */
void bmp::Write_BMP_Image() 
{
   // go to the beginning of the file
	BMP_Image* image = this->the_image;
	FILE * fptr = fopen(this->filename,"w+");
	fseek(fptr, 0, SEEK_SET);
	if (!fwrite(&image->header, sizeof(BMP_Header), 1, fptr)) {
		fprintf(stderr, "Error writing to output file\n");
		fclose(fptr);
		return; 
	}
   // write header
	if (!fwrite(image->data, image->header.imagesize, 1, fptr)) {
		fprintf(stderr, "Error writing to output file\n");
		fclose(fptr);
		return;
	}
   // write image data
	fclose(fptr);
}

bmp::bmp(int width, int height, char* fname)
{
	BMP_Image *image;
	this->filename = fname;
	int pixelSize = 24 / 8;
	int i;
	int j;
	int k;
	int newWidth = width;
	int imageWidth = width;
	int pad = 0;
	if ((pixelSize * newWidth) % 4 != 0) {
		pad = 4 - ((pixelSize * newWidth) % 4);
	}
	int newHeight = height;
	int imageHeight = height;
	int imageSize = (pixelSize*newWidth + pad)*newHeight;
	unsigned char* newData = (unsigned char*)malloc(imageSize);
	//printf("%d \n",pixelSize*(newWidth*newHeight));
	int indexNew = 0;
	for (i = 0; i < imageHeight; i++) {
		for (j = 0; j < imageWidth; j++) {
			for (k = 0; k < pixelSize; k++) {
				newData[indexNew] = '5';
				indexNew++;
			}
		}
		indexNew += pad;
	}
	//this->the_image->data[indexNew] = 0;
	// getting the box coordinates to stay within range
	// proceed only if left_x <= right_x and bottom_y <= top_y
	// create a new image cropped from the given image
	int bits = pixelSize;
	this->example = Read_BMP_Image("airplane.bmp");
	this->the_image = (BMP_Image*)malloc(sizeof(BMP_Image) * 1);
	this->the_image->header.height = height;
	this->the_image->header.width = width;
	this->the_image->header.imagesize = imageSize;
	this->the_image->header.size = imageSize + 54;
	this->the_image->data = newData;
	this->the_image->header.type = 19778;			// Magic identifier
	this->the_image->header.reserved1 = 0;			// Not used
	this->the_image->header.reserved2 = 0;			// Not used
	this->the_image->header.offset = BMP_HEADER_SIZE;			// Offset to image data in bytes from beginning of file (54 bytes)
	this->the_image->header.DIB_header_size = DIB_HEADER_SIZE;		// DIB Header size in bytes (40 bytes)
	this->the_image->header.planes = 1;			// Number of color planes
	this->the_image->header.bits = pixelSize*8;			// Bits per pixel
	this->the_image->header.compression = 0;		// Compression type
	this->the_image->header.xresolution = 2835;		// Pixels per meter
	this->the_image->header.yresolution = 2835;		// Pixels per meter
	this->the_image->header.ncolours = 0;			// Number of colors  
	this->the_image->header.importantcolours = 0;		// Important colors

	if (!this->Is_BMP_Header_Valid(&this->the_image->header)) {
		printf("header was wrong\n");
	}
}

bmp::bmp()
{
}

bmp::~bmp()
{
}

/* The input argument is the BMP_Image pointer. The function frees memory of 
 * the BMP_Image.
 */
void bmp::Free_BMP_Image(BMP_Image* image) {
	if (image == NULL) {
		return;
	}
	free(image->data);
	free(image);
}

// Given a valid BMP_Image, create a new image that retains the image in the
// box specified by left_x, right_x, bottom_y, top_y
//
/*
BMP_Image* bmp::Crop_BMP_Image(BMP_Image *image, int left_x,
	int right_x, int bottom_y,
	int top_y)
{
	int imageHeight = image->header.height;
	int imageWidth = image->header.width;
	if (left_x > right_x || top_y < bottom_y) {
		fprintf(stderr, "Can't crop the image\n");
		return NULL;
	}
	left_x = (left_x < 0) ? 0 : ((left_x >(imageWidth - 1))
		? imageWidth - 1 : left_x);
	right_x = (right_x < 0) ? 0 : ((right_x >(imageWidth - 1))
		? imageWidth - 1 : right_x);
	bottom_y = (bottom_y < 0) ? 0 : ((bottom_y >(imageHeight - 1))
		? imageHeight - 1 : bottom_y);
	top_y = (top_y < 0) ? 0 : ((top_y >(imageHeight - 1))
		? imageHeight - 1 : top_y);
	int pixelSize = image->header.bits / 8;
	unsigned char *oldData = image->data;
	int i;
	int j;
	int k;
	int newWidth = right_x - left_x + 1;
	int newPad = 0;
	int oldPad = 0;
	if ((pixelSize * newWidth) % 4 != 0) {
		newPad = 4 - ((pixelSize * newWidth) % 4);
	}
	if ((pixelSize * imageWidth) % 4 != 0) {
		oldPad = 4 - ((pixelSize * imageWidth) % 4);
	}
	int newHeight = top_y - bottom_y + 1;
	unsigned char *newData = (unsigned char*)(malloc(pixelSize*(newWidth + newPad) * newHeight));
	int indexOld = 0;
	int indexNew = 0;
	for (i = 0; i < imageHeight; i++) {
		for (j = 0; j < imageWidth; j++) {
			if (j >= left_x && j <= right_x && i >= bottom_y && i <= top_y) {
				for (k = 0; k < pixelSize; k++) {
					newData[indexNew] = oldData[indexOld];
					indexNew++;
					indexOld++;
				}
			}
			else {
				indexOld += pixelSize;
			}
			if (j == right_x && i <= top_y && i >= bottom_y) {
				indexNew += newPad;
			}		
		}
		indexOld += oldPad;
	}
	// getting the box coordinates to stay within range
	// proceed only if left_x <= right_x and bottom_y <= top_y
	// create a new image cropped from the given image
	int bits = image->header.bits / 8;
	int pad = 0;
	if (bits * (right_x - left_x + 1) % 4 != 0) {
		pad = 4 - ((bits * (right_x - left_x + 1)) % 4);
	}
	int imageSize = (bits * (right_x - left_x + 1) + pad) *
		(top_y - bottom_y + 1);	
	BMP_Image *t_image = NULL;
	t_image = (BMP_Image*)(malloc(sizeof(BMP_Image) * 1));
	t_image->header.height = top_y - bottom_y + 1;
	t_image->header.width = right_x - left_x + 1;
	t_image->header.imagesize = imageSize;
	t_image->header.size = imageSize + 54;
	t_image->data = (unsigned char *)malloc(imageSize * 1);
	int count;
	for (count = 0; count < imageSize; count++) {
		(t_image->data)[count] = newData[count];
	}
	t_image->header.type = image->header.type;			// Magic identifier
	t_image->header.reserved1 = image->header.reserved1;			// Not used
	t_image->header.reserved2 = image->header.reserved2;			// Not used
	t_image->header.offset = image->header.offset;			// Offset to image data in bytes from beginning of file (54 bytes)
	t_image->header.DIB_header_size = image->header.DIB_header_size;		// DIB Header size in bytes (40 bytes)
	t_image->header.planes = image->header.planes;			// Number of color planes
	t_image->header.bits = image->header.bits;			// Bits per pixel
	t_image->header.compression = image->header.compression;		// Compression type
	t_image->header.xresolution = image->header.xresolution;		// Pixels per meter
	t_image->header.yresolution = image->header.yresolution;		// Pixels per meter
	t_image->header.ncolours = image->header.ncolours;			// Number of colors  
	t_image->header.importantcolours = image->header.importantcolours;		// Important colors
	free(newData);
	Free_BMP_Image(image);
	return t_image;
}
//*/
void bmp::save() {
	Write_BMP_Image();
}