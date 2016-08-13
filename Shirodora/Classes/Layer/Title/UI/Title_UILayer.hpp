//
//  Title_UILayer.hpp
//  Shirodora
//
//  Created by 今西一喜 on 2016/08/13.
//
//

#ifndef CTitle_UILayer_hpp
#define CTitle_UILayer_hpp

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include "InputLayer.hpp"


//======================================================
//
// タイトルUIクラス
//
//======================================================
class CTitle_UILayer : public CInputLayer{
public:
    CTitle_UILayer();
    ~CTitle_UILayer();
    
public:
    bool init() override;
    void update(float _dt)override;
   
    /**
     *  @desc   入力処理
     */
    void inputFunc();

private:
    
};

#endif /* CTitle_UILayer_hpp */
