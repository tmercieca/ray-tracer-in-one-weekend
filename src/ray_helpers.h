#include "hittable.h"
#include <cassert>
#include <color.h>
#include <ray.h>
#include <vec3.h>
#include <random>

inline color ray_color(const ray &r, const hittable &world) {
  hit_record record;
  if (world.hit(r, 0, 9999999, record)) {
    return 0.5 * (record.normal + color(1, 1, 1));
  }

  // background colour
  vec3 unit_direction = unit_vector(r.direction());
  auto t = 0.5 * (unit_direction.y() + 1.0);
  return (1.0 - t) * color(1.0, 1.0, 1.0) + t * color(0.5, 0.7, 1.0);
}

inline double random_unit() {
    static std::uniform_real_distribution<double> distribution(0.0, 1.0);
    static std::mt19937 generator;
    return distribution(generator);
}
