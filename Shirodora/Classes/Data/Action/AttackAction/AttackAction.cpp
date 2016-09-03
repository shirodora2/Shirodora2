//
//  AttackAction.cpp
//  Shirodora
//
//  Created by 服部優宇一 on 2016/07/16.
//
//

#include "Shirodora.hpp"

//========================================
//CMoveActionクラスの関数
//========================================
/**
 *@desc     コンストラクタ
 *@param    攻撃間隔
 *@param    攻撃対象
 */
CSimpleAttackAction::CSimpleAttackAction(int interval, CHARACTER_AGGREGATE_TYPE targetType){
  
    this->m_attackInterval = interval;
    this->m_attackCounter = interval;
    this->m_targetType = targetType;
}

//アクションを開始させる関数
void CSimpleAttackAction::start(){
    this->m_isStartAction = true;
}


/*
 * @desc 更新処理
 * @param アクションを取り付けるキャラクターのアドレス
 */
void CSimpleAttackAction::update(CCharacter* pChara){
    
    //キャラクターの状態が攻撃状態ならIDLEにする。
    if(pChara->getState() == STATE::ATTACK)
        pChara->setState(STATE::IDLE);
    
    
    if(this->m_isStartAction==true){
        
        //キャラクターの状態をATTACKにする
        pChara->setState(STATE::ATTACK);
        
        //カウンター回す
        this->m_attackCounter--;
        
        //カウンター０になったら
        if(this->m_attackCounter<=0){
            
            //自身のコリジョンデータの生成
            CCollisionData myCollisionData(pChara->getMove(),pChara->getAttackBody());
            
            //敵のキャラクターが攻撃範囲（m_pAttackBody）に入っていかの判定
            std::shared_ptr<CIteratorTemplate<CCharacter*>> itr = CCharacterManager::getInstance()->iterator(this->m_targetType);
          
            while(itr->hasNext() == true){
                
                //敵キャラのコリジョンを取得
                CCharacter* pEneChara = itr->next();
                CCollisionData eneCollisionData(pEneChara->getMove(),pEneChara->getCollisionBody());
                
                //範囲内の敵にダメージ
                if(myCollisionData.collisionDecision(eneCollisionData)){
                    
                    int damage = pEneChara->getStatus()->decreaseHp(pChara->getStatus()->getAttackPt(),
                                                       pChara->getStatus()->getType());
                    
                    if(pEneChara->getStatus()->getHp() <= 0)
                        pEneChara->setActive(false);
                
                    //***************************************************
                    // ダメージラベル
                    //***************************************************
                    //CCLOG("cccccc%d",pEneChara->getStatus()->getHp());
                    
                    std::string str = std::to_string(damage);
                    
                    cocos2d::Label* pDamage = cocos2d::Label::createWithSystemFont(str, "Alial", 15);
                    
                    int posX = RANDOM_FUNC::random(-10, 10);
                    
                    pDamage->setPosition(pEneChara->getSprite()->getContentSize().width/2 + posX,pEneChara->getSprite()->getContentSize().height + posX/2);
                    
                    pDamage->setColor(cocos2d::Color3B::RED);
                    
                    auto move = cocos2d::MoveBy::create(1.0f, cocos2d::Vec2(0.0f,10.0f));
                    auto wait = cocos2d::DelayTime::create(0.5f);
                    auto fade = cocos2d::FadeOut::create(0.5f);
                    auto remove = cocos2d::RemoveSelf::create();
                    auto sequence = cocos2d::Sequence::create(wait, fade, remove, NULL);
                    auto spawn = cocos2d::Spawn::create(sequence, move, NULL);
                    
                    pDamage->runAction(spawn);
                    
                    if(pEneChara->getSprite()->getScaleX() < 0)
                        pDamage->setScale(-1.0f,1.0f);
                    
                    CCLOG("%f",pEneChara->getSprite()->getScaleX());
                    
                    pEneChara->getSprite()->addChild(pDamage);
                    //***************************************************
                    //***************************************************

                }
            }
            
            this->m_attackCounter = this->m_attackInterval;
        }
    }
    
    this->m_isStartAction = false;
}

/*
 * @desc アクションを停止させる関数
 * @param アクションを取り付けるキャラクターのアドレス
 */
void CSimpleAttackAction::stop(CCharacter* pChara){
}

void CSimpleAttackAction::stop(){
    this->m_attackCounter = this->m_attackInterval;
    this->m_isStartAction = false;
}


