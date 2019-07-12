#pragma once

#include<string>
#include"../Library/Draw/Draw.h"
#include"../LoadResource/LoadResource.h"


#define MAP_CHIP_SIZE 32
#define MAP_SIZE_WIDTH 10
#define MAP_SIZE_HEIGHT 3

/*
これいる？
・Mapクラスで定義
・構造体にするにしても、クラス内で
・座標、画像、チップ番号、当たり判定の矩形が必要
*/


/*
・Dataはcsvで読み取るようにする
・縦はフル、横はUIを置くので、その分の幅で作成
・アイテムはランダム、床などの構造は基本一定
*/


class Map {
public:
	Map() {}
	~Map() {};

	void Draw();

private:
	enum MapChipList {
		MAP_TEXTURE_INIT,
		FLOOR1,
		FLOOR2,
		FLOOR3,
		MAP_TEXTURE_MAX
	};

	struct MapChip {
		Texture tex;		// 画像
		D3DXVECTOR2 pos;	// 描画座標
		int id;				// マップチップ番号
	};

	std::string m_texture;
	MapChip m_mapChip[MAP_SIZE_HEIGHT][MAP_SIZE_WIDTH];
	
	Resource& res = Resource::GetInstance();
};

