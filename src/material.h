#ifndef MATERIAL_H
#define MATERIAL_H

#include "ray.h"
#include "vec3.h"

struct hit_record;

class material {
public:
  virtual bool scatter(const ray &r_in, const hit_record &record,
                       color &attenuation, ray &scattered) const = 0;
};

#endif
