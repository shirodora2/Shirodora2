
//
//  LauncherManager.cpp
//  BarrageGame
//
//  Created by Ryoutarou Onimura on 2016/07/13.
//
//

#include "LauncherManager.hpp"

//=========================================================================
// 追加のインクルードはここから
//=========================================================================

//=========================================================================
//
// LaunchScheduler
//
//=========================================================================
//=========================================================================
// set
//=========================================================================
/**
 *  @desc   発射台設定
 */
void CLauncherManager::setLauncher(LAUNCHER_TYPE type, cocos2d::Layer *pLayer){
    switch(type){
        case LAUNCHER_TYPE::SUMMON :
            if(this->m_pSummonLauncher == NULL) this->m_pSummonLauncher = new CSummonLauncher(pLayer) ;
            break;
            
        default:
            break;
    }
}

//=========================================================================
// メンバ関数
//=========================================================================
/**
 *  @desc   clear
 */
void CLauncherManager::clear(){
    // 設置した砲台を解放して初期化する
    if(this->m_pSummonLauncher != NULL){
        delete this->m_pSummonLauncher ;
        this->m_pSummonLauncher = NULL ;
    }
}

/**
 *  @desc   update
 */
void CLauncherManager::update(){
    // 発射台の更新処理
    this->m_pSummonLauncher->update() ;
}

//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
/**
 *  @desc   constructor
 */
CLauncherManager::CLauncherManager(){/*処理なし*/}

/**
 *  @desc   copy constructor
 */
CLauncherManager::CLauncherManager(const CLauncherManager &mgr){/*処理なし*/}

/**
 *  @desc   destructor
 */
CLauncherManager::~CLauncherManager(){
    // 設置した砲台を解放する
    // 設置した砲台を解放して初期化する
    if(this->m_pSummonLauncher != NULL){
        delete this->m_pSummonLauncher ;
        this->m_pSummonLauncher = NULL ;
    }
}