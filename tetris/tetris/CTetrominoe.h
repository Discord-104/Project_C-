#pragma once
#include "CBlock.h"
#include <math.h>

#define MAX_EL_T 4			//I tetrominoe sono composti da 4 elementi
#define I_CENTRAL 1			//Posizione del blocco centrale
#define PI 3.14159265359	//Pi




//Tasselli del tetris
class CTetrominoe
{
private:
	CBlock tetrominoe[MAX_EL_T];
public:
	//Costruttori 
	CTetrominoe();
	CTetrominoe(CBlock central_block, char shape);	//Costruttore con parametri il blocco posizionato al centro (riga = 0) e la forma (da questi elementi si può risalire alla posizione degli altri)

	//Getter
	CBlock at(int index);
	CBlock central_block();	//Ritorna il blocco centrale (blocco in posizione 1)
	int get_block_X(int index);
	int get_block_Y(int index);
	CColor get_block_Color(int index);

	//Setter
	void set(int index, CBlock block);
	void set_block_X(int index, int x);
	void set_block_Y(int index, int y);
	void set_block_Color(int index, CColor color);

	void rotate();
	int isInside(int column, int row);
	void add(CBlock b2, int i);
	void sub(CBlock b2, int i);
};