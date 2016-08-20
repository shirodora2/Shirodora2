//
//  SummonCreateFactory.cpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/07/16.
//
//

#include "Shirodora.hpp"

//=========================================================================
//
// SummonCreateFactory
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
 *  @desc   召喚生成
 *  @desc   タグ
 *  @param  生成位置
 */
CSummon *CSummonCreateFactory::create(int tag, const cocos2d::Vec2 &position){
    // カーソルの型を用意
    CSummon *pSummon {NULL} ;
    // メンバ変数を生成したカーソルを受け取る
    pSummon = this->create() ;
    
    // メンバ変数の設定
    this->setMove(pSummon, position) ;
    this->setSprite(pSummon) ;
    this->setStatus(pSummon) ;
    this->setCollisionBody(pSummon) ;
    this->setAttackBody(pSummon) ;
    this->setAnimation(pSummon) ;
    this->setAction(pSummon) ;
    this->setTag(pSummon, tag) ;
    
    // 設定したデータを反映させる
    pSummon->apply() ;
    
    return  pSummon ;
}

/**
 *  @desc   召喚生成とメンバ変数取り付け
 */
CSummon *CSummonCreateFactory::create(){
    // 召喚の型を用意
    CSummon *pSummon {NULL} ;
    // 召喚生成
    pSummon = CCREATE_FUNC::create<CSummon>() ;
    
    // メンバ変数の生成
    pSummon->setMove(new CMove()) ;
    pSummon->setSprite(cocos2d::Sprite::create()) ;
    pSummon->setStatus(new CStatusOfCharacter()) ;
    pSummon->setCollisionBody(new CBody()) ;
    pSummon->setAttackBody(new CBody()) ;
    pSummon->setAnimations(new std::vector<CAnimation*>()) ;
    pSummon->setActions(new std::vector<CAction*>()) ;
    
    return pSummon ;
}