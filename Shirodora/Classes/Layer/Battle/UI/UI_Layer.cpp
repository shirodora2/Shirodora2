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
#include "CharacterIconSprite.hpp"
#include "CostSprite.hpp"


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

    
    //キャラアイコン
    for(int i = 0; i < 3 ; i++ ){
        m_charaIconBox[i] = CAttackIcon::create();
        addChild(m_charaIconBox[i]);
    }
    for(int i = 3; i < 6 ; i++ ){
        m_charaIconBox[i] = CDefenceIcon::create();
        addChild(m_charaIconBox[i]);
    }
    for(int i = 0; i < MAXICON ; i++){
        m_charaIconBox[i]->setPosition(Director::getInstance()->getWinSize().width * 0.2f +
                                       (m_charaIconBox[i]->getContentSize().width * i),
                                       Director::getInstance()->getWinSize().height * 0.1f);
    }
    
    //コストアイコン
    for(int i = 0 ; i < MAXCOST ; i++){
        m_costBox[i] = CCostSprite::create();
        m_costBox[i]->setPosition(Director::getInstance()->getWinSize().width * 0.08f,
                                  Director::getInstance()->getWinSize().height * 0.7f +
                                  (-m_costBox[i]->getContentSize().height * i) );
        addChild(m_costBox[i]);
        
    }
    
    scheduleUpdate();
    return true;
}

void CUI_Layer::update(float _dt){
    m_testcost++;
    
    if(m_testcost == 60){
        m_testcost = 0;

        for(int i = 0; i < MAXCOST ; i++){
            if(m_costBox[i]->getCostFlag() == true){
                m_costBox[i]->setCostFlag(false);
                return;
            }
            
        }
    }
    
}
