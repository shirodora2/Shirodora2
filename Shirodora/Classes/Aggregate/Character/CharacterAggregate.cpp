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
 *  @desc   集合体への追加
 */
void CCharacterAggregate::add(CCharacter *pChara){
    this->m_pAggregate->push_back(pChara) ;
}

CCharacter *CCharacterAggregate::CCharacterAggregate::getTag(int tag){
    for(CCharacter* pChara : (*this->m_pAggregate)){
        if(pChara->getTag() == tag){
            return pChara ;
        }
    }
    return NULL ;
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