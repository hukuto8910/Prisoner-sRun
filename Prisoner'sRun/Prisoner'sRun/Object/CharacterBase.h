#pragma once

#include"ObjectBase.h"


// キャラクターの基底クラス
class CharacterBase :public ObjectBase {
public:
	CharacterBase() {
		m_animation_count = 0;
	}
	virtual ~CharacterBase() {}

	/*
	・アニメーション回す関数
	・死亡判定
	*/

	// アニメーション画像の更新
	/*
	第1：1コマのアニメーション描画速度
	第2：アニメーション初期化時の画像番号
		・デフォルトは0で指定しない限りは画像の1枚目に戻る
		・指定がある場合は、画像が回り切った後、指定の画像で初期化される
	*/
	void AnimationCount(int anim_speed, int anim_num = 0) {

		if (m_animation_count > anim_speed) {
			m_animation_num++;
			m_animation_count = 0;
			if (m_animation_num >= m_animation_tex_num) {
				m_animation_num = 0;
			}
		}
		else {
			m_animation_count++;
		}
	}

protected:
	float m_speed;	// 移動速度

	int m_animation_num;		// アニメーション番号
	int m_animation_count;		// アニメーション更新用カウント
	int m_animation_tex_num;	// アニメーション画像の数
	int m_animation_speed;		// アニメーション1コマの速度
};
