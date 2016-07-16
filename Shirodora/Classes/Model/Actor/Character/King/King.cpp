//
//  King.cpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/07/14.
//
//

#include "Shirodora.hpp"

//=========================================================================
//
// King
//
//=========================================================================
//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
/**
 *  @desc   constructor
 */
CKing::CKing(){
    
}

/**
 *  @desc   destructor
 */
CKing::~CKing(){
    
}

//=========================================================================
// init
//=========================================================================
/**
 *  @desc   init
 */
bool CKing::init(){
    if(CActor::init() == false) return false ;
    
    // 初期状態を待機にしておく
    this->m_state = KING_STATE::IDLE ;
    
    return true ;
}

//=========================================================================
// メンバ関数
//=========================================================================
/**
 *  @desc   update
 *  @param  微小時間
 */
void CKing::update(float deltaTime){
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
void CKing::action(){
    
}

/**
 *  @desc   移動処理
 */
void CKing::move(){
    if(inputflag.m_left.isPressed() == true){
        this->m_pMove->addDirection(-1.0f * cocos2d::Vec2::UNIT_X) ;
        this->m_pMove->setAccele(0.7f) ;
    }
    if(inputflag.m_right.isPressed() == true){
        this->m_pMove->addDirection(1.0f * cocos2d::Vec2::UNIT_X) ;
        this->m_pMove->setAccele(0.7f) ;
    }
    if(inputflag.m_up.isPressed() == true){
        this->m_pMove->addDirection(1.0f * cocos2d::Vec2::UNIT_Y) ;
        this->m_pMove->setAccele(0.7f) ;
    }
    if(inputflag.m_down.isPressed() == true){
        this->m_pMove->addDirection(-1.0f * cocos2d::Vec2::UNIT_Y) ;
        this->m_pMove->setAccele(0.7f) ;
    }
    
    this->m_pMove->moveBy() ;
}

/**
 *  @desc   アニメーション処理
 */
void CKing::animation(){
    (*this->m_pAnimations)[(int)KING_STATE::IDLE]->update() ;
}

/**
 *  @desc   衝突判定処理
 */
void CKing::collision(){
    
}

/**
 *  @desc   状態チェック処理
 */
void CKing::checkState(){
    
}

/**
 *  @desc   反映処理
 */
void CKing::apply(){
    // 位置データを反映
    this->m_pSprite->cocos2d::Sprite::setPosition(this->m_pMove->getPosition()) ;
    
    // チップデータを反映
    this->m_pSprite->setTextureRect((*this->m_pAnimations)[(int)KING_STATE::IDLE]->getCurrentChip()) ;
}

/**
 *  @desc   Character１体との衝突
 *  @param  CCharacter*
 */
bool CKing::collisionAt(CCharacter *pChara){
    return true ;
}

/**
 *  @desc   衝突処理
 *  @param  CCharacter*
 */
void CKing::hit(CCharacter *pChara){
    
}

/**
 *  @desc   イベントコールバック
 *  @tips   何か外部から呼び出す必要のあるアクションとか
 */
void CKing::eventCallBack(){
    
}
