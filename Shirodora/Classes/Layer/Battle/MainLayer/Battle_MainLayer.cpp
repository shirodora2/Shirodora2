//
//  GameMainLayer.cpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/07/03.
//
//

#include "Battle_MainLayer.hpp"

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include "Constants.hpp"
#include "Manager.hpp"

//=========================================================================
//
// GameMainLayer
//
//=========================================================================
//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
/**
 *  @desc   constructor
 */
CBattele_MainLayer::CBattele_MainLayer(){}

/**
 *  @desc   destructor
 */
CBattele_MainLayer::~CBattele_MainLayer(){
    
}

//=========================================================================
// init
//=========================================================================
/**
 *  @desc   init
 */
bool CBattele_MainLayer::init(){
    if(CInputAndMouseLayer::init() == false) return false ;
    
    // !!!:テスト用背景
    cocos2d::Sprite *pBackGround = cocos2d::Sprite::create("gameMainBG.png") ;
    pBackGround->setPosition(WINDOW_WIDTH * 0.5f, WINDOW_HEIGHT * 0.5f) ;
    this->addChild(pBackGround) ;
    
    // !!!:テスト用カーソルスプライト
    this->m_pCursor = cocos2d::Sprite::create("Bone.png") ;
    this->m_pCursor->setColor(cocos2d::Color3B::MAGENTA) ;
    this->m_pCursor->setPosition(WINDOW_WIDTH * 0.5f, WINDOW_HEIGHT * 0.5f) ;
    this->addChild(this->m_pCursor) ;
    
    // スケジューラーに登録
    this->scheduleUpdate() ;
    
    return true ;
}

//=========================================================================
// set
//=========================================================================

//=========================================================================
// get
//=========================================================================

//=========================================================================
// メンバ関数
//=========================================================================
/**
 *  @desc   update
 *  @param  微小時間
 */
void CBattele_MainLayer::update(float deltaTime){
    this->m_pCursor->setPosition(mouse.getCurrentCursorPosition()) ;
}