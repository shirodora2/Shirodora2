//
//  SummonTriggerAggregate_ReadyAll.hpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/07/31.
//
//

#ifndef SummonTriggerAggregate_ReadyAll_hpp
#define SummonTriggerAggregate_ReadyAll_hpp

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include "SummonTriggerAggregate.hpp"

//=========================================================================
//
// 弾幕トリガーで発射可能なものの集まり
//
//=========================================================================
class CSummonTriggerAggregate_ReadyAll : public CSummonTriggerAggregate {
public :
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
    /**
     *  @desc   コンストラクタ
     */
    CSummonTriggerAggregate_ReadyAll(std::vector<CTriggerTemplateBase<CSummon>*> *pAggre) ;
    
    /**
     *  @desc   デストラクタ
     */
    ~CSummonTriggerAggregate_ReadyAll() ;
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
    /**
     *  @desc   開始イテレーターの取得
     *  @return イテレーター
     */
    std::shared_ptr<CIteratorTemplate<CTriggerTemplateBase<CSummon>*>> iterator() override ;
    
};

#endif /* SummonTriggerAggregate_ReadyAll_hpp */
