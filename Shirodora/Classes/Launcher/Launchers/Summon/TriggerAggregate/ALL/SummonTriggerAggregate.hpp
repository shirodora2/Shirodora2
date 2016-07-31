//
//  SummonTriggerAggregate.hpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/07/31.
//
//

#ifndef SummonTriggerAggregate_hpp
#define SummonTriggerAggregate_hpp

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
// 召喚キャラトリガー集合
//
//=========================================================================
class CSummonTriggerAggregate : public IAggregateTemplate<CTriggerTemplateBase<CSummon>*> {
public :
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
    /**
     *  @desc   コンストラクタ
     */
    CSummonTriggerAggregate(std::vector<CTriggerTemplateBase<CSummon>*> *pAggre) ;
    
    /**
     *  @desc   デストラクタ
     */
    virtual ~CSummonTriggerAggregate() ;
    
    //=========================================================================
    // get
    //=========================================================================
    /**
     *  @desc   最大サイズの取得
     */
    inline int getSize() override {return this->m_pAggregate->size() ;}
    
    /**
     *  @desc   要素の取得
     *  @param  添字番号
     */
    inline CTriggerTemplateBase<CSummon> *getAt(int index) override {return (*this->m_pAggregate)[index] ;}
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
    /**
     *  @desc   開始イテレーターの取得
     *  @return イテレーター
     */
    virtual std::shared_ptr<CIteratorTemplate<CTriggerTemplateBase<CSummon>*>> iterator() override ;
    
private :
    //=========================================================================
    // メンバ変数
    //=========================================================================
    // 集合体
    std::vector<CTriggerTemplateBase<CSummon>*> *m_pAggregate {NULL} ;
};

#endif /* SummonTriggerAggregate_hpp */
