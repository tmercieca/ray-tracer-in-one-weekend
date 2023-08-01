#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"
#include <cassert>

class sphere : public hittable {
public:
  sphere() {}
  sphere(point3 c, double r) : center(c), radius(r){};

  virtual bool hit(const ray &r, double t_min, double t_max,
                   hit_record &rec) const override;

public:
  point3 center;
  double radius;
};

inline bool sphere::hit(const ray &r, double t_min, double t_max,
                        hit_record &record) const {
  vec3 oc = r.origin() - center;
  auto a = r.direction().length_squared();
  auto half_b = dot(oc, r.direction());
  auto c = oc.length_squared() - radius * radius;

  auto discriminant = half_b * half_b - a * c;
  if (discriminant < 0)
    return false;
  auto sqrtd = sqrt(discriminant);

  // Find the nearest root that lies in the acceptable range.
  auto root = (-half_b - sqrtd) / a;
  if (root < t_min || t_max < root) {
    root = (-half_b + sqrtd) / a;
    if (root < t_min || t_max < root)
      return false;
  }

  record.t = root;
  record.p = r.at(record.t);
  record.normal = (record.p - center) / radius;

  return true;
}

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
  auto half_b = dot(oc, r.direction());
  auto c = dot(oc, oc) - radius * radius;
  auto discriminant = half_b * half_b - a * c;

  if (discriminant < 0) {
    return -1.0;
  } else {
    // choosing closest
    return (-half_b - sqrt(discriminant)) / a;
  }
}

#endif