#pragma once

#include"../Texture/Texture.h"


namespace Draw2D {

	// 四角形の描画関数
	/*
		第1　：画像名
		第2　：描画位置
		第3,4：描画サイズ(1＝画像ピクセルサイズ)　デフォルト：1
		第5,6：オフセット　デフォルト：0(左上)
		第7　：深度(0＝最前,1＝最背)　デフォルト：0
		第8　：頂点カラー
	*/
	void Box(
		const Texture& file_name,
		D3DXVECTOR2 pos,
		float width = 1.f, float height = 1.f,
		float offset_x = 0.f, float offset_y = 0.f,
		float depth = 0.f,
		D3DXCOLOR color = 0x00ffffff
	);

	// 四角形の統合画像アニメーション描画関数
	void BoxAnimation(
		const Texture& file_name,
		D3DXVECTOR2 pos,
		float x_cut_num = 0, float y_cut_num = 0,
		int tex_num = 0,
		float depth = 0.f,
		float width = 1.f, float height = 1.f,
		float offset_x = 0.f, float offset_y = 0.f
	);
}
