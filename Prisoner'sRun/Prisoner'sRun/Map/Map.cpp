#include"Map.h"


int map_chip_data[MAP_SIZE_HEIGHT][MAP_SIZE_WIDTH] = {
	{1,1,1,1,1,1,1,1,1,1},
	{2,2,2,2,2,2,2,2,2,2},
	{3,3,3,3,3,3,3,3,3,3}
};

void Map::Init() {

}

void Map::Update() {

}

void Map::Draw() {
	
	// リスト内のマップチップを全て描画する
	for (int i = 0; i < MAP_SIZE_HEIGHT; i++) {
		for (int j = 0; j < MAP_SIZE_WIDTH; j++) {
			Draw2D::Box(m_map_chip[i][j].tex.c_str(), m_map_chip[i][j].pos, 0.5f);
		}
	}
}

void Map::Create() {

	for (int i = 0; i < MAP_SIZE_HEIGHT; i++) {
		for (int j = 0; j < MAP_SIZE_WIDTH; j++) {

			// MapDataのチップ番号を渡す
			m_map_chip[i][j].id = map_chip_data[i][j];

			// 画像のサイズ分ずらして描画する
			m_map_chip[i][j].pos.x = (float)j * MAP_CHIP_SIZE;
			m_map_chip[i][j].pos.y = (float)i * MAP_CHIP_SIZE;

			// チップ番号によって画像を変える
			m_map_chip[i][j].tex = EntryMapTexture(m_map_chip[i][j].id);
			/*switch (m_map_chip[i][j].id) {

			case MapChipList::FLOOR1:
				m_map_chip[i][j].tex = res.GetTextureName(TextureList::MAP_FLOOR1_TEX);
				break;

			case MapChipList::FLOOR2:
				m_map_chip[i][j].tex = res.GetTextureName(TextureList::MAP_FLOOR2_TEX);
				break;

			case MapChipList::FLOOR3:
				m_map_chip[i][j].tex = res.GetTextureName(TextureList::MAP_FLOOR3_TEX);
				break;

			case MapChipList::WALL_TOP1:
				m_map_chip[i][j].tex = res.GetTextureName(TextureList::MAP_WALL_TOP1_TEX);
				break;
				
			case MapChipList::WALL_TOP2:
				m_map_chip[i][j].tex = res.GetTextureName(TextureList::MAP_WALL_TOP2_TEX);
				break;

			case MapChipList::WALL_TOP3:
				m_map_chip[i][j].tex = res.GetTextureName(TextureList::MAP_WALL_TOP3_TEX);
				break;

			case MapChipList::WALL_UNDER1:
				m_map_chip[i][j].tex = res.GetTextureName(TextureList::MAP_WALL_UNDER1_TEX);
				break;
			case MapChipList::WALL_UNDER2:
				m_map_chip[i][j].tex = res.GetTextureName(TextureList::MAP_WALL_UNDER2_TEX);
				break;

			case MapChipList::WALL_UNDER3:
				m_map_chip[i][j].tex = res.GetTextureName(TextureList::MAP_WALL_UNDER3_TEX);
				break;

			case MapChipList::CEILING1:
				m_map_chip[i][j].tex = res.GetTextureName(TextureList::MAP_CEILING1_TEX);
			}*/
		}
	}
}

std::string Map::EntryMapTexture(const int id) {

	switch (id) {
	case MapChipList::FLOOR1:
		return res.GetTextureName(TextureList::MAP_FLOOR1_TEX);

	case MapChipList::FLOOR2:
		return res.GetTextureName(TextureList::MAP_FLOOR2_TEX);

	case MapChipList::FLOOR3:
		return res.GetTextureName(TextureList::MAP_FLOOR3_TEX);

	case MapChipList::WALL_TOP1:
		return res.GetTextureName(TextureList::MAP_WALL_TOP1_TEX);

	case MapChipList::WALL_TOP2:
		return res.GetTextureName(TextureList::MAP_WALL_TOP2_TEX);

	case MapChipList::WALL_TOP3:
		return res.GetTextureName(TextureList::MAP_WALL_TOP3_TEX);

	case MapChipList::WALL_UNDER1:
		return res.GetTextureName(TextureList::MAP_WALL_UNDER1_TEX);

	case MapChipList::WALL_UNDER2:
		return res.GetTextureName(TextureList::MAP_WALL_UNDER2_TEX);

	case MapChipList::WALL_UNDER3:
		return res.GetTextureName(TextureList::MAP_WALL_UNDER3_TEX);

	case MapChipList::CEILING1:
		return res.GetTextureName(TextureList::MAP_CEILING1_TEX);

	case MapChipList::CEILING2:
		return res.GetTextureName(TextureList::MAP_CEILING2_TEX);

	case MapChipList::CEILING3:
		return res.GetTextureName(TextureList::MAP_CEILING3_TEX);

	case MapChipList::CEILING_CORNER1:
		return res.GetTextureName(TextureList::MAP_CEILING_CORNER1_TEX);

	case MapChipList::CEILING_CORNER2:
		return res.GetTextureName(TextureList::MAP_CEILING_CORNER1_TEX);
	}

	return nullptr;
}
