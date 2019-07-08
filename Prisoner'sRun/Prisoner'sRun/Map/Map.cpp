#include"Map.h"


int mapChipData[MAP_SIZE_HEIGHT][MAP_SIZE_WIDTH] = {
	{1,1,1,1,1,1,1,1,1,1},
	{2,2,2,2,2,2,2,2,2,2},
	{3,3,3,3,3,3,3,3,3,3}
};


void Map::Draw() {

	for (int i = 0; i < MAP_SIZE_HEIGHT; i++) {
		for (int j = 0; j < MAP_SIZE_WIDTH; j++) {

			// MapDataのチップ番号を渡す
			m_mapChip[i][j].id = mapChipData[i][j];

			// 画像のサイズ分ずらして描画する
			m_mapChip[i][j].pos.x = (float)j * MAP_CHIP_SIZE;
			m_mapChip[i][j].pos.y = (float)i * MAP_CHIP_SIZE;

			// チップ番号によって描画画像を変える
			switch (m_mapChip[i][j].id) {

			case FLOOR1:
				m_texture = res.GetTextureName(TextureList::MAP_FLOOR1_TEX);
				break;

			case FLOOR2:
				m_texture = res.GetTextureName(TextureList::MAP_FLOOR2_TEX);
				break;

			case FLOOR3:
				m_texture = res.GetTextureName(TextureList::MAP_FLOOR3_TEX);
				break;
			}

			Draw2D::Box(m_texture.c_str(), m_mapChip[i][j].pos);
		}
	}
}
