//
//  CharacterAggregate_Player2Tag.cpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/07/31.
//
//

#include "CharacterAggregate_Player2Tag.hpp"

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include "CharacterIterator_Player2Tag.hpp"

//=========================================================================
//
// 召喚キャラ集合_プレイヤー２
//
//=========================================================================
//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
/**
 *  @desc   コンストラクタ
 */
CCharacterAggregate_Player2Tag::CCharacterAggregate_Player2Tag(std::vector<CCharacter*> *pAggre) :
CCharacterAggregate(pAggre){}

/**
 *  @desc   デストラクタ
 */
CCharacterAggregate_Player2Tag::~CCharacterAggregate_Player2Tag(){}

//=========================================================================
// メンバ関数
//=========================================================================
/**
 *  @desc   開始イテレーターの取得
 *  @return イテレーター
 */
std::shared_ptr<CIteratorTemplate<CCharacter*>> CCharacterAggregate_Player2Tag::iterator(){
    return std::shared_ptr<CIteratorTemplate<CCharacter*>>(new CCharacterIterator_Player2Tag(this)) ;
}