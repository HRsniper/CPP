#include <iostream>
#include <fstream>

using namespace std;

const int width = 255, height = 255;

int main()
{

    ofstream img("foto.ppm");
    img << "P3" << endl;
    img << width << " " << height << endl;
    img << 255 << endl;

    for (size_t i = 0; i < width; i++)
    {
        for (size_t x = 0; x < height; x++)
        {
            int r = x % 255;
            int g = i % 255;
            int b = i * x % 255;

            img << r << " " << g << " " << b << endl;
        }
    }
    return 0;
}
// usar um conversor de .ppm para .png . jpg ou outro
