#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
using namespace std;

#include "PPM.h"

void PPM::read(string &fileName) 
{
	int lineAmnt = 2;
	fstream fin;
	string line;

	fin.open(fileName, ios::out);

	//check if file is there
	if (fin.is_open() == 0)
	{
		cout << "error opening file\n";
		return;
	}

	getline(fin, line);

	//check if file type is PPM
	if (line != "P6")
	{
		cout << "incorrect format\n";
		return;
	}

	//record dimensions
	getline(fin, line);

	stringstream ss;

	ss << line;

	ss >> height >> width;

	//record max color value
	getline(fin, line);

	ss << line;

	ss >> maxValue;


	getline(fin, line);

	//skip comments
	while (line[0] == '#')
	{
		getline(fin, line);
		lineAmnt++;
	}

	//allocate image storage
	img = new RGB*[height];
	for (int i = 0; i < height; i++)
	{
		img[i] = new RGB[width];
	}

	fin.close();

	fin.open(fileName, ios::binary);

	for (int i = 0; i < lineAmnt; i++)
	{
		getline(fin, line);
	}
	

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			getline(fin, line);

			string r;
			string g;
			string b;

			stringstream zz;
			zz << line;
			zz << r << g << b;

			img[i][j].R = stoi(r);
			img[i][j].G = stoi(g);
			img[i][j].B = stoi(b);
		}
	}
}

void PPM::write(string &fileName) 
{ 
	string outName;
	outName = fileName;
	for (int i = 0; i < 3; i++)
	{
		outName.pop_back();
	}
	outName += "_wmsg.ppm";

	ofstream fout(outName.c_str(), ios::out | ios::binary);

	if (fout.is_open() == 0)
	{
		cout << "error opening file\n";
		return;
	}

	fout << "P6\n";
	fout << width << ' ' << height << "\n";
	fout << maxValue << "\n";

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			fout << img[i][j].R;
			fout << img[i][j].G;
			fout << img[i][j].B;
		}
	}
}
