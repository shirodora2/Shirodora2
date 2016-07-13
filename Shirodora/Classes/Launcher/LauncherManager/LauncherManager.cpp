
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
        case LAUNCHER_TYPE::NONE :
            //if(this->m_p/**/Launcher == NULL) this->m_p/**/Launcher = new CLauncher</**/>(pLayer) ;
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
}

/**
 *  @desc   update
 */
void CLauncherManager::update(){
    //this->m_p/**/Launcher->update() ;
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
}