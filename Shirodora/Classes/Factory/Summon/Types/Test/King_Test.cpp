//
//  King_Test.cpp
//  Shirodora
//
//  Created by 服部優宇一 on 2016/08/20.
//
//

#include "Shirodora.hpp"
#include "King_Test.hpp"

//=========================================================================
//
// KingCreateFactory
//
//=========================================================================
//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
/**
 *  @desc   constructor
 */
CKing_Test::CKing_Test(){}

/**
 *  @desc   destructor
 */
CKing_Test::~CKing_Test(){}

//=========================================================================
// メンバ関数
//=========================================================================
/**
 *  @desc   位置データ設定
 *  @param  CKing*
 */
void CKing_Test::setMove(CKing *pKing , const cocos2d::Vec2 &position){
    pKing->getMove()->setPosition(position) ;
}

/**
 *  @desc   画像データ設定
 *  @param  CKing*
 */
void CKing_Test::setSprite(CKing *pKing){
    pKing->getSprite()->setTexture("TestMoveSprite.png") ;
}

/**
 *  @desc   ステータス設定
 *  @param  CKing*
 */
void CKing_Test::setStatus(CKing *pKing){
    pKing->getStatus()->setStatus(100, 100, TYPE::NONE, 10) ;
}

/**
 *  @desc   実体データ設定
 *  @param  CKing*
 */
void CKing_Test::setCollisionBody(CKing *pKing){
    cocos2d::Vec2 apexs[4] = {
        cocos2d::Vec2(32.0f, 32.0f),
        cocos2d::Vec2(-32.0f, 32.0f),
        cocos2d::Vec2(-32.0f, -32.0f),
        cocos2d::Vec2(32.0f, -32.0f)
    };
    
    pKing->getCollisionBody()->setApexs(4, apexs) ;
}

/**
 *  @desc   攻撃範囲データ設定
 *  @param  CKing*
 */
void CKing_Test::setAttackBody(CKing *pKing){
    pKing->setAttackPosition(cocos2d::Vec2(64.0f, 0.0f)) ;
    
    cocos2d::Vec2 apexs[4] = {
        cocos2d::Vec2(32.0f, 32.0f),
        cocos2d::Vec2(-32.0f, 32.0f),
        cocos2d::Vec2(-32.0f, -32.0f),
        cocos2d::Vec2(32.0f, -32.0f)
    };
    
    pKing->getCollisionBody()->setApexs(4, apexs) ;
}

/**
 *  @desc   アニメーションデータ設定
 *  @param  CKing*
 */
void CKing_Test::setAnimation(CKing *pKing){
    CChipNotAnimation *pAnime = new CChipNotAnimation() ;
    pAnime->addChipData(new CChip(0.0f, 0.0f, 64.0f, 64.0f)) ;
    pKing->getAnimations()->push_back(pAnime) ;
}

/**
 *  @desc   アクションデータ設定
 *  @param  CKing*
 */
void CKing_Test::setAction(CKing *pKing){
    
}

/**
 *  @desc   タグ設定
 *  @param  タグNo
 */
void CKing_Test::setTag(CKing *pKing, int tag){
    pKing->setPlayerTag(tag) ;
}
