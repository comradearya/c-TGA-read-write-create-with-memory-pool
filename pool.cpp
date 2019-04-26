#include "func.hpp"

using namespace std;
pool* MemPool(){
    pool *Mpool;
    Mpool=new pool;
    int block=sizeof(image::HEADER)+256*256*(sizeof(image::chanels))+sizeof(mem_block_info);//size of block
  //  int mem_block=sizeof(image::HEADER)+256*256*sizeof(image::chanels);
    Mpool->size=10*block; //for 10 images
    Mpool->begin=new char[Mpool->size];// адрес начала
    Mpool->end=Mpool->begin+Mpool->size; //адрес конца
    for (int i=0; i<Mpool->size; i++){
        Mpool->begin[i]=0;
    }
    cout<<"size:"<<Mpool->size<<endl;
    cout<<"begin:"<<reinterpret_cast<image*>(Mpool->begin)<<endl;
    cout<<"end:"<<reinterpret_cast<image*>(Mpool->end)<<endl;
    if (true){
        return Mpool;
        } 
    else{
        return nullptr;
    } 
}

image* pool_new(pool* Mpool, int size){
    char* ptr=Mpool->begin;
  
    while((ptr+sizeof(mem_block_info)+size)<Mpool->end)//существует место
    {
        if(reinterpret_cast<mem_block_info*>(ptr)->allocated==1) //в случае если выделена
        {
            int curr_block_size=reinterpret_cast<mem_block_info*>(ptr)->block_size;
            ptr=ptr+sizeof(mem_block_info)+curr_block_size;//продвинуться дальше в пуле
        }
        if(reinterpret_cast<mem_block_info*>(ptr)->allocated==0){
            reinterpret_cast<mem_block_info*>(ptr)->allocated=1;
            reinterpret_cast<mem_block_info*>(ptr)->block_size=size;
            cout<<"Memory successfully allocated"<<endl;
            cout<<"Rest volume is:"<<reinterpret_cast<mem_block_info*>(ptr)->block_size<<endl;
            return (reinterpret_cast<image*>(ptr+sizeof(mem_block_info)));
        }
        else{
            cout<<"No memory allocated."<<endl;
            return (nullptr);
        }
    }
    cout<<"No memory allocated."<<endl;
            return (nullptr);
    //}
}

void pool_delete(image* img, pool* Mpool){
    
    if((reinterpret_cast<char*>(img) <= Mpool->end) && (reinterpret_cast<char*>(img) >= Mpool->begin))
    {
        char* ptr = reinterpret_cast<char*>(img);
        mem_block_info* mem = reinterpret_cast<mem_block_info*>(ptr - sizeof(mem_block_info));
        int mem_size = mem->block_size + sizeof(mem_block_info);
        mem->allocated = 0;
        mem->block_size = 0;
        ptr = reinterpret_cast<char*>(mem);
        for(int i = 0; i < mem_size; i++)
        {
            ptr[i] = 0;
        }
    }
    else
    {
        cout<<"the image is not in pool, can't delete it"<<endl;
    }
}