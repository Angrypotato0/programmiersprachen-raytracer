#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "shape.hpp"
#include "sphere.hpp"
#include "box.hpp"


 
TEST_CASE("Sphere: get_center", "[aufgabe5.2]") {
  Sphere s1 {}; 
  REQUIRE(0.0f == s1.get_center().x);
  REQUIRE(0.0f == s1.get_center().y);
  REQUIRE(0.0f == s1.get_center().z);

  Sphere s2 {{0.4f, 2.3f, 1.2f}, 4.3f};
  REQUIRE(0.4f == s2.get_center().x);
  REQUIRE(2.3f == s2.get_center().y);
  REQUIRE(1.2f == s2.get_center().z);

}

TEST_CASE("Sphere: get_radius)", "[aufgabe5.2]") {
  Sphere s1 {}; 
  REQUIRE(0.0f == s1.get_rad());

  Sphere s2 {{0.4f, 2.3f, 1.2f}, -4.3f};
  REQUIRE(-4.3f == s2.get_rad());


}
TEST_CASE("Sphere: set_radius)", "[aufgabe5.2]") {
  Sphere s1 {};
  s1.set_rad({0.4f});  
  REQUIRE(0.4f == s1.get_rad());

  Sphere s2 {{0.4f, 2.3f, 1.2f}, -4.3f};
  s2.set_rad({0.7f});
  REQUIRE(0.7f == s2.get_rad());


}
TEST_CASE("Sphere: set_center", "[aufgabe5.2]") {
  Sphere s1 {}; 
  s1.set_center({6.9f,6.9f,6.9f});
  REQUIRE(6.9f == s1.get_center().x);
  REQUIRE(6.9f == s1.get_center().y);
  REQUIRE(6.9f == s1.get_center().z);

  Sphere s2 {{0.4f, 2.3f, 1.2f}, 4.3f};
  s2.set_center({});
  REQUIRE(0.0f == s2.get_center().x);
  REQUIRE(0.0f == s2.get_center().y);
  REQUIRE(0.0f == s2.get_center().z);

}



int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
