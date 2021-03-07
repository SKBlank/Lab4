#include <iostream>
#include <sstream>
using namespace std;

#include "PPM.h"
#include "Rnumgen.h"

const char ETX = 0x3;

struct pixel 
{
  write this
}

void set_pixel_list(...) 
{
  write this
}

void encode(...) 
{
  write this
}

void decode(...) 
{
  write this
}

int main(int argc, char *argv[]) 
{
  //parse command line arguments
  // if something not right,
  //  print error message and exit
	string usageOption;
	stringstream zz;
	zz << argv[1];
	zz >> usageOption;

	string fname;
	stringstream ss;
	ss << argv[2];
	ss >> fname;


	if (argc < 2)
	{
		cout << "Usage: -encode|decode image.ppm\n";
		return 0;
	}





  PPM img;
  img.read(fname);

  declare pixel_list

  set_pixel_list(pixel_list);


  /*if (mode = ENCODE) {
    encode(fname, img);
	img.write(fname)
  }
  else
  if (mode = DECODE) 
    decode(fname, img);
	*/

  if (usageOption == "-encode")
  {
	  encode(fname, img);
	  img.write(fname);
  }
  else if (usageOption == "-decode")
  {
	  decode(fname, img);
  }
  else
  {
	  cout << "Usage: -encode|decode image.ppm\n";
	  return 0;
  }

}
