#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "shape.hpp"
#include "sphere.hpp"
#include "box.hpp"


 
TEST_CASE("Sphere: get_get_center", "[aufgabe5.2]") {
  Sphere s1 {}; 
  REQUIRE(0.0f == s1.get_center().x);
  REQUIRE(0.0f == s1.get_center().y);
  REQUIRE(0.0f == s1.get_center().z);

  Sphere s2 {{0.4f, 2.3f, 1.2f}, 4.3f};
  REQUIRE(0.4f == s2.get_center().x);
  REQUIRE(2.3f == s2.get_center().y);
  REQUIRE(1.2f == s2.get_center().z);

}

TEST_CASE("Sphere: get_get_rad)", "[aufgabe5.2]") {
  Sphere s1 {}; 
  REQUIRE(0.0f == s1.get_rad());

  Sphere s2 {{0.4f, 2.3f, 1.2f}, -4.3f};
  REQUIRE(-4.3f == s2.get_rad());


}
TEST_CASE("Sphere: set_get_rad)", "[aufgabe5.2]") {
  Sphere s1 {};
  s1.set_rad({0.4f});  
  REQUIRE(0.4f == s1.get_rad());

  Sphere s2 {{0.4f, 2.3f, 1.2f}, -4.3f};
  s2.set_rad({0.7f});
  REQUIRE(0.7f == s2.get_rad());


}
TEST_CASE("Sphere: get area","[aufgabe5.2]"){
  Sphere s1{};
  REQUIRE(0.0f==s1.area());

  Sphere s2 {{0.4f, 2.3f, 1.2f}, 4.3f};
  REQUIRE(Approx(232.3522f) == s2.area());

  Sphere s3 {{6.9f, 4.2f, -1.2f}, -6.9f};
  REQUIRE(Approx(598.2849f) == s3.area());

  Sphere s4 {{6.9f, 4.2f, -1.2f}, 1.25f};
  REQUIRE(Approx(19.635f) == s4.area());
}
TEST_CASE("Sphere: get volume","[aufgabe5.2]"){
  Sphere s1 {};
  REQUIRE(0.0f == s1.volume());

  Sphere s2 {{0.4f, 2.3f, 1.2f}, 4.3f};
  REQUIRE(Approx(333.0381f) == s2.volume());

  Sphere s3 {{6.9f, 4.2f, -1.2f}, -6.9f};
  REQUIRE(Approx(1376.0553f) == s3.volume());

  Sphere s4 {{6.9f, 4.2f, -1.2f}, 1.25f};
  REQUIRE(Approx(8.18123f) == s4.volume());
}

TEST_CASE("Sphere: set_get_center", "[aufgabe5.2]") {
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
TEST_CASE("Box: get area","[aufgabe5.2]"){
  Box b1{};
  REQUIRE(0.0f == b1.area());
  Box b2 {{1.0f, 2.3f, 4.1f}, {0.0f, 2.5f, 1.2f}};
  REQUIRE(Approx(4.24f) == b2.area());

  Box b3 {{-1.0f, -4.3f, 5.6f}, {-9.0f, 1.5f, -2.2f}};
  REQUIRE(Approx(58.48f) == b3.area());

  Box b4 {{-2.8f, 1.1f, -1.9f}, {-3.3f, 6.9f, -4.2f}};
  REQUIRE(Approx(30.18f) == b4.area());
}
TEST_CASE("Box: get volume","[aufgabe5.2"){
  Box b1 {};
  REQUIRE(0.0f == b1.volume());

  Box b2 {{1.0f, 2.3f, 4.1f}, {0.0f, 2.5f, 1.2f}};
  REQUIRE(Approx(0.58f) == b2.volume());

  Box b3 {{-1.0f, -4.3f, 5.6f}, {-9.0f, 1.5f, -2.2f}};
  REQUIRE(Approx(361.92f) == b3.volume());

  Box b4 {{-2.8f, 1.1f, -1.9f}, {-3.3f, 6.9f, -4.2f}};
  REQUIRE(Approx(6.67f) == b4.volume()); 
}
TEST_CASE("Sphere: construktor","[aufgabe5.3]"){
Sphere s1 {};
  REQUIRE(0.0f == s1.get_center().x);
  REQUIRE(0.0f == s1.get_center().y);
  REQUIRE(0.0f == s1.get_center().z);

  REQUIRE(0.0f == s1.get_rad());

  REQUIRE("Sphere" == s1.get_name());

  REQUIRE(0.0f == s1.get_color().r);
  REQUIRE(0.0f == s1.get_color().g);
  REQUIRE(0.0f == s1.get_color().b);
  
  Sphere s2 {{1.6f, 3.5f, 2.2f}, 46.3f};
  REQUIRE(1.6f == s2.get_center().x);
  REQUIRE(3.5f == s2.get_center().y);
  REQUIRE(2.2f == s2.get_center().z);

  REQUIRE(46.3f == s2.get_rad());

  REQUIRE("Sphere" == s2.get_name());

  REQUIRE(0.0f == s2.get_color().r);
  REQUIRE(0.0f == s2.get_color().g);
  REQUIRE(0.0f == s2.get_color().b);

  Sphere s3 {"Sphere 3", {4.9f, 3.2f, 1.2f}, {5.1f, 5.1f, 5.1f}, -6.9f};
  REQUIRE(5.1f == s3.get_center().x);
  REQUIRE(5.1f == s3.get_center().y);
  REQUIRE(5.1f == s3.get_center().z);

  REQUIRE(-6.9f == s3.get_rad());

  REQUIRE("Sphere 3" == s3.get_name());

  REQUIRE(4.9f == s3.get_color().r);
  REQUIRE(3.2f == s3.get_color().g);
  REQUIRE(1.2f == s3.get_color().b);


}
TEST_CASE("Box: construktor","[aufgabe5.3]"){
 Box b1 {};
  REQUIRE(0.0f == b1.get_min().x);
  REQUIRE(0.0f == b1.get_min().y);
  REQUIRE(0.0f == b1.get_min().z);

  REQUIRE(0.0f == b1.get_max().x);
  REQUIRE(0.0f == b1.get_max().y);
  REQUIRE(0.0f == b1.get_max().z);

  REQUIRE("box" == b1.get_name());

  REQUIRE(0.0f == b1.get_color().r);
  REQUIRE(0.0f == b1.get_color().g);
  REQUIRE(0.0f == b1.get_color().b);


  Box b2 {{1.0f, 2.3f, 4.1f}, {0.0f, 2.5f, 1.2f}};
  REQUIRE(1.0f == b2.get_min().x);
  REQUIRE(2.3f == b2.get_min().y);
  REQUIRE(4.1f == b2.get_min().z);

  REQUIRE(0.0f == b2.get_max().x);
  REQUIRE(2.5f == b2.get_max().y);
  REQUIRE(1.2f == b2.get_max().z);

  REQUIRE("box" == b2.get_name());

  REQUIRE(0.0f == b2.get_color().r);
  REQUIRE(0.0f == b2.get_color().g);
  REQUIRE(0.0f == b2.get_color().b);


  Box b3 {"box 3", {1.0f, 0.3f, 0.5f}, {-1.0f, -4.3f, 5.6f}, {-9.0f, 1.5f, -2.2f}};
  REQUIRE(-1.0f == b3.get_min().x);
  REQUIRE(-4.3f == b3.get_min().y);
  REQUIRE(5.6f == b3.get_min().z);

  REQUIRE(-9.0f == b3.get_max().x);
  REQUIRE(1.5f == b3.get_max().y);
  REQUIRE(-2.2f == b3.get_max().z);

  REQUIRE("box 3" == b3.get_name());

  REQUIRE(1.0f == b3.get_color().r);
  REQUIRE(0.3f == b3.get_color().g);
  REQUIRE(0.5f == b3.get_color().b);
}

TEST_CASE("Box + Sphere: print","[aufgabe5.5]"){
  Sphere s1 {{0.4f, 2.3f, 1.2f}, 4.3f};
  std::cout << s1 << std::endl;

  Sphere s2 {"Sphere 2", {0.9f, 0.35f, 0.2f}, {6.9f, 4.2f, -1.2f}, -6.9f};
  std::cout << s2 << std::endl;

  Box b1 {{1.2f, 4.3f, 66.6f}, {3.2f, 5.5f, 8.8f}};
  std::cout << b1 <<  std::endl;

  Box b2 {"box 2", {1.0f, 0.3f, 0.5f}, {-1.0f, -4.3f, 5.6f}, {-9.0f, 1.5f, -2.2f}};
  std::cout << b2 <<  std::endl;

}




int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
