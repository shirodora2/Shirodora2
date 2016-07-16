//
//  MoveAction.hpp
//  Shirodora
//
//  Created by 服部優宇一 on 2016/07/16.
//
//

#ifndef MoveAction_hpp
#define MoveAction_hpp

#include <stdio.h>
#include "Action.hpp"

class CCharacter ;
//===========================================
//移動に関するクラス
//===========================================
class CMoveAction : public CAction{
public:
    //コンストラクタ
    CMoveAction(cocos2d::Vec2 direction ,float velocity) ;
    
    //アクションを開始
    void start() override ;
    /**
     * @desc 更新処理
     * @param アクションを取り付けるキャラクターのアドレス
     */
    void update(CCharacter* pChara) override ;
    //アクションを停止
    void stop() override ;
    void stop(CCharacter* pChara) override ;
    
    //速度の設定
    void setDirectionAndVelocity(cocos2d::Vec2 direction ,float velocity){
        this->m_direction = direction ;
        this->m_vel = velocity ;
    }
    
    //x方向の速度の取得
    float getVel(){
        return this->m_vel ;
    }
    
    //進行方向の取得
    cocos2d::Vec2 getDirection(){
        return this->m_direction ;
    }
    
private:
    //進行方向
    cocos2d::Vec2 m_direction ;
    //速度
    float m_vel = 0.0f ;
};

#endif /* MoveAction_hpp */
