class Pixel {
private:
	int R;
	int G;
	int B;
	
public:
	explicit Pixel(int r = 0, int g = 0, int b = 0) : R(r), G(g), B(b) {}
	
	int getR() const {
		return R;
	}
	
	int getG() const{
		return G;
	}
	
	int getB() const{
		return B;
	}
};

class Image {
public:
	Image(int w, int h) : width(w), height(h), image(w * h), resolution(w * h) {}
	
	void setPixel(int x, int y, int R, int G, int B) {
	        int pos = y * width + x;
		if(x >= width || y >= height || x < 0 || y < 0)
			throw std::out_of_range("Exceed image size");
			
		if(R < 0 || G < 0 || B < 0)
			throw std::invalid_argument("Negative position");
			
		Pixel p = Pixel(R, G, B);
		image[pos] = p;
	}
	
	Pixel getPixel(int x, int y) {
	        int pos = y * width + x;
		if(x >= width || y >= height || x < 0 || y < 0)
			throw std::out_of_range("Exceed image size");

		return image[pos];
	}
	
private:
	std::vector<Pixel> image;
	int width;
	int height;
	int resolution;
};
