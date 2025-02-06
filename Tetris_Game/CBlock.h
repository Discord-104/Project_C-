#pragma once
#include "CColor.h"
using namespace std;

//Blocchi che compongono i tetrominoes
class CBlock
{
private:
	int x;		//Posizione x nel campo (colonna)
	int y;		//Posizione y nel campo (riga)
	CColor color;

public:
	//Costruttori
	CBlock();
	CBlock(int x, int y);
	CBlock(int x, int y, CColor color);

	//Getter
	int get_X();
	int get_Y();
	CColor get_Color();

	//Setter
	void set_X(int x);
	void set_Y(int y);
	void set_Color(CColor color);

	void add(CBlock p);
	void sub(CBlock p);

};

