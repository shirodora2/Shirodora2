//
//  MouseLayer.hpp
//  BarrageGame
//
//  Created by Ryoutarou Onimura on 2016/06/25.
//
//

#ifndef MouseLayer_hpp
#define MouseLayer_hpp

#include <stdio.h>

//=========================================================================
// 追加のインクルードはここから
//=========================================================================

//=========================================================================
//
// マウスレイヤークラス
//
//=========================================================================
class CMouseLayer : public cocos2d::Layer {
public :
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
    /**
     *  @desc   constructor
     */
    CMouseLayer() ;
    
    /**
     *  @desc   destructor
     */
    virtual ~CMouseLayer() override ;
    
    //=========================================================================
    // init
    //=========================================================================
    /**
     *  @desc   init
     */
    virtual bool init() override ;
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
    /**
     *  @desc   マウスクリック時の処理
     *  @param  マウスイベント
     */
    void mouseClicked(cocos2d::EventMouse *pEvent) ;
    
    /**
     *  @desc   マウスドロップ時の処理
     *  @param  マウスイベント
     */
    void mouseDroped(cocos2d::EventMouse *pEvent) ;
    
    /**
     *  @desc   マウス移動時の処理
     *  @param  マウスイベント
     */
    void mouseMoved(cocos2d::EventMouse *pEvent) ;
    
    /**
     *  @desc   マウススクロール時の処理
     *  @param  マウスイベント
     */
    void mouseScrolled(cocos2d::EventMouse *pEvent) ;
    
    /**
     *  @desc   update
     *  @param  deltaTime
     */
    virtual void update(float deltaTime) override ;
    
};

#endif /* MouseLayer_hpp */
