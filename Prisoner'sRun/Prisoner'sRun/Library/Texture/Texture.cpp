#include<unordered_map>
#include"Texture.h"



	static std::unordered_map <std::string, Texture>tex_list;	// 画像保存リスト

	// 変換コンストラクタ
	Texture::Texture(const char* fileName) :Texture() {

		// ファイル名が空の場合は即時returnする
		if (fileName == nullptr || *fileName == '\0') {
			return;
		}

		auto itr = tex_list.find(fileName);

		// まだ読み込まれていない場合
		if (itr == tex_list.end()) {

			name = fileName;

			// ファイル情報を取得
			D3DXIMAGE_INFO info;
			if (SUCCEEDED(D3DXGetImageInfoFromFile(fileName, &info))) {

				size.x = (float)info.Width;
				size.y = (float)info.Height;

				// テクスチャの読み込み
				D3DXCreateTextureFromFile(Device::dev, fileName, &tex);
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
	Texture::Texture(const Texture&t) :tex(t), size(t.size) {

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

	void Texture::Relese() {

		for (auto list = tex_list.begin(); list != tex_list.end();) {

			if (&list != nullptr) {
				list = tex_list.erase(list);
			}
			else {
				list++;
			}
		}
	}
