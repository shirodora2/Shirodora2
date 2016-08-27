//
//  Summon.cpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/07/14.
//
//

#include "Shirodora.hpp"

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
    for(CAction *pAction : (*this->m_pActions)){
        pAction->update(this) ;
    }
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
    (*this->m_pAnimations)[(int)STATE::IDLE]->update() ;
}

/**
 *  @desc   衝突判定処理
 */
void CSummon::collision(){
    
    
    //自身のm_tagから衝突判定相手を決定する
    CHARACTER_AGGREGATE_TYPE type = CHARACTER_AGGREGATE_TYPE::NONE;
    (this->m_tag >= 1000 && this->m_tag < 2000)?
        type = CHARACTER_AGGREGATE_TYPE::PLAYER_2 :
        type = CHARACTER_AGGREGATE_TYPE::PLAYER_1 ;
    
    //攻撃範囲内に敵が入っていれば、状態(m_state)をATTACKに変更する　→　攻撃アクション開始
    //＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝わからん＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
    //自身のコリジョンデータの生成
    CCollisionData myCollisionData(this->m_pMove,this->m_pAttackBody);
    
    //敵のキャラクターが攻撃範囲（m_pAttackBody）に入っていかの判定
    std::shared_ptr<CIteratorTemplate<CCharacter*>> itr = CCharacterManager::getInstance()->iterator(type);
    while(itr->hasNext() == true){
        
        //敵キャラのコリジョンを取得
        CCharacter* pChara = itr->next();
        CCollisionData eneCollisionData(pChara->getMove(),pChara->getCollisionBody());
        
        //一匹でも攻撃範囲にいたら攻撃状態にする
        if(myCollisionData.collisionDecision(eneCollisionData)){
           
            //攻撃アクションを開始する
            (*this->m_pActions)[0]->start();
            return;

        }
    }
    //＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝わからん＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
}

/**
 *  @desc   状態チェック処理
 */
void CSummon::checkState(){
    
    //画像の反転処理
    if(this->m_pMove->getDirection().x < 0){
        this->m_pSprite->setScale( -1.0f, 1.0f );
    }
    if(this->m_pMove->getDirection().x > 0){
        this->m_pSprite->setScale( 1.0f, 1.0f );
    }

}

/**
 *  @desc   反映処理
 */
void CSummon::apply(){
    // 位置データを反映
    this->m_pSprite->cocos2d::Sprite::setPosition(this->m_pMove->getPosition()) ;
    
    // チップデータを反映
    this->m_pSprite->setTextureRect((*this->m_pAnimations)[(int)STATE::IDLE]->getCurrentChip()) ;
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
    
    //攻撃（敵弾）に当たった時のダメージ処理
    //this->m_pStatus->decreaseHp(pChara->getStatus()->getAttackPt(), pChara->getStatus()->getType());
}

/**
 *  @desc   イベントコールバック
 *  @tips   何か外部から呼び出す必要のあるアクションとか
 */
void CSummon::eventCallBack(){
    
}