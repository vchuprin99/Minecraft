#include "application.h"

class MinecraftApp : public Minecraft::Application {
	virtual void OnUserInit() override {

	}
	virtual void OnUserUpdate() override {

	}
};

int main() {
	
	auto app = std::make_unique<MinecraftApp>();
	app->Construct({ 1280, 720, "Minecraft", false, false });
	app->Start();

	return 0;
}