#include "hittable.h"
#include <cassert>
#include <color.h>
#include <ray.h>

inline color ray_color(const ray &r, const hittable &world, int depth) {
  hit_record record;

  // stop ray bounce; stop gathering light. protects against stack overflow too
  if (depth <= 0) {
    return color(0, 0, 0);
  }

  // set t_min to avoid floating point, addressing shadow acne
  if (world.hit(r, 0.001, 99999999999, record)) {
    ray scattered;
    color attenuation;

    if (record.mat->scatter(r, record, attenuation, scattered)) {
      return attenuation * ray_color(scattered, world, depth - 1);
    }
    return color(0, 0, 0);

    vec3 unit_direction = unit_vector(r.direction());
    auto t = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - t) * color(1.0, 1.0, 1.0) + t * color(0.5, 0.7, 1.0);
  }

  // background colour
  vec3 unit_direction = unit_vector(r.direction());
  auto t = 0.5 * (unit_direction.y() + 1.0);
  return (1.0 - t) * color(1.0, 1.0, 1.0) + t * color(0.5, 0.7, 1.0);
}

