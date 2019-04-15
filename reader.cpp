#include <iostream>
using namespace std;
#include <array>
#include "writeImage.hpp"
unsigned char *readBMP(char *filename)
{
    int i;
    FILE *f = fopen(filename, "rb");
    unsigned char info[54];
    fread(info, sizeof(unsigned char), 54, f); // read the 54-byte header

    // extract image height and width from header
    int width = *(int *)&info[18];
    int height = *(int *)&info[22];

    int size = 3 * width * height;
    unsigned char *data = new unsigned char[size]; // allocate 3 bytes per pixel
    fread(data, sizeof(unsigned char), size, f);   // read the rest of the data at once
    fclose(f);

    for (i = 0; i < size; i += 3)
    {
        unsigned char tmp = data[i];
        data[i] = data[i + 2];
        data[i + 2] = tmp;
        cout << "R:"<<(int) data[i] << "G:" << (int)data[i+1] << "B:" << (int)data[i+2] << endl;
    }
    
    return data;
}

int arraySize(int arr[])
{
    return sizeof(arr) / sizeof(arr[0]);
}
int main(void)
{
    cout << "Hello";
    unsigned char* imageData = readBMP("Shapes.bmp");
    
    cout << sizeof(imageData) / sizeof(imageData[0]);

}
