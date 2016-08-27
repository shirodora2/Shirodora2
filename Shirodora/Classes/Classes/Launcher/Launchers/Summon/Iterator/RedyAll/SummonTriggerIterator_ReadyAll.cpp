//
//  SummonTriggerIterator_ReadyAll.cpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/07/31.
//
//

#include "SummonTriggerIterator_ReadyAll.hpp"

//=========================================================================
//
// 召喚キャラトリガーで発射可能なもの全てを走査するイテレーター
//
//=========================================================================
//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
/**
 *  @desc   コンストラクタ
 */
CSummonTriggerIterator_ReadyAll::CSummonTriggerIterator_ReadyAll(IAggregateTemplate<CTriggerTemplateBase<CSummon>*> *pAggre) :
CIteratorTemplate(pAggre){}

/**
 *  @desc   デストラクタ
 */
CSummonTriggerIterator_ReadyAll::~CSummonTriggerIterator_ReadyAll(){}

//=========================================================================
// メンバ関数
//=========================================================================
/**
 *  @desc   次が存在するかどうかをチェック
 *  @return true...次がある false...次がない
 */
bool CSummonTriggerIterator_ReadyAll::hasNext(){
    // 最大数を超えていたらfalse
    if(m_pAggre->getSize() <= this->m_currentIndex) {
        return false ;
    }
    
    CTriggerTemplateBase<CSummon> *pTrigger = this->m_pAggre->getAt(this->m_currentIndex) ;
    
    if(pTrigger->isReady() == true) return true ;
    
    ++this->m_currentIndex ;
    return this->hasNext() ;
}