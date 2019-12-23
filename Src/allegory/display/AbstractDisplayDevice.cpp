#include "AbstractDisplayDevice.h"

namespace allegory::display {

	void AbstractDisplayDevice::clear() {
		this->fill(Color::BLACK);
	}

	void AbstractDisplayDevice::fill(Color color) {
		for (int x = 0; x < width(); ++x) {
			for (int y = 0; y < height(); ++y) {
				drawPixel(x, y, color);
			}
		}
	}

}
