#include "GuiHeader.h"
#include "Header.h"
#include <iostream>

using namespace std;
namespace GUI {
	int Interactions::GetToTheChoppa(int size, int depth, int color1R, int color1G, int color1B, int color2R, int color2G, int color2B, int gradient)
	{

		Generate(size,depth,color1R,color1G,color1B,color2R,color2G,color2B,gradient);
		return 0;
	}
	void Interactions::SqSize(int size, int face_height)
	{
		return;
	}
	void Interactions::FirstColor(int Rval, int Gval, int Bval)
	{
		return;
	}
	void Interactions::SecondColor(int Rval, int Gval, int Bval)
	{
		return;
	}
	void Interactions::Gradient(int True)
	{
		return;
	}
}

GUI_Variables gui()
{
	return GUI_Variables();
}
