#ifndef HITTABLE_H
#define HITTABLE_H

#include "material.h"
#include "ray.h"
#include <memory>

using std::shared_ptr;

struct hit_record {
  point3 p;
  double t;
  vec3 normal;
  shared_ptr<material> mat;
  bool front_face;

  void set_face_normal(const ray &r, const vec3 &outward_normal) {
    // set the hit record normal vector

    front_face = dot(r.direction(), outward_normal) < 0;
    normal = front_face ? outward_normal : -outward_normal;
  }
};

class hittable {
public:
  virtual bool hit(const ray &r, double t_min, double t_max,
                   hit_record &record) const = 0;
};

#endif
