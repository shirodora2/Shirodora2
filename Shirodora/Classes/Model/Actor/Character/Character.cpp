//
//  Character.cpp
//  BarrageGame
//
//  Created by Ryoutarou Onimura on 2016/07/08.
//
//

#include "Character.hpp"

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include "Manager.hpp"
#include "Animation.hpp"
#include "Body.hpp"
#include "Move.hpp"

//=========================================================================
//
// Character
//
//=========================================================================
//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
/**
 *  @desc   constructor
 */
CCharacter::CCharacter(){/*処理なし*/}

/**
 *  @desc   destructor
 */
CCharacter::~CCharacter(){
    // 位置データ解放
    if(this->m_pMove != NULL){
        delete this->m_pMove ;
        this->m_pMove = NULL ;
    }
    // アニメーションデータ群解放
    std::vector<CAnimation*>::iterator itr = this->m_pAnimations->begin() ;
    while(itr != this->m_pAnimations->end()){
        if(*itr != NULL){
            delete *itr ;
            *itr = NULL ;
        }
        ++itr ;
    }
    if(this->m_pAnimations != NULL){
        delete this->m_pAnimations ;
        this->m_pAnimations = NULL ;
    }
}