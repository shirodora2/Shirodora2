//
//  EnemySpawner.cpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/08/27.
//
//

#include "EnemySpawner.hpp"

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include "SummonFactoryManager.hpp"
#include "SummonLauncher.hpp"
#include "LaunchDatas.hpp"
#include "TriggerTypes.hpp"
#include "Constants.hpp"
#include "EnemySpawnAlgorithm_Base.hpp"
#include "EnemySpawnAlgorithm_Easy.hpp"

//=========================================================================
//
// 敵生成機
//
//=========================================================================
//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
/**
 *  @desc   コンストラクタ
 */
CEnemySpawner::CEnemySpawner(AI_LEVEL level){
    // TODO: - - - - - - - - - - - - 変更予定 - - - - - - - - - - - - - - - - -
    // 外部でステートパターン
    // レベルによって生成するアルゴリズムを変更
    switch(level){
        case AI_LEVEL::EASY :
            this->m_pAlgorithm = new CEnemySpawnAlgorithm_Easy() ;
            break ;
        default :
            break ;
    }
}

/**
 *  @desc   デストラクタ
 */
CEnemySpawner::~CEnemySpawner(){
    if(this->m_pAlgorithm != NULL){
        delete this->m_pAlgorithm ;
        this->m_pAlgorithm = NULL ;
    }
}

//=========================================================================
// メンバ関数
//=========================================================================
/**
 *  @desc   更新処理
 *  @param  微小時間
 */
void CEnemySpawner::update(){
    // 時間更新
    ++this->m_time ;
    // FIXME:- - - - - - - - - - - - 修正予定 - - - - - - - - - - - - - - - - -
    // コスト回復とかあればここで
    
    this->m_pAlgorithm->update(this->m_time, this->m_cost) ;
}