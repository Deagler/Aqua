#pragma once

class Color  {
public:
	Color()
	{
		*(int*)this = 0;
	}
	Color(int r, int g, int b, int a = 255)
	{
		colors[0] = r;
		colors[1] = g;
		colors[2] = b;
		colors[3] = a;
	}

	inline int r() { return (this->colors[0]); }
	inline int g() { return (this->colors[1]); }
	inline int b() { return (this->colors[2]); }
	inline int a() { return (this->colors[3]); }


private:
	unsigned char colors[4];
};
