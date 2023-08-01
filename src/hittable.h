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
};

class hittable {
public:
  virtual bool hit(const ray &r, double t_min, double t_max,
                   hit_record &record) const = 0;
};

#endif
