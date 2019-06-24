#include"../Device/Device.h"
#include"Draw.h"


#define FVF (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1)


struct Vertex {
	D3DXVECTOR4 pos;	// x,y,z,rhw
	DWORD col;			// 色
	D3DXVECTOR2 uv;		// テクスチャ座標
};


namespace Draw2D {

	void Box(const Texture& file_name, D3DXVECTOR2 pos, float w, float h, float offset_x, float offset_y, float depth, D3DXCOLOR color) {

		float width = file_name.GetSize().x * w;
		float height = file_name.GetSize().y * h;

		float x1 = pos.x - width * (offset_x);			// 左上X頂点
		float x2 = pos.x + width * (1.f - offset_x);	// 右下X頂点
		float y1 = pos.y - height * (offset_y);			// 左上Y頂点
		float y2 = pos.y + height * (1.f - offset_y);	// 右下Y頂点

		Vertex vtx[4] = {
			// 頂点X, 頂点Y, 深度, 除算数, 頂点色, 描画X頂点, 描画Y頂点
			{{x1, y1, depth, 1.f}, color, {0.f, 0.f}},
			{{x2, y1, depth, 1.f}, color, {1.f, 0.f}},
			{{x2, y2, depth, 1.f}, color, {1.f, 1.f}},
			{{x1, y2, depth, 1.f}, color, {0.f, 1.f}}
		};

		Device::dev->SetTexture(0, file_name);
		Device::dev->SetFVF(FVF);

		Device::dev->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, vtx, sizeof(Vertex));
	}
}