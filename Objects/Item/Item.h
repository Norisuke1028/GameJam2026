#pragma once

#include "../GameObject.h"
#include "../../Utility/InputControl.h"
#include <vector>

class Item : public GameObject
{
private:
	InputControl* input;

public:
	Item();
	virtual ~Item();

	void Initialize() override;
	void Update() override;
	void Draw(const Vector2D& screen_offset) const override;
	void Finalize() override;

	// ˆÊ’uî•ñæ“¾ˆ—
	const Vector2D& GetLocation() const;
	// ˆÊ’uî•ñæ“¾ˆ—
	const Vector2D& GetVelocity() const;
};

