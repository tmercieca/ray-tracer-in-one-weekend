#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include "hittable.h"

#include <memory>
#include <vector>

using std::shared_ptr;

class hittable_list : public hittable {
public:
  hittable_list() {}
  hittable_list(shared_ptr<hittable> object) { add(object); }

  void clear() { objects.clear(); }
  void add(shared_ptr<hittable> object) { objects.push_back(object); }

  virtual bool hit(const ray &r, double t_min, double t_max,
                   hit_record &record) const override;

public:
  std::vector<shared_ptr<hittable>> objects;
};

inline bool hittable_list::hit(const ray &r, double t_min, double t_max,
                               hit_record &record) const {
  hit_record temp_record;
  bool hit_anything = false;
  auto closest_so_far = t_max;

  for (const auto &object : objects) {
    if (object->hit(r, t_min, closest_so_far, temp_record)) {
      hit_anything = true;
      closest_so_far = temp_record.t;
      record = temp_record;
    }
  }

  return hit_anything;
}

#endif