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
    
    //状態(m_state)がATTACKなら、攻撃アクションを行う
    if(this->m_state == STATE::ATTACK){
        
        //(*this->m_pActions)[ 攻撃番号 ]->update(this);
    }
}

/**
 *  @desc   移動処理
 */
void CKing::move(){
    
    this->moveInput();
    
    this->m_pMove->moveBy() ;
}

/**
 *  @desc   アニメーション処理
 */
void CKing::animation(){
    (*this->m_pAnimations)[(int)STATE::IDLE]->update() ;
}

/**
 *  @desc   衝突判定処理
 */
void CKing::collision(){
    
    
    //自身のコリジョンデータの生成
    //CCollisionData myCollisionData(this->m_pMove,this->m_pAttackBody);
    
    
    //=====================================
    //　行動範囲制限に関する判定（画面など）
    //=====================================
    
    
    
    
    
    //=====================================
    //　ここから攻撃に関する判定
    //=====================================
    //入力状態だったら飛ばす
    if(this->m_state == STATE::INPUTING)
        return;
    
    //攻撃範囲内に敵が入っていれば、状態(m_state)をATTACKに変更する　→　攻撃アクション開始
    //＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝わからん＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
    //自身のコリジョンデータの生成
    CCollisionData myCollisionData(this->m_pMove,this->m_pAttackBody);
    
    //敵のキャラクターが攻撃範囲（m_pAttackBody）に入っていかの判定
    std::shared_ptr<CIteratorTemplate<CCharacter*>> itr = CCharacterManager::getInstance()->iterator(CHARACTER_AGGREGATE_TYPE::PLAYER_2);
    while(itr->hasNext() == true){
        
        //敵キャラのコリジョンを取得
        CCharacter* pChara = itr->next();
        CCollisionData eneCollisionData(pChara->getMove(),pChara->getCollisionBody());
        
        //一匹でも攻撃範囲にいたら攻撃状態にする
        if(myCollisionData.collisionDecision(eneCollisionData)){
            
            //攻撃アクションを開始する
            //(*this->m_pActions)[1]->start();
            return;
        }
    }
    //＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝わからん＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝

}

/**
 *  @desc   状態チェック処理
 */
void CKing::checkState(){
    
    
    //向いた方向のベクトル取得
    cocos2d::Vec2 direction = this->m_pMove->getDirection();
   
    //攻撃範囲の中心座標を取得
    cocos2d::Vec2 centerPos = this->m_pAttackBody->getCenterPosition();
    
    //中心座標と向いた方向の乗算がマイナスなら、
    //逆方向を向くということになるので
    //中心座標の２倍分、マイナスに移動させる
    if(direction.x * centerPos.x < 0){
        cocos2d::Vec2 movePos( -(centerPos.x * 2.0f), 0.0f);
        this->m_pAttackBody->move(movePos);
    }
    
    //CCLOG("攻撃のやつ %f:%f", centerPos.x,centerPos.y);
    
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
void CKing::apply(){
    // 位置データを反映
    this->m_pSprite->cocos2d::Sprite::setPosition(this->m_pMove->getPosition()) ;
    
    // チップデータを反映
    this->m_pSprite->setTextureRect((*this->m_pAnimations)[0]->getCurrentChip()) ;
}

/**
 *  @desc   Character１体との衝突
 *  @param  CCharacter*
 */
bool CKing::collisionAt(CCharacter *pChara){
    
    //特になし
    return true ;
}

/**
 *  @desc   衝突処理
 *  @param  CCharacter*
 */
void CKing::hit(CCharacter *pChara){
    
    //攻撃（敵弾）に当たった時のダメージ処理
    //this->m_pStatus->decreaseHp(pChara->getStatus()->getAttackPt(), pChara->getStatus()->getType());
}

/**
 *  @desc   イベントコールバック
 *  @tips   何か外部から呼び出す必要のあるアクションとか
 */
void CKing::eventCallBack(){
    
}


/**
 *  @desc   入力による移動
 */
void CKing::moveInput(){
    
    //とりあえず IDLE状態 にしておく（デフォ）
    this->m_state = STATE::IDLE;

    //GAME_MODE が CHECKなら入力できない
    if(CGameMode::GAME_MODE::CHECK == CGameMode::getInstance()->getGameMode())
        return;
    
    //入力があれば状態(m_state)を入力状態(INPUTING)にする
    if(inputflag.m_a.isInputing() == true){
        this->m_state = STATE::INPUTING;
        this->m_pMove->addDirection(-1.0f * cocos2d::Vec2::UNIT_X) ;
        this->m_pMove->setAccele(0.7f) ;
    }
    if(inputflag.m_d.isInputing() == true){
        this->m_state = STATE::INPUTING;
        this->m_pMove->addDirection(1.0f * cocos2d::Vec2::UNIT_X) ;
        this->m_pMove->setAccele(0.7f) ;
    }
    
    if(inputflag.m_w.isInputing() == true){
        this->m_state = STATE::INPUTING;
        this->m_pMove->addDirection(1.0f * cocos2d::Vec2::UNIT_Y) ;
        this->m_pMove->setAccele(0.7f) ;
    }
    
    if(inputflag.m_s.isInputing() == true){
        this->m_state = STATE::INPUTING;
        this->m_pMove->addDirection(-1.0f * cocos2d::Vec2::UNIT_Y) ;
        this->m_pMove->setAccele(0.7f) ;
    }

}
