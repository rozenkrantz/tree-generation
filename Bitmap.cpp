#include <fstream>
#include <iostream>
#include "Bitmap.h"
#include "BitmapInfoHeader.h"
#include "BitmapFileHeader.h"

namespace dequinox
{
	    void log2()
    	{
        	std::cout << " ";
    	}

    	template<typename Head, typename... Tail>
    	void log2(Head H, Tail... T){
        	std::cout << H << " ";
        	log2(T...);
    	}
	
		Bitmap::Bitmap(int width, int height) :
            m_width(width), m_height(height), m_pPixels(new uint8_t[width * height * m_bitsPerPixel/8]{})
      	{
      	}
	
		Bitmap::Bitmap(std::string filename)
      	{
            BitmapFileHeader fileHeader;
            BitmapInfoHeader infoHeader;

            std::ifstream file(filename, std::ios::binary);

            file.read((char *)&fileHeader, sizeof(fileHeader));
            file.read((char *)&infoHeader, sizeof(infoHeader));

            m_width  = infoHeader.width;
            m_height = infoHeader.height;
            m_bitsPerPixel = infoHeader.bitsPerPixel;

            std::cout << fileHeader.header << std::endl;
            std::cout << infoHeader.headerSize << std::endl;
            std::cout << infoHeader.bitsPerPixel << std::endl;
            std::cout << infoHeader.dataSize << std::endl;
            std::cout << fileHeader.dataOffset << std::endl;

            file.seekg(fileHeader.dataOffset);

            m_pPixels = std::unique_ptr<uint8_t[]> (new uint8_t[infoHeader.width*infoHeader.height*infoHeader.bitsPerPixel/8]);

            file.read((char *)m_pPixels.get(), infoHeader.width * infoHeader.height * infoHeader.bitsPerPixel/8);

            file.close();
	    }

		bool Bitmap::write(std::string filename)
      	{
            BitmapFileHeader fileHeader;
            BitmapInfoHeader infoHeader;

            fileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + m_width * m_height * m_bitsPerPixel / 8;
            fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

            infoHeader.bitsPerPixel = m_bitsPerPixel;
            infoHeader.width = m_width;
            infoHeader.height = m_height;

            std::ofstream file(filename, std::ios::binary);

            if (!file)
            {
                  return false;
            }

            file.write((char *)&fileHeader, sizeof(fileHeader));
            file.write((char *)&infoHeader, sizeof(infoHeader));
            file.write((char *)m_pPixels.get(),  m_width * m_height * m_bitsPerPixel / 8);

            file.close();
            return true;
      	}
	
	
      	int Bitmap::getWidth()
      	{
            return m_width;
      	}

      	int Bitmap::getHeight()
      	{
            return m_height;
      	}
		
      	uint8_t *Bitmap::getPixel(int x, int y)
      	{
            uint8_t *pPixel = m_pPixels.get();

            pPixel += y*(m_bitsPerPixel/8)*m_width + x*(m_bitsPerPixel/8);

        	return pPixel;
      	}

      	void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue)
      	{
        		uint8_t *pPixel = m_pPixels.get();

	            pPixel += y*(m_bitsPerPixel/8)*m_width + x*(m_bitsPerPixel/8);

            	pPixel[0] = blue;
            	pPixel[1] = green;
            	pPixel[2] = red;
				pPixel[3] = 255;
      	}

		void Bitmap::circle(int x, int y, int radius, uint8_t red, uint8_t green, uint8_t blue)
      	{
        	for (int i = x - radius; i <= x + radius; i++)
          	{
                for (int j = y - radius; j <= y + radius; j++)
                {
                    if ((x-i)*(x-i) + (y-j)*(y-j) <= radius * 2)
                    {
                            setPixel(i, j, red, green, blue);
                    }
                }
          	}
      	}

      	void Bitmap::setLine(int x1, int y1, int x2, int y2, uint8_t red, uint8_t green, uint8_t blue)
      	{
            	double x_speed = x2 - x1;
            	double y_speed = y2 - y1;
            	double max_speed;
	        	if (abs(x_speed) > abs(y_speed))
                	max_speed = abs(x_speed);
            	else
                	max_speed = abs(y_speed);

            	x_speed /= max_speed;
            	y_speed /= max_speed;

            	double x = x1, y = y1;
            	
				while ((x != x2 || y != y2) && (x >= 0 && y >= 0 && x < m_width && y < m_height)){
                	setPixel(x, y, red, green, blue);
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
