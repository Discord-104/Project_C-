#include "CTetris.h"

//Costruttori
CTetris::CTetris()
{
	for (int r = 0; r < ROW; r++)
	{
		for (int c = 0; c < COLUMN; c++)
		{
			if (c % 2 == 0)
				this->matrix[r][c] = CColor();
			else
				this->matrix[r][c] = CColor(255, 255, 255);
		}
	}

	this->lines = 0;
	this->score = 0;
	this->speed = INITIAL_SPEED;

	this->CreateTetrominoe();
}

//Getter
long int CTetris::get_score()
{
	return this->score;
}

long int CTetris::get_lines()
{
	return this->lines;
}

/// <summary>
/// Metodo per gestire un movimento
/// </summary>
/// <param name="key">Tasto premuto per il movimento (passato dal main), in caso non sia stato premuto nessun tasto -1</param>
void CTetris::movement(int key)
{
	CTetrominoe copy = tetrominoe;

	if (key != -1)
	{
		if (key == KEY_RIGHT)		//Freccia dx
		{
			CTetrominoe tmp = copy;

			for (int i = 0; i < MAX_EL_T; i++)		//movimento a dx
				copy.add(CBlock(1, 0), i);		//aggiungo alle coordinate 1x

			if (copy.isInside(COLUMN, ROW) != 0 || !this->isAlloud())
				copy = tmp;
		}
		else if (key == KEY_LEFT)	//Freccia sx
		{
			CTetrominoe tmp = copy;

			for (int i = 0; i < MAX_EL_T; i++)		//movimento a sx
				copy.sub(CBlock(1, 0), i);		//sottraggo alle coordinate 1x

			if (copy.isInside(COLUMN, ROW) != 0 || !this->isAlloud())
				copy = tmp;
		}
		else if (key == KEY_UP)		//Freccia up
		{
			CTetrominoe tmp = copy;
			copy.rotate();		//rotazione

			//WALL KICK
			while (copy.isInside(COLUMN, ROW) != 0)		//Controllo se la rotazione è valida
			{

				if (copy.isInside(COLUMN, ROW) == 1)			//Se esce a destra-- > -1x
					for (int i = 0; i < MAX_EL_T; i++)
						copy.sub(CBlock(1, 0), i);
				else if (copy.isInside(COLUMN, ROW) == -1)		//Se esce a sinistra --> +1x
					for (int i = 0; i < MAX_EL_T; i++)
						copy.add(CBlock(1, 0), i);
				else if (copy.isInside(COLUMN, ROW) == -2)		//Se esce a sopra --> +1y
					for (int i = 0; i < MAX_EL_T; i++)
						copy.add(CBlock(0, 1), i);
				else if (copy.isInside(COLUMN, ROW) == 2)		//Se esce a sopra --> -1y
					for (int i = 0; i < MAX_EL_T; i++)
						copy.sub(CBlock(0, 1), i);
			}

			if (!this->isAlloud())
				copy = tmp;
		}
		else if (key == KEY_DOWN)	//Freccia down premuta
			this->speed /= 2;		//aumenta la velocità di discesa 
		else if (key == KEY_DOWN + 1)	//Freccia down rilasciata
			this->speed *= 2;		//ripristino la velocità di discesa normale
	}
		
	

	//Controllo se il movimento è valido  (non appoggia e non esce dalla matrice )
	if (!this->isOut() && !this->isLaid())
	{
		//Spostamento verso il basso	
		for (int i = 0; i < MAX_EL_T; i++)
			copy.add(CBlock(0, 1), i);		//aggiungo alle coordinate 1y	CBlock(0, 1)

		this->tetrominoe = copy;
	}
	else
	{
		//Se non è valido --> Sposto il colore nella matrice
		int counter = 0; //Conta il numero di righe completate
		for (int i = 0; i < MAX_EL_T; i++)
		{
			this->matrix[tetrominoe.at(i).get_Y() + counter][tetrominoe.at(i).get_X()] = tetrominoe.at(i).get_Color();

			//Controllo se una riga è stata completata --> aumento il couter di 1
			if (this->isLineComplete(tetrominoe.at(i).get_Y()))
			{
				counter++;
				//Se si --> cancello la riga (shift) 
				this->shift(tetrominoe.at(i).get_Y() + counter);
			}
		}
		// genero un nuovo tetrominoe 
		this->CreateTetrominoe();
	}
}

void CTetris::CreateTetrominoe()
{
	srand(time(NULL));
	//crea un tetromino nella riga 0 colonna centrale del campo di forma randomica (scelta all'interno del vettore shapes) e colore randomico (scelto all'interno del vettore colors)
	this->tetrominoe = CTetrominoe(CBlock(COLUMN / 2, 0, colors[rand() % 7]), shapes[rand() % 7]);
}

bool CTetris::isGameOver()
{
	for (int i = 0; i < MAX_EL_T; i++)
	{
		int x = tetrominoe.at(i).get_X(),
			y = tetrominoe.at(i).get_Y();

		if ((matrix[y][x].get_Red() != MINRGB && matrix[y][x].get_Green() != MINRGB && matrix[y][x].get_Blue() != MINRGB) ||        // colore
			(matrix[y][x].get_Red() != MAXRGB && matrix[y][x].get_Green() != MAXRGB && matrix[y][x].get_Blue() != MAXRGB))
			return true;
	}

	return false;
}

bool CTetris::isLineComplete(int r)
{
	for (int c = 0; c < COLUMN; c++)
	{
		if ((matrix[r][c].get_Red() == MINRGB && matrix[r][c].get_Green() == MINRGB && matrix[r][c].get_Blue() == MINRGB) ||        // colore
			(matrix[r][c].get_Red() == MAXRGB && matrix[r][c].get_Green() == MAXRGB && matrix[r][c].get_Blue() == MAXRGB))
			return false;
	}
	return true;
}

bool CTetris::isAlloud()
{
	int count = 0;
	for (int i = 0; i < 4; i++)
	{
		int x = this->tetrominoe.at(i).get_X(),
			y = this->tetrominoe.at(i).get_Y();
		if ((matrix[y][x].get_Red() == MINRGB && matrix[y][x].get_Green() == MINRGB && matrix[y][x].get_Blue() == MINRGB) ||
			(matrix[y][x].get_Red() == MAXRGB && matrix[y][x].get_Green() == MAXRGB && matrix[y][x].get_Blue() == MAXRGB))
			count++;
	}

	if (count == 4)
		return true;
	return false;
}

void CTetris::shift(int row)
{
	for (int c = 0; c < COLUMN; c++)
	{
		for (int r = row; r >= 0; r--)
			matrix[r][c] = matrix[r - 1][c];
	}

	for (int c = 0; c < COLUMN; c++)
	{
		if (c % 2 == 0)
			this->matrix[0][c] = CColor();
		else
			this->matrix[0][c] = CColor(255, 255, 255);
	}
		
}

CColor CTetris::get_color(int x, int y)
{
	return this->matrix[y][x];
}


CColor CTetris::get_color(int i)
{
	return this->tetrominoe.at(i).get_Color();
}

int CTetris::get_x(int i)
{
	return this->tetrominoe.get_block_X(i);
}

int CTetris::get_y(int i)
{
	return this->tetrominoe.get_block_Y(i);
}

int CTetris::get_speed()
{
	return this->speed;
}

bool CTetris::isOut()
{
	for (int i = 0; i < MAX_EL_T; i++)
	{
		if (this->tetrominoe.get_block_Y(i) + 1 >= ROW)	//controllo se esco dall matrice al successivo spostamento
			return true;
	}

	return false;
}

bool CTetris::isLaid()
{
	for (int i = 0; i < MAX_EL_T; i++)
	{
		CColor block = this->matrix[this->tetrominoe.get_block_Y(i) + 1][this->tetrominoe.get_block_X(i)];

		if ((block.get_Red() == MINRGB && block.get_Green() == MINRGB && block.get_Blue() == MINRGB) ||
			(block.get_Red() == MAXRGB && block.get_Green() == MAXRGB && block.get_Blue() == MAXRGB))
			continue;
		else
			return true;
	}
	return false;
}