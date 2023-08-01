#include "hittable.h"

class lambertian : public material {
public:
  lambertian(const color &a) : albedo(a) {}

  virtual bool scatter(const ray &r_in, const hit_record &record,
                       color &attenuation, ray &scattered) const override {
    auto scatter_direction = record.normal + random(0.0, 1.0);

    // if random unit vector is exactly opposite normal,
    // the two will sum to zero
    if (scatter_direction.near_zero())
      scatter_direction = record.normal;

    scattered = ray(record.p, scatter_direction);
    attenuation = albedo;
    return true;
  }

public:
  color albedo;
};