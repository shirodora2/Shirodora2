//
//  FactoryManager.cpp
//  Shirodora
//
//  Created by 服部優宇一 on 2016/08/20.
//
//

#include "Shirodora.hpp"


//=========================================================================
//
// KingUnitFactoryManager
//
//=========================================================================
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
CKing *CKingFactoryManager::create(int tag, KING_TYPE type, float x, float y){
    // 敵ユニットの型を用意
    CKing *pUnit {NULL} ;
    // 敵ユニットを生成
    pUnit = this->getFactory(type)->create(tag, cocos2d::Vec2(x, y)) ;
    
    // デコレーターを使う際にはここで装飾
    
    // スケージューラーに登録
    pUnit->scheduleUpdate() ;
    
    return pUnit ;
}

//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
/**
 *  @desc   constructor
 */
CKingFactoryManager::CKingFactoryManager(){
    this->m_pFactories = new std::map<KING_TYPE, CKingCreateFactory*>() ;
}

/**
 *  @desc   copy constructor
 */
CKingFactoryManager::CKingFactoryManager(const CKingFactoryManager &mgr){/*処理なし*/}

/**
 *  @desc   destructor
 */
CKingFactoryManager::~CKingFactoryManager(){
    std::map<KING_TYPE, CKingCreateFactory*>::iterator itr = this->m_pFactories->begin() ;
    while(itr != this->m_pFactories->end()){
        if(itr->second != NULL){
            delete itr->second ;
            itr->second = NULL ;
        }
        itr++ ;
    }
    if(this->m_pFactories != NULL){
        delete this->m_pFactories ;
        this->m_pFactories = NULL ;
    }
}

//=========================================================================
// set
//=========================================================================
/**
 *  @desc   工場設定
 *  @param  KING_TYPE
 *  @tips   工場追加はここへ
 */
void CKingFactoryManager::setFactory(KING_TYPE type){
    CKingCreateFactory *pFactory {NULL} ;
    switch(type){
        case KING_TYPE::TEST :
            pFactory = new CKing_Test() ;
            break;
            
        default:
            break;
    }
    (*this->m_pFactories)[type] = pFactory ;
}

//=========================================================================
// get
//=========================================================================
/**
 *  @desc   工場取得
 *  @param  KING_TYPE
 *  @return CKingCreateFactory*
 */
CKingCreateFactory *CKingFactoryManager::getFactory(KING_TYPE type){
    std::map<KING_TYPE, CKingCreateFactory*>::iterator itr = this->m_pFactories->begin() ;
    while(itr != this->m_pFactories->end()){
        if(itr->first == type){
            return itr->second ;
        }
        ++itr ;
    }
    this->setFactory(type) ;
    
    return (*this->m_pFactories)[type] ;
}