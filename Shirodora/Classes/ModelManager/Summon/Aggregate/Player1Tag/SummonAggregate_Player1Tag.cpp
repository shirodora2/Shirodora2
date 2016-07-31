//
//  SummonAggregate_Player1Tag.cpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/07/31.
//
//

#include "SummonAggregate_Player1Tag.hpp"

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include "SummonIterator_Player1Tag.hpp"

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
CSummonAggregate_Player1Tag::CSummonAggregate_Player1Tag(std::vector<CSummon*> *pAggre) :
CSummonAggregate(pAggre){}

/**
 *  @desc   デストラクタ
 */
CSummonAggregate_Player1Tag::~CSummonAggregate_Player1Tag(){}

//=========================================================================
// メンバ関数
//=========================================================================
/**
 *  @desc   開始イテレーターの取得
 *  @return イテレーター
 */
std::shared_ptr<CIteratorTemplate<CSummon*>> CSummonAggregate_Player1Tag::iterator(){
    return std::shared_ptr<CIteratorTemplate<CSummon*>>(new CSummonIterator_Player1Tag(this)) ;
}