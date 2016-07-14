//
//  Launcher.cpp
//  BarrageGame
//
//  Created by Ryoutarou Onimura on 2016/07/13.
//
//

#include "Launcher.hpp"

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include "LaunchTrigger.hpp"
#include "LauncherManager.hpp"

//=========================================================================
//
// Launcher
//
//=========================================================================
//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
/**
 *  @desc   constructor
 */
template<typename Ty>
CLauncher<Ty>::CLauncher(cocos2d::Layer *pLayer) : m_pLayer(pLayer){
    // スケジューラーを生成する
    this->m_pLaunchSchedule = new std::vector<CLaunchTrigger<Ty>*>() ;
}

/**
 *  @desc   destructor
 */
template<typename Ty>
CLauncher<Ty>::~CLauncher(){
    // イテレーターを回してスケジューラーに残っているトリガーを解放
    typename std::vector<CLaunchTrigger<Ty>*>::iterator itr = this->m_pLaunchSchedule->begin() ;
    while(itr != this->m_pLaunchSchedule->end()){
        if(*itr != NULL){
            delete *itr ;
            *itr = NULL ;
        }
        ++itr ;
    }
    // スケジューラーを解放
    if(this->m_pLaunchSchedule != NULL){
        if(this->m_pLaunchSchedule != NULL){
            delete this->m_pLaunchSchedule ;
            this->m_pLaunchSchedule = NULL ;
        }
    }
}

/**
 *  @desc   update
 */
template<typename Ty>
void CLauncher<Ty>::update(){
    // トリガーの発射
    this->launch() ;
    // 発射したトリガーをスケジューラーから外す
    this->erase() ;
}

/**
 *  @desc   発射し終わったものをスケジュールから取り外す
 */
template<typename Ty>
void  CLauncher<Ty>::erase(){
    typename std::vector<CLaunchTrigger<Ty>*>::iterator itr = this->m_pLaunchSchedule->begin() ;
    while(itr != this->m_pLaunchSchedule->end()){
        if((*itr)->isLaunched() == true){
            delete *itr ;
            *itr = NULL ;
            this->m_pLaunchSchedule->erase(itr) ;
        }
        else{
            ++itr ;
        }
    }
}
