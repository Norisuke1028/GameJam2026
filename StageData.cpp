#include "StageData.h"

#include "Utility/ResourceManager.h"
#include "DxLib.h"

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

StageData* StageData::instance = nullptr;

void StageData::Load()
{
	//ファイルを開く(.csv)
	FILE* fp = NULL;
	std::string file_name = "Resource/stage/StageMap.csv";
	//指定したファイルを開く
	errno_t result = fopen_s(&fp, file_name.c_str(), "r");

	// エラーチェック
	if (result != 0)
	{
		throw (file_name + "が開けません");
	}

	//横１行全部入るように
	char buffer[435];


	int y = 0;
	ResourceManager* rm = ResourceManager::GetInstance();

	//fgetsでファイルから１行抜き出す
	while (fgets(buffer, sizeof(buffer), fp) != NULL)
	{

		int x = 0;   //x座標(列番号)

		//1行のデータを1文字ずつ処理したい
		for (char* p = buffer; *p != '\0'; ++p)
		{
			const float block_size = 32.0f;
			if (*p == ',')
			{
				continue;
			}
			if (*p == '\n')
			{
				break;
			}

			Vector2D generate_location = Vector2D((float)x, (float)y) * block_size;
			//対象の文字があるか確認
			//夜空
			//if (*p == 'y')
			//{
			//	//対象の文字があれば「２次元座標」と「画像情報」を覚える
			//	int image_sora = rm->GetImages("Resource/image/Block/sky.png").at(0);
			//	DrawGraph((int)generate_location.x + velocity.x, (int)generate_location.y, image_sora, TRUE);
			//}

			//土
			if (*p == 't')
			{
				//対象の文字があれば「２次元座標」と「画像情報」を覚える
				int image_soil = rm->GetImages("Resource/image/Block/soil.png").at(0);
				DrawGraph((int)generate_location.x + velocity.x, (int)generate_location.y, image_soil, TRUE);
			}
			//雪
			if (*p == 's')
			{
				//対象の文字があれば「２次元座標」と「画像情報」を覚える
				int image_snow = rm->GetImages("Resource/image/Block/snow.png").at(0);
				DrawGraph((int)generate_location.x + velocity.x, (int)generate_location.y, image_snow, TRUE);
			}

			//雪だるま
			if (*p == 'm')
			{
				//対象の文字があれば「２次元座標」と「画像情報」を覚える
				int image_snowman = rm->GetImages("Resource/image/snowman.png").at(0);
				DrawGraph((int)generate_location.x + velocity.x, (int)generate_location.y, image_snowman, TRUE);
			}

			//街並み
			if (*p == 'c')
			{
				//対象の文字があれば「２次元座標」と「画像情報」を覚える
				int image_city = rm->GetImages("Resource/image/city.png").at(0);
				DrawGraph((int)generate_location.x + velocity.x, (int)generate_location.y, image_city, TRUE);
			}



			//次の列
			x++;

		}

		//次の行
		y++;

	}


	//ファイルを閉じる
	fclose(fp);
}

StageData* StageData::GetInstance()
{
    if (instance == nullptr)
    {
        instance = new StageData();
    }
    return instance;
}


StageData::~StageData()
{

}

void StageData::Initialize()
{
	s_location = 0;
}

void StageData::Update()
{
	s_location += velocity.x;
}

void StageData::Draw(const Vector2D& screen_offset) const
{
	DrawFormatString(120, 140, GetColor(255, 255, 0), "%d",location);
}

void StageData::Finalize()
{

}
float StageData::GetLocation()const
{
	return s_location;
}

Vector2D StageData::GetVelocity()
{
	return velocity;
}

void StageData::SetVelocity(float velo)
{
	velocity.x -= velo;
}