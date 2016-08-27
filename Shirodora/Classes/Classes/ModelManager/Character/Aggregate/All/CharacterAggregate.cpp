//
//  CharacterAggregate.cpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/07/31.
//
//

#include "CharacterAggregate.hpp"

//=========================================================================
//
// 召喚キャラ集合
//
//=========================================================================
//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
/**
 *  @desc   コンストラクタ
 */
CCharacterAggregate::CCharacterAggregate(std::vector<CCharacter*> *pAggre) :
m_pAggregate(pAggre){}

/**
 *  @desc   デストラクタ
 */
CCharacterAggregate::~CCharacterAggregate(){}

//=========================================================================
// メンバ関数
//=========================================================================
/**
 *  @desc   開始イテレーターの取得
 *  @return
 */
std::shared_ptr<CIteratorTemplate<CCharacter*>> CCharacterAggregate::iterator(){
    return std::shared_ptr<CIteratorTemplate<CCharacter*>>(new CIteratorTemplate<CCharacter*>(this)) ;
}