//
//  CastleHpBar.cpp
//  Shirodora
//
//  Created by 毎床　公喜 on 2016/07/09.
//
//

#include "CastleHpBar.hpp"
#include "CharacterManager.hpp"
#include "Character.hpp"
#include "Status.hpp"



USING_NS_CC;
CCastleHpPlayerBar::CCastleHpPlayerBar(){
}
CCastleHpPlayerBar::~CCastleHpPlayerBar(){
}

bool CCastleHpPlayerBar::init(){
    if(!Sprite::init())return false;
    setTexture("PlayerLife_Frame.png");
    
    //Player_1 城のHP参照
    std::shared_ptr<CIteratorTemplate<CCharacter*>> itr = CCharacterManager::getInstance()->iterator(CHARACTER_AGGREGATE_TYPE::PLAYER_1_CASTLE) ;
    while(itr->hasNext() == true){
        CCharacter *pChara = itr->next() ;
        m_MaxHp = pChara->getStatus()->getMaxHp();
        m_Hp = pChara->getStatus()->getHp();
    }

    
    progresTimerCreate();
    scheduleUpdate();
    
    return true;
}

void CCastleHpPlayerBar::update(float _dt){
    applyFunc();
}






void CCastleHpPlayerBar::progresTimerCreate(){
    //タイマーにスプライトをセット
    m_pHpGage = ProgressTimer::create(Sprite::create("PlayerLife_Gage.png"));
    //最初は0パーセント
    m_pHpGage->setPercentage(0);
    //タイマーの形（棒状に設定）
    m_pHpGage->setType(kCCProgressTimerTypeBar);
    //バーの伸びる方向（x方向に設定）
    m_pHpGage->setBarChangeRate(Vec2(1, 0));
    //タイマーの基準点（左側に設定）
    m_pHpGage->setMidpoint(Vec2(0, 0));
    //タイマーを配置
    m_pHpGage->setPosition(Point(this->getContentSize() * 0.5f));
    
    m_pHpGage->setPercentage(100);

    
    this->addChild(m_pHpGage);
    

}


void CCastleHpPlayerBar::applyFunc(){
    //毎回HPを参照し続ける
    std::shared_ptr<CIteratorTemplate<CCharacter*>> itr = CCharacterManager::getInstance()->iterator(CHARACTER_AGGREGATE_TYPE::PLAYER_1_CASTLE) ;
    while(itr->hasNext() == true){
        CCharacter *pChara = itr->next() ;
        m_Hp = pChara->getStatus()->getHp();
    }

    
    if(m_pHpGage != NULL){
        if(m_Hp < 0){
            m_Hp = 0;
        }
        m_Hp -= 1.f;
        float hp = m_Hp / m_MaxHp * 100;

        m_pHpGage->setPercentage(hp);
    }else{
        CCLOG("HPゲージNULL");
    }

}

//-------------------------------------------------------------------------------------------

CCastleHpEnemyBar::CCastleHpEnemyBar(){
}
CCastleHpEnemyBar::~CCastleHpEnemyBar(){
}

bool CCastleHpEnemyBar::init(){
    if(!Sprite::init())return false;
    setTexture("EnemyLife_Frame.png");
    
    //Player_2 城のHP参照
    std::shared_ptr<CIteratorTemplate<CCharacter*>> itr = CCharacterManager::getInstance()->iterator(CHARACTER_AGGREGATE_TYPE::PLAYER_2_CASTLE) ;
    while(itr->hasNext() == true){
        CCharacter *pChara = itr->next() ;
        m_MaxHp = pChara->getStatus()->getMaxHp();
        m_Hp = pChara->getStatus()->getHp();
    }

    
    progresTimerCreate();
    scheduleUpdate();
    
    return true;
}

void CCastleHpEnemyBar::update(float _dt){
    applyFunc();
}






void CCastleHpEnemyBar::progresTimerCreate(){
    //タイマーにスプライトをセット
    m_pHpGage = ProgressTimer::create(Sprite::create("EnemyLife_Gage.png"));
    //最初は0パーセント
    m_pHpGage->setPercentage(0);
    //タイマーの形（棒状に設定）
    m_pHpGage->setType(kCCProgressTimerTypeBar);
    //バーの伸びる方向（x方向に設定）
    m_pHpGage->setBarChangeRate(Vec2(1, 0));
    //タイマーの基準点（左側に設定）
    m_pHpGage->setMidpoint(Vec2(1, 0));
    //タイマーを配置
    m_pHpGage->setPosition(Point(this->getContentSize() * 0.5f));
    
    m_pHpGage->setPercentage(100);
    
    
    this->addChild(m_pHpGage);
    
    
}


void CCastleHpEnemyBar::applyFunc(){
    
    //毎回HPを参照し続ける
    std::shared_ptr<CIteratorTemplate<CCharacter*>> itr = CCharacterManager::getInstance()->iterator(CHARACTER_AGGREGATE_TYPE::PLAYER_2_CASTLE) ;
    while(itr->hasNext() == true){
        CCharacter *pChara = itr->next() ;
        m_Hp = pChara->getStatus()->getHp();
    }

    
    if(m_pHpGage != NULL){
        if(m_Hp < 0){
            m_Hp = 0;
        }
        
        m_Hp -= 1.f;
        float hp = m_Hp / m_MaxHp * 100;
        m_pHpGage->setPercentage(hp);
        
    }else{
        CCLOG("HPゲージNULL");
    }
    
}

