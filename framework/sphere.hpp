#ifndef SPHERE_HPP
#define SPHERE_HPP
#include "shape.hpp"
#include <glm/vec3.hpp>



class Sphere : class Shape 
 {
 public:
 	Sphere();
 	~Sphere(glm::vec3 const& center, double rad );

 	float area() const override ;
 	float volume() const override ;
 	glm::vec3 get_center() const;
 	double get_rad() const;
 	void set_rad (double rad);
 	void set_center (glm::vec3 const& center);
 private:
 	glm::vec3 center_;
 	double rad_;


 
 	
 }; 