//
//  Move.hpp
//  BarrageGame
//
//  Created by Ryoutarou Onimura on 2016/06/25.
//
//

#ifndef Move_hpp
#define Move_hpp

#include <stdio.h>

//=========================================================================
// 追加のインクルードはここから
//=========================================================================

//=========================================================================
//
// Move
//
//=========================================================================
class CMove {
public :
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
    /**
     *  @desc   constructor
     */
    CMove() ;
    
    /**
     *  @desc   constructor
     */
    CMove(const cocos2d::Vec2 &position,
          const cocos2d::Vec2 &direction = cocos2d::Vec2::ZERO,
          float velocity = 0.0f,
          float accele = 0.0f,
          float angle = 0.0f,
          float rotateVel = 0.0f) ;
    
    /**
     *  @desc   copy constructor
     */
    CMove(const CMove &move) ;
    
    /**
     *  @desc   destructor
     */
    virtual ~CMove() ;
    
    //=========================================================================
    // set
    //=========================================================================
    /**
     *  @desc   setPosition
     *  @param  position
     */
    void setPosition(const cocos2d::Vec2 &position) ;
    
    /**
     *  @desc   setDirection
     *  @param  direction
     */
    void setDirection(const cocos2d::Vec2 &direction) ;
    
    /**
     *  @desc   setVelocity
     *  @param  velocity
     */
    void setVelocity(float velocity) ;
    
    /**
     *  @desc   setAccele
     *  @param  accele
     */
    void setAccele(float accele) ;
    
    /**
     *  @desc   setAngle
     *  @param  angle
     */
    void setAngle(float angle) ;
    
    /**
     *  @desc   setRotateVel
     *  @param  angleVel
     */
    void setRotateVel(float rotateVel) ;
    
    /**
     *  @desc   setFriction
     *  @param  friction
     */
    void setFriction(float friction) ;
    
    /**
     *  @desc   setMaxSpeed
     *  @param  maxSpeed
     */
    void setMaxSpeed(float maxSpeed) ;
    
    /**
     *  @desc   set
     *  @param  CMove
     */
    void set(const CMove &move) ;
    
    //=========================================================================
    // get
    //=========================================================================
    /**
     *  @desc   getPosition
     *  @return position
     */
    cocos2d::Vec2 getPosition() const ;
    
    /**
     *  @desc   getDirection
     *  @return directionon
     */
    cocos2d::Vec2 getDirection() const ;
    
    /**
     *  @desc   getVelocity
     *  @return velocity
     */
    float getVelocity() const ;
    
    /**
     *  @desc   getAccele
     *  @return accele
     */
    float getAccele() const ;
    
    /**
     *  @desc   getAngle
     *  @return angle
     */
    float getAngle() const ;
    
    /**
     *  @desc   getAngleVel
     *  @return angleVel
     */
    float getRotateVel() const ;
    
    /**
     *  @desc   getFriction
     *  @return friction
     */
    float getFriction() const ;
    
    /**
     *  @desc   getMaxSpeed
     *  @return maxSpeed
     */
    float getMaxSpeed() const ;
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
    /**
     *  @desc   位置加算
     *  @param  加算する数値
     */
    void addPosition(const cocos2d::Vec2 &vector) ;
    
    /**
     *  @desc   addDirection
     *  @param  direction
     */
    void addDirection(const cocos2d::Vec2 &direction) ;
    
    /**
     *  @desc   addAccele
     *  @param  accele
     */
    void addAccele(float accele) ;
    
    /**
     *  @desc   移動処理
     */
    void moveBy() ;
    
private :
    //=========================================================================
    // メンバ変数
    //=========================================================================
    // 位置座標
    cocos2d::Vec2 m_position ;
    // 方向ベクトル
    cocos2d::Vec2 m_direction ;
    // 速度
    float m_velocity = 0.0f ;
    // 加速度
    float m_accele = 0.0f ;
    // 角度
    float m_angle = 0.0f ;
    // 角速度
    float m_rotateVel = 0.0f ;
    // 摩擦係数
    float m_friction = 0.3f ;
    // 最大速度
    float m_maxSpeed = 4.0f ;
    
};

#endif /* Move_hpp */
