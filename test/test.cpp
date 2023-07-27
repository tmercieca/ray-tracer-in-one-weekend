#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this
                          // in one cpp file

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
#include <ray_helpers.h>
#include <vec3.h>

double EPSILON = 0.0001f;

point3 origin_centre(0, 0, 0);

TEST_CASE("Ray intersects the sphere at two points", "[hit_sphere]") {
  double radius = 1.0;
  ray r(point3(0, 0, 2), vec3(0, 0, -1));

  REQUIRE_THAT(hit_sphere(origin_centre, radius, r), Catch::Matchers::WithinAbs(1.0f, EPSILON));
}

TEST_CASE("Ray intersects the sphere at one point (tangent)", "[hit_sphere]") {
  double radius = 1.0;
  ray r(point3(1, 0, 0), vec3(0, 1, 0));

  REQUIRE_THAT(hit_sphere(origin_centre, radius, r), Catch::Matchers::WithinAbs(0.0f, EPSILON));
}

TEST_CASE("Ray misses the sphere", "[hit_sphere]") {
  double radius = 1.0;
  ray r(point3(0, 2, 2), vec3(0, -1, 0));

  REQUIRE_THAT(hit_sphere(origin_centre, radius, r), Catch::Matchers::WithinAbs(-1.0f, EPSILON));
}
