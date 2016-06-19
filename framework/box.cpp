#include "box.hpp"
#include "shape.hpp"
#include <cmath>

Box::Box() : Shape{"box",{0.0f, 0.0f, 0.0f}}, min_ {0.0f,0.0f,0.0f}, max_ {0.0f,0.0f,0.0f} {}
Box::Box(glm::vec3 const& min, glm::vec3 const& max) :
Shape{"box",{0.0f, 0.0f, 0.0f}}, max_{max}, min_{min}{}
Box::Box(std::string const& name, Color const& color, glm::vec3 const& min, glm::vec3 const& max) :
Shape{name,color}, max_{max}, min_{min}{}

	float Box::area() const {
		glm::vec3 dif = max_-min_;
		float res = 2 * (dif.x * dif.y + dif.x * dif.z + dif.y * dif.z);
		while(res<0){
			res = res*(-1);
		}
		return res;

	} 
 	float Box::volume() const {
 		glm::vec3 dif =max_-min_;
 		float res = dif.x * dif.y * dif.z;
 		while(res<0){
			res = res*(-1);
		}
		return res;

 	} 

 	std::ostream& Box::print(std::ostream& os) const {
    Shape::print(os);
    os << "Minimum: " << min_.x << ", " << min_.y << ", " << min_.z << "\n" << "Maximum:"  << max_.x<<", "<< max_.y << ", " << max_.z << std::endl;
    return os;
  }

 
 	glm::vec3 const& Box::get_max() const{
 		return max_;
 	}
 	glm::vec3 const& Box::get_min() const{
 		return min_;
 	}
 	void Box::set_max(glm::vec3 const& max){
 		max_=max;
 	};
	void Box::set_min(glm::vec3 const& min){
 		min_=min;
 	};
 	