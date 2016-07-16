//
//  SummonCreateFactory.cpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/07/16.
//
//

#include "SummonCreateFactory.hpp"

//=========================================================================
// 前方宣言
//=========================================================================
#include "Constants.hpp"
#include "Summon.hpp"
#include "Move.hpp"
#include "Body.hpp"

//=========================================================================
//
// EnemyUnitCreateFactory
//
//=========================================================================
//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
/**
 *  @desc   destructor
 */
CSummonCreateFactory::~CSummonCreateFactory(){}

//=========================================================================
// メンバ関数
//=========================================================================
/**
 *  @desc   カーソル生成
 *  @param  生成位置
 */
CSummon *CSummonCreateFactory::create(const cocos2d::Vec2 &position){
    // カーソルの型を用意
    CSummon *pUnit {NULL} ;
    // メンバ変数を生成したカーソルを受け取る
    pUnit = this->create() ;
    
    // メンバ変数の設定
    this->setMove(pUnit, position) ;
    this->setSprite(pUnit) ;
    this->setStatus(pUnit) ;
    this->setCollisionBody(pUnit) ;
    this->setAnimation(pUnit) ;
    this->setAction(pUnit) ;
    
    // 設定したデータを反映させる
    pUnit->apply() ;
    
    return  pUnit ;
}

/**
 *  @desc   カーソル生成とメンバ変数取り付け
 */
CSummon *CSummonCreateFactory::create(){
    // カーソルの型を用意
    CSummon *pUnit {NULL} ;
    // カーソル生成
    pUnit = CCREATE_FUNC::create<CSummon>() ;
    
    // メンバ変数の生成
    pUnit->setMove(new CMove()) ;
    pUnit->setSprite(cocos2d::Sprite::create()) ;
    //pUnit->setStatus(new CUnitStatus()) ;
    pUnit->setCollisionBody(new CBody()) ;
    pUnit->setAnimations(new std::vector<CAnimation*>()) ;
    //pUnit->setActions(new std::vector<CAction<CEnemyUnit>*>()) ;
    
    return pUnit ;
}