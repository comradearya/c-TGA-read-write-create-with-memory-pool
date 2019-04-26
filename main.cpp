#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <cstring>


#include "func.hpp"
using namespace std;

int main(int argc, char* argv[]){
    pool *Mpool;
    Mpool=new pool;
    int block=sizeof(image::HEADER)+256*256*(sizeof(image::chanels))+sizeof(mem_block_info);//size of block
    int mem_block=sizeof(image::HEADER)+256*256*3*sizeof(image::chanels::b);
    Mpool->size=10*block; //for 10 images
    Mpool->begin=new char[Mpool->size];// адрес начала
    Mpool->end=Mpool->begin+Mpool->size; //адрес конца
    for (int i=0; i<Mpool->size; i++){
        Mpool->begin[i]=0;
    }
    cout<<"size:"<<Mpool->size<<endl;
    cout<<"begin:"<<reinterpret_cast<image*>(Mpool->begin)<<endl;
    cout<<"end:"<<reinterpret_cast<image*>(Mpool->end)<<endl;
    if(Mpool!=nullptr){
    image* img1 = nullptr;
    image* img2 = nullptr;
    image* img3 = nullptr;
    image* img4 = nullptr;
    img1 = pool_new(Mpool, mem_block);
    cout<<"image 1 has an adress: "<<img1<<endl;
    img2 = pool_new(Mpool, 10*mem_block);
    cout<<"image 2 has an adress: "<<img2<<endl;
    img3 = pool_new(Mpool, 2*mem_block);
    cout<<"image 3 has an adress:"<<(img3)<<endl;
 //cout<<"image 3 has an adress:"<<reinterpret_cast<void*>(img3)<<endl;
    pool_delete(img1, Mpool);
    img4= pool_new(Mpool,20*mem_block);
    cout<<"image 4 has an adress: "<<img4<<endl;
    delete[] Mpool->begin;
    delete Mpool;
    }
    else {
        cout<<Mpool<<endl;
    }

    image::HEADER img;
    img.idlength=0;
    img.colourmapdepth=0;
    img.datatypecode=2;
    img.colourmaporigin=0;
    img.colourmaplength=0;
    img.colourmapdepth=24;
    img.x_origin=0;
    img.y_origin=0;
    img.width=256;
    img.height=256;
    img.bitsperpixel=32;
    img.imagedescriptor=0;
    
    image::chanels *mat;
         mat=new image::chanels[256*256*3];
   if (mat==nullptr){
           cout<<"ERR: No space for matrix."<<endl;
    }

    
    if (argc<2){
        cout<<"PLease enter an argument."<<endl;}
for (int i=1;i<argc;i++){

    const char *cwhite="create_white";
if (!strcmp(argv[i],cwhite)){

        mat->r=0;
        mat->g=0;
        mat->b=255;
        mat->a=255;
  
    char white[]="white.tga";

    create_tga(white,img, mat);
}
else if(strcmp(argv[i],"create_black")==0){

        mat->r=0;
        mat->g=0;
        mat->b=0;
        mat->a=255;
  
    char black[]="black.tga";
    create_tga(black,img, mat);

}
else if(!(strcmp(argv[i],"create_color")))
{

        mat->r=0;
        mat->g=0;   
        mat->b=0;
        mat->a=255;

    char gradient []="gradient.tga";
  create_gradient(gradient, img, mat);
  ReadFile(gradient, img, mat);
}

else {
    cout<<"Wrong command! Try again."<<endl;
}
    
    return 0;
}
delete []mat;


}
