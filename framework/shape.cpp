#include "shape.hpp"


Shape::Shape(): name_{"Shape"}, mat_{}{}
Shape::Shape(std::string const& name, Color const& color): name_{name},mat_{mat}{}

Shape::~Shape(){}

const& std::string Shape::get_name() const{
	return name_;
}



Material const& Shape::get_matter() const{
	return mat_;
}


std::ostream& Shape::print(std::ostream& os) const{
os << "Name: "<<name_<<"\n"<<"Material: "<< mat_ <<std::endl;
return os;
}


std::ostream& operator <<(std::ostream& os, Shape const& s){
	return s.print(os);
}