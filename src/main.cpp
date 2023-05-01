#include "color.h"
#include "vec3.h"

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
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;

        for (int i = 0; i< image_Width; ++i)
        {
            color pixel_color(double(i)/(image_Width-1), double(j)/(image_height-1), 0.25);
            write_color(std::cout, pixel_color);
        }
    }

    std::cerr << "\nDone.\n";
}
