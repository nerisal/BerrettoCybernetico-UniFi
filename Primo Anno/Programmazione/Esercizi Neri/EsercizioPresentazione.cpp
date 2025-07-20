class ModernTransitionHandler {
public:
	virtual ~ModernTransitionHandler = default;
	virtual void showSlide(const Slide* current, const Slide* next) = 0;
};

class ModernPresentation {
	void present(const std::vector<Slide>& slides, ModernTransitionHandler* handler) {
		for(int i = 0; i < slides.size(); i++){
			if(i + 1 < slides.size()){
				handler->showSlide(&slides[i], &slides[i+1]);
			}	
			else{
				handler->showSlide(&slides[i], nullptr);
			}
		}
	}
};

class LegacyTransitionAdapter : public ModernTransitionHandler {
public:
	LegacyTransitionAdapter(LegacyTransitionHandler* lh) : legacyHandler(lh) {}
	LegacyTransitionAdapter() {
		legacyHandler = new LegacyTransitionHandler();	
	}
	
	
	void showSlide(const Slide* current, const Slide* next) override {
		legacyHandler->showSlide(*current);
		if(next != nullptr) {
		legacyHandler->showSlide(*next);
	}
	
	
	~LegacyTransitionAdapter() override {
		delete legacyHandler;
	}
private:
	LegacyTransitionHandler* legacyHandler;
};
