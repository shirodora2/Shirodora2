//
//  Castle_Normal.cpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/08/20.
//
//

#include "Castle_Normal.hpp"

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include "Shirodora.hpp"
#include "Castle.hpp"

//=========================================================================
//
// CCastle_Normal
//
//=========================================================================
//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
/**
 *  @desc   constructor
 */
CCastle_Normal::CCastle_Normal(){
    
}

/**
 *  @desc   destructor
 */
CCastle_Normal::~CCastle_Normal(){
    
}

//=========================================================================
// メンバ関数
//=========================================================================
/**
 *  @desc   位置データ設定
 *  @param  CCastle*
 */
void CCastle_Normal::setMove(CCastle *pCastle){
    /*特になし*/
}

/**
 *  @desc   画像データ設定
 *  @param  CCastle*
 */
void CCastle_Normal::setSprite(CCastle *pCastle){
    pCastle->getSprite()->setTexture("Castle.png") ;
}

/**
 *  @desc   ステータス設定
 *  @param  CCastle*
 */
void CCastle_Normal::setStatus(CCastle *pCastle){
    pCastle->getStatus()->setStatus(100, 100, TYPE::NONE, 0, 0, 1, 30) ;
}

/**
 *  @desc   実体データ設定
 *  @param  CCastle*
 */
void CCastle_Normal::setCollisionBody(CCastle *pCastle){
    cocos2d::Vec2 apexs[4] = {
        cocos2d::Vec2(150.0f, 300.0f),
        cocos2d::Vec2(-150.0f, 300.0f),
        cocos2d::Vec2(-150.0f, -300.0f),
        cocos2d::Vec2(150.0f, -300.0f)
    };
    
    pCastle->getCollisionBody()->setApexs(4, apexs) ;
}

/**
 *  @desc   攻撃範囲データ設定
 *  @param  CCastle*
 */
void CCastle_Normal::setAttackBody(CCastle *pCastle){
    /*攻撃範囲はない*/
}

/**
 *  @desc   アニメーションデータ設定
 *  @param  CCastle*
 */
void CCastle_Normal::setAnimation(CCastle *pCastle){
    CChipNotAnimation *pAnime = new CChipNotAnimation() ;
    pAnime->addChipData(new CChip(0.0f, 0.0f, 500.0f, 600.0f)) ;
    pCastle->getAnimations()->push_back(pAnime) ;
}

/**
 *  @desc   アクションデータ設定
 *  @param  CCastle*
 */
void CCastle_Normal::setAction(CCastle *pCastle){
    /*アクションはない*/
}

