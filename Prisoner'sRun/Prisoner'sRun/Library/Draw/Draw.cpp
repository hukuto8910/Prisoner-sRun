#include"../Device/Device.h"
#include"Draw.h"


#define FVF (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1)


struct Vertex {
	D3DXVECTOR4 pos;	// x,y,z,rhw
	DWORD col;			// 色
	D3DXVECTOR2 uv;		// テクスチャ座標
};


namespace Draw2D {

	// 四角形の画像描画
	void Box(const Texture& fileName, D3DXVECTOR2 pos, float w, float h, float offsetX, float offsetY, float depth, D3DXCOLOR color) {

		// 画像サイズの取得
		float width = fileName.GetSize().x * w;
		float height = fileName.GetSize().y * h;

		// 描画位置の計算
		float x1 = pos.x - width * (offsetX);			// 左上X頂点
		float x2 = pos.x + width * (1.f - offsetX);	// 右下X頂点
		float y1 = pos.y - height * (offsetY);			// 左上Y頂点
		float y2 = pos.y + height * (1.f - offsetY);	// 右下Y頂点

		Vertex vtx[4] = {
			// 頂点X, 頂点Y, 深度, 除算数, 頂点色, 描画X頂点, 描画Y頂点
			{{x1, y1, depth, 1.f}, color, {0.f, 0.f}},
			{{x2, y1, depth, 1.f}, color, {1.f, 0.f}},
			{{x2, y2, depth, 1.f}, color, {1.f, 1.f}},
			{{x1, y2, depth, 1.f}, color, {0.f, 1.f}}
		};

		Device::dev->SetTexture(0, fileName);
		Device::dev->SetFVF(FVF);

		Device::dev->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, vtx, sizeof(Vertex));
	}

	
	// 四角形の統合画像のアニメーション描画
	void BoxAnimation(const Texture& fileName, D3DXVECTOR2 pos, int xCutNum, int yCutNum, int tex_num, float depth, float w, float h, float offsetX, float offsetY) {

		float width = fileName.GetSize().x * w;
		float height = fileName.GetSize().y * h;

		float x1 = pos.x - (width / xCutNum) * (offsetX);			
		float x2 = pos.x + (width / xCutNum) * (1.f - offsetX);	
		float y1 = pos.y - (height / yCutNum) * (offsetY);			
		float y2 = pos.y + (height / yCutNum) * (1.f - offsetY);	
		

		// UVの初期化
		float uv_x1 = 0.f;		// 画像の左上頂点
		float uv_x2 = 1.f;		// 画像の右上頂点
		float uv_y1 = 0.f;		// 画像の右下頂点
		float uv_y2 = 1.f;		// 画像の左下頂点

		// ｘ軸の分割計算
		if (xCutNum > 0) {

			// 分割後の1枚の横幅
			float cut_size = 1.0f / xCutNum;

			// 縦分割がある場合は、余り算で計算する
			if (tex_num > xCutNum) {
				uv_x1 = cut_size * (tex_num % xCutNum);
			}
			else {
				uv_x1 = cut_size * tex_num;
			}

			uv_x2 = uv_x1 + cut_size;
		}

		// ｙ軸の分割計算
		if (yCutNum > 0) {

			// 分割後の1枚の縦幅
			float cut_size = 1.0f / yCutNum;

			// 現在のｘ軸をアニメーション番号に割ったものをサイズと掛ける
			uv_y1 = cut_size * (tex_num / xCutNum);
			uv_y2 = uv_y1 + cut_size;
		}
		

		Vertex vtx[4] = {
			// 頂点X, 頂点Y, 深度, 除算数, 頂点色, 描画X頂点, 描画Y頂点
			{{x1, y1, depth, 1.f}, 0x00ffffff, {uv_x1, uv_y1}},
			{{x2, y1, depth, 1.f}, 0x00ffffff, {uv_x2, uv_y1}},
			{{x2, y2, depth, 1.f}, 0x00ffffff, {uv_x2, uv_y2}},
			{{x1, y2, depth, 1.f}, 0x00ffffff, {uv_x1, uv_y2}}
		};

		Device::dev->SetTexture(0, fileName);
		Device::dev->SetFVF(FVF);

		Device::dev->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, vtx, sizeof(Vertex));
	}

}
