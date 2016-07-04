#ifndef BOX_HPP
#define BOX_HPP
#include "shape.hpp"
#include <glm/vec3.hpp>
#include <algorithm>

class Box : public Shape
{
public:
	Box();
	Box(glm::vec3 const& min, glm::vec3 const& max);
	Box(std::string const& name, Color const& color, glm::vec3 const& min, glm::vec3 const& max);

	float area() const ;
 	float volume() const ;
	glm::vec3 const& get_max() const;
	glm::vec3 const& get_min() const;
	void set_max(glm::vec3 const& max);
	void set_min(glm::vec3 const& min);
	bool intersect(Ray const& ray, float& t)const override;
	std::ostream& print(std::ostream& os) const override;
	bool in_box(glm::vec3 const& point) const;
private:
	glm::vec3 min_;
	glm::vec3 max_;	

};
	bool in_box(glm::vec3 const& min, glm::vec3 const& max, glm::vec3 const& point);

#endif
