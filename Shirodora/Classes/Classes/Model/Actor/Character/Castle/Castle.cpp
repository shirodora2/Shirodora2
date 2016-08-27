//
//  Castle.cpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/08/20.
//
//

#include "Castle.hpp"
#include "Shirodora.hpp"

//=========================================================================
// 前方宣言
//=========================================================================

//=========================================================================
//
// 城クラス
//
//=========================================================================
//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
/**
 *  @desc   constructor
 */
CCastle::CCastle(){
    
}

/**
 *  @desc   destructor
 */
CCastle::~CCastle(){
    
}

//=========================================================================
// init
//=========================================================================
/**
 *  @desc   init
 */
bool CCastle::init(){
    if(CActor::init() == false) return false ;
    
    // 初期状態を待機にしておく
    this->m_state = STATE::IDLE ;
    
    return true ;
}

//=========================================================================
// メンバ関数
//=========================================================================
/**
 *  @desc   update
 *  @param  微小時間
 */
void CCastle::update(float deltaTime){
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
void CCastle::action(){
    for(CAction *pAction : (*this->m_pActions)){
        pAction->update(this) ;
    }
}

/**
 *  @desc   移動処理
 */
void CCastle::move(){
    
}

/**
 *  @desc   アニメーション処理
 */
void CCastle::animation(){
    (*this->m_pAnimations)[(int)m_state]->update() ;
}

/**
 *  @desc   衝突判定処理
 */
void CCastle::collision(){
    
}

/**
 *  @desc   状態チェック処理
 */
void CCastle::checkState(){
    if(this->m_pStatus->getHp() <= 0){
        this->m_state = STATE::DEAD ;
    }
}

/**
 *  @desc   反映処理
 */
void CCastle::apply(){
    // チップデータを反映
    this->m_pSprite->setTextureRect((*this->m_pAnimations)[(int)m_state]->getCurrentChip()) ;
}

/**
 *  @desc   Character１体との衝突
 *  @param  CCharacter*
 */
bool CCastle::collisionAt(CCharacter *pChara){
    return true ;
}

/**
 *  @desc   衝突処理
 *  @param  CCharacter*
 */
void CCastle::hit(CCharacter *pChara){
    
}

/**
 *  @desc   イベントコールバック
 *  @tips   何か外部から呼び出す必要のあるアクションとか
 */
void CCastle::eventCallBack(){
    
}