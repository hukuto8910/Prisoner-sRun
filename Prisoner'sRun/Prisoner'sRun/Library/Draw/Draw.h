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
		const Texture& fileName,
		D3DXVECTOR2 pos,
		float width = 1.f, float height = 1.f,
		float offsetX = 0.f, float offsetY = 0.f,
		float depth = 0.f,
		D3DXCOLOR color = 0x00ffffff
	);


	// 四角形の統合画像アニメーション描画関数
	/*
		第1	  ：画像名
		第2	  ：描画位置
		第3,4 ：画像の分割数(ｘ,ｙ)		 
		第5	  ：アニメーションの画像番号
		第6	  ：深度		デフォルト：0
		第7,8 ：画像サイズ	デフォルト：1
		第9,10：オフセット	デフォルト：0

		・第3引数にｘ軸の画像分割数、第4引数にｙ軸の画像分割数を入れる
		・第5引数の番号は別途でカウントを回したものを入れる
		　　	(あくまで、番号の場所にあたる画像を描画するだけ)
		・基本的に第5引数までは指定すること
		・分割しない場合は、1を入れる
	*/
	void BoxAnimation(
		const Texture& fileName,
		D3DXVECTOR2 pos,
		int xCutNum, int yCutNum,
		int texNum,
		float depth = 0.f,
		float width = 1.f, float height = 1.f,
		float offsetX = 0.f, float offsetY = 0.f
	);
}
