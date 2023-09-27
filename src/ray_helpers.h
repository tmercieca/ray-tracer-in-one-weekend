#include <color.h>
#include <ray.h>
#include <vec3.h>

#include <iostream>

inline double hit_sphere(const point3 &center, double radius, const ray &r) {
  vec3 oc = r.origin() - center;
  auto a = dot(r.direction(), r.direction());
  auto b = 2.0 * dot(oc, r.direction());
  auto c = dot(oc, oc) - radius * radius;
  auto discriminant = b * b - 4 * a * c;
  return discriminant > 0;
}

inline color ray_color(const ray &r) {
  if (hit_sphere(point3(0, 0, -1), 0.5, r))
    return color(1, 0, 0);
  vec3 unit_direction = unit_vector(r.direction());
  auto t = 0.5 * (unit_direction.y() + 1.0);
  return (1.0 - t) * color(1.0, 1.0, 1.0) + t * color(0.5, 0.7, 1.0);
}
