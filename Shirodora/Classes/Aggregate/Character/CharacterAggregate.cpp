//
//  CharacterAggregate.cpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/07/15.
//
//

#include "CharacterAggregate.hpp"

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include "Character.hpp"

//=========================================================================
//
// CharacterAggregate
//
//=========================================================================
//=========================================================================
// メンバ関数
//=========================================================================
/**
 *  @desc   clear
 */
void CCharacterAggregate::clear(){
    this->m_pAggregate->erase(this->m_pAggregate->begin(), this->m_pAggregate->end()) ;
}

/**
 *  @desc   update
 */
void CCharacterAggregate::update(){
    std::vector<CCharacter*>::iterator itr = this->m_pAggregate->begin() ;
    while(itr != this->m_pAggregate->end()){
        if((*itr)->isActive() == false){
            (*itr)->removeFromParent() ;
            this->m_pAggregate->erase(itr) ;
        }
        else{
            ++itr ;
        }
    }
}

/**
 *  @desc   集合体への追加
 */
void CCharacterAggregate::add(CCharacter *pChara){
    this->m_pAggregate->push_back(pChara) ;
}

//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
/**
 *  @desc   constructor
 */
CCharacterAggregate::CCharacterAggregate(){
    this->m_pAggregate = new std::vector<CCharacter*>() ;
}

/**
 *  @desc   copy constructor
 */
CCharacterAggregate::CCharacterAggregate(const CCharacterAggregate &aggre){}

/**
 *  @desc   destructor
 */
CCharacterAggregate::~CCharacterAggregate(){
    std::vector<CCharacter*>::iterator itr = this->m_pAggregate->begin() ;
    while(itr != this->m_pAggregate->end()){
        if(*itr != NULL){
            delete *itr ;
            *itr = NULL ;
        }
        ++itr ;
    }
    if(this->m_pAggregate != NULL){
        delete this->m_pAggregate ;
        this->m_pAggregate = NULL ;
    }
}