//
//  CastleFactoryManager.cpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/08/20.
//
//

#include "CastleFactoryManager.hpp"

#include "CastleCreateFactory.hpp"
#include "Castle.hpp"
#include "Castle_Normal.hpp"

//=========================================================================
//
// CCastleFactoryManager
//
//=========================================================================
//=========================================================================
// メンバ変数
//=========================================================================
/**
 *  @desc   召喚生成
 *  @param  タグ
 *  @param  生成位置 x
 *  @param  生成位置 y
 */
CCastle *CCastleFactoryManager::create(int tag, float x, float y){
    // 城を用意
    CCastle *pCastle {NULL} ;
    // 城を生成
    pCastle = this->m_pFactory->create(tag, cocos2d::Vec2(x, y)) ;
    
    // デコレーターを使う際にはここで装飾
    
    // スケージューラーに登録
    pCastle->scheduleUpdate() ;
    
    return pCastle ;
}

//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
/**
 *  @desc   constructor
 */
CCastleFactoryManager::CCastleFactoryManager(){
    this->m_pFactory = new CCastle_Normal() ;
}

/**
 *  @desc   copy constructor
 */
CCastleFactoryManager::CCastleFactoryManager(const CCastleFactoryManager &mgr){/*処理なし*/}

/**
 *  @desc   destructor
 */
CCastleFactoryManager::~CCastleFactoryManager(){
    if(this->m_pFactory != NULL){
        delete this->m_pFactory ;
        this->m_pFactory = NULL ;
    }
}

//=========================================================================
// set
//=========================================================================


//=========================================================================
// get
//=========================================================================
