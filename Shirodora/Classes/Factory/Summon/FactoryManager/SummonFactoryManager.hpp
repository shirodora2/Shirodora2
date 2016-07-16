//
//  SummonFactoryManager.hpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/07/16.
//
//

#ifndef SummonFactoryManager_hpp
#define SummonFactoryManager_hpp

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include "SingletonTemplate.hpp"

//=========================================================================
// 前方宣言
//=========================================================================
class CSummon ;
class CSummonCreateFactory ;

//=========================================================================
// BARRAGE_TYPE
//=========================================================================
enum class SUMMON_TYPE {
    NONE        = -1,
    TEST,
    MAX
};

//=========================================================================
//
// SummonFactoryManager
//
//=========================================================================
class CSummonFactoryManager : public CSingletonTemplate<CSummonFactoryManager> {
    public :
    //=========================================================================
    // メンバ変数
    //=========================================================================
    /**
     *  @desc   召喚生成
     *  @param  SUMMON_TYPE
     *  @param  生成位置 x
     *  @param  生成位置 y
     */
    CSummon *create(SUMMON_TYPE type, float x, float y) ;
    
private :
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
    friend class CSingletonTemplate<CSummonFactoryManager> ;
    
    /**
     *  @desc   constructor
     */
    CSummonFactoryManager() ;
    
    /**
     *  @desc   copy constructor
     */
    CSummonFactoryManager(const CSummonFactoryManager &mgr) ;
    
    /**
     *  @desc   destructor
     */
    ~CSummonFactoryManager() ;
    
    //=========================================================================
    // set
    //=========================================================================
    /**
     *  @desc   工場設定
     *  @param  SUMMON_TYPE
     */
    void setFactory(SUMMON_TYPE type) ;
    
    //=========================================================================
    // get
    //=========================================================================
    /**
     *  @desc   工場取得
     *  @param  SUMMON_TYPE
     *  @return CSummonCreateFactory*
     */
    CSummonCreateFactory *getFactory(SUMMON_TYPE type) ;
    
    //=========================================================================
    // メンバ変数
    //=========================================================================
    // カーソル生成工場
    std::map<SUMMON_TYPE, CSummonCreateFactory*> *m_pFactories {NULL} ;
    
};

#endif /* SummonFactoryManager_hpp */
