#ifndef FILTERLINEAR_H
#define FILTERLINEAR_H

#include "Filter.h"
#include "vec3.h"

class FilterLinear : public Filter {

private:

	math::Vec3<float> a, c;

public: 

	FilterLinear();

	FilterLinear(math::Vec3<float> a, math::Vec3<float> b);

	FilterLinear(const FilterLinear &src);

	~FilterLinear();

	void setA(math::Vec3<float> a);

	void setC(math::Vec3<float> c);

	math::Vec3<float> getA();

	math::Vec3<float> getC();

	image::Image operator << (const image::Image &image);
};

#endif