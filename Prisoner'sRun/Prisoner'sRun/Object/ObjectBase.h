#pragma once

#include<string>
#include"../LoadResource/LoadResource.h"
#include"../Library/Draw/Draw.h"


// オブジェクトの基底クラス
class ObjectBase {
public:
	ObjectBase() {}
	virtual ~ObjectBase() {}

	//  純粋仮想関数　//　
	/*
	派生先の実体を作るオブジェクトのクラスで必ず定義すること
	抽象クラスは定義しなくてもいい
	*/
	//初期化
	virtual void Init() = 0;
	// 更新
	virtual void Update() = 0;
	// 描画
	virtual void Draw() = 0;

protected:
	D3DXVECTOR2 m_pos;		// 位置座標
	std::string m_texture;	// 画像

	Resource& res = Resource::GetInstance();	// 画像指定用Resource変数
};
