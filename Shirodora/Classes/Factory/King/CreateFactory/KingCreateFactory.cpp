//
//  CreateFactory.cpp
//  Shirodora
//
//  Created by 服部優宇一 on 2016/08/20.
//
//

#include "Shirodora.hpp"


//=========================================================================
//
// KingCreateFactory
//
//=========================================================================
//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
/**
 *  @desc   destructor
 */
CKingCreateFactory::~CKingCreateFactory(){}

//=========================================================================
// メンバ関数
//=========================================================================
/**
 *  @desc   キング生成
 *  @desc   タグ
 *  @param  生成位置
 */
CKing *CKingCreateFactory::create(int tag, const cocos2d::Vec2 &position){
    // カーソルの型を用意
    CKing *pKing {NULL} ;
    // メンバ変数を生成したカーソルを受け取る
    pKing = this->create() ;
    
    // メンバ変数の設定
    this->setMove(pKing, position) ;
    this->setSprite(pKing) ;
    this->setStatus(pKing) ;
    this->setCollisionBody(pKing) ;
    this->setAttackBody(pKing) ;
    this->setAnimation(pKing) ;
    this->setAction(pKing) ;
    this->setTag(pKing, tag) ;
    
    // 設定したデータを反映させる
    pKing->apply() ;
    
    return  pKing ;
}

/**
 *  @desc   キング生成とメンバ変数取り付け
 */
CKing *CKingCreateFactory::create(){
    // 召喚の型を用意
    CKing *pKing {NULL} ;
    // 召喚生成
    pKing = CCREATE_FUNC::create<CKing>() ;
    
    // メンバ変数の生成
    pKing->setMove(new CMove()) ;
    pKing->setSprite(cocos2d::Sprite::create()) ;
    pKing->setStatus(new CStatusOfCharacter()) ;
    pKing->setCollisionBody(new CBody()) ;
    pKing->setAttackBody(new CBody()) ;
    pKing->setAnimations(new std::vector<CAnimation*>()) ;
    pKing->setActions(new std::vector<CAction*>()) ;
    
    return pKing ;
}