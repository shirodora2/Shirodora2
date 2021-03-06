//
//  Title_MainLayer.hpp
//  Shirodora
//
//  Created by 今西一喜 on 2016/08/13.
//
//

#ifndef Title_MainLayer_hpp
#define Title_MainLayer_hpp

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include "InputLayer.hpp"


//=========================================================================
//
// CTitle_MainLayer
//
//=========================================================================
class CTitle_MainLayer : public CInputLayer {
    public :
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
    /**
     *  @desc   constructor
     */
    CTitle_MainLayer() ;
    
    /**
     *  @desc   destructor
     */
    virtual ~CTitle_MainLayer() ;
    
    //=========================================================================
    // init
    //=========================================================================
    /**
     *  @desc   init
     */
    virtual bool init() override ;
    
    //=========================================================================
    // set
    //=========================================================================
    
    //=========================================================================
    // get
    //=========================================================================
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
    /**
     *  @desc   update
     *  @param  微小時間
     */
    virtual void update(float deltaTime) override ;
    
    /**
     *  @desc   入力処理
     */
    void inputFunc();
    
    
  
  
    
    //=========================================================================
    // メンバ変数
    //=========================================================================
 
};


#endif /* Title_MainLayer_hpp */
