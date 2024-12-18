#include "CBlock.h"

//Costruttori
CBlock::CBlock()
{
	this->x = 0;
	this->y = 0;
	this->color = CColor();
}

CBlock::CBlock(int x, int y, CColor color)
{
	this->x = x;
	this->y = y;
	this->color = color;
}

CBlock::CBlock(int x, int y)
{
	this->x = x;
	this->y = y;
	this->color = CColor();
}

//Getter
int CBlock::get_X()
{
	return this->x;
}

int CBlock::get_Y()
{
	return this->y;
}

CColor CBlock::get_Color()
{
	return this->color;
}


//Setter
void CBlock::set_X(int x)
{
	this->x = x;
}

void CBlock::set_Y(int y)
{
	this->y = y;
}

void CBlock::set_Color(CColor color)
{
	this->color = CColor();
}

void CBlock::add(CBlock p)
{
	this->x += p.x;
	this->y += p.y;
}

void CBlock::sub(CBlock p)
{
	this->x -= p.x;
	this->y -= p.y;
}