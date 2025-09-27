class LegacyRectangle {
public:
	LegacyRectangle(int top_left_x, int top_left_y, int bottom_right_x, int bottom_right_y) : top_left_x(top_left_x), top_left_y(top_left_y), bottom_right_x(bottom_right_x), bottom_right_y(bottom_right_y) {}
	
	void draw() const {
		std::cout << "Rectangle of dim: " << bottom_right_x - top_left_x << " x " << top_left_y - bottom_right_y << endl; 
	}

private:
	int top_left_x;
	int top_left_y;
	int bottom_right_x;
	int bottom_right_y;
};

class Rectangle {
	virtual ~Rectangle() {}
	
	virtual void draw() const = 0;
};

class RectangleAdapter : public Recangle {
public:
	RectangleAdapter(int top_left_x, int top_left_y, int width, int height) : adaptee(top_left_x, top_left_y, top_left_x + width, top_left_y - height) {}
	
	virtual void draw() const override {
		adaptee.draw();
	}
private:
	LegacyRectangle adaptee;
};
