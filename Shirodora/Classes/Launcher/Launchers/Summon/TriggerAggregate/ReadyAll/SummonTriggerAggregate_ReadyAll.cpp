//
//  SummonTriggerAggregate_ReadyAll.cpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/07/31.
//
//

#include "SummonTriggerAggregate_ReadyAll.hpp"

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include "SummonTriggerIterator_ReadyAll.hpp"

//=========================================================================
//
// 弾幕トリガーで発射可能なものの集まり
//
//=========================================================================
//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
/**
 *  @desc   コンストラクタ
 */
CSummonTriggerAggregate_ReadyAll::CSummonTriggerAggregate_ReadyAll(std::vector<CTriggerTemplateBase<CSummon>*> *pAggre) :
CSummonTriggerAggregate(pAggre){}

/**
 *  @desc   デストラクタ
 */
CSummonTriggerAggregate_ReadyAll::~CSummonTriggerAggregate_ReadyAll(){}

//=========================================================================
// メンバ関数
//=========================================================================
/**
 *  @desc   開始イテレーターの取得
 *  @return イテレーター
 */
std::shared_ptr<CIteratorTemplate<CTriggerTemplateBase<CSummon>*>> CSummonTriggerAggregate_ReadyAll::iterator(){
    return std::shared_ptr<CIteratorTemplate<CTriggerTemplateBase<CSummon>*>>(new CSummonTriggerIterator_ReadyAll(this)) ;
}