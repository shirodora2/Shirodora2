//
//  TimeLabel.cpp
//  Shirodora
//
//  Created by 毎床　公喜 on 2016/07/09.
//
//

#include "TimeLabel.hpp"
USING_NS_CC;

CTimeLable::CTimeLable(){
}
CTimeLable::~CTimeLable(){
}

bool CTimeLable::init(){
    if(!Sprite::init())return false;
    
    //ーーーーーーーー画像の設定ーーーーーーーーーーーー
    
    //フォント
    Sprite* sp = Sprite::create("TimeNumberSymbol.png");
    sp->setPositionX(-20);
    addChild(sp);
    
    for(int i = 0; i < 3 ; i++ ){
        SpriteBox[i] = Sprite::create("TimeNumber.png");
        SpriteBox[i]->setTextureRect(Rect(0,0,23,30));
        addChild(SpriteBox[i]);
    }
    
    SpriteBox[0]->setPositionX(-40);
    SpriteBox[1]->setPositionX(10);
    SpriteBox[2]->setPositionX(40);

    
    //ーーーーーーレクトの生成ーーーーーーーーーーーー
    m_numberSpriteBox[0] = Rect(0,0,18,30);
    m_numberSpriteBox[1] = Rect(28,0,10,30);
    m_numberSpriteBox[2] = Rect(48,0,18,30);
    m_numberSpriteBox[3] = Rect(76,0,18,30);
    m_numberSpriteBox[4] = Rect(104,0,18,30);
    m_numberSpriteBox[5] = Rect(132,0,18,30);
    m_numberSpriteBox[6] = Rect(160,0,18,30);
    m_numberSpriteBox[7] = Rect(188,0,18,30);
    m_numberSpriteBox[8] = Rect(216,0,18,30);
    m_numberSpriteBox[9] = Rect(244,0,18,30);


    
    scheduleUpdate();
    return true;
}

void CTimeLable::update(float _dt){
    timeCalculationFunc();
}

//時間の計算
void CTimeLable::timeCalculationFunc(){
    //残り０なら入らない
    if(m_time <= 0  )return ;
    //トータルタイムを減らす
    m_time--;
    
    //分の計算
    int min = m_time / 3600;
    SpriteBox[0]->setTextureRect(m_numberSpriteBox[min]);
    //10秒台
    int sec = (int)m_time % 3600 ;
    int sec2 = sec / 600;
    SpriteBox[1]->setTextureRect(m_numberSpriteBox[sec2]);
    //１秒台
    int sec3 = (int)m_time % 600 ;
    int sec4 = sec3 / 60;
    SpriteBox[2]->setTextureRect(m_numberSpriteBox[sec4]);

}
