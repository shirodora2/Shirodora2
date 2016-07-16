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

//=========================================================================
//
// EnemyUnitFactoryManager
//
//=========================================================================
//=========================================================================
// メンバ変数
//=========================================================================
/**
 *  @desc   敵ユニット生成
 *  @param  ENEMY_UNIT_TYPE
 *  @param  生成位置 x
 *  @param  生成位置 y
 */
CSummon *CEnemyUnitFactoryManager::create(SUMMON_TYPE type, float x, float y){
    // 敵ユニットの型を用意
    CSummon *pUnit {NULL} ;
    // 敵ユニットを生成
    pUnit = this->getFactory(type)->create(cocos2d::Vec2(x, y)) ;
    
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
CEnemyUnitFactoryManager::CEnemyUnitFactoryManager(){
    this->m_pFactories = new std::map<SUMMON_TYPE, CSummonCreateFactory*>() ;
}

/**
 *  @desc   copy constructor
 */
CEnemyUnitFactoryManager::CEnemyUnitFactoryManager(const CEnemyUnitFactoryManager &mgr){/*処理なし*/}

/**
 *  @desc   destructor
 */
CEnemyUnitFactoryManager::~CEnemyUnitFactoryManager(){
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
 *  @param  ENEMY_UNIT_TYPE
 *  @tips   工場追加はここへ
 */
void CEnemyUnitFactoryManager::setFactory(SUMMON_TYPE type){
    CSummonCreateFactory *pFactory {NULL} ;
    switch(type){
        case SUMMON_TYPE::TEST :
            //pFactory = new CEnemyUnit_Test() ;
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
 *  @param  ENEMY_UNIT_TYPE
 *  @return CBarrageCreateFactoryTemplate*
 */
CSummonCreateFactory *CEnemyUnitFactoryManager::getFactory(SUMMON_TYPE type){
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