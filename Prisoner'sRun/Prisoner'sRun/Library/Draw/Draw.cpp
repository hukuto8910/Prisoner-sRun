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

	void BoxAnimation(const Texture& file_name, D3DXVECTOR2 pos, float x_cut_num, float y_cut_num, int tex_num, float depth, float w, float h, float offset_x, float offset_y) {

		float width = file_name.GetSize().x * w;
		float height = file_name.GetSize().y * h;

		float x1 = pos.x - width * (offset_x);			// 左上X頂点
		float x2 = pos.x + width * (1.f - offset_x);	// 右下X頂点
		float y1 = pos.y - height * (offset_y);			// 左上Y頂点
		float y2 = pos.y + height * (1.f - offset_y);	// 右下Y頂点
		
		float u = 1.f;
		float v = 1.f;
		if (x_cut_num > 0) {
			u /= x_cut_num;
		}
		if (y_cut_num > 0) {
			v /=  y_cut_num;
		}

		Vertex vtx[4] = {
			// 頂点X, 頂点Y, 深度, 除算数, 頂点色, 描画X頂点, 描画Y頂点
			{{x1, y1, depth, 1.f}, 0x00ffffff, {u * tex_num, v * tex_num}},
			{{x2, y1, depth, 1.f}, 0x00ffffff, {u * tex_num + u, v * tex_num}},
			{{x2, y2, depth, 1.f}, 0x00ffffff, {u * tex_num, v * tex_num + v}},
			{{x1, y2, depth, 1.f}, 0x00ffffff, {u * tex_num + u, v * tex_num + v}}
		};

		Device::dev->SetTexture(0, file_name);
		Device::dev->SetFVF(FVF);

		Device::dev->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, vtx, sizeof(Vertex));

		/*
		左上(0,0)　右上(1,0)
		左下(0,1)　右下(1,1)
		UVcut＝2,0　　＝2枚
		{0, 0},{0.5, 0},{0.5, 1},{0, 1} =1枚目
		{0.5, 1},{1, 1},{0.5, 1},{1, 1} =2枚目

		　画像/分割数　*　画像番号　＝　u
		  画像/分割数　*　画像
		1u = 1/2 = 0.5*0 = 0 , 2u = 1/2 = 0.5*0 + 0.5 = 0.5
		3u = 1/2 = 0.5*0 = 0 , 4u = 1/2 = 0.5*0 + 0.5 = 0.5
		1y = 1*0 = 0	 , 2y = 1*0 = 0
		3y = 1*0 + 1 = 1 , 4y = 1*0 + 1 =1
		
		2_1u = 1/2 = 0.5*1 = 0.5
		2_2u = 1/2 = 0.5*1 
		*/
	}

}
