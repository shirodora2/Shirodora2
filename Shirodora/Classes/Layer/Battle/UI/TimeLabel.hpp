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
#include <stdio.h>

class CTimeLable : public cocos2d::Sprite{
public:
    CTimeLable();
    ~CTimeLable();
    //画像のRECT格納
    static const int MAXNUMBER = 10;
    
    //制限時間のセッターゲッター
    void setTime(float _time){this->m_time = _time;}
    float getTime(){return m_time;}

    
    bool init()  override;
    
    void update(float _dt)override;
    
    //時間の計算
    void timeCalculationFunc();
    
    CREATE_FUNC(CTimeLable);
    

private:
    //制限時間
    float m_time = 7200;
    //分
    int m_Minute = 0;
    //秒
    int m_Second = 0;
    
    //スプライト群（数字）
    cocos2d::Rect m_numberSpriteBox[MAXNUMBER];
    
    //スプライト
    cocos2d::Sprite* SpriteBox[3];
    


    
};

#endif /* TimeLabel_hpp */
