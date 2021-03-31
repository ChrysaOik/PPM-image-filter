#ifndef FILTER_H
#define FILTER_H

#include "Image.h"

class Filter {

public:

	virtual image::Image operator << (const image::Image & image) = 0;

	Filter();

	Filter(const Filter &src);

	virtual ~Filter();

};

#endif