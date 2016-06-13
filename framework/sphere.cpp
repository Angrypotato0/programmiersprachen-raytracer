#include "sphere.hpp"
#include <cmath>


Sphere::Sphere() : center {0.0,0.0,0.0}, rad {0.0}{}
Sphere::Sphere(glm::vec3 const& center, double rad) :
 center{center_}, rad{rad_}{}


 float area () const override{
 	return 4.0f * M_PI * rad_ * rad_;
 }

 float volume() const override{
 	return (4.0f / 3.0f) * M_PI * rad_ * rad_ * rad_;
 }

 glm::vec3 Sphere::get_center() const{
 return center_;
 }

 double Sphere::get_rad() const{
 	return rad_;
 }

 void Sphere::set_center(glm::vec3 const& center) {
 	center = center_;
 }

 void Sphere::set_rad(double rad){
 	rad = rad_;
 }
 