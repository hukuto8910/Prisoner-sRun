#include"Texture.h"
#include"Device.h"


// 変換コンストラクタ
Texture::Texture(const char* file_name) :Texture() { // : Texture() 自身のデフォルトコンストラクタを呼び出している
	// ファイル名が空の場合は即時returnする
	if (file_name == nullptr || *file_name == '\0') {
		return;
	}

	auto itr = tex_list.find(file_name);
	// まだ読み込まれていない場合
	if (itr == tex_list.end()) { // endは末尾まで　itrは探してくれてる人
		// ファイル名を記録
		name = file_name;

		// ファイル情報を取得
		D3DXIMAGE_INFO info;
		if (SUCCEEDED(D3DXGetImageInfoFromFile(file_name, &info))) {
			size.x = (float)info.Width;
			size.y = (float)info.Height;

			// テクスチャの読み込み
			D3DXCreateTextureFromFile(Device::dev, file_name, &tex);
			// テクスチャの登録
			tex_list.emplace(name, *this); // nameとthis(自身)を照らし合わせる
		}
		else {
			MessageBox(NULL, "画像読み込み失敗", "", MB_OK);
		}
	}
	// すでに読み込まれていた場合
	else {
		tex = itr->second.tex;
		if (tex) {
			// 参照カウント インクリメント
			tex->AddRef();
		}
		// fastがアドレス、secondが中身
		size = itr->second.size;
		name = itr->second.name;
	}
}

// コピーコンストラクタ
Texture::Texture(const Texture&t) :tex(nullptr), size(t.size) {
	if (tex) {
		tex->AddRef();
	}
}

// デストラクタ
Texture::~Texture() {
	if (tex) {
		tex->Release();
	}
}

// 
Texture& Texture::operator=(const Texture& t) {
	if (tex) {
		tex->Release();
	}
	tex = t.tex;
	if (tex) {
		tex->AddRef();
	}
	size = t.size;
	name = t.name;
	return *this;
}
