#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"

#include <iostream>

inline void write_color(std::ostream &out, color pixel_color) {
  // Write the translated [0,255] value of each color component.
  out << static_cast<int>(255.999 * pixel_color.x()) << ' '
      << static_cast<int>(255.999 * pixel_color.y()) << ' '
      << static_cast<int>(255.999 * pixel_color.z()) << '\n';
}

inline color gamma_correct(color pixel_color) {
  // gamma correct for gamma=2.0
  return color(sqrt(pixel_color[0]), sqrt(pixel_color[1]), sqrt(pixel_color[2]));
}

#endif
