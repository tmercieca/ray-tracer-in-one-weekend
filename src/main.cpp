#include <camera.h>
#include <dielectric.h>
#include <hittable_list.h>
#include <ray_helpers.h>
#include <sphere.h>
#include <lambertian.h>
#include <metal.h>

#include <memory>

using std::make_shared;

int main() {
  // World
  hittable_list world;
  world.add(make_shared<sphere>(point3(0, -100.5, -1), 100,
                                make_shared<lambertian>(color(0.8, 0.8, 0.0))));
  world.add(make_shared<sphere>(point3(0, 0, -1), 0.5,
                                make_shared<lambertian>(color(0.7, 0.3, 0.3))));
  world.add(make_shared<sphere>(point3(-1.0, 0.0, -1.0), 0.5,
                                make_shared<metal>(color(0.8, 0.8, 0.8), 0.3)));
  world.add(make_shared<sphere>(point3(1.0, 0.0, -1.0), 0.5,
                                make_shared<metal>(color(0.8, 0.6, 0.2), 1.0)));

  // Camera
  camera camera;

  // Image
  const auto aspect_ratio = 16.0 / 9.0;
  const int image_Width = 256;
  const int image_height = static_cast<int>(image_Width / aspect_ratio);
  const int samples_per_pixel = 100;
  const int max_depth = 50;

  // Render
  std::cout << "P3\n" << image_Width << ' ' << image_height << "\n255\n";

  for (int j = image_height - 1; j >= 0; --j) {
    std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;

    for (int i = 0; i < image_Width; ++i) {
      color pixel_color_cumulative(0, 0, 0);

      for (int s = 0; s < samples_per_pixel; ++s) {
        auto u = (i + random_unit()) / (image_Width - 1);
        auto v = (j + random_unit()) / (image_height - 1);
        auto r = camera.get_ray(u, v);
        pixel_color_cumulative += ray_color(r, world, max_depth);
      }

      write_color(std::cout, gamma_correct(pixel_color_cumulative * 1.0 /
                                           samples_per_pixel));
    }
  }

  std::cerr << "\nDone.\n";
}
