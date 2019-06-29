#pragma once

#include<string>
#include<vector>
#include<unordered_map>
#include"../Library/Texture/Texture.h"
#include"../Library/Draw/Draw.h"
#include"../LoadResource.h"


#define MAP_CHIP_SIZE 32
#define MAP_SIZE_WIDTH 10
#define MAP_SIZE_HEIGHT 3

/*
これいる？
・Mapクラスで定義
・構造体にするにしても、クラス内で
・座標、画像、チップ番号、当たり判定の矩形が必要
*/
struct MapChip{
	Texture tex;
	D3DXVECTOR2 pos;
	int id;
};

/*
・Dataはcsvで読み取るようにする
・縦はフル、横はUIを置くので、その分の幅で作成
・アイテムはランダム、塚などの構造は基本一定
*/
int mapChipData[MAP_SIZE_HEIGHT][MAP_SIZE_WIDTH] = {
	{1,1,1,1,1,1,1,1,1,1},
	{2,2,2,2,2,2,2,2,2,2},
	{3,3,3,3,3,3,3,3,3,3}
};

class Map {
public:

	Map() {

	}
	~Map() {

	};

	void Draw() {

		for (int i = 0; i < MAP_SIZE_HEIGHT; i++) {
			for (int j = 0; j < MAP_SIZE_WIDTH; j++) {

				// MapDataのチップ番号を渡す
				mapChip[i][j].id = mapChipData[i][j];
				
				// 画像のサイズ分ずらして描画する
				mapChip[i][j].pos.x = (float)j * MAP_CHIP_SIZE;
				mapChip[i][j].pos.y = (float)i * MAP_CHIP_SIZE;

				// チップ番号によって描画画像を変える
				switch (mapChip[i][j].id) {
				case FLOOR1:
					test = Resource::m_texture_list->at(TextureList::MAP_FLOOR1);
					break;
				case FLOOR2:
					test = Resource::m_texture_list->at(TextureList::MAP_FLOOR2);
					break;
				case FLOOR3:
					test = Resource::m_texture_list->at(TextureList::MAP_FLOOR3);
					break;
				}

				Draw2D::Box(test, mapChip[i][j].pos);
			}
		}
	}

private:
	Texture test;// = "Resource/Texture/Map/floor1.png";
	MapChip mapChip[MAP_SIZE_HEIGHT][MAP_SIZE_WIDTH];
	enum MapTextureList {
		MAP_TEXTURE_INIT,
		FLOOR1,
		FLOOR2,
		FLOOR3,
		MAP_TEXTURE_MAX
	};
};

