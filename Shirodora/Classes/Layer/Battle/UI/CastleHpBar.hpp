//
//  CastleHpBar.hpp
//  Shirodora
//
//  Created by 毎床　公喜 on 2016/07/09.
//
//

#ifndef CastleHpBar_hpp
#define CastleHpBar_hpp

#include "cocos2d.h"

class CCastleHpPlayerBar : public cocos2d::Sprite{
public:
    CCastleHpPlayerBar();
    ~CCastleHpPlayerBar();

    
    bool init() override;
    
    void update(float _dt) override;
    
    void setCastleHp(float _hp){this->m_Hp = _hp;}
    float getCastleHp(){return this->m_Hp;}
    
    //プログレスタイマークリエイト
    void progresTimerCreate();
    //値の反映
    void applyFunc();
    
    CREATE_FUNC(CCastleHpPlayerBar);
    


private:
    float m_MaxHp = 760;
    float m_Hp = 760;
    cocos2d::ProgressTimer* m_pHpGage = NULL;

};

class CCastleHpEnemyBar : public cocos2d::Sprite{
public:
    CCastleHpEnemyBar();
    ~CCastleHpEnemyBar();
    
    bool init() override;
    
    void update(float _dt) override;
    
    void setCastleHp(float _hp){this->m_Hp = _hp;}
    float getCastleHp(){return this->m_Hp;}
    
    //プログレスタイマークリエイト
    void progresTimerCreate();
    //値の反映
    void applyFunc();
    
    CREATE_FUNC(CCastleHpEnemyBar);
    
private:
    float m_MaxHp = 760;
    float m_Hp = 760;
    cocos2d::ProgressTimer* m_pHpGage = NULL;

};



#endif /* CastleHpBar_hpp */
