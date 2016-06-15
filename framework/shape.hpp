#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "color.hpp"
#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include <cmath>
#include <string>
#include <iostream>
class Shape
{
public:
	Shape() : 
	name_ {"shape"},
	color_ {0.0f, 0.0f, 0.0f} {}
	Shape(std::string const& name, Color const& color) :
		name_{name},
		color_{color} {}
	virtual float area() const = 0;
	virtual float volume() const = 0;
	std::string name() const;
	Color const& color() const;
private:
std::string name_;
Color color_;
};

#endif