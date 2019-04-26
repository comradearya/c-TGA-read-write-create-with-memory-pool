using namespace std;
#include "func.hpp"


using namespace std;

void create_tga(char *filename, image::HEADER header, image::chanels *mat)
{
    fstream file;
    cout << "Start!" << endl;
    file.open(filename, ios::out | ios::binary);
    if (!file)
    {
        cout << "Error in opening " << endl;
    }
    cout << "File is ready for the work." << endl;
    file.write(reinterpret_cast<char *>(&header), sizeof(image::HEADER));
    for (int i = 0; i < header.height * header.width; i++)
    {
        file.write(reinterpret_cast<char *>(&mat->r), sizeof(char));
        file.write(reinterpret_cast<char *>(&mat->g), sizeof(char));
        file.write(reinterpret_cast<char *>(&mat->b), sizeof(char));
        file.write(reinterpret_cast<char *>(&mat->a), sizeof(char));
    }
    file.close();
}

void create_gradient(char *filename, image::HEADER header, image::chanels *mat)
{
    fstream file;
    cout << "Start!" << endl;
    file.open(filename, ios::out | ios::binary);
    if (!file)
    {
        cout << "Error in opening " << endl;
    }
    cout << "File is ready for the work." << endl;
    file.write(reinterpret_cast<char *>(&header), sizeof(image::HEADER));
    for (int i = 0; i < header.height * header.width; i++)
    {
        int j = 0;
        j = i - (i % header.width - header.height);
        mat->r = i + j;
        mat->g = i + j;
        mat->b = i + j;
        file.write(reinterpret_cast<char *>(&mat->r), sizeof(char));
        file.write(reinterpret_cast<char *>(&mat->g), sizeof(char));
        file.write(reinterpret_cast<char *>(&mat->b), sizeof(char));
        file.write(reinterpret_cast<char *>(&mat->a), sizeof(char));
    }

    file.close();
}

void ReadFile(char *filename, image::HEADER header, image::chanels *mat)
{
    fstream file;
    cout << "Start!" << endl;
    file.open(filename, ios::out | ios::binary);
    if (!file)
    {
        cout << "Error in opening " << endl;
    }
    else
    {
        cout << "Preparing for reading from file..." << endl;
    }
    file.read(reinterpret_cast<char *>(&header), sizeof(image::HEADER));

    cout << reinterpret_cast<int *>(&header.bitsperpixel) << endl;
    for (int i = 0; i < header.height * header.width; i++)
    {
        file.read(reinterpret_cast<char *>(&mat->r), sizeof(char));
        file.read(reinterpret_cast<char *>(&mat->g), sizeof(char));
        file.read(reinterpret_cast<char *>(&mat->b), sizeof(char));
    }
    cout << "Reading from file completed!" << endl;
}

void OpenGile(char *filename);