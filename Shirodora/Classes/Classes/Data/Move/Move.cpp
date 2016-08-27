//
//  Move.cpp
//  BarrageGame
//
//  Created by Ryoutarou Onimura on 2016/06/25.
//
//

#include "Move.hpp"

//=========================================================================
// 追加のインクルードはここから
//=========================================================================

//=========================================================================
//
// Move
//
//=========================================================================
/**
 *  @desc   constructor
 */
CMove::CMove(){}

/**
 *  @desc   copy constructor
 */
CMove::CMove(const CMove &move){
    this->set(move) ;
}

/**
 *  @desc   destructor
 */
CMove::~CMove(){}

//=========================================================================
// set
//=========================================================================

/**
 *  @desc   set
 *  @param  CMove
 */
void CMove::set(const CMove &move){
    this->setPosition(move.getPosition()) ;
    this->setDirection(move.getDirection()) ;
    this->setVelocity(move.getVelocity()) ;
    this->setAccele(move.getAccele()) ;
    this->setAngle(move.getAngle()) ;
    this->setRotateVel(move.getRotateVel()) ;
    this->setFriction(move.getFriction()) ;
    this->setMaxSpeed(move.getMaxSpeed()) ;
}

//=========================================================================
// メンバ関数
//=========================================================================
/**
 *  @desc   移動処理
 *  @tips   加速と摩擦計算考慮
 */
void CMove::moveBy(){
    // 摩擦力を用意
    float friction = 0.0f ;
    
    // 現在の速度から摩擦力を決定する
    if(this->m_friction < this->m_velocity){
        friction = -this->m_friction ;
    }
    else if(0 < this->m_velocity){
        friction = -this->m_velocity ;
    }
    
    // 摩擦力とか速度から現在の速度を算出
    this->m_velocity += this->m_accele + friction ;
    
    // 算出した速度を最大速度と比べて実際の速度を決定する
    if(this->m_maxSpeed < this->m_velocity){
        this->m_velocity = this->m_maxSpeed ;
    }
    else if(this->m_velocity < -this->m_maxSpeed){
        this->m_velocity = -this->m_maxSpeed ;
    }
    
    // 速度が 0なら進行方向を 原点にする
    if(this->m_velocity == 0.0f){
        this->m_direction = cocos2d::Vec2::ZERO ;
    }
    
    // 進行方向と速度をかけて移動距離を算出し、位置に加算する
    else{
        this->m_position += (this->m_direction.getNormalized() * this->m_velocity) ;
    }
    
    // 回転速度を計算する
    if(this->m_rotateVel != 0.0f){
        this->m_angle += this->m_rotateVel ;
    }
    
    // 計算が終わったら加速度を初期化する
    this->m_accele = 0.0f ;
    
}