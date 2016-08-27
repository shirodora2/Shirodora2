//
//  Summon_Test.cpp
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
 *  @desc   constructor
 */
CSummon_Test::CSummon_Test(){}

/**
 *  @desc   destructor
 */
CSummon_Test::~CSummon_Test(){}

//=========================================================================
// メンバ関数
//=========================================================================
/**
 *  @desc   位置データ設定
 *  @param  CSummon*
 */
void CSummon_Test::setMove(CSummon *pSummon , const cocos2d::Vec2 &position){
    pSummon->getMove()->setPosition(position) ;
}

/**
 *  @desc   画像データ設定
 *  @param  CSummon*
 */
void CSummon_Test::setSprite(CSummon *pSummon){
    pSummon->getSprite()->setTexture("TestMoveSprite.png") ;
}

/**
 *  @desc   ステータス設定
 *  @param  CSummon*
 */
void CSummon_Test::setStatus(CSummon *pSummon){
    pSummon->getStatus()->setStatus(100, 100, TYPE::NONE, 0, 10, 1, 30) ;
}

/**
 *  @desc   実体データ設定
 *  @param  CSummon*
 */
void CSummon_Test::setCollisionBody(CSummon *pSummon){
    cocos2d::Vec2 apexs[4] = {
        cocos2d::Vec2(32.0f, 32.0f),
        cocos2d::Vec2(-32.0f, 32.0f),
        cocos2d::Vec2(-32.0f, -32.0f),
        cocos2d::Vec2(32.0f, -32.0f)
    };
    
    pSummon->getCollisionBody()->setApexs(4, apexs) ;
}

/**
 *  @desc   攻撃範囲データ設定
 *  @param  CSummon*
 */
void CSummon_Test::setAttackBody(CSummon *pSummon){
    pSummon->setAttackPosition(cocos2d::Vec2(64.0f, 0.0f)) ;
    
    //頂点座標
    cocos2d::Vec2 apexs[4] = {
        cocos2d::Vec2(0.0f, 64.0f),  //左上
        cocos2d::Vec2(0.0f, -64.0f), //左下
        cocos2d::Vec2(-64.0f, 64.0f), //右上
        cocos2d::Vec2(-64.0f, -64.0f) //右下
    };
    
    //中心座標
    pSummon->getAttackBody()->setCenterPosition(cocos2d::Vec2(32.0f, 0.0f));
    
    pSummon->getAttackBody()->setApexs(4, apexs) ;
}

/**
 *  @desc   アニメーションデータ設定
 *  @param  CSummon*
 */
void CSummon_Test::setAnimation(CSummon *pSummon){
    CChipNotAnimation *pAnime = new CChipNotAnimation() ;
    pAnime->addChipData(new CChip(0.0f, 0.0f, 64.0f, 64.0f)) ;
    pSummon->getAnimations()->push_back(pAnime) ;
}

/**
 *  @desc   アクションデータ設定
 *  @param  CSummon*
 */
void CSummon_Test::setAction(CSummon *pSummon){
    pSummon->getActions()->push_back(new CSimpleAttackAction(60, CHARACTER_AGGREGATE_TYPE::PLAYER_1)) ;
}

/**
 *  @desc   タグ設定
 *  @param  タグNo
 */
void CSummon_Test::setTag(CSummon *pSummon, int tag){
    pSummon->setPlayerTag(tag) ;
}