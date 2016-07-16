//
//  Summon.cpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/07/14.
//
//

#include "Summon.hpp"

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include "Character.hpp"
#include "Move.hpp"
#include "Body.hpp"
#include "Animation.hpp"
#include "Status.hpp"

//=========================================================================
//
// Summon
//
//=========================================================================
//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
/**
 *  @desc   constructor
 */
CSummon::CSummon(){
    
}

/**
 *  @desc   destructor
 */
CSummon::~CSummon(){
    if(this->m_pCollisionBody != NULL){
        delete this->m_pCollisionBody ;
        this->m_pCollisionBody = NULL ;
    }
    if(this->m_pAttackBody != NULL){
        delete this->m_pAttackBody ;
        this->m_pAttackBody = NULL ;
    }
}

//=========================================================================
// init
//=========================================================================
/**
 *  @desc   init
 */
bool CSummon::init(){
    if(CActor::init() == false) return false ;
    
    // 初期状態を待機にしておく
    this->m_state = SUMMON_STATE::IDLE ;
    
    return true ;
}

//=========================================================================
// メンバ関数
//=========================================================================
/**
 *  @desc   update
 *  @param  微小時間
 */
void CSummon::update(float deltaTime){
    this->action() ;
    this->move() ;
    this->collision() ;
    this->checkState() ;
    this->apply() ;
    this->animation() ;
}

/**
 *  @desc   アクション処理
 */
void CSummon::action(){
    
}

/**
 *  @desc   移動処理
 */
void CSummon::move(){
    this->m_pMove->moveBy() ;
}

/**
 *  @desc   アニメーション処理
 */
void CSummon::animation(){
    (*this->m_pAnimations)[(int)SUMMON_STATE::IDLE]->update() ;
}

/**
 *  @desc   衝突判定処理
 */
void CSummon::collision(){
    
}

/**
 *  @desc   状態チェック処理
 */
void CSummon::checkState(){
    
}

/**
 *  @desc   反映処理
 */
void CSummon::apply(){
    // 位置データを反映
    this->m_pSprite->cocos2d::Sprite::setPosition(this->m_pMove->getPosition()) ;
    
    // チップデータを反映
    this->m_pSprite->setTextureRect((*this->m_pAnimations)[(int)SUMMON_STATE::IDLE]->getCurrentChip()) ;
}

/**
 *  @desc   Character１体との衝突
 *  @param  CCharacter*
 */
bool CSummon::collisionAt(CCharacter *pChara){
    return true ;
}

/**
 *  @desc   衝突処理
 *  @param  CCharacter*
 */
void CSummon::hit(CCharacter *pChara){
    
}

/**
 *  @desc   イベントコールバック
 *  @tips   何か外部から呼び出す必要のあるアクションとか
 */
void CSummon::eventCallBack(){
    
}