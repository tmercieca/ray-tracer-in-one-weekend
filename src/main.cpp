#include <hittable_list.h>
#include <ray_helpers.h>
#include <sphere.h>

#include <memory>

using std::make_shared;

int main() {
  // World
  hittable_list world;
  world.add(make_shared<sphere>(point3(0, 0, -1), 0.5));
  world.add(make_shared<sphere>(point3(0, -100.5, -1), 100));

  // Image
  const auto aspect_ratio = 16.0 / 9.0;
  const int image_Width = 256;
  const int image_height = static_cast<int>(image_Width / aspect_ratio);
  const int samples_per_pixel = 100;

  // Camera
  auto viewport_height = 2.0;
  auto viewport_width = aspect_ratio * viewport_height;
  auto focal_length = 1.0;

  auto origin = point3(0, 0, 0);
  auto horizontal = vec3(viewport_width, 0, 0);
  auto vertical = vec3(0, viewport_height, 0);
  auto lower_left_corner =
      origin - horizontal / 2 - vertical / 2 - vec3(0, 0, focal_length);
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
        ray r(origin, lower_left_corner + u * horizontal + v * vertical - origin);
        pixel_color_cumulative += ray_color(r, world, max_depth);
      }

      write_color(std::cout, gamma_correct(pixel_color_cumulative * 1.0 / samples_per_pixel));
    }
  }

  std::cerr << "\nDone.\n";
}
