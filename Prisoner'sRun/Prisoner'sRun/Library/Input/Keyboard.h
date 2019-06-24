#pragma once

#include<Windows.h>


const int MAX_KEY_NUM = 256;


struct Key {
public:
	static Key& GetInstance();

	// 更新
	void Update();
	// 押されている間
	bool On(int n_vir_key);
	// 押した瞬間
	bool Press(int n_vir_key);
	// 離した瞬間
	bool Release(int n_vir_key);

private:
	enum Timing {
		NOW,
		PREV,
		NUM_TIMING
	};


	bool Test(BYTE key);

private:
	BYTE keys[NUM_TIMING][MAX_KEY_NUM] = {};
};
