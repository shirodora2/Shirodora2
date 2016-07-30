//
//  CostSprite.cpp
//  Shirodora
//
//  Created by 毎床　公喜 on 2016/07/19.
//
//

#include "CostSprite.hpp"
USING_NS_CC;

CCostSprite::CCostSprite(){
}
CCostSprite::~CCostSprite(){
}

bool CCostSprite::init(){
    if(!Sprite::init())return false;
    
    setTexture("Summon_SmallFrame.png");
    
    m_sp = Sprite::create("Summon_SmallIcon.png");
    m_sp->setPosition(Point(getContentSize().width * 0.5f,
                          getContentSize().height* 0.5f));
    addChild(m_sp);
    
    scheduleUpdate();
    return true;
}

void CCostSprite::update(float _dt){
    if(m_costFlag == false){
        m_sp->setVisible(false);
    }else{
        m_sp->setVisible(true);
    }
}
