#include "circle.hpp"
#include <cassert>
#include <cmath>

Circle::Circle() :
	r_{1.0f},
	centerx_{0.5f},
	centery_{0.5f} {}

Circle::Circle(float r, float centerx, float centery) :
	r_{r},
	centerx_{centerx},
	centery_{centery} {}


float Circle::get_r() const {

	return r_;
}

float Circle::get_centerx() const {

	return centerx_;
}

float Circle::get_centery() const {

	return centery_;
}

float Circle::circumference() const {
	return M_PI * r_ * 2;
}	

bool Circle::is_inside(float x, float y){

	float abstand = sqrt((x - centerx_)*(x - centerx_) + (y - centery_) * (y - centery_));

	if(abstand <= (r_ / 10)){
		return true;
	} else {
		return false;
	}

}

bool operator< (Circle const& a, Circle const& b) {
	return a.get_r() < b.get_r();
}

bool operator> (Circle const& a, Circle const& b) {
	return a.get_r() > b.get_r();
}

bool operator== (Circle const& a, Circle const& b) {
	return a.get_r() == b.get_r();
}