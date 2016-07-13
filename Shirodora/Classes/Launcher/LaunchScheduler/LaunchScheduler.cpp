
//
//  LaunchScheduler.cpp
//  BarrageGame
//
//  Created by Ryoutarou Onimura on 2016/07/13.
//
//

#include "LaunchScheduler.hpp"

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
void CLaunchScheduler::setLauncher(LAUNCHER_TYPE type, cocos2d::Layer *pLayer){
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
 *  @desc   update
 */
void CLaunchScheduler::update(){
    //this->m_p/**/Launcher->update() ;
}

//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
/**
 *  @desc   constructor
 */
CLaunchScheduler::CLaunchScheduler(){}

/**
 *  @desc   copy constructor
 */
CLaunchScheduler::CLaunchScheduler(const CLaunchScheduler &sch){}

/**
 *  @desc   destructor
 */
CLaunchScheduler::~CLaunchScheduler(){
    
}