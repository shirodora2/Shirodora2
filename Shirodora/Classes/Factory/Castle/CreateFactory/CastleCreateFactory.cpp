//
//  CastleCreateFactory.cpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/08/20.
//
//

#include "CastleCreateFactory.hpp"
#include "Shirodora.hpp"
#include "Castle.hpp"

//=========================================================================
//
// CCastleCreateFactory
//
//=========================================================================
//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
/**
 *  @desc   destructor
 */
CCastleCreateFactory::~CCastleCreateFactory(){}

//=========================================================================
// メンバ関数
//=========================================================================
/**
 *  @desc   召喚生成
 *  @desc   タグ
 *  @param  生成位置
 */
CCastle *CCastleCreateFactory::create(int tag, const cocos2d::Vec2 &position){
    // カーソルの型を用意
    CCastle *pCastle {NULL} ;
    // メンバ変数を生成したカーソルを受け取る
    pCastle = this->create() ;
    
    // プレイヤータグと位置の設定
    pCastle->setPlayerTag(tag) ;
    pCastle->getMove()->setPosition(position) ;
    
    // メンバ変数の設定
    this->setMove(pCastle) ;
    this->setSprite(pCastle) ;
    this->setStatus(pCastle) ;
    this->setCollisionBody(pCastle) ;
    this->setAttackBody(pCastle) ;
    this->setAnimation(pCastle) ;
    this->setAction(pCastle) ;
    
    // 位置データを反映
    pCastle->getSprite()->setPosition(pCastle->getMove()->getPosition()) ;
    
    // 設定したデータを反映させる
    pCastle->apply() ;
    
    return  pCastle ;
}

/**
 *  @desc   召喚生成とメンバ変数取り付け
 */
CCastle *CCastleCreateFactory::create(){
    // 召喚の型を用意
    CCastle *pCastle {NULL} ;
    // 召喚生成
    pCastle = CCREATE_FUNC::create<CCastle>() ;
    
    // メンバ変数の生成
    pCastle->setMove(new CMove()) ;
    pCastle->setSprite(cocos2d::Sprite::create()) ;
    pCastle->setStatus(new CStatusOfCharacter()) ;
    pCastle->setCollisionBody(new CBody()) ;
    pCastle->setAttackBody(new CBody()) ;
    pCastle->setAnimations(new std::vector<CAnimation*>()) ;
    pCastle->setActions(new std::vector<CAction*>()) ;
    
    return pCastle ;
}