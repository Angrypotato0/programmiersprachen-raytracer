#include "box.hpp"
#include "shape.hpp"
#include <cmath>

Box::Box() : Shape{"box",{0.0f, 0.0f, 0.0f}}, min_ {0.0f,0.0f,0.0f}, max_ {0.0f,0.0f,0.0f} {}
Box::Box(glm::vec3 const& min, glm::vec3 const& max) :
Shape{"box",{0.0f, 0.0f, 0.0f}}, max_{max}, min_{min}{
	min_.x = std::min(min.x, max.x);
    min_.y = std::min(min.y, max.y);
    min_.z = std::min(min.z, max.z);
    max_.x = std::max(min.x, max.x);
    max_.y = std::max(min.y, max.y);
    max_.z = std::max(min.z, max.z);}
Box::Box(std::string const& name, Color const& color, glm::vec3 const& min, glm::vec3 const& max) :
Shape{name,color}, max_{max}, min_{min}{
	min_.x = std::min(min.x, max.x);
    min_.y = std::min(min.y, max.y);
    min_.z = std::min(min.z, max.z);
    max_.x = std::max(min.x, max.x);
    max_.y = std::max(min.y, max.y);
    max_.z = std::max(min.z, max.z);}

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

 	bool Box::intersect(Ray const& ray, float& t) const {
 		bool result = true;
 		int z_1 = 0;
 		int z_2 = 0;
 		int z_3 = 0;

 		if (ray.direction().x != 0) {
    
       		glm::vec3 intersect_1{};
       		float v_1 = (min_.x - ray.origin().x) / ray.direction().x;
       		intersect_1.x = ray.origin().x + v_1 * ray.direction().x;
      		intersect_1.y = ray.origin().y + v_1 * ray.direction().y;
      		intersect_1.z = ray.origin().z + v_1 * ray.direction().z;

    
      		glm::vec3 intersect_2{};
      		float v_2 = (max_.x - ray.origin().x) / ray.direction().x;
      		intersect_2.x = ray.origin().x + v_2 * ray.direction().x;
      		intersect_2.y = ray.origin().y + v_2 * ray.direction().y;
      		intersect_2.z = ray.origin().z + v_2 * ray.direction().z;

      		if (in_box(intersect_1)==true || in_box(intersect_2)==true){
      			z_1 = 1;
      		}
 		}

 		if (ray.direction().y != 0){
 			glm::vec3 intersect_1{};
      		float v_1 = (min_.y - ray.origin().y) / ray.direction().y;
      		intersect_1.x = ray.origin().x + v_1 * ray.direction().x;
      		intersect_1.y = ray.origin().y + v_1 * ray.direction().y;
      		intersect_1.z = ray.origin().z + v_1 * ray.direction().z;

    
      		glm::vec3 intersect_2{};
      		float v_2 = (max_.y - ray.origin().y) / ray.direction().y;
      		intersect_2.x = ray.origin().x + v_2 * ray.direction().x;
      		intersect_2.y = ray.origin().y + v_2 * ray.direction().y;
      		intersect_2.z = ray.origin().z + v_2 * ray.direction().z;


      		if (in_box(intersect_1) == true || in_box(intersect_2) == true) {
        		z_2 = 1;
      		}
 		}

 		if (ray.direction().z != 0){
   
      		glm::vec3 intersect_1{};
      		float v_1 = (min_.z - ray.origin().z) / ray.direction().z;
      		intersect_1.x = ray.origin().x + v_1 * ray.direction().x;
      		intersect_1.y = ray.origin().y + v_1 * ray.direction().y;
      		intersect_1.z = ray.origin().z + v_1 * ray.direction().z;

      		glm::vec3 intersect_2{};
      		float v_2 = (max_.z - ray.origin().z) / ray.direction().z;
      		intersect_2.x = ray.origin().x + v_2 * ray.direction().x;
      		intersect_2.y = ray.origin().y + v_2 * ray.direction().y;
      		intersect_2.z = ray.origin().z + v_2 * ray.direction().z;
   
      		if (in_box(intersect_1) == true || in_box(intersect_2) == true) {
        		z_3 = 1;
      		}
    	}

    	t = 0;

    	if (z_1 == 0 && z_2 == 0 && z_3 == 0){
    		result = false;
    	}

    	return result;

 	}

 	bool Box::in_box(glm::vec3 const& point) const {
 		bool result = false;
 		if (point.x >= min_.x && point.x <= max_.x) {
      		if (point.y >= min_.y && point.y <= max_.y) {
        		if (point.z >= min_.z && point.z <= max_.z) {
          			result = true;
        		}
      		}
    	}
    	return result;
 	}

 	bool in_box(glm::vec3 const& min, glm::vec3 const& max, glm::vec3 const& point) {
    Box b {min, max};
    return b.in_box(point);
   }




 	