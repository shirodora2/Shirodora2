//
//  SummonTriggerAggregate.cpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/07/31.
//
//

#include "SummonTriggerAggregate.hpp"

//=========================================================================
//
// 召喚キャラトリガー集合
//
//=========================================================================
//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
/**
 *  @desc   コンストラクタ
 */
CSummonTriggerAggregate::CSummonTriggerAggregate(std::vector<CTriggerTemplateBase<CSummon>*> *pAggre) :
m_pAggregate(pAggre){}

/**
 *  @desc   デストラクタ
 */
CSummonTriggerAggregate::~CSummonTriggerAggregate(){}

//=========================================================================
// メンバ関数
//=========================================================================
/**
 *  @desc   開始イテレーターの取得
 *  @return
 */
std::shared_ptr<CIteratorTemplate<CTriggerTemplateBase<CSummon>*>> CSummonTriggerAggregate::iterator(){
    return std::shared_ptr<CIteratorTemplate<CTriggerTemplateBase<CSummon>*>>(new CIteratorTemplate<CTriggerTemplateBase<CSummon>*>(this)) ;
}