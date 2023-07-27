#include <cassert>
#include <color.h>
#include <ray.h>
#include <vec3.h>

inline bool is_point_in_sphere(const point3 &point, const point3 &sphere_centre,
                               double radius) {
  double distance = std::sqrt(std::pow(point.x() - sphere_centre.x(), 2) +
                              std::pow(point.y() - sphere_centre.y(), 2) +
                              std::pow(point.z() - sphere_centre.z(), 2));
  return distance < radius;
}

inline double hit_sphere(const point3 &centre, double radius, const ray &r) {
  assert(!is_point_in_sphere(r.origin(), centre, radius) &&
         "Assuming point is in front, outside sphere");

  vec3 oc = r.origin() - centre;
  auto a = dot(r.direction(), r.direction());
  auto b = 2.0 * dot(oc, r.direction());
  auto c = dot(oc, oc) - radius * radius;
  auto discriminant = b * b - 4 * a * c;

  if (discriminant < 0) {
    return -1.0;
  } else {
    // choosing closest
    return (-b - sqrt(discriminant)) / (2.0 * a);
  }
}

inline color ray_color(const ray &r) {
  auto t = hit_sphere(point3(0, 0, -1), 0.5, r);
  if (t > 0.0) {
    vec3 N = unit_vector(r.at(t) - vec3(0, 0, -1));
    return 0.5 * color(N.x() + 1, N.y() + 1, N.z() + 1);
  }

  // background colour
  vec3 unit_direction = unit_vector(r.direction());
  t = 0.5 * (unit_direction.y() + 1.0);
  return (1.0 - t) * color(1.0, 1.0, 1.0) + t * color(0.5, 0.7, 1.0);
}
