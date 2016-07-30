//
//  CostSprite.hpp
//  Shirodora
//
//  Created by 毎床　公喜 on 2016/07/19.
//
//

#ifndef CostSprite_hpp
#define CostSprite_hpp

#include "cocos2d.h"

class CCostSprite : public cocos2d::Sprite{
public:
    CCostSprite();
    ~CCostSprite();
    
    void setCostFlag(bool _flag){m_costFlag = _flag;}
    bool getCostFlag(){return m_costFlag;}
    
    bool init() override;
    
    void update(float _dt) override;
    
    CREATE_FUNC(CCostSprite);
private:
    bool m_costFlag = true;
    
    Sprite* m_sp = NULL;
    
};

#endif /* CostSprite_hpp */
