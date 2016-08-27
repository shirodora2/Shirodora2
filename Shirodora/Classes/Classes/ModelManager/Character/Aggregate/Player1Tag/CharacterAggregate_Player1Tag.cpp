//
//  CharacterAggregate_Player1Tag.cpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/07/31.
//
//

#include "CharacterAggregate_Player1Tag.hpp"

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include "CharacterIterator_Player1Tag.hpp"

//=========================================================================
//
// 召喚キャラ集合_プレイヤー１
//
//=========================================================================
//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
/**
 *  @desc   コンストラクタ
 */
CCharacterAggregate_Player1Tag::CCharacterAggregate_Player1Tag(std::vector<CCharacter*> *pAggre) :
CCharacterAggregate(pAggre){}

/**
 *  @desc   デストラクタ
 */
CCharacterAggregate_Player1Tag::~CCharacterAggregate_Player1Tag(){}

//=========================================================================
// メンバ関数
//=========================================================================
/**
 *  @desc   開始イテレーターの取得
 *  @return イテレーター
 */
std::shared_ptr<CIteratorTemplate<CCharacter*>> CCharacterAggregate_Player1Tag::iterator(){
    return std::shared_ptr<CIteratorTemplate<CCharacter*>>(new CCharacterIterator_Player1Tag(this)) ;
}