//
//  SummonAggregate.cpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/07/31.
//
//

#include "SummonAggregate.hpp"

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
CSummonAggregate::CSummonAggregate(std::vector<CSummon*> *pAggre) :
m_pAggregate(pAggre){}

/**
 *  @desc   デストラクタ
 */
CSummonAggregate::~CSummonAggregate(){}

//=========================================================================
// メンバ関数
//=========================================================================
/**
 *  @desc   開始イテレーターの取得
 *  @return
 */
std::shared_ptr<CIteratorTemplate<CSummon*>> CSummonAggregate::iterator(){
    return std::shared_ptr<CIteratorTemplate<CSummon*>>(new CIteratorTemplate<CSummon*>(this)) ;
}