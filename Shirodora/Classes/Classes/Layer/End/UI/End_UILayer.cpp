//
//  End_UILayer.cpp
//  Shirodora
//
//  Created by 今西一喜 on 2016/08/16.
//
//

#include "End_UILayer.hpp"
#include "InputManager.hpp"


//======================================================
//
// タイトルUIクラス
//
//======================================================
//コンストラクタ
CEnd_UILayer::CEnd_UILayer(){
}
//デストラクタ
CEnd_UILayer::~CEnd_UILayer(){
}

//初期化
bool CEnd_UILayer::init(){
    if(!Layer::init())return false;
    
    scheduleUpdate();
    
    return true;
}


//更新処理
void CEnd_UILayer::update(float _dt){
    
    this->inputFunc();
}

/**
 *  @desc   入力処理
 */
void CEnd_UILayer::inputFunc(){
    
    //*****別のinputFunc間で同時に同じ入力情報は取得できない************
    //if(inputflag.m_z.isPressed() == true){
    if(inputflag.m_a.isPressed() == true){
        CCLOG("タイトルでaキー押した : UI");
    }
}

