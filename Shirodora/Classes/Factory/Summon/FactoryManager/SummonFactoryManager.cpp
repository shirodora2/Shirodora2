//
//  SummonFactoryManager.cpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/07/16.
//
//

#include "SummonFactoryManager.hpp"

#include "SummonCreateFactory.hpp"
#include "Summon.hpp"
#include "SummonTypes.hpp"

//=========================================================================
//
// EnemyUnitFactoryManager
//
//=========================================================================
//=========================================================================
// メンバ変数
//=========================================================================
/**
 *  @desc   召喚生成
 *  @param  タグ
 *  @param  SUMMON_TYPE
 *  @param  生成位置 x
 *  @param  生成位置 y
 */
CSummon *CSummonFactoryManager::create(int tag, SUMMON_TYPE type, float x, float y){
    // 敵ユニットの型を用意
    CSummon *pUnit {NULL} ;
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
CSummonFactoryManager::CSummonFactoryManager(){
    this->m_pFactories = new std::map<SUMMON_TYPE, CSummonCreateFactory*>() ;
}

/**
 *  @desc   copy constructor
 */
CSummonFactoryManager::CSummonFactoryManager(const CSummonFactoryManager &mgr){/*処理なし*/}

/**
 *  @desc   destructor
 */
CSummonFactoryManager::~CSummonFactoryManager(){
    std::map<SUMMON_TYPE, CSummonCreateFactory*>::iterator itr = this->m_pFactories->begin() ;
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
 *  @param  SUMMON_TYPE
 *  @tips   工場追加はここへ
 */
void CSummonFactoryManager::setFactory(SUMMON_TYPE type){
    CSummonCreateFactory *pFactory {NULL} ;
    switch(type){
        case SUMMON_TYPE::TEST :
            pFactory = new CSummon_Test() ;
            break;
            
        case SUMMON_TYPE::TEST2 :
            pFactory = new CPlayerSummon_Test() ;
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
 *  @param  SUMMON_TYPE
 *  @return CSummonCreateFactory*
 */
CSummonCreateFactory *CSummonFactoryManager::getFactory(SUMMON_TYPE type){
    std::map<SUMMON_TYPE, CSummonCreateFactory*>::iterator itr = this->m_pFactories->begin() ;
    while(itr != this->m_pFactories->end()){
        if(itr->first == type){
            return itr->second ;
        }
        ++itr ;
    }
    this->setFactory(type) ;
    
    return (*this->m_pFactories)[type] ;
}