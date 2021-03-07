#ifndef __PPM_H__
#define __PPM_H__

#include <iostream>
#include <fstream>
#include <string>

struct RGB 
{ 
  RGB() 
  { 
	  R = 0;
	  G = 0;
	  B = 0;
  }

  unsigned char R, G, B;
};

class PPM 
{ 
  public:
    PPM() 
	{
		width = 0;
		height = 0;
		maxValue = 255;
	}
    ~PPM() 
	{ 
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				//delete img[i][j];
			}
			delete img[i];
		}
	}

	void read(string &);
	void write(string &);

	RGB *operator[](int index) 
	{ 
		return img[index];
	}

	int get_Nrows() 
	{ 
		return width;
	}

	int get_Ncols() 
	{ 
		return height;
	}

  private:
	  unsigned int height;
	  unsigned int width;
	  unsigned int maxValue;
	  unsigned int size;

	RGB **img;
};



#endif
