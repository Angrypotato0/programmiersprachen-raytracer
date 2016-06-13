#include "box.hpp"
#include <cmath>

Box::Box() : max{0.0f,0.0f,0.0f}, min{}{0.0f,0.0f,0.0f} {}
Box::Box() : max{max_}, min{min_}{}

	float area() const override ;
 	float volume() const override ;

 	glm::vec3 get_max() const{
 		return max;
 	}
 	glm::vec3 get_min() const{
 		return min;
 	}

 	void set_max(glm::vec3 const& max){
 		max_ = max;
 	}
 	void set_min(glm::vec3 const& min){
 		min_ = min;
 	}