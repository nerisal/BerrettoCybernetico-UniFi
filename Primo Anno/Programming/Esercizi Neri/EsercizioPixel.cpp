class Pixel {
private:
	int R;
	int G;
	int B;
	
public:
	Pixel() : R(0), G(0), B(0) {}
	
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
	Image(int w, int h) : width(w), heigth(h), image(w * h) {
		resolution = width * heigth;
	}
	
	void setPixel(int x, int y, int R, int G, int B) {
		if((x * width + y) > resolution)
			throw std::out_of_range("Exeed image size");
			
		if(x < 0 || y > 0)
			throw std::invalid_argument("Negative position");
			
		Pixel p = Pixel(R, G, B);
		vector[x + heigth * y]] = p;
	}
	
	Pixel getPixel(int x, int) {
		if((x * width + y) > resolution)
			throw std::out_of_range("Exeed image size");
			
		if(x < 0 || y > 0)
			throw std::invalid_argument("Negative position");
			
		auto p = vector[x + heigth * y];
		
		cout << "Red: " << p.getR() << " Green: " << p.getG() << " Blue: " << p.getB();
		return p;
	}
	
private:
	std::vector<Pixel> image;
	int width;
	int heigth;
	int resolution;
};
