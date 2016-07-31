//
//  SummonAggregate_Player2Tag.cpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/07/31.
//
//

#include "SummonAggregate_Player2Tag.hpp"

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include "SummonIterator_Player2Tag.hpp"

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
CSummonAggregate_Player2Tag::CSummonAggregate_Player2Tag(std::vector<CSummon*> *pAggre) :
CSummonAggregate(pAggre){}

/**
 *  @desc   デストラクタ
 */
CSummonAggregate_Player2Tag::~CSummonAggregate_Player2Tag(){}

//=========================================================================
// メンバ関数
//=========================================================================
/**
 *  @desc   開始イテレーターの取得
 *  @return イテレーター
 */
std::shared_ptr<CIteratorTemplate<CSummon*>> CSummonAggregate_Player2Tag::iterator(){
    return std::shared_ptr<CIteratorTemplate<CSummon*>>(new CSummonIterator_Player2Tag(this)) ;
}