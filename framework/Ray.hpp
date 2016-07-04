#ifndef RAY_HPP
#define RAY_HPP
#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include <glm/gtx/intersect.hpp>
struct Ray
{
	Ray(): origin_{0.0f,0.0f,0.0f}, direction_{0.0f, 0.0f, 0.0f}{}
	Ray(glm::vec3 const& origin, glm::vec3 const& direction):origin_{origin}, direction_{glm::normalize(direction)}{}


	glm::vec3 origin() const{
		return origin_;
	}
	glm::vec3 direction() const{
		return direction_;
	}


  	glm::vec3 origin_;
  	glm::vec3 direction_;

};

#endif