class Widget {
public:
	virtual void draw() = 0;
	virtual ~Widget() {}
};

class Button : public Widget {
public:
	explicit Button(std::string t) : text(t) {}
	
	virtual void draw() override {
		std::cout << "Button: " << text << std::endl;
	}

private:
	std::string text;
};

class TextArea : public Widget {
public:
	explicit TextArea(std::string t) : text(t) {}
	
	virtual void draw() override {
		std::cout << "Text: " << text << std::endl;
	}
private:
	std::string text;
};

#include <list>
class LayoutManager : public Widget {
public:
	virtual void draw() override {
		for(const auto& element : elements)
			element->draw();
	}
	
	void addWidget(std::shared_ptr<Widget> w) {
		elements.push_back(std::move(w));
	}
	
	void removeWidget(std::shared_ptr<Widget> w) {
		elements.remove(std::move(w));
	}
private:
	std::list<std::shared_ptr<Widget>> elements;
};
