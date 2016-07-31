//
//  SummonManager.hpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/07/31.
//
//

#ifndef SummonManager_hpp
#define SummonManager_hpp

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include "SingletonTemplate.hpp"
#include "AggregateTemplate.hpp"

//=========================================================================
// 前方宣言
//=========================================================================
class CSummon ;
class CSummonAggregate ;

enum class SUMMON_AGGREGATE_TYPE {
    NONE        = -1,
    ALL,
    PLAYER_1,
    PLAYER_2,
    MAX
};

//=========================================================================
//
// 召喚キャラ管理
//
//=========================================================================
class CSummonManager : public CSingletonTemplate<CSummonManager> {
public :
    //=========================================================================
    // get
    //=========================================================================
    /**
     *  @desc   iteratorの取得
     *  @param  欲しいiterator集合体の種類
     *  @return iterator
     */
    std::shared_ptr<CIteratorTemplate<CSummon*>> iterator(SUMMON_AGGREGATE_TYPE type) ;
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
    /**
     *  @desc   召喚キャラの追加
     *  @param  CSummon*
     */
    void add(CSummon *pChara) ;
    
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
    friend class CSingletonTemplate<CSummonManager> ;
    /**
     *  @desc   コンストラクタ
     */
    CSummonManager() ;
    
    /**
     *  @desc   コピーコンストラクタ
     */
    CSummonManager(const CSummonManager &mgr) ;
    
    /**
     *  @desc   デストラクタ
     */
    ~CSummonManager() ;
    
    //=========================================================================
    // set
    //=========================================================================
    /**
     *  @desc   集合体設定
     *  @param  集合体の種類
     */
    void setAggregate(SUMMON_AGGREGATE_TYPE type) ;
    
    //=========================================================================
    // メンバ変数
    //=========================================================================
    // 集合体群
    CSummonAggregate *m_pAggregates[(int)SUMMON_AGGREGATE_TYPE::MAX] {NULL} ;
    // キャラクター群
    std::vector<CSummon*> *m_pCharacters {NULL} ;
};

#endif /* SummonManager_hpp */
