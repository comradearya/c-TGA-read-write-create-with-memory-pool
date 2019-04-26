#ifndef FUNC_HPP
#define FUNC_HPP
#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cmath>

class image
{
public:
#pragma pack(push, 1)
    class HEADER
    {
    public:
        //HEADER();
        char idlength;
        char colourmaptype;
        char datatypecode;
        short int colourmaporigin;
        short int colourmaplength;
        char colourmapdepth;
        short int x_origin;
        short int y_origin;
        short width;
        short height;
        char bitsperpixel;
        char imagedescriptor;
    };

#pragma pack(pop)

    struct chanels {
        int8_t r;
        int8_t g;
        int8_t b;
        int8_t a;
    };
    union COL {
        int32_t color;
        chanels matrix;
    };
    COL *matrix;
};

struct pool
{
    int size;
    char *begin;
    char *end;
};

struct mem_block_info
{
    int allocated;
    int block_size;
};

pool* MemPool();
image* pool_new(pool* Mpool, int size);
void pool_delete(image* img, pool* Mpool);

void create_tga(char *, image::HEADER , image::chanels *);
void create_gradient(char*, image::HEADER, image::chanels *);
void ReadFile(char *, image::HEADER , image::chanels *);
void OpenGile(char *);

#endif