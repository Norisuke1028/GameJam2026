#pragma once

#include "../GameObject.h"
#include <vector>

class Player : public GameObject
{
	
public:
	Player();
	virtual ~Player();

	void Initialize() override;
	void Update() override;
	void Draw() const override;
	void Finalize() override;
};