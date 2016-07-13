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
    // 発射スケジュールの生成
    this->m_pLaunchSchedule = new std::vector<CLaunchTrigger<Ty>*>() ;
    // 発射先のレイヤーのポインタを受け取る
    this->m_pLayer = pLayer ;
}

/**
 *  @desc   destructor
 */
template<typename Ty>
CLauncher<Ty>::~CLauncher(){
    // イテレーターを回してスケジューラーに残されているトリガーがあれば解放する
    typename std::vector<CLaunchTrigger<Ty>*>::iterator itr = this->m_pLaunchSchedule->begin() ;
    while(itr != this->m_pLaunchSchedule->end()){
        if(*itr != NULL){
            delete *itr ;
            *itr = NULL ;
        }
        ++itr ;
    }
    // スケジューラーの解放
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
    // スケジューラーに取り付けられているもので発射可能なものを発射する
    for(CLaunchTrigger<Ty> *pTrigger : (*this->m_pLaunchSchedule)){
        // 発射できるものか調べる
        if(pTrigger->isReady() == true ){
            Ty *pTy {NULL} ;
            // 発射されるものを受け取り
            pTy = pTrigger->launch() ;
            // 取り付け先であるレイヤーに貼り付ける
            this->m_pLayer->addChild(pTy) ;
        }
    }
    // 発射完了したものを解放する
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
