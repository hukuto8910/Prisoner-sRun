#pragma once

#include<string>
#include"../Device/Device.h"


class Texture {
public:
	// メンバイニシャライザ―
	Texture() :tex(nullptr), size(0.f, 0.f) {} 

	// 変換コンストラクタ
	Texture(const char* fileName); 

	// コピーコンストラクタ
	Texture(const Texture& t); 
	
	// Operatorの代入演算子
	Texture& operator=(const Texture& t); 

	~Texture();


	// 解放関数
	/*
	各シーン遷移時に前のシーンの画像を解放する
	*/
	void Relese();
	

	// LPDIRECT3DTEXTURE9が呼ばれたらtexのポインタを戻り値として返す
	operator LPDIRECT3DTEXTURE9() const {
		return tex;
	}
	// アクセス方法
	const D3DXVECTOR2& GetSize() const {
		return size; // sizeを返す
	}
	const std::string& GetName() const {
		return name; // nameを返す
	}

private:
	LPDIRECT3DTEXTURE9 tex;	// 画像
	D3DXVECTOR2 size;		// 画像サイズ
	std::string name;		// 画像名
};
