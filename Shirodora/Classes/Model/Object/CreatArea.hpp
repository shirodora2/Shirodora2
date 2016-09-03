//
//  CreatArea.hpp
//  Shirodora
//
//  Created by 今西一喜 on 2016/09/03.
//
//

#ifndef CreatArea_hpp
#define CreatArea_hpp

#include <stdio.h>
#include "cocos2d.h"

//========================================================================
// 召喚エリア
//========================================================================
class CCreateArea : public cocos2d::Sprite{
public:
    //コンストラクタ
    CCreateArea();
    
    //デストラクタ
    virtual ~CCreateArea();
    
    //初期化処理
    virtual bool init() override;
    
    //更新処理
    virtual void update(float deltaTime) override;
    
    //点滅
    void fadeUpDate(float delta);
};


#endif /* CreatArea_hpp */
