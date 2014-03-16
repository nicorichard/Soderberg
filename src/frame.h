#pragma once

#include "png.h"
#include <stdlib.h>
#include <stdint.h>
#include <iostream>
#include <fstream>

#define PNGSIGSIZE 8

class Frame
{
public:
    Frame() {}
    ~Frame();

    bool open(const char *fname);
    bool save(const char *filename, char *title);                           // Save image to file
    bool flip();

private:
    static void userReadData(png_structp pngPtr, png_bytep data, png_size_t length);
    static bool validate(std::istream &src);

    png_uint_32 width;
    png_uint_32 height;
    png_uint_32 bitdepth;
    png_uint_32 channels;
    png_uint_32 colourtype;

    png_structp pngPtr;
    png_bytep *rowPtrs;
    png_infop infoPtr;
    char *data;
}; 