#include "shape.hpp"


Shape::Shape(): name_{"Shape"}, color_{0.0f,0.0f,0.0f}{}
Shape::Shape(std::string const& name, Color const& color): name_{name},color_{color}{}

Shape::~Shape(){
	std::cout << "Shape Destruction: "<<name_<<std::endl;
}

std::string Shape::get_name() const{
	return name_;
}



Color const& Shape::get_color() const{
	return color_;
}


std::ostream& Shape::print(std::ostream& os) const{
os << "Name: "<<name_<<"\n"<<"Color : "<<color_.r<<", "<<color_.g<<", "<<color_.b<<std::endl;
return os;
}


std::ostream& operator <<(std::ostream& os, Shape const& s){
	return s.print(os);
}