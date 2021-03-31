#include "FilterLinear.h"
#include <vector>
#include <iostream>

using namespace std;
using namespace image;
using namespace math;

FilterLinear::FilterLinear() : a(), c() {}

FilterLinear::FilterLinear(math::Vec3<float> a, math::Vec3<float> c) : a(a), c(c) {}

FilterLinear::FilterLinear(const FilterLinear &src) {
	a = src.a;
	c = src.c;
}

FilterLinear::~FilterLinear() {}

void FilterLinear::setA(math::Vec3<float> a) {
	this->a = a;
}

void FilterLinear::setC(math::Vec3<float> c) {
	this->c = c;
}

math::Vec3<float> FilterLinear::getA() {
	return a;
}

math::Vec3<float> FilterLinear::getC() {
	return c;
}


image::Image FilterLinear::operator << (const image::Image & image) { 
	
	image::Image newImage(image);
	
	
	for (unsigned int i = 0; i < image.getWidth(); i++) {

		for (unsigned int j = 0; j < image.getHeight(); j++) {

			math::Vec3<float> cur = (math::Vec3<float>)newImage(i,j);
			math::Vec3<float> newColor = getA() * cur + getC();

			newColor = newColor.clampToLowerBound(0);
			newColor = newColor.clampToUpperBound(1);

			newImage.setData(&newColor);
			
		}
	}

	return newImage;
}
