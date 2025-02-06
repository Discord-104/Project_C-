#pragma once
#include "CTetrominoe.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#define COLUMN 10
#define ROW 15
#define N_SHAPES 7
#define INITIAL_SPEED 500	//Velocità iniziale di discesa (ovvero ogni quanto viene ridisegnata la pagina)

#define KEY_UP 38
#define KEY_DOWN 40
#define KEY_LEFT 37
#define KEY_RIGHT 39
#define KEY_SPACE 32

static CColor colors[N_SHAPES] = { CColor(0, 204, 255), CColor(0, 0, 204), CColor(255, 102, 0), CColor(255, 255, 0), CColor(51, 204, 51), CColor(255, 0, 0), CColor(153, 0, 204) };
static char shapes[N_SHAPES] = { 'J', 'L', 'S' , 'Z' , 'T' , 'O', 'I' };	//Vettore contenente le possibili forme che un tetrominoe può assumere

//Campo di gioco
class CTetris
{
private:
	CTetrominoe tetrominoe;
	CColor matrix[ROW][COLUMN];
	long int score;		//punteggio
	long int lines;		//righe completate
	int speed;			//velocità di discesa

	

public:
	//Costruttori
	CTetris();

	//Getter
	long int get_score();			  //TODO capire se servono getter di: x, y, color, matrix_at (TEST: non vengono usati dal main)
	long int get_lines();
	CColor get_color(int x, int y);
	CColor get_color(int i);
	int get_x(int i);
	int get_y(int i);
	int get_speed();

	//Setter
									  //TODO capire se servono setter di: x, t, color, matrix_at, score, lines (TEST: i valori non vengono modificati dall'utente ma dal programma stesso)

	void movement(int key);
	void CreateTetrominoe();
	bool isGameOver();
	bool isLineComplete(int r);
	bool isAlloud();
	void shift(int row);

	bool isOut();
	bool isLaid();
};


//Movimento
		//Input di un tasto (gestito in Finestra.h e passato dal main) 
			//Freccia dx || sx --> movimento a dx || sx
			//Space bar --> Tetrominoe portato in posizione finale
			//Freccia up --> rotazione
				//Controllo se la rotazione è valida  <------------|           
			//Freccia down --> aumenta la velocità di discesa      |
		//Spostamento verso il basso							   |
			//Controllo se il movimento è valido   <---------------|
				//Se non è valido:
					//Sposto il colore nella matrice
						//Controllo se una riga è stata completata 
							//Se si --> cancello la riga (shift) 
					// genero un nuovo tetrominoe    
						//Controllo che la posizione COLONNE / 2, 0 sia libera
							//Se no --> Game Over