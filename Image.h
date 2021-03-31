#ifndef IMAGE_
#define IMAGE_

#include "imageio.h"

namespace image {


class Image :public math::Array2D<math::Vec3<float>> {


public:
	bool load(const string& filename, const string& format);

	bool save(const string& filename, const string& format);


};

}
#endif