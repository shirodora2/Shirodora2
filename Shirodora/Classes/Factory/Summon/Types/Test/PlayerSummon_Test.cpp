//
//  PlayerSummon_Test.cpp
//  Shirodora
//
//  Created by 服部優宇一 on 2016/08/27.
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
CPlayerSummon_Test::CPlayerSummon_Test(){}

/**
 *  @desc   destructor
 */
CPlayerSummon_Test::~CPlayerSummon_Test(){}

//=========================================================================
// メンバ関数
//=========================================================================
/**
 *  @desc   位置データ設定
 *  @param  CSummon*
 */
void CPlayerSummon_Test::setMove(CSummon *pSummon , const cocos2d::Vec2 &position){
    pSummon->getMove()->setPosition(position) ;
}

/**
 *  @desc   画像データ設定
 *  @param  CSummon*
 */
void CPlayerSummon_Test::setSprite(CSummon *pSummon){
    pSummon->getSprite()->setTexture("Soldier.png") ;
}

/**
 *  @desc   ステータス設定
 *  @param  CSummon*
 */
void CPlayerSummon_Test::setStatus(CSummon *pSummon){
    pSummon->getStatus()->setStatus(100, 100, TYPE::NONE, 0, 5, 1, 30) ;
}

/**
 *  @desc   実体データ設定
 *  @param  CSummon*
 */
void CPlayerSummon_Test::setCollisionBody(CSummon *pSummon){
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
void CPlayerSummon_Test::setAttackBody(CSummon *pSummon){
    pSummon->setAttackPosition(cocos2d::Vec2(64.0f, 0.0f)) ;
    
    //頂点座標
    cocos2d::Vec2 apexs[4] = {
        cocos2d::Vec2(0.0f, 64.0f),  //左上
        cocos2d::Vec2(0.0f, -64.0f), //左下
        cocos2d::Vec2(64.0f, 64.0f), //右上
        cocos2d::Vec2(64.0f, -64.0f) //右下
    };
    
    //中心座標
    pSummon->getAttackBody()->setCenterPosition(cocos2d::Vec2(32.0f, 0.0f));
    
    pSummon->getAttackBody()->setApexs(4, apexs) ;
}

/**
 *  @desc   アニメーションデータ設定
 *  @param  CSummon*
 */
void CPlayerSummon_Test::setAnimation(CSummon *pSummon){
    CChipAnimation *pAnime = new CChipAnimation(20,4,true) ;
    pAnime->addChipData(new CChip(0.0f, 0.0f, 64.0f, 64.0f)) ;
    pSummon->getAnimations()->push_back(pAnime) ;
    
    CChipAnimation *pAnime2 = new CChipAnimation(20, 4, true) ;
    pAnime2->addChipData(new CChip(0.0f, 128.0f, 64.0f, 64.0f)) ;
    pSummon->getAnimations()->push_back(pAnime2) ;
    
    CChipAnimation *pAnime3 = new CChipAnimation(20,4,true) ;
    pAnime3->addChipData(new CChip(0.0f, 0.0f, 64.0f, 64.0f)) ;
    pSummon->getAnimations()->push_back(pAnime3) ;
}

/**
 *  @desc   アクションデータ設定
 *  @param  CSummon*
 */
void CPlayerSummon_Test::setAction(CSummon *pSummon){
    pSummon->getActions()->push_back(new CSimpleAttackAction(60, CHARACTER_AGGREGATE_TYPE::PLAYER_2)) ;
    pSummon->getActions()->push_back(new CMoveAction(cocos2d::Vec2(1.0f,0.0f), 1)) ;

}

/**
 *  @desc   タグ設定
 *  @param  タグNo
 */
void CPlayerSummon_Test::setTag(CSummon *pSummon, int tag){
    pSummon->setPlayerTag(tag) ;
}
