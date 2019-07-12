#pragma once
#define NOMINMAX
#include<Windows.h>


#define MAX_KEY_NUM  256


struct Key {
public:
	static Key& GetInstance();

	// 更新
	void Update();
	// 押されている間
	bool On(int nVirKey);
	// 押した瞬間
	bool Press(int nVirKey);
	// 離した瞬間
	bool Release(int nVirKey);

private:
	enum Timing {
		NOW,
		PREV,
		NUM_TIMING
	};


	bool Test(BYTE key)const;

private:
	BYTE keys[NUM_TIMING][MAX_KEY_NUM] = {};
};
