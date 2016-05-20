#ifndef CIRCLE_HPP
#define CIRCLE_HPP
//#include "color.hpp"

class Circle{
	
public:

	Circle();
	Circle(float, float, float);
	float get_r() const ;
	float get_centerx() const ;
	float get_centery() const ;
	float circumference() const ;

	bool is_inside(float, float);

private:
	float r_;
	float centerx_;
	float centery_;
};

bool operator> (Circle const&, Circle const&) ;
bool operator< (Circle const&, Circle const&) ;
bool operator== (Circle const&, Circle const&) ;


#endif