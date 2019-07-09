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
		int x_cut_num = 1, int y_cut_num = 1,
		int tex_num = 0,
		float depth = 0.f,
		float width = 1.f, float height = 1.f,
		float offset_x = 0.f, float offset_y = 0.f
	);
}
/*
・UVは一枚０～１.０
＞横１２８　縦６４の場合　５分割　
	UV一枚当たり　＝　ｘ1/５
	　　　→　UVの最大値から分割数を割った幅
	   １．０/５　＝　UV一枚当たりのサイズ
・UVには画像の最初と最後が必要
　　　開始位置　＝　UV1枚当たりの幅　*　現在のアニメーション番号
	　終了位置　＝　UV1枚当たりの幅　+　開始位置


	 int length		// アニメーション枚数
	 int slice_num	// アニメーション番号
	 float x,y		
	 if(アニメーション枚数が０以下){ returen }
	 float slice_size = 1.0/length　　		// 1枚当たりの幅
	 float uv_x1 = slice_size * slice_num	// 1枚の幅*アニメーション番号
	 float uv_y1 = 0.f;						// ｙは左上固定なので０
	 float uv_x2 = uv_x1 + slice_size
	 float uv_y2 = 1.f

	 1.0/length(5とする) = 0.2  // 1枚当たり
	 0.2(slice_size) * 0() = 0　	// 開始位置
	 uv_x1 = 0, uv_y1 = 0
	 uv_x2 = 0 + 0.2(←slice_size)
	 　‥‥uv_x1 = 0.2(slice_size) + 2(slice_num)

*/