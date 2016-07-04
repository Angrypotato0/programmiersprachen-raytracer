#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "Ray.hpp"
#include "matter.hpp"
#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include <glm/gtx/intersect.hpp>
#include <cmath>
#include <string>
#include <iostream>
class Shape
{
public:
	Shape() ;
	Shape(std::string const& name, Material const& mat) ;
	virtual ~Shape() ;
	virtual float area() const = 0;
	virtual float volume() const = 0;
	virtual std::ostream& print(std::ostream& os) const;
	virtual bool intersect(Ray const& ray, float& t) = 0;
	std::string get_name() const;
	Material const& get_matter() const;


protected:
std::string name_;
Material mat_;
};


std::ostream& operator << (std::ostream& os, Shape const& s);

#endif