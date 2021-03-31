#include "FilterGamma.h"
#include <vector>
#include <math.h>

FilterGamma::FilterGamma() :y() {}

FilterGamma::FilterGamma(float y) : y(y) {}

FilterGamma::FilterGamma(const FilterGamma &src) {
	y = src.y;
}

FilterGamma::~FilterGamma() {}

void FilterGamma::setY(float y) {
	this->y = y;
}

float FilterGamma::getY() {
	return y;
}

image::Image FilterGamma::operator <<(const image::Image& image)
{

	image::Image newImage(image);

	for (unsigned int i = 0; i < image.getWidth(); i++) {

		for (unsigned int j = 0; j < image.getHeight(); j++) {

			math::Vec3<float> cur = (math::Vec3<float>)newImage(i, j);
			float r = pow(cur[0], getY());
			float g = pow(cur[1], getY());
			float b = pow(cur[2], getY());

			math::Vec3<float> newColor(r, g, b);
			newColor = newColor.clampToLowerBound(0);
			newColor = newColor.clampToUpperBound(1);

			newImage.setData(&newColor);
		}
	}

	return newImage;
}



