#import "func.hpp"

image::chanels* gradient(image::chanels *mat, int i)
{
    int j;
    j = i - (i % 256 - 256);
    mat->r = i + j;
    mat->g = i + j;
    mat->b = i + j;
    mat->a = 255;
    return (mat);
}


image::chanels* irandom(image::chanels *mat, int i)
{
    int j = rand() % 256;
    mat->r = i + j;
    mat->g = i + j;
    mat->b = i + j;
    
   return (mat);
}

image::chanels *dobutok(image::chanels *mat, int i, int j)
{
    mat->r = i * j;
    mat->g = i * j;
    mat->b = i *j;
    return (mat);
}

image::chanels *summa (image::chanels *mat, int i, int j){
    mat->r = i + j;
    mat->g = i + j;
    mat->b = i + j;
    return (mat);
}

image::chanels *subtract (image::chanels *mat, int i, int j){
    mat->r = i - j;
    mat->g = i - j;
    mat->b = i - j;
    return (mat);
}

image::chanels *sqrtdob (image::chanels *mat, int i, int j){
    mat->r = sqrt(i*j);
    mat->g = sqrt(i*j);
    mat->b = sqrt(i*j);
    return (mat);
}

image::chanels *var6 (image::chanels *mat, int i, int j){//not actualy siry
    mat->r=2*(128-i)*(128-j)/(256*sqrt(2));
    mat->g=2*(128-i)*(128-j)/(256*sqrt(2));
    mat->b=2*(128-i)*(128-j)/(256*sqrt(2));
    return (mat);
}

image::chanels *var7(image::chanels *mat, int i, int j){
    mat->r=2*abs((128-i)*(128-j))/(256*256);
    mat->g=2*abs((128-i)*(128-j))/(256*256);
    mat->b=2*abs((128-i)*(128-j))/(256*256);
    return (mat);
}

image::chanels *varsin(image::chanels *mat, int i, int j){
    mat->r=abs(sin(j+i))*255;
    mat->g=abs(sin(j+i))*255;
    mat->b=abs(sin(j+i))*255;
    return (mat);
}

image::chanels *varcos(image::chanels *mat, int i, int j){
    mat->r=abs(cos(j+i))*255;
    mat->g=abs(cos(j+i))*255;
    mat->b=abs(cos(j+i))*255;
    return (mat);
}
