#include "CTetrominoe.h"

//Costruttori 
CTetrominoe::CTetrominoe()
{
	for (int i = 0; i < MAX_EL_T; i++)
	{
		this->tetrominoe[i] = CBlock();
	}
}

CTetrominoe::CTetrominoe(CBlock central_block, char shape) //Costruttore con parametri il blocco centrale e la forma (da questi elementi si può risalire alla posizione degli altri)
{	
	if (shape == 'J')
	{
		tetrominoe[0] = central_block;
		tetrominoe[1] = CBlock(central_block.get_X(), central_block.get_Y() + 1, central_block.get_Color());
		tetrominoe[2] = CBlock(central_block.get_X(), central_block.get_Y() + 2, central_block.get_Color());
		tetrominoe[3] = CBlock(central_block.get_X() - 1, central_block.get_Y() + 2, central_block.get_Color());
	}
	else if (shape == 'L')
	{
		tetrominoe[0] = central_block;
		tetrominoe[1] = CBlock(central_block.get_X(), central_block.get_Y() + 1, central_block.get_Color());
		tetrominoe[2] = CBlock(central_block.get_X(), central_block.get_Y() + 2, central_block.get_Color());
		tetrominoe[3] = CBlock(central_block.get_X() + 1, central_block.get_Y() + 2, central_block.get_Color());
	}
	else if (shape == 'S')
	{
		tetrominoe[0] = CBlock(central_block.get_X() + 1, central_block.get_Y(), central_block.get_Color());
		tetrominoe[1] = central_block;
		tetrominoe[2] = CBlock(central_block.get_X(), central_block.get_Y() + 1, central_block.get_Color());
		tetrominoe[3] = CBlock(central_block.get_X() - 1, central_block.get_Y() + 1, central_block.get_Color());
	}
	else if (shape == 'Z')
	{
		tetrominoe[0] = CBlock(central_block.get_X() - 1, central_block.get_Y(), central_block.get_Color());
		tetrominoe[1] = central_block;
		tetrominoe[2] = CBlock(central_block.get_X(), central_block.get_Y() + 1, central_block.get_Color());
		tetrominoe[3] = CBlock(central_block.get_X() + 1, central_block.get_Y() + 1, central_block.get_Color());
	}
	else if (shape == 'T')
	{
		tetrominoe[0] = central_block;
		tetrominoe[1] = CBlock(central_block.get_X(), central_block.get_Y() + 1, central_block.get_Color());
		tetrominoe[2] = CBlock(central_block.get_X() + 1, central_block.get_Y() + 1, central_block.get_Color());
		tetrominoe[3] = CBlock(central_block.get_X() - 1, central_block.get_Y() + 1, central_block.get_Color());
	}
	else if(shape == 'O')
	{
		tetrominoe[0] = central_block;
		tetrominoe[1] = CBlock(central_block.get_X() + 1, central_block.get_Y(), central_block.get_Color());
		tetrominoe[2] = CBlock(central_block.get_X() + 1, central_block.get_Y() + 1, central_block.get_Color());
		tetrominoe[3] = CBlock(central_block.get_X(), central_block.get_Y() + 1, central_block.get_Color());
	}
	else if (shape == 'I')
	{
		tetrominoe[0] = central_block;
		tetrominoe[1] = CBlock(central_block.get_X(), central_block.get_Y() + 1, central_block.get_Color());
		tetrominoe[2] = CBlock(central_block.get_X(), central_block.get_Y() + 2, central_block.get_Color());
		tetrominoe[3] = CBlock(central_block.get_X(), central_block.get_Y() + 3, central_block.get_Color());
	}
}


//Getter
CBlock CTetrominoe::at(int index)
{
	if (index < 0 || MAX_EL_T <= index)
		return CBlock();

	return this->tetrominoe[index];
}

void CTetrominoe::add(CBlock b2, int i)
{
	this->tetrominoe[i].add(b2);
}

void CTetrominoe::sub(CBlock b2, int i)
{
	this->tetrominoe[i].sub(b2);
}

CBlock CTetrominoe::central_block()
{
	return this->tetrominoe[I_CENTRAL];
}
//Ritorna il blocco centrale (blocco in posizione 1)
int CTetrominoe::get_block_X(int index)
{
	if (index < 0 || MAX_EL_T <= index)
		return -1;

	return this->tetrominoe[index].get_X();
}

int CTetrominoe::get_block_Y(int index)
{
	if (index < 0 || MAX_EL_T <= index)
		return -1;

	return this->tetrominoe[index].get_Y();
}

CColor CTetrominoe::get_block_Color(int index)
{
	if (index < 0 || MAX_EL_T <= index)
		return CColor();

	return this->tetrominoe[index].get_Color();
}


//Setter
void CTetrominoe::set(int index, CBlock block)
{
	if(0 <= index && index < MAX_EL_T)
		this->tetrominoe[index] = block;
}

void CTetrominoe::set_block_X(int index, int x)
{
	if (0 <= index && index < MAX_EL_T)
		this->tetrominoe[index].set_X(x);
}

void CTetrominoe::set_block_Y(int index, int y)
{
	if (0 <= index && index < MAX_EL_T)
		this->tetrominoe[index].set_Y(y);
}

void CTetrominoe::set_block_Color(int index, CColor color)
{
	if (0 <= index && index < MAX_EL_T)
		this->tetrominoe[index].set_Color(color);
}

void CTetrominoe::rotate()
{
	//matrice di rotazione (90°)
	int rotationMatrix[2][2] = { {cos(PI / 2), -sin(PI / 2)}, {sin(PI / 2), cos(PI / 2)} };
	
	//Tengo da parte il blocco centrale del tetrominoe 
	CBlock centre = CBlock(this->tetrominoe[I_CENTRAL].get_X(), this->tetrominoe[I_CENTRAL].get_Y(), this->tetrominoe[I_CENTRAL].get_Color());

	for (int i = 0; i < MAX_EL_T; i++)
	{
		//sottraggo ad ogni tetrominoe il blocco centrale per traslare l'asse
		this->tetrominoe[i].sub(centre);
		int tmp[2] = { tetrominoe[i].get_X(), tetrominoe[i].get_Y() };

		//Moltiplico le coordinate per la matrice di rotazione
		for (int r = 0; r < 2; r++)
		{
			int sum = 0;
			for (int c = 0; c < 2; c++)
				sum += (rotationMatrix[r][c] * tmp[c]);

			if (r == 0)
				this->tetrominoe[i].set_X(sum);
			else if (r == 1)
				this->tetrominoe[i].set_Y(sum);
		}
		this->tetrominoe[i].add(centre);
	}
}

int CTetrominoe::isInside(int column, int row)
{
	for (int i = 0; i < MAX_EL_T; i++)
	{
		if (this->get_block_X(i) >= column) // fuori a destra
			return 1;
		else if (this->get_block_X(i) < 0) // fuori a sinistra
			return -1;
		else if (this->get_block_Y(i) < 0) //fuori sopra
			return -2;
		else if (this->get_block_Y(i) >= row)
			return 2;
	}	
	return 0;			//-1 0 1
}