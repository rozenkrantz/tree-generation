#ifndef BITMAPFILEHEADER_H
#define BITMAPFILEHEADER_H

#include <cstdint>
#pragma pack(push, 2)

namespace dequinox
{
      struct BitmapFileHeader
      {
            char header[2]{'B', 'M'};
            int32_t fileSize;
            int32_t reserved{0};
            int32_t dataOffset;
      };
}

#pragma pack(pop)
#endif // BITMAPFILEHEADER_H
