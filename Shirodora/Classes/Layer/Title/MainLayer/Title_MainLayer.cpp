//
//  Title_MainLayer.cpp
//  Shirodora
//
//  Created by 今西一喜 on 2016/08/13.
//
//

#include "Title_MainLayer.hpp"
#include "InputManager.hpp"
#include "BattleScene.hpp"
#include "Constants.hpp"

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
CTitle_MainLayer::CTitle_MainLayer(){}

/**
 *  @desc   destructor
 */
CTitle_MainLayer::~CTitle_MainLayer(){}

//=========================================================================
// init
//=========================================================================
/**
 *  @desc   init
 */
bool CTitle_MainLayer::init(){
    if(CInputLayer::init() == false) return false ;
    
    // タイトル背景
    cocos2d::Sprite *pBackGround = cocos2d::Sprite::create("BackGround_Left.png");
    pBackGround->setPosition(500.0f,300.0f);
    this->addChild(pBackGround);
    
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
void CTitle_MainLayer::update(float deltaTime){
    
    this->inputFunc();
}

/**
 *  @desc   入力処理
 */
void CTitle_MainLayer::inputFunc(){
    
    if(inputflag.m_z.isPressed() == true){
        CCLOG("タイトルでzキー押した : MAIN");
        cocos2d::Scene* pScene = CCREATE_FUNC::create<CBattleScene>();
        cocos2d::Director::getInstance()->replaceScene(pScene);
    }
    
}



