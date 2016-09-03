//
//  EnemySpawnAlgorithm_Easy.cpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/08/27.
//
//

#include "EnemySpawnAlgorithm_Easy.hpp"

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include "SummonLauncher.hpp"
#include "SummonFactoryManager.hpp"
#include "LaunchDatas.hpp"
#include "TriggerTypes.hpp"
#include "Constants.hpp"
#include "EnemySpawnAlgorithm_Base.hpp"
#include "EnemySpawnAlgorithm_Easy.hpp"
#include "CharacterManager.hpp"
#include "Character.hpp"
#include "Move.hpp"

//=========================================================================
//
//
//
//=========================================================================
//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================

CEnemySpawnAlgorithm_Easy::CEnemySpawnAlgorithm_Easy() : CEnemySpawnAlgorithm_Base(600){}

/**
 *  @desc   デストラクタ
 */
CEnemySpawnAlgorithm_Easy::~CEnemySpawnAlgorithm_Easy(){}

//=========================================================================
// メンバ関数
//=========================================================================
/**
 *  @desc   更新処理
 */
void CEnemySpawnAlgorithm_Easy::update(int time, int cost){
    ++this->m_counter ;
    // とりあえず出せるやつがあれば出すパターン
    if(this->m_waitTime <= this->m_counter){
        // 敵発射処理
        this->launchEnemy(time, cost) ;
        // カウンターの初期化
        this->m_counter = 0 ;
    }
}

/**
 *  @desc   敵のランチデータを返す
 *  @param  時間
 *  @param  コスト
 */
void CEnemySpawnAlgorithm_Easy::launchEnemy(int time, int cost){
    
    float posY = 300.0f ;
    
    std::shared_ptr<CIteratorTemplate<CCharacter*>> itr = CCharacterManager::getInstance()->iterator(CHARACTER_AGGREGATE_TYPE::PLAYER_1_KING) ;
    while(itr->hasNext() == true){
        CCharacter *pChara = itr->next() ;
        posY = pChara->getMove()->getPosition().y ;
    }
    
    // 召喚キャラ発射データを生成
    CLaunchData<CSummon> *pSummonLaunchData = new CLaunchData<CSummon>(2010, SUMMON_TYPE::TEST, 1600.0f, posY) ;
    // 召喚キャラ発射トリガーを生成
    CTrigger_Timer<CSummon> *pTrigger = new CTrigger_Timer<CSummon>(pSummonLaunchData, 0) ;
    // 発射トリガーを発射台に取り付け
    CSummonLauncher::getInstance()->add(pTrigger) ;
}