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

class CCastleHpBar : public cocos2d::ProgressTimer{
private:
    float m_Hp = 0;
public:
    CCastleHpBar();
    ~CCastleHpBar();
    
    bool init() override;
    
    void update(float _dt) override;
    
    void setCastleHp(float _hp){this->m_Hp = _hp;}
    float getCastleHp(){return this->m_Hp;}
    
    CREATE_FUNC(CCastleHpBar);
};

#endif /* CastleHpBar_hpp */
