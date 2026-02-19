#pragma once

#include "Objects/GameObject.h"
#include <vector>

class StageData : public GameObject
{
private:
	static StageData* instance;

	float s_location;

	StageData();
	~StageData();

public:

	void Initialize() override;
	void Update() override;
	void Draw(const Vector2D& screen_offset) const override;
	void Finalize() override;

	//ˆÊ’uî•ñæ“¾ˆ—
	float GetLocation() const;
	Vector2D GetVelocity();
	void SetVelocity(float velo);

public:
	static StageData* GetInstance();
};

