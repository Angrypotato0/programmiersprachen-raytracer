#include "sphere.hpp"
#include <cmath>


Sphere::Sphere() :Shape{"Sphere",{0.0f, 0.0f, 0.0f}}, center_ {0.0f,0.0f,0.0f}, rad_ {0.0}{}
Sphere::Sphere(glm::vec3 const& center, float rad) :
 Shape{"Sphere",{0.0f, 0.0f, 0.0f}}, center_{center}, rad_{rad}{}
Sphere::Sphere(std::string const& name, Color const& color, glm::vec3 const& center, float rad):
 Shape{name,color}, center_{center}, rad_{rad}{}


 float Sphere::area () const {
 	return 4.0f * M_PI * rad_ * rad_;
 }

 float Sphere::volume() const{
 	float res = (4.0f / 3.0f) * M_PI * rad_ * rad_ * rad_;
 	while(res<0){
			res = res*(-1);
		}
		return res;
 }

 glm::vec3 const& Sphere::get_center() const{
 return center_;
 }

 float Sphere::get_rad() const{
 	return rad_;
 }

 void Sphere::set_center(glm::vec3 const& center) {
 	center_ = center;
 }

 void Sphere::set_rad(float const& rad){
 	rad_ = rad;
 }
