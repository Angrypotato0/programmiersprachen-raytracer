#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "color.hpp"
#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include <cmath>
#include <string>
class Shape
{
public:
	virtual float area() const = 0;
	virtual float volume() const = 0;
private:

};
#endif