#pragma once
using namespace std;

#define MINRGB 0
#define MAXRGB 255

class CColor
{
private:
	int r;
	int g;
	int b;

public:
	//Costruttori
	CColor();
	CColor(int r, int g, int b);

	//Getter
	int get_Red();
	int get_Green();
	int get_Blue();

	//Setter
	void set_Red(int r);
	void set_Green(int g);
	void set_Blue(int b);
};