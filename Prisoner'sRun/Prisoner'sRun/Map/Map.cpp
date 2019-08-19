#include<sstream>
#include"Map.h"


Map::Map() {
	m_map.reserve(30);
}
void Map::Init() {
	
}
/*
void Map::EntryMapTexture(MapChip& map) {

	switch (map.chip_num) {

	case MapChipList::MAP_TEXTURE_INIT:
		map.tex_name = res.GetTextureName(TextureList::MAP_WALL_UNDER1_TEX);
		break;

	case MapChipList::FLOOR1:
		map.tex_name = res.GetTextureName(TextureList::MAP_FLOOR1_TEX);
		break;

	case MapChipList::FLOOR2:
		map.tex_name = res.GetTextureName(TextureList::MAP_FLOOR2_TEX);
		break;

	case MapChipList::FLOOR3:
		map.tex_name = res.GetTextureName(TextureList::MAP_FLOOR3_TEX);
		break;

	case MapChipList::WALL_TOP1:
		map.tex_name = res.GetTextureName(TextureList::MAP_WALL_TOP1_TEX);
		break;

	case MapChipList::WALL_TOP2:
		map.tex_name = res.GetTextureName(TextureList::MAP_WALL_TOP2_TEX);
		break;

	case MapChipList::WALL_TOP3:
		map.tex_name = res.GetTextureName(TextureList::MAP_WALL_TOP3_TEX);
		break;

	case MapChipList::WALL_UNDER1:
		map.tex_name = res.GetTextureName(TextureList::MAP_WALL_UNDER1_TEX);
		break;

	case MapChipList::WALL_UNDER2:
		map.tex_name = res.GetTextureName(TextureList::MAP_WALL_UNDER2_TEX);
		break;

	case MapChipList::WALL_UNDER3:
		map.tex_name = res.GetTextureName(TextureList::MAP_WALL_UNDER3_TEX);
		break;

	case MapChipList::CEILING_RIGTH1:
	case MapChipList::CEILING_LEFT1:
	case MapChipList::CEILING_UNDER1:
	case MapChipList::CEILING_TOP1:
		map.tex_name = res.GetTextureName(TextureList::MAP_CEILING1_TEX);
		break;

	case MapChipList::CEILING_RIGTH2:
	case MapChipList::CEILING_LEFT2:
	case MapChipList::CEILING_UNDER2:
	case MapChipList::CEILING_TOP2:
		map.tex_name = res.GetTextureName(TextureList::MAP_CEILING2_TEX);
		break;

	case MapChipList::CEILING_RIGTH3:
	case MapChipList::CEILING_LEFT3:
	case MapChipList::CEILING_UNDER3:
	case MapChipList::CEILING_TOP3:
		map.tex_name = res.GetTextureName(TextureList::MAP_CEILING3_TEX);
		break;

	case MapChipList::CEILING_CORNER_TOP_LEFT:	
	case MapChipList::CEILING_CORNER_TOP_RIGHT:
		map.tex_name = res.GetTextureName(TextureList::MAP_CEILING_CORNER1_TEX);
		break;

	case MapChipList::CEILING_CORNER_UNDER_LEFT:
	case MapChipList::CEILING_CORNER_UNDER_RIGHT:
		map.tex_name = res.GetTextureName(TextureList::MAP_CEILING_CORNER2_TEX);
		break;
	}

	return;
}*/
