//
//  SummonTriggerIterator_ReadyAll.hpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/07/31.
//
//

#ifndef SummonTriggerIterator_ReadyAll_hpp
#define SummonTriggerIterator_ReadyAll_hpp

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include "AggregateTemplate.hpp"
#include "TriggerTemplateBase.hpp"

//=========================================================================
// 前方宣言
//=========================================================================
class CSummon ;

//=========================================================================
//
// 召喚キャラトリガーで発射可能なもの全てを走査するイテレーター
//
//=========================================================================
class CSummonTriggerIterator_ReadyAll : public CIteratorTemplate<CTriggerTemplateBase<CSummon>*> {
public :
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
    /**
     *  @desc   コンストラクタ
     */
    CSummonTriggerIterator_ReadyAll(IAggregateTemplate<CTriggerTemplateBase<CSummon>*> *pAggre) ;
    
    /**
     *  @desc   デストラクタ
     */
    ~CSummonTriggerIterator_ReadyAll() ;
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
    /**
     *  @desc   次が存在するかどうかをチェック
     *  @return true...次がある false...次がない
     */
    bool hasNext() override ;
    
};

#endif /* SummonTriggerIterator_ReadyAll_hpp */
