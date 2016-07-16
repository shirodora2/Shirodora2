//
//  UI_Layer.hpp
//  Shirodora
//
//  Created by 毎床　公喜 on 2016/07/09.
//
//

#ifndef UI_Layer_hpp
#define UI_Layer_hpp

#include "cocos2d.h"

class CTimeLable;
class CCastleHpBar;

enum class CZoderUI : int{
    Time = 0,
    Bar = 1,
    Cost = 2,
    Icons = 3,
};

class CUI_Layer : public cocos2d::Layer{
private:
    //制限時間
    CTimeLable* m_pTimeLabel = NULL;
    //城の耐久値
    CCastleHpBar* m_pCastleHpBar = NULL;
public:
    CUI_Layer();
    ~CUI_Layer();
    
    bool init() override;
    
    void update(float _dt)override;
    
    CREATE_FUNC(CUI_Layer);
};

#endif /* UI_Layer_hpp */
