#include <iostream>

#include "Finestra.h"
#include "Utility.h"
#include "CTetris.h"
using namespace std;

#define DIM 50  //dimensione di un blocco

void drawRect(HDC hdc, RECT bounds, CColor colore, int x, int y);
void drawCornice(HDC hdc);

CTetris campo;

void Draw(HDC hdc, RECT bounds)
{
   if (campo.isGameOver())
   {
       drawCornice(hdc);

       campo.movement(key);
       key = -1;   //RICORDA: dopo aver fatto un movimento mettere key a -1, altrimenti viene salvato (e ripetuto!) il movimento precedente (come snake)

       for (int r = 0; r < ROW; r++)
       {
           for (int c = 0; c < COLUMN; c++)
           {
               drawRect(hdc, bounds, campo.get_color(c, r), DIM * c + DIM, DIM * r + DIM);
           }
       }

       for (int i = 0; i < MAX_EL_T; i++)
       {
           CColor color = campo.get_color(i);

           int x = campo.get_x(i);
           int y = campo.get_y(i);

           drawRect(hdc, bounds, color, DIM * x + DIM, DIM * y + DIM);
       }

       Sleep(campo.get_speed());
   }

  
}

void drawRect(HDC hdc, RECT bounds, CColor colore, int x, int y)
{
    for (int i = 0; i < DIM; i++)
    {
        for (int c = 0; c < DIM; c++)
        {
            SetPixel(hdc, x + c, y + i, RGB(colore.get_Red(), colore.get_Green(), colore.get_Blue()));
        }
    }
}

void drawCornice(HDC hdc)
{
    for (int x = DIM - 1; x < DIM * COLUMN + DIM; x++)
    {
        SetPixel(hdc, x, DIM - 1, RGB(0, 0, 0));

        SetPixel(hdc, x, DIM * ROW + DIM, RGB(0, 0, 0));
    }

    for (int y = DIM - 1; y < DIM * ROW + DIM; y++)
    {
        SetPixel(hdc, DIM - 1, y, RGB(0, 0, 0));

        SetPixel(hdc, DIM * COLUMN + DIM, y, RGB(0, 0, 0));
    }
}

int main()
{
    
    //nascondo la console
    ShowWindow(GetConsoleWindow(), SW_HIDE);
    
    CreateMyWindow(Draw);

	return 0;
}