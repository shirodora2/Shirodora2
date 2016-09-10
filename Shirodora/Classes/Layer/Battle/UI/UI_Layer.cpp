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
#include "CharacterManager.hpp"
#include "Character.hpp"
#include "Status.hpp"


USING_NS_CC;

CUI_Layer::CUI_Layer(){
}
CUI_Layer::~CUI_Layer(){
}

bool CUI_Layer::init(){
    if(!Layer::init())return false;
    //ゲームモード
    m_systemMode = SYSTEM_MODE::NONE;
    
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
                                       (m_charaIconBox[i]->getContentSize().width  * i),
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
    
    //キングコストの参照
    std::shared_ptr<CIteratorTemplate<CCharacter*>> itr = CCharacterManager::getInstance()->iterator(CHARACTER_AGGREGATE_TYPE::PLAYER_1_KING) ;
    while(itr->hasNext() == true){
        CCharacter *pChara = itr->next() ;
        m_cost = pChara->getStatus()->getCost();
    }


    
    scheduleUpdate();
    return true;
}

void CUI_Layer::update(float _dt){
    //ゲームの状態
    switch (m_systemMode) {
        case SYSTEM_MODE::NONE:
            m_systemMode = SYSTEM_MODE::START;
            break;
        case SYSTEM_MODE::START:
             scheduleOnce(schedule_selector(CUI_Layer::StartProductionFunc), 0.f);
            m_systemMode = SYSTEM_MODE::PLAY;
            break;
        case SYSTEM_MODE::PLAY:
            
            //コストの演出処理
            costFunc();
            
            
            //プレイヤー WIN
            if(m_pCastleHpPlayerBar->getCastleHp() >= 0 && m_pCastleHpEnemyBar->getCastleHp() < 0){
                scheduleOnce(schedule_selector(CUI_Layer::WinProductionFunc), 0.f);
                m_systemMode = SYSTEM_MODE::END;


            //プレイヤー LOSE
            }else if(m_pCastleHpPlayerBar->getCastleHp() < 0 && m_pCastleHpEnemyBar->getCastleHp() > 0){
                scheduleOnce(schedule_selector(CUI_Layer::LoseProductionFunc), 0.f);
                m_systemMode = SYSTEM_MODE::END;

            // Time Up
            }else if(m_pTimeLabel->getTime() <= 0){
                scheduleOnce(schedule_selector(CUI_Layer::TimeUpProductionFunc), 0.f);

                //プレイヤー WIN
                if(m_pCastleHpPlayerBar->getCastleHp() > m_pCastleHpEnemyBar->getCastleHp()){
                    scheduleOnce(schedule_selector(CUI_Layer::WinProductionFunc), 2.f);
                    m_systemMode = SYSTEM_MODE::END;


                //プレイヤー LOSE
                }else if(m_pCastleHpPlayerBar->getCastleHp() < m_pCastleHpEnemyBar->getCastleHp()){
                    scheduleOnce(schedule_selector(CUI_Layer::StartProductionFunc), 2.f);
                    m_systemMode = SYSTEM_MODE::END;

                // DROW
                }else{
                    scheduleOnce(schedule_selector(CUI_Layer::DrowProductionFunc), 2.f);
                    m_systemMode = SYSTEM_MODE::END;


                }
                

            }

            break;
        case SYSTEM_MODE::END:
            
            break;
        default:
            break;
    }
    
}


void CUI_Layer::StartProductionFunc(float _dt){
    auto start = Sprite::create("GameStart.png");
    start->setPosition(Director::getInstance()->getWinSize().width * 0.5f,
                       Director::getInstance()->getWinSize().height * 0.7f);
    addChild(start);
    
    auto move = MoveTo::create(0.4f, Point(this->getPosition().x + getContentSize().width / 2,
                                          this->getPosition().y + getContentSize().height / 2));
    auto wait = DelayTime::create(3.f);
    auto remove = RemoveSelf::create();
    auto sequence = Sequence::create(move,
                                     wait,
                                     remove,
                                     NULL);
    start->runAction(sequence);
}
void CUI_Layer::WinProductionFunc(float _dt){
    auto start = Sprite::create("Win.png");
    start->setPosition(Point(Director::getInstance()->getWinSize() * 0.5f));
    addChild(start);
    
    auto move = MoveTo::create(3.f, Point(Director::getInstance()->getWinSize() * 0.2f));
    auto wait = DelayTime::create(3.f);
    auto remove = RemoveSelf::create();
    auto sequence = Sequence::create(move,
                                     wait,
                                     remove,
                                     NULL);
    start->runAction(sequence);

    
}
void CUI_Layer::LoseProductionFunc(float _dt){
    auto start = Sprite::create("Lose.png");
    start->setPosition(Point(Director::getInstance()->getWinSize() * 0.5f));
    addChild(start);
    
    auto rotate = RotateTo::create(2.f, 30.f, 10.f);
    auto move = MoveTo::create(3.f, Point(start->getPosition().x,
                                          start->getPosition().y -200));
    auto wait = DelayTime::create(2.f);
    auto remove = RemoveSelf::create();
    auto sequence = Sequence::create(rotate,
                                     wait,
                                     move,
                                     remove,
                                     NULL);
    start->runAction(sequence);
    

}
void CUI_Layer::DrowProductionFunc(float _dt){
    auto start = Sprite::create("Draw.png");
    start->setPosition(Point(Director::getInstance()->getWinSize() * 0.5f));
    addChild(start);
    
    auto move = MoveTo::create(3.f, Point(Director::getInstance()->getWinSize() * 0.2f));
    auto wait = DelayTime::create(3.f);
    auto remove = RemoveSelf::create();
    auto sequence = Sequence::create(move,
                                     wait,
                                     remove,
                                     NULL);
    start->runAction(sequence);
    

}

void CUI_Layer::TimeUpProductionFunc(float _dt){
    auto timeUp = Sprite::create("TimeUp.png");
    timeUp->setPosition(Point(Director::getInstance()->getWinSize() * 0.5f));
    addChild(timeUp);
    
    auto wait = DelayTime::create(2.f);
    auto remove = RemoveSelf::create();
    auto sequence = Sequence::create(wait,
                                     remove,
                                     NULL);
    timeUp->runAction(sequence);
    

}



//コストの演出メソッド
void CUI_Layer::costFunc(){
    //キングコストの参照
    std::shared_ptr<CIteratorTemplate<CCharacter*>> itr = CCharacterManager::getInstance()->iterator(CHARACTER_AGGREGATE_TYPE::PLAYER_1_KING) ;
    while(itr->hasNext() == true){
        CCharacter *pChara = itr->next() ;
        m_cost = pChara->getStatus()->getCost();
    }

    
    for(int i = 0 ; i < MAXCOST ; i++){
        if( i < m_cost ){
            m_costBox[i]->setCostFlag(true);
        }else{
            m_costBox[i]->setCostFlag(false);
        }
    }
    
}

