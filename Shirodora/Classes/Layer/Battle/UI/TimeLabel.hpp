//
//  TimeLabel.hpp
//  Shirodora
//
//  Created by 毎床　公喜 on 2016/07/09.
//
//

#ifndef TimeLabel_hpp
#define TimeLabel_hpp

#include "cocos2d.h"
#include <string>

class CTimeLable : public cocos2d::Label{
private:
    //制限時間
    float m_time = 0;
public:
    CTimeLable();
    ~CTimeLable();
    
    bool init()  override;
    
    void update(float _dt)override;
    
    //制限時間のセッターゲッター
    void setTime(float _time){this->m_time = _time;}
    float getTime(){return m_time;}
    
    CREATE_FUNC(CTimeLable);
    
};

#endif /* TimeLabel_hpp */
