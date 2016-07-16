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
     *  @desc   位置座標設定
     *  @param  位置座標
     */
    inline void setPosition(const cocos2d::Vec2 &position){this->m_position = position ;}
    
    /**
     *  @desc   進行方向設定
     *  @param  進行方向
     *  @tips   正規化される
     */
    inline void setDirection(const cocos2d::Vec2 &direction){this->m_direction = direction.getNormalized() ;}
    
    /**
     *  @desc   速度設定
     *  @param  速度
     */
    inline void setVelocity(float velocity){this->m_velocity = velocity ;}
    
    /**
     *  @desc   加速度設定
     *  @param  加速度
     */
    inline void setAccele(float accele){this->m_accele = accele ;}
    
    /**
     *  @desc   角度設定
     *  @param  角度
     */
    inline void setAngle(float angle){this->m_angle = angle ;}
    
    /**
     *  @desc   角速度設定
     *  @param  角速度
     */
    inline void setRotateVel(float rotateVel){this->m_rotateVel = rotateVel ;}
    
    /**
     *  @desc   摩擦係数設定
     *  @param  摩擦係数
     */
    inline void setFriction(float friction){this->m_friction = friction ;}
    
    /**
     *  @desc   最大速度設定
     *  @param  最大速度
     */
    inline void setMaxSpeed(float maxSpeed){this->m_maxSpeed = maxSpeed ;}
    
    /**
     *  @desc   set
     *  @param  CMove
     */
    void set(const CMove &move) ;
    
    //=========================================================================
    // get
    //=========================================================================
    /**
     *  @desc   位置座標取得
     *  @return 位置座標
     */
    inline cocos2d::Vec2 getPosition() const {return this->m_position ;}
    
    /**
     *  @desc   進行方向取得
     *  @return 進行方向
     */
    inline cocos2d::Vec2 getDirection() const {return this->m_direction ;}
    
    /**
     *  @desc   速度取得
     *  @return 速度
     */
    inline float getVelocity() const {return this->m_velocity ;}
    
    /**
     *  @desc   加速度取得
     *  @return 加速度
     */
    inline float getAccele() const {return this->m_accele ;}
    
    /**
     *  @desc   角度取得
     *  @return 角度
     */
    inline float getAngle() const {return this->m_angle ;}
    
    /**
     *  @desc   角速度取得
     *  @return 角速度
     */
    inline float getRotateVel() const {return this->m_rotateVel ;}
    
    /**
     *  @desc   摩擦係数取得
     *  @return 摩擦係数
     */
    inline float getFriction() const {return this->m_friction ;}
    
    /**
     *  @desc   最大速度取得
     *  @return 最大速度
     */
    inline float getMaxSpeed() const {return this->m_maxSpeed ;}
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
    /**
     *  @desc   位置加算
     *  @param  加算する数値
     */
    inline void addPosition(const cocos2d::Vec2 &vector){this->m_position += vector ;}
    
    /**
     *  @desc   進行方向加算
     *  @param  direction
     */
    inline void addDirection(const cocos2d::Vec2 &direction){this->m_direction = (this->m_direction + direction).getNormalized() ;}
    
    // !!!:使わない可能性あり
    /**
     *  @desc   加速度加算
     *  @param  accele
     */
    inline void addAccele(float accele){this->m_accele += accele ;}
    
    /**
     *  @desc   移動処理
     *  @tips   加速と摩擦計算考慮
     */
    void moveBy() ;
    
private :
    //=========================================================================
    // メンバ変数
    //=========================================================================
    // 位置座標
    cocos2d::Vec2 m_position ;
    // 進行方向
    cocos2d::Vec2 m_direction ;
    // 速度
    float m_velocity = 0.0f ;
    // 加速度
    float m_accele = 0.0f ;
    // 角度 ディグリー角
    float m_angle = 0.0f ;
    // 角速度 ディグリー角
    float m_rotateVel = 0.0f ;
    // 摩擦係数
    float m_friction = 0.3f ;
    // 最大速度
    float m_maxSpeed = 4.0f ;
    
};

#endif /* Move_hpp */
