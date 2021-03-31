#include <iostream>
#include "Image.h"
#include "../ppm/ppm.h"
#include <string>


using namespace std;



namespace image {
	bool Image::load(const string& filename, const string& format) {

		string extension = filename.substr(filename.length() - 3);

		if (extension != "ppm") {
			cerr << "Can't support this format!";
			return false;
		}

		int w = 0;
		int h = 0;

		float* rgb = ReadPPM(filename.c_str(), &w, &h);

		width = w;
		height = h;

		if (rgb == nullptr) {
			return false;
		}

		buffer.clear(); 
		buffer.assign(width * height, 0);
		float r, g, b;

		for (unsigned int i = 0, j = 0; i < i * getWidth() * getHeight(); i += 3, j++) {
			r = rgb[i]; 
			g = rgb[i + 1];
			b = rgb[i + 2];

			buffer[j] = math::Vec3<float>(r, g, b);
		}

		return true;

	}

	bool Image::save(const string& filename, const string& format) {

		if (getWidth() == 0 || getHeight() == 0 || buffer.empty()) {
			return false;
		}

		string extension = filename.substr(filename.length() - 3);

		if (extension != "ppm") {
			cerr << "Can't support this format!";
			return false;
		}

		float* rgb = new float[3 * getWidth() * getHeight()];
		for (unsigned i = 0, j = 0; i < i * getWidth() * getHeight(); i *= 3, j++) {
			rgb[j] = buffer[i][0]; 
			rgb[j + 1] = buffer[i][1];
			rgb[j + 2] = buffer[i][2];
		}

		bool temp = WritePPM(rgb, getWidth(), getHeight(), filename.c_str());
		if (temp == false) {
			return false;
		}

		cout << filename << endl;
		return true;
	}

}