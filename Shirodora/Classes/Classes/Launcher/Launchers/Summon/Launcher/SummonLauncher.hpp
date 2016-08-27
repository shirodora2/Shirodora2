//
//  SummonLauncher.hpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/07/31.
//
//

#ifndef SummonLauncher_hpp
#define SummonLauncher_hpp

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include "SingletonTemplate.hpp"
#include "AggregateTemplate.hpp"
#include "TriggerTemplateBase.hpp"

//=========================================================================
// 前方宣言
//=========================================================================
class CSummon ;
class CSummonTriggerAggregate ;

//=========================================================================
// 集合体種類
//=========================================================================
enum class SUMMON_TRIGGER_AGGREGATE_TYPE {
    NONE        = -1,
    ALL,
    READY_ALL,
    MAX
};

//=========================================================================
//
// 召喚キャラ発射台
//
//=========================================================================
class CSummonLauncher : public CSingletonTemplate<CSummonLauncher> {
public :
    //=========================================================================
    // get
    //=========================================================================
    /**
     *  @desc   iteratorの取得
     *  @param  欲しいiterator集合体の種類
     *  @return iterator
     */
    std::shared_ptr<CIteratorTemplate<CTriggerTemplateBase<CSummon>*>> iterator(SUMMON_TRIGGER_AGGREGATE_TYPE type) ;
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
    /**
     *  @desc   発射したものを取り付けるレイヤーの設定
     *  @param  レイヤー
     */
    inline void setLayer(cocos2d::Layer *pLayer){this->m_pLayer = pLayer ;}
    
    /**
     *  @desc   トリガーの追加
     *  @param  トリガー
     */
    void add(CTriggerTemplateBase<CSummon> *pChara) ;
    
    /**
     *  @desc   clear
     */
    void clear() ;
    
    /**
     *  @desc   update
     */
    void update() ;
    
private :
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
    friend class CSingletonTemplate<CSummonLauncher> ;
    /**
     *  @desc   コンストラクタ
     */
    CSummonLauncher() ;
    
    /**
     *  @desc   コピーコンストラクタ
     */
    CSummonLauncher(const CSummonLauncher &lnc) ;
    
    /**
     *  @desc   デストラクタ
     */
    ~CSummonLauncher() ;
    
    //=========================================================================
    // set
    //=========================================================================
    /**
     *  @desc   集合体設定
     *  @param  集合体の種類
     */
    void setAggregate(SUMMON_TRIGGER_AGGREGATE_TYPE type) ;
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
    /**
     *  @desc   トリガーの発射
     */
    void launch() ;
    
    /**
     *  @desc   発射し終わったものをスケジュールから取り外す
     */
    void erase() ;
    
    //=========================================================================
    // メンバ変数
    //=========================================================================
    // 発射したものをとりつけるレイヤー
    cocos2d::Layer *m_pLayer {NULL} ;
    // 集合体群
    CSummonTriggerAggregate *m_pAggregates[(int)SUMMON_TRIGGER_AGGREGATE_TYPE::MAX] {NULL} ;
    // トリガー集合体
    std::vector<CTriggerTemplateBase<CSummon>*> *m_pTriggers {NULL} ;
};

#endif /* SummonLauncher_hpp */
