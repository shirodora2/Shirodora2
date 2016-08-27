//
//  Character.cpp
//  BarrageGame
//
//  Created by Ryoutarou Onimura on 2016/07/08.
//
//

#include "Shirodora.hpp"

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
    // ステータスデータ解放
    if(this->m_pStatus != NULL){
        delete this->m_pStatus ;
        this->m_pStatus = NULL ;
    }
    // 実態データ解放
    if(this->m_pCollisionBody != NULL){
        delete this->m_pCollisionBody ;
        this->m_pCollisionBody = NULL ;
    }
    // 攻撃範囲データ解放
    if(this->m_pAttackBody != NULL){
        delete this->m_pAttackBody ;
        this->m_pAttackBody = NULL ;
    }
    // アニメーションデータ群解放
    std::vector<CAnimation*>::iterator animItr = this->m_pAnimations->begin() ;
    while(animItr != this->m_pAnimations->end()){
        if(*animItr != NULL){
            delete *animItr ;
            *animItr = NULL ;
        }
        ++animItr ;
    }
    if(this->m_pAnimations != NULL){
        delete this->m_pAnimations ;
        this->m_pAnimations = NULL ;
    }
    // アクションデータ群解放
    std::vector<CAction*>::iterator ActItr = this->m_pActions->begin() ;
    while(ActItr != this->m_pActions->end()){
        if(*ActItr != NULL){
            delete *ActItr ;
            *ActItr = NULL ;
        }
        ++ActItr ;
    }
    if(this->m_pAnimations != NULL){
        delete this->m_pAnimations ;
        this->m_pAnimations = NULL ;
    }
}