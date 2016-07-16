//
//  MoveAction.cpp
//  Shirodora
//
//  Created by 服部優宇一 on 2016/07/16.
//
//

#include "Shirodora.hpp"
//========================================
//CMoveActionクラスの関数
//========================================
//コンストラクタ
CMoveAction::CMoveAction(cocos2d::Vec2 direction ,float velocity){
    this->m_direction = direction ;
    this->m_vel = velocity ;
    
    //アクションを開始させる
    this->start() ;
}

//アクションを開始させる関数
void CMoveAction::start(){
    
    this->m_isStartAction = true ;
}


/*
 * @desc 更新処理
 * @param アクションを取り付けるキャラクターのアドレス
 */
void CMoveAction::update(CCharacter* pChara){
    
    if(this->m_isStartAction == true){
        //進行方向の設定
        pChara->getMove()->setDirection(this->getDirection()) ;
        //速度の設定
        pChara->getMove()->setVelocity(this->getVel()) ;
    }
}

/*
* @desc アクションを停止させる関数
* @param アクションを取り付けるキャラクターのアドレス
*/
void CMoveAction::stop(CCharacter* pChara){
    
    this->m_isStartAction = false ;
    
    //プレイヤーの進行を止める
    pChara->getMove()->setDirection(cocos2d::Vec2(0,0)) ;
    pChara->getMove()->setVelocity(0.0f) ;
    
}

void CMoveAction::stop(){
}




