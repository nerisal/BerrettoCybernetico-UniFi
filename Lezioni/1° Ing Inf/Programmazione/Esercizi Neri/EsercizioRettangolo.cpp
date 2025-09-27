class LegacyRectangle {
private:
	int top_left_x;
	int top_left_y;
	int bottom_right_x;
	int bottom_right_y;
public:
	LegacyRectangle(int tlx, int tly, int brx, int bry) : top_left_x(tlx), top_left_y(tly), bottom_right_x(brx), bottom_right_y(bry) {}
	virtual ~LegacyRectangle() {}
	
	virtual void draw() {
		std::cout << "Top left corner coordinates: " << top_left_x << " - " << top_left_y << " Bottom right corner " << bottom_right_x << " -" << bottom_right_y << std::endl;
	}
};

class Rectangle {
public:
	virtual ~Rectangle(){};
	virtual void draw() = 0;
};


class RectangleAdapter : private LegacyRectangle , public Rectangle {
public:
	RectangleAdapter(int tlx, int tly, int w, int h) : LegacyRectangle(tlx, tly, tlx + w, tly + h){}
	
	virtual ~RectangleAdapter() {}
	
	void draw() override {
		LegacyRectangle::draw();
	}
};
