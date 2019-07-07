#pragma once

#include"../SceneBase.h"
#include"../../Map/Map.h"


class GameMain :public SceneBase{
public:
	GameMain();
	~GameMain()override {}

	void Init()override;
	void Update()override;
	void Draw()override;

private:

};