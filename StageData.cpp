#include "StageData.h"

#include "Utility/ResourceManager.h"
#include "Objects/Enemy/Enemy.h"
#include "Objects/Item/Item.h"
#include "Objects/Block/Block.h"
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
	enemy_spawn_positions.clear();  //エネミーの出現位置初期化
	item_spwn_positions.clear();  //アイテムの出現位置初期化
    block_spawn_positions.clear();
	ResourceManager* rm = ResourceManager::GetInstance();

	//fgetsでファイルから１行抜き出す
	while (fgets(buffer, sizeof(buffer), fp) != NULL)
	{

		int x = 0;   //x座標(列番号)

        // 1行のデータを1文字ずつ処理
        for (char* p = buffer; *p != '\0'; ++p)
        {
            if (*p == '\n')
            {
                break;
            }

            // カンマは「区切り」なのでスキップするが、xは進めない
            if (*p == ',')
            {
                continue;
            }

            const float block_size = 32.0f;
            Vector2D generate_location = Vector2D((float)x, (float)y) * block_size;

            // 土
            if (*p == 't')
            {
                Vector2D pos;
                pos.x = x * block_size;
                pos.y = y * block_size;
                // ブロックのタイプと位置を渡す
                block_spawn_positions.push_back({ pos, BlockType::Soil });
            }

            // 雪
            if (*p == 's')
            {
                Vector2D pos;
                pos.x = x * block_size;
                pos.y = y * block_size;
                // ブロックのタイプと位置を渡す
                block_spawn_positions.push_back({ pos, BlockType::Snow });
            }

            // 雪だるま
            if (*p == 'm')
            {
                int image_snowman = rm->GetImages("Resource/image/snowman.png").at(0);
                DrawGraph((int)generate_location.x + velocity.x,
                    (int)generate_location.y,
                    image_snowman,
                    TRUE);
            }

            // 街並み
            if (*p == 'c')
            {
                int image_city = rm->GetImages("Resource/image/city.png").at(0);
                DrawGraph((int)generate_location.x + velocity.x,
                    (int)generate_location.y,
                    image_city,
                    TRUE);
            }

            // 枯れ木
            if (*p == 'k')
            {
                int image_tree = rm->GetImages("Resource/image/tree1.png").at(0);
                DrawGraph((int)generate_location.x + velocity.x,
                    (int)generate_location.y,
                    image_tree,
                    TRUE);
            }

            // エネミー
            if (*p == 'e')
            {
                Vector2D pos;
                pos.x = x * block_size;
                pos.y = y * block_size;
                // エネミーの位置を渡す
                enemy_spawn_positions.push_back(pos);
            }

            //アイテム
            if (*p == 'k')
            {
				Vector2D pos;
				pos.x = x * block_size;
				pos.y = y * block_size;
				// アイテムの位置を渡す
				item_spwn_positions.push_back(pos);
            }
            // 1セル処理したら必ず次の列へ
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

void StageData::Update(float delta_second)
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
// エネミーのスポーン位置取得
const std::vector<Vector2D>& StageData::GetEnemySpawnPositions() const
{
	return enemy_spawn_positions;
}

// アイテムのスポーン位置取得
const std::vector<Vector2D>& StageData::GetItemSpawnPositions() const
{
    return item_spwn_positions;
}

// ブロック（足場）のスポーン位置取得
const std::vector<BlockSpawnData>& StageData::GetBlockSpawnPositions() const
{
    return block_spawn_positions;
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