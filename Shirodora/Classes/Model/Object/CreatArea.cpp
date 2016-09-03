//
//  CreatArea.cpp
//  Shirodora
//
//  Created by 今西一喜 on 2016/09/03.
//
//

#include "CreatArea.hpp"

//===================================================
// 背景クラス
//===================================================
//コンストラクタ
CCreateArea::CCreateArea(){
}

//デストラクタ
CCreateArea::~CCreateArea(){
}

//初期化処理
bool CCreateArea::init(){
    
    if(cocos2d::Sprite::init() == false){
        CCLOG("CCreateAreaの初期化に失敗");
        return false;
    }
    
    //画像の設定
    this->setTexture("createArea.png");
    
    //update()メンバ関数の呼び出し
    this->schedule(schedule_selector(CCreateArea::fadeUpDate), 2.2f);
    
    return true;
}


//更新処理
void CCreateArea::update(float deltaTime){}

//点滅
void CCreateArea::fadeUpDate(float delta){
    auto act1 = cocos2d::FadeOut::create(1.0f);
    auto act2 = cocos2d::FadeIn::create(1.0f);
    auto seq = cocos2d::Sequence::create(act1, act2, NULL);
    this->runAction(seq);
}

