#pragma once

#include <iostream>

class AbstractFrame {
public:
	AbstractFrame(int w, int h) : w(w), h(h) {};
	void virtual Draw() = 0;

protected:
	int w;
	int h;
};

class AbstractScreenResolution {
public:
	AbstractScreenResolution(int w, int h) : w(w), h(h) {};
	void virtual InstallFrame() = 0;

protected:
	int w;
	int h;
};

class PCFrame : public AbstractFrame {
public:
	PCFrame(int w, int h) : AbstractFrame(w, h) {};

	void Draw() {
		std::cout << "Screen Resolution [" << w << ", " << h << "] for PC Frame" << std::endl;
	}
};

class MobileFrame : public AbstractFrame {
public:
	MobileFrame(int w, int h) : AbstractFrame(w, h) {};

	void Draw() {
		std::cout << "Screen Resolution [" << w << ", " << h << "] for Mobile Frame" << std::endl;
	}
};

class HighResolution : public AbstractScreenResolution {
public:
	HighResolution(int w, int h) : AbstractScreenResolution(w, h) {}

	void InstallFrame() {
		std::cout << "High Resolution [" << w << ", " << h << "] in mobile" << std::endl;
	}
};

class LowResolution : public AbstractScreenResolution {
public:
	LowResolution(int w, int h) : AbstractScreenResolution(w, h) {}

	void InstallFrame() {
		std::cout << "Low Resolution [" << w << ", " << h << "] in mobile" << std::endl;
	}
};

class AbstractFactory {
public:
	virtual AbstractFrame* CreateFrame() = 0;
	virtual AbstractScreenResolution* CreateResolution() = 0;
};

class SchemaPC : public AbstractFactory {
public:
	AbstractFrame* CreateFrame() {
		return new PCFrame(1920, 1080);
	}

	AbstractScreenResolution* CreateResolution() {
		return new HighResolution(1920, 1080);
	}
};

class SchemaMobile : public AbstractFactory {
public:
	AbstractFrame* CreateFrame() {
		return new MobileFrame(1080, 720);
	}

	AbstractScreenResolution* CreateResolution() {
		return new LowResolution(1080, 720);
	}
};

class SchemaFactory {
public:
	void PrepareResolution(AbstractFactory* schema) {
		frame = schema->CreateFrame();
		resol = schema->CreateResolution();
		frame->Draw();
		resol->InstallFrame();
	}

private:
	AbstractFrame* frame;
	AbstractScreenResolution* resol;
};

