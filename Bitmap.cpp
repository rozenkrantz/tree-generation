#include <fstream>
#include <iostream>
#include "Bitmap.h"
#include "BitmapInfoHeader.h"
#include "BitmapFileHeader.h"

namespace dequinox
{
	Bitmap::Bitmap(int width, int height) :
        	m_width(width), m_height(height), 
		m_pPixels(new uint8_t[width * height * 3]{})
      	{
      	}

      	bool Bitmap::write(std::string filename)
      	{
        	BitmapFileHeader fileHeader;
            	BitmapInfoHeader infoHeader;

            	fileHeader.fileSize = sizeof(BitmapFileHeader) 
			+ sizeof(BitmapInfoHeader) + m_width * m_height * 3;
            	fileHeader.dataOffset = sizeof(BitmapFileHeader) 
			+ sizeof(BitmapInfoHeader);

		infoHeader.width = m_width;
		infoHeader.height = m_height;

		std::ofstream file(filename, std::ios::binary);

		if (!file)
			return false;

		file.write((char *)&fileHeader, sizeof(fileHeader));
		file.write((char *)&infoHeader, sizeof(infoHeader));
		file.write((char *)m_pPixels.get(),  m_width * m_height * 3);

		file.close();
		return true;
      	}

      	void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue)
      	{
        		uint8_t *pPixel = m_pPixels.get();

            	pPixel += y*3*m_width + x*3;

            	pPixel[0] = blue;
            	pPixel[1] = green;
            	pPixel[2] = red;
      	}


      	void Bitmap::setLine(int x1, int y1, int x2, int y2, uint8_t red, uint8_t green, uint8_t blue)
      	{
            	double x_speed = x2 - x1;
            	double y_speed = y2 - y1;
            	x_speed /= 5.0;
            	y_speed /= 5.0;
            	double x, y;

            	x = x1;
            	y = y1;

            	while (x != x2 || y != y2)
            	{
                	uint8_t *pPixel = m_pPixels.get();
                	pPixel += (int)y*3*m_width + (int)x*3;

        		pPixel[0] = blue;
                	pPixel[1] = green;
                	pPixel[2] = red;
                	double dist1 = (y2-y)*(y2-y) + (x2-x)*(x2-x);
                	x += x_speed;
                	y += y_speed;
                	double dist2 = (y2-y)*(y2-y) + (x2-x)*(x2-x);
                	if (dist1 < dist2) break;
            	}
      	}

      	Bitmap::~Bitmap()
      	{
      	}
}
