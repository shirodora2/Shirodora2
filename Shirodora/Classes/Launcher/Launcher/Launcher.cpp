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
CLauncher<Ty>::CLauncher(cocos2d::Layer *pLayer){
    this->m_pLaunchSchedule = new std::vector<CLaunchTrigger<Ty>*>() ;
    this->m_pLayer = pLayer ;
}

/**
 *  @desc   destructor
 */
template<typename Ty>
CLauncher<Ty>::~CLauncher(){
    typename std::vector<CLaunchTrigger<Ty>*>::iterator itr = this->m_pLaunchSchedule->begin() ;
    while(itr != this->m_pLaunchSchedule->end()){
        if(*itr != NULL){
            delete *itr ;
            *itr = NULL ;
        }
        ++itr ;
    }
    if(this->m_pLaunchSchedule != NULL){
        if(this->m_pLaunchSchedule != NULL){
            delete this->m_pLaunchSchedule ;
            this->m_pLaunchSchedule = NULL ;
        }
    }
}

//=========================================================================
// メンバ関数
//=========================================================================
/**
 *  @desc   update
 */
template<typename Ty>
void CLauncher<Ty>::update(){
    // 発射可能なものを発射する
    for(CLaunchTrigger<Ty> *pTrigger : (*this->m_pLaunchSchedule)){
        if(pTrigger->isReady() == true ){
            Ty *pTy {NULL} ;
            pTy = pTrigger->launch() ;
            this->m_pLayer->addChild(pTy) ;
        }
    }
    // 発射したものを取り外す
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

// テンプレートの明示的インスタンス化
//template class CLauncher</**/> ;
