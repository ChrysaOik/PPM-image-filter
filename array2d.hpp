#ifndef ARRAY2D_HPP
#define ARRAY2D_HPP


#include <vector>
#include <string>

using namespace std;



	template <typename T>
	class Array2D {
	
	protected:
		vector<T> buffer;                       

		unsigned int width,
			height;		             

	public:
		
		const unsigned int getWidth() const {
			return width;
		}


		const unsigned int getHeight() const {
			return height;
		}

		T * getRawDataPtr() {
			return buffer;
		}

		void setData(const T * const & data_ptr) {

			if (buffer.width < data_ptr.getWidth() || buffer.height < data_ptr.getHeight() || getHeight() == 0 || getWidth() == 0 || data_ptr.empty() )
				return;
			
			buffer.clear();
			for (int i = 0; i < getWidth() * getHeight(); i++) {
				buffer.push_back(data_ptr.at(i));
			}
		}

		T & operator () (unsigned int x, unsigned int y) {
			return buffer.at((x + (getWidth() *y))); 
		}


		
		Array2D(unsigned int width = 0, unsigned int height = 0, const T * data_ptr = 0) :width(width), height(height), data_ptr(data_ptr) { 
			buffer.clear();
		}

		Array2D(const Array2D &src) {
			width = src.width;
			height = src.height;
			setData(src.buffer);
		}

		

		~Array2D() {
			buffer.clear();
		}

		Array2D & operator = (const Array2D & right) { 
			unsigned int size = getWidth() * getHeight();
			unsigned int rightSize = right.getHeight() * right.getWidth();

			if (&right != this) {
				if (size != rightSize) {
					buffer.clear();
					size = rightSize;
					buffer.assign(size, 0);
				}
			}

			width = right.getWidth();
			height = right.getHeight();
			setData(right.buffer);
			return *this;
		}
	};

#endif