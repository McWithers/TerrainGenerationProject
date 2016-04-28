#include "GuiHeader.h"
#include "Header.h"
#include <iostream>

using namespace std;
GUI_Variables iso(6, 4, 255, 255, 255, 0, 0, 0, 1);
namespace GUI {
	int Interactions::GetToTheChoppa()
	{
		Generate();
		return 0;
	}
	void Interactions::SqSize(int size, int face_height)
	{
		GUI_Variables::size = size;
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