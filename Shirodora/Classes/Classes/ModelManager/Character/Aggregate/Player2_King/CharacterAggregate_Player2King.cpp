//
//  CharacterAggregate_Player2King.cpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/08/03.
//
//

#include "CharacterAggregate_Player2King.hpp"

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include "CharacterIterator_Player2King.hpp"

//=========================================================================
//
// キャラ集合_プレイヤー２キング
//
//=========================================================================
//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
/**
 *  @desc   コンストラクタ
 */
CCharacterAggregate_Player2King::CCharacterAggregate_Player2King(std::vector<CCharacter*> *pAggre) :
CCharacterAggregate(pAggre){}

/**
 *  @desc   デストラクタ
 */
CCharacterAggregate_Player2King::~CCharacterAggregate_Player2King(){}

//=========================================================================
// メンバ関数
//=========================================================================
/**
 *  @desc   開始イテレーターの取得
 *  @return イテレーター
 */
std::shared_ptr<CIteratorTemplate<CCharacter*>> CCharacterAggregate_Player2King::iterator(){
    return std::shared_ptr<CIteratorTemplate<CCharacter*>>(new CCharacterIterator_Player2King(this)) ;
}