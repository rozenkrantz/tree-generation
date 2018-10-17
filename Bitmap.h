#ifndef BITMAP_H_
#define BITMAP_H_

#include <string>
#include <cstdint>
#include <memory>

namespace dequinox
{
    class Bitmap
    {
        private:
            int m_width{0};
            int m_height{0};
            int m_bitsPerPixel{32};
            std::unique_ptr<uint8_t[]> m_pPixels{nullptr};
        public:
            Bitmap(int width, int height);
            Bitmap(std::string filename);
            int getHeight();
            int getWidth();
            uint8_t *getPixel(int x, int y);
            void circle(int x, int y, int radius, uint8_t red, uint8_t green, uint8_t blue);
            void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
            void setLine(int x1, int y1, int x2, int y2, uint8_t red, uint8_t green, uint8_t blue);
            bool write(std::string filename);
            virtual ~Bitmap();
      };
}

#endif // BITMAP_H_
