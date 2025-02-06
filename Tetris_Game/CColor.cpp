#include "CColor.h"

//Costruttori
CColor::CColor()
{
	this->r = 0;
	this->g = 0;
	this->b = 0;
}

CColor::CColor(int r, int g, int b)
{
	this->r = r;
	this->g = g;
	this->b = b;
}


//Getter
int CColor::get_Red()
{
	return this->r;
}

int CColor::get_Green()
{
	return this->g;
}

int CColor::get_Blue()
{
	return this->b;
}


//Setter
void CColor::set_Red(int r)
{
	this->r = r;
}

void CColor::set_Green(int g)
{
	this->g = g;
}

void CColor::set_Blue(int b)
{
	this->b = b;
}

