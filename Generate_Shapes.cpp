#include "Header.h"

void Generate_Shapes::make2dterrainimage(int** array) {
	BMP * image = new BMP;
	image->SetSize(5, 5);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			RGBApixel  * newPixel = new RGBApixel;
			if (array[i][j] != -1) {
				newPixel->Red = (array[i][j] * 255) / 100;
				newPixel->Green = 0;
				newPixel->Blue = 0;
			}
			else
			{
				newPixel->Red = 192;
				newPixel->Green = 192;
				newPixel->Blue = 192;
			}
			image->SetPixel(i, j, *newPixel);
		}
	}
	image->WriteToFile("terrain");
}

Generate_Shapes::Generate_Shapes()
{
	this->a = 0;
}

Generate_Shapes::Generate_Shapes(int a)
{
	this->a = a;
}

/*for (i = 0; i < iso.width; i++) {
for (j = 0; j < iso.height; j++) {
RGBApixel* pixel = new RGBApixel;
pixel->Alpha = 127;
//pixel->Red = (int)(iso.height * 0 / (j + 1))%255;
pixel->Red = 150;
//pixel->Green = (int)((iso.height/25)*i);
pixel->Green = 150;
pixel->Blue = 150;
image->SetPixel(i, j, *pixel);
}
}*/
//iso.place_cube(2, 2, 2);
//change made
//bmp image(10,10,(char*)"air.bmp");
//image->save();
//printf("Saved!\n");
/*int x_max = Plot.get_x();
int y_max = Plot.get_y();
int z_max = Plot.get_z();
int * a = (int *)malloc(sizeof(int) * 2);
int * b = (int *)malloc(sizeof(int) * 2);
a[0] = 40;//x1
b[1] = 60;//y1
b[0] = 100;//x2
a[1] = 80;//y2
*/
/*for (i = -sqSize/2 + 2; i < x_max-sqSize/2 - 2; i++) {
for (j = -sqSize/2 + 2; j < y_max-sqSize/2 - 2; j++) {
for (k = -sqSize/2 + 2; k < z_max-sqSize/2 - 2; k++) {
//cout << "cos: " <<  11 * cos(k) << endl;
//if(i == 11 * cos(k *  (PI/180) || j == 11 * sin(k * (PI/180)))){

//if(i == j || i == k == j){
//if(k == (k/sqrt(1 - ((i * i)/ 28 * 28))) - (k * k)/16 + (i * i)/25 || i == j == k ) {
//if(k /16 == (i * i)/49 - (j *j)/81 || k * k == i * i + j * j){
//if(k * k == i * i + j*j || i * i == k * k + j * j || j * j == i * i + k * k || j * 5* sin(i * (PI/180)) == j * k) {// || i * 5 * cos(j * (PI / 180)) == i * k){
//if (10 * sin(k) >= k && 11 * sin(k) < k && 11 * cos(j) <= j && 9 * cos(j) > j) {
//if (i*i + j*j + k*k <= 19 * 19 ? i*i + j*j + k*k >= 18 * 18 ? 1 : 0 : 0) {
//if (1) {
Plot.set_point(i+sqSize/2, j+sqSize/2, k+sqSize/2);
int * point = iso.find_xy(i+sqSize/2, j+sqSize/2, k+sqSize/2);
iso.place_cube(i+sqSize/2, j+sqSize/2, k+sqSize/2);
RGBApixel* pixel = new RGBApixel;
pixel->Alpha = 127;
pixel->Red = Plot.get_point(i, j, k)->r;
pixel->Green = Plot.get_point(i, j, k)->g;
pixel->Blue = Plot.get_point(i, j, k)->b;
image->SetPixel(point[0], iso.height - point[1], *pixel);

//cout << "i: " << i << "  j: " << j << "  k: " << k << endl;

}
}
}
*/
