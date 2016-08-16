//
//  End_MainLayer.cpp
//  Shirodora
//
//  Created by 今西一喜 on 2016/08/16.
//
//

#include "End_MainLayer.hpp"
#include "TitleScene.hpp"
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
CEnd_MainLayer::CEnd_MainLayer(){}

/**
 *  @desc   destructor
 */
CEnd_MainLayer::~CEnd_MainLayer(){}

//=========================================================================
// init
//=========================================================================
/**
 *  @desc   init
 */
bool CEnd_MainLayer::init(){
    if(CInputLayer::init() == false) return false ;
    
    
    
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
void CEnd_MainLayer::update(float deltaTime){
    
    this->inputFunc();
}

/**
 *  @desc   入力処理
 */
void CEnd_MainLayer::inputFunc(){
    
    if(inputflag.m_z.isPressed() == true){
        CCLOG("タイトルでzキー押した : MAIN");
        cocos2d::Scene* pScene = CCREATE_FUNC::create<CTitleScene>();
        cocos2d::Director::getInstance()->replaceScene(pScene);
    }
    
}
