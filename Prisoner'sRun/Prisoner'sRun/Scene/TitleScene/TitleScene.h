#pragma once

#include<string>
#include"../../LoadResource/LoadResource.h"

class Title {
public:
	Title();
	~Title() {};

	void Update();
	void Draw();

private:
	std::string m_texture;

	Resource& rec = Resource::GetInsutance();
};
