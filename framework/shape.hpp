#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "color.hpp"
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
	Shape(std::string const& name, Color const& color) ;
	virtual ~Shape();
	virtual float area() const = 0;
	virtual float volume() const = 0;
	virtual std::ostream& print(std::ostream& os) const;
	std::string get_name() const;
	Color const& get_color() const;

protected:
std::string name_;
Color color_;
};


std::ostream& operator << (std::ostream& os, Shape const& s);

#endif