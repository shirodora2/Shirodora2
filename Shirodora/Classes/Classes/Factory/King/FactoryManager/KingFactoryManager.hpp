//
//  FactoryManager.hpp
//  Shirodora
//
//  Created by 服部優宇一 on 2016/08/20.
//
//

#ifndef KingFactoryManager_hpp
#define KingFactoryManager_hpp

#include <stdio.h>

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include "SingletonTemplate.hpp"

//=========================================================================
// 前方宣言
//=========================================================================
class CKing ;
class CKingCreateFactory ;

//=========================================================================
// KING_TYPE
//=========================================================================
enum class KING_TYPE {
    NONE        = -1,
    TEST,
    MAX
};

//=========================================================================
//
// KingFactoryManager
//
//=========================================================================
class CKingFactoryManager : public CSingletonTemplate<CKingFactoryManager> {
    public :
    //=========================================================================
    // メンバ変数
    //=========================================================================
    /**
     *  @desc   キング生成
     *  @param  タグ
     *  @param  KING_TYPE
     *  @param  生成位置 x
     *  @param  生成位置 y
     */
    CKing *create(int tag, KING_TYPE type, float x, float y) ;
    
    private :
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
    friend class CSingletonTemplate<CKingFactoryManager> ;
    
    /**
     *  @desc   constructor
     */
    CKingFactoryManager() ;
    
    /**
     *  @desc   copy constructor
     */
    CKingFactoryManager(const CKingFactoryManager &mgr) ;
    
    /**
     *  @desc   destructor
     */
    ~CKingFactoryManager() ;
    
    //=========================================================================
    // set
    //=========================================================================
    /**
     *  @desc   工場設定
     *  @param  KING_TYPE
     */
    void setFactory(KING_TYPE type) ;
    
    //=========================================================================
    // get
    //=========================================================================
    /**
     *  @desc   工場取得
     *  @param  KING_TYPE
     *  @return CKingCreateFactory*
     */
    CKingCreateFactory *getFactory(KING_TYPE type) ;
    
    //=========================================================================
    // メンバ変数
    //=========================================================================
    // カーソル生成工場
    std::map<KING_TYPE, CKingCreateFactory*> *m_pFactories {NULL} ;
    
};


#endif /* KingFactoryManager_hpp */
