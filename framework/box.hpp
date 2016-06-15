#ifndef BOX_HPP
#define BOX_HPP
#include "shape.hpp"
#include <glm/vec3.hpp>

class Box : public Shape
{
public:
	Box();
	Box(glm::vec3 const& max, glm::vec3 const& min);

	float area() const ;
 	float volume() const ;
	glm::vec3 const& get_max() const;
	glm::vec3 const& get_min() const;
	void set_max(glm::vec3 const& max);
	void set_min(glm::vec3 const& min);
private:
	glm::vec3 min_;
	glm::vec3 max_;	

};

#endif
