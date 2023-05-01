#include <iostream>

int main()
{
    // Image
    const int image_Width = 256;
    const int image_height = 256;

    // Render
    std::cout << "P3\n" << image_Width << ' ' << image_height << "\n255\n";

    for (int j = image_height - 1; j >= 0; --j)
    {
        for (int i = 0; i< image_Width; ++i)
        {
            auto r = double (i) / (image_Width-1);
            auto g = double(j) / (image_height-1);
            auto b = 0.25;

            int ir = 255.999 * r;
            int ig = 255.999 * g;
            int ib = 255.999 * b;

            std::cout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }
}
