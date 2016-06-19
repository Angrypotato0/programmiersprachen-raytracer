#ifndef SPHERE_HPP
#define SPHERE_HPP
#include "shape.hpp"
#include <glm/vec3.hpp>



class Sphere : public Shape 
 {
 public:
 	Sphere();
 	Sphere(glm::vec3 const& center, float rad );
 	Sphere(std::string const& name, Color const& color, glm::vec3 const& center ,float rad);

 	float area() const  ;
 	float volume() const  ;
 	glm::vec3 const& get_center() const;
 	float get_rad() const;
 	void set_rad (float const& rad);
 	void set_center (glm::vec3 const& center);
 	std::ostream& print(std::ostream& os) const override;
 private:
 	glm::vec3 center_;
 	double rad_;
};
 #endif   