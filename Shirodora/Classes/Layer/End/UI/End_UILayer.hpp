//
//  End_UILayer.hpp
//  Shirodora
//
//  Created by 今西一喜 on 2016/08/16.
//
//

#ifndef End_UILayer_hpp
#define End_UILayer_hpp

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include "InputLayer.hpp"


//======================================================
//
// タイトルUIクラス
//
//======================================================
class CEnd_UILayer : public CInputLayer{
public:
    CEnd_UILayer();
    ~CEnd_UILayer();
    
public:
    bool init() override;
    void update(float _dt)override;
    
    /**
     *  @desc   入力処理
     */
    void inputFunc();
    
private:
    
};


#endif /* End_UILayer_hpp */
