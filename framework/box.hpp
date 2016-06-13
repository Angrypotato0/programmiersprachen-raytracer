#ifndef BOX_HPP
#define BOX_HPP
#include "shape.hpp"
#include <glm/vec3.hpp>

class Box : class Shape
{
public:
	Box();
	~Box(glm::vec3 const& max, glm::vec3 const& min);

	float area() const override ;
 	float volume() const override ;
	glm::vec3 get_max() const;
	glm::vec3 get_min() const;
	void set_max(glm::vec3 const& max);
	void set_min(glm::vec3 const& min);
private:
	glm::vec3 const& max_;
	glm::vec3 const& min_;

};

#endif
