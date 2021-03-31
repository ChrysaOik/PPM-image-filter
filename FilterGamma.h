#ifndef FILTERGAMMA_H
#define FILTERGAMMA_H

#include "Filter.h"

class FilterGamma : public Filter {

private:
	float y;

public:

	FilterGamma();

	FilterGamma(float y);

	FilterGamma(const FilterGamma &src);

	~FilterGamma();

	void setY(float y);

	float getY();

	image::Image operator << (const image::Image &image);
};

#endif
