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
TEST_CASE("Box: get_max", "[aufgabe5.2]") {
  Box b1 {}; 
  REQUIRE(0.0f == b1.get_max().x);
  REQUIRE(0.0f == b1.get_max().y);
  REQUIRE(0.0f == b1.get_max().z);

  Box b2 {{0.4f, 2.3f, 1.2f}, {0.5f, 3.4f, 1.2f}};
  REQUIRE(0.5f == b2.get_max().x);
  REQUIRE(3.4f == b2.get_max().y);
  REQUIRE(1.2f == b2.get_max().z);

}

TEST_CASE("Box: get_min", "[aufgabe5.2]") {
  Box b1 {}; 
  REQUIRE(0.0f == b1.get_min().x);
  REQUIRE(0.0f == b1.get_min().y);
  REQUIRE(0.0f == b1.get_min().z);

  Box b2 {{0.4f, 2.3f, 1.2f}, {0.5f, 3.4f, 1.2f}};
  REQUIRE(0.4f == b2.get_min().x);
  REQUIRE(2.3f == b2.get_min().y);
  REQUIRE(1.2f == b2.get_min().z);



}
TEST_CASE("Box: set_max)", "[aufgabe5.2]") {
  Box b1 {};
  b1.set_max({});  
  REQUIRE(0.0f == b1.get_max().x);
  REQUIRE(0.0f == b1.get_max().y);
  REQUIRE(0.0f == b1.get_max().z);

  Box b2 {{0.4f, 2.3f, 1.2f}, {0.5f, 3.4f, 1.2f}};
  b2.set_max({0.7f, 0.9f, 1.0f});
  REQUIRE(0.7f == b2.get_max().x);
  REQUIRE(0.9f == b2.get_max().y);
  REQUIRE(1.0f == b2.get_max().z);


}
TEST_CASE("Box: set_min", "[aufgabe5.2]") {
  Box b1 {}; 
  b1.set_min({});  
  REQUIRE(0.0f == b1.get_min().x);
  REQUIRE(0.0f == b1.get_min().y);
  REQUIRE(0.0f == b1.get_min().z);

  Box b2 {{0.4f, 2.3f, 1.2f}, {0.5f, 3.4f, 1.2f}};
  b2.set_min({0.7f, 0.9f, 1.0f});
  REQUIRE(0.7f == b2.get_min().x);
  REQUIRE(0.9f == b2.get_min().y);
  REQUIRE(1.0f == b2.get_min().z);

}
TEST_CASE("Shape: print","[aufgabe5.4]"){
  Sphere s1 {{0.4f, 2.3f, 1.2f}, 4.3f};
  std::cout << s1 << std::endl;

  Sphere s2 {"Sphere 2", {0.9f, 0.35f, 0.2f}, {6.9f, 4.2f, -1.2f}, -6.9f};
  std::cout << s2 << std::endl;

  Box b1 {};
  std::cout << b1 << std::endl;

  //auto b2 = std::make_shared<Box>(Box{"Box 2", {1.0f, 0.3f, 0.5f}, {-1.0f, -4.3f, 5.6f}, {-9.0f, 1.5f, -2.2f}});
  //b2 -> print(std::cout);

}



int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
