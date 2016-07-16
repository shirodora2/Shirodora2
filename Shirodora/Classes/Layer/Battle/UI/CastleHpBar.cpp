//
//  CastleHpBar.cpp
//  Shirodora
//
//  Created by 毎床　公喜 on 2016/07/09.
//
//

#include "CastleHpBar.hpp"
USING_NS_CC;
CCastleHpBar::CCastleHpBar(){
}
CCastleHpBar::~CCastleHpBar(){
}

bool CCastleHpBar::init(){
    if(!ProgressTimer::init())return false;
    Sprite* sp = Sprite::create("");
    setSprite(sp);
    
    setPercentage(100);
    
    setType(ProgressTimerType::BAR);
    
    setBarChangeRate(Vec2(-1,0));
    
    setMidpoint(Vec2(1,0));
    
    
    scheduleUpdate();
    
    return true;
}

void CCastleHpBar::update(float _dt){
    setPercentage(m_Hp);
}
