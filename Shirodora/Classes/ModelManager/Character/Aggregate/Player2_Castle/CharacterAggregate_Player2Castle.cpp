//
//  CharacterAggregate_Player2Castle.cpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/08/20.
//
//

#include "CharacterAggregate_Player2Castle.hpp"

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include "CharacterIterator_Player2Castle.hpp"

//=========================================================================
//
// キャラ集合_プレイヤー２城
//
//=========================================================================
//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
/**
 *  @desc   コンストラクタ
 */
CCharacterAggregate_Player2Castle::CCharacterAggregate_Player2Castle(std::vector<CCharacter*> *pAggre) :
CCharacterAggregate(pAggre){}

/**
 *  @desc   デストラクタ
 */
CCharacterAggregate_Player2Castle::~CCharacterAggregate_Player2Castle(){}

//=========================================================================
// メンバ関数
//=========================================================================
/**
 *  @desc   開始イテレーターの取得
 *  @return イテレーター
 */
std::shared_ptr<CIteratorTemplate<CCharacter*>> CCharacterAggregate_Player2Castle::iterator(){
    return std::shared_ptr<CIteratorTemplate<CCharacter*>>(new CCharacterIterator_Player2Castle(this)) ;
}