#pragma once

#include "../GameObject.h"
#include "../../Utility/InputControl.h"
#include <vector>

class Player : public GameObject
{
private:
	InputControl* input;

public:
	Player();
	virtual ~Player();

	void Initialize() override;
	void Update() override;
	void Draw() const override;
	void Finalize() override;
};