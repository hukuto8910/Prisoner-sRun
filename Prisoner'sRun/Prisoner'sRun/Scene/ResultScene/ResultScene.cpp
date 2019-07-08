#include"ResultScene.h"


Result::Result() {

	m_scene = SceneId::RESULT;
	m_scene_step = SceneStep::SCENE_INIT;
}

void Result::Init() {
	m_scene_step = SceneStep::SCENE_UPDATE;
}

void Result::Update() {
	/*
	BadEndとHappyEndがあるので、
	フラグでクリアリザルトとゲームオーバーリザルトを変える
	（変更するのはサウンドとテクスチャのみで遷移、描画方法は同一）
	*/
}

void Result::Draw() {

}
