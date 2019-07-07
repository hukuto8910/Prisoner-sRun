#pragma once

#include<d3dx9.h>
#include<string>
#include<unordered_map>


class Texture {
public:
	Texture() :tex(nullptr), size(0.f, 0.f) {} // メンバイニシャライザ―　初期化
	Texture(const char* file_name); // 変換コンストラクタ
	Texture(const Texture& t); // コピーコンストラクタ
	~Texture(); // デストラクタ
	Texture& operator=(const Texture& t); // Operatorの代入演算子

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
	LPDIRECT3DTEXTURE9 tex;
	D3DXVECTOR2 size;
	std::string name;
};
