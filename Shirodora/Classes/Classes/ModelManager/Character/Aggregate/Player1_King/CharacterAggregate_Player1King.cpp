//
//  CharacterAggregate_Player1King.cpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/08/03.
//
//

#include "CharacterAggregate_Player1King.hpp"

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include "CharacterIterator_Player1King.hpp"

//=========================================================================
//
// キャラ集合_プレイヤー１キング
//
//=========================================================================
//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
/**
 *  @desc   コンストラクタ
 */
CCharacterAggregate_Player1King::CCharacterAggregate_Player1King(std::vector<CCharacter*> *pAggre) :
CCharacterAggregate(pAggre){}

/**
 *  @desc   デストラクタ
 */
CCharacterAggregate_Player1King::~CCharacterAggregate_Player1King(){}

//=========================================================================
// メンバ関数
//=========================================================================
/**
 *  @desc   開始イテレーターの取得
 *  @return イテレーター
 */
std::shared_ptr<CIteratorTemplate<CCharacter*>> CCharacterAggregate_Player1King::iterator(){
    return std::shared_ptr<CIteratorTemplate<CCharacter*>>(new CCharacterIterator_Player1King(this)) ;
}