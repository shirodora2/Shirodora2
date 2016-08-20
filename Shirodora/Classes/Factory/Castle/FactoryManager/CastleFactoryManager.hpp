//
//  CastleFactoryManager.hpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/08/20.
//
//

#ifndef CastleFactoryManager_hpp
#define CastleFactoryManager_hpp

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include "SingletonTemplate.hpp"

//=========================================================================
// 前方宣言
//=========================================================================
class CCastle ;
class CCastleCreateFactory ;

//=========================================================================
//
// CCastleFactoryManager
//
//=========================================================================
class CCastleFactoryManager : public CSingletonTemplate<CCastleFactoryManager> {
public :
    //=========================================================================
    // メンバ変数
    //=========================================================================
    /**
     *  @desc   城生成
     *  @param  タグ
     *  @param  生成位置 x
     *  @param  生成位置 y
     */
    CCastle *create(int tag, float x, float y) ;
    
private :
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
    friend class CSingletonTemplate<CCastleFactoryManager> ;
    
    /**
     *  @desc   constructor
     */
    CCastleFactoryManager() ;
    
    /**
     *  @desc   copy constructor
     */
    CCastleFactoryManager(const CCastleFactoryManager &mgr) ;
    
    /**
     *  @desc   destructor
     */
    ~CCastleFactoryManager() ;
    
    //=========================================================================
    // メンバ変数
    //=========================================================================
    // 城生成工場
    CCastleCreateFactory *m_pFactory {NULL} ;
    
};

#endif /* CastleFactoryManager_hpp */
