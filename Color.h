#ifndef COLOR_H
#define COLOR_H
struct Color
{
	Color();
	Color(int _r, int _g, int _b) {r = _r; g = _g; b = _b;}
	int r;
	int g;
	int b;
};
#endif