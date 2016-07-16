//
//  UI_Layer.cpp
//  Shirodora
//
//  Created by 毎床　公喜 on 2016/07/09.
//
//

#include "UI_Layer.hpp"

#include "TimeLabel.hpp"
#include "CastleHpBar.hpp"


USING_NS_CC;

CUI_Layer::CUI_Layer(){
}
CUI_Layer::~CUI_Layer(){
}

bool CUI_Layer::init(){
    if(!Layer::init())return false;
    //制限時間ラベル
    m_pTimeLabel = CTimeLable::create();
    m_pTimeLabel->setPosition(Director::getInstance()->getWinSize().width * 0.5f,
                              Director::getInstance()->getWinSize().height * 0.9f);
    addChild(m_pTimeLabel,(int)CZoderUI::Time);
    
    //城の耐久値のバー
    m_pCastleHpPlayerBar = CCastleHpPlayerBar::create();
    m_pCastleHpPlayerBar->setPosition(Director::getInstance()->getWinSize().width * 0.2f,
                                Director::getInstance()->getWinSize().height * 0.9f);
    addChild(m_pCastleHpPlayerBar,(int)CZoderUI::Bar);
    
    m_pCastleHpEnemyBar = CCastleHpEnemyBar::create();
    m_pCastleHpEnemyBar->setPosition(Director::getInstance()->getWinSize().width * 0.8f,
                                      Director::getInstance()->getWinSize().height * 0.9f);
    addChild(m_pCastleHpEnemyBar,(int)CZoderUI::Bar);

    
    scheduleUpdate();
    return true;
}

void CUI_Layer::update(float _dt){
    
}
