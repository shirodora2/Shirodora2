//
//  EndScene.hpp
//  Shirodora
//
//  Created by 今西一喜 on 2016/08/16.
//
//

#ifndef EndScene_hpp
#define EndScene_hpp


//=========================================================================
//  前方宣言
//=========================================================================
class CEnd_MainLayer ;
class CEnd_UILayer ;


//=========================================================================
//
// CEndScene
//
//=========================================================================
class CEndScene : public cocos2d::Scene {
    public :
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
    /**
     *  @desc   constructor
     */
    CEndScene() ;
    
    /**
     *  @desc   destructor
     */
    ~CEndScene() ;
    
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
    
    //=========================================================================
    // メンバ変数
    //=========================================================================
    // ゲームメインレイヤー
    CEnd_MainLayer *m_pMainLayer {NULL} ;
    
    // UIレイヤー
    CEnd_UILayer *m_pUILayer {NULL} ;
    
    
};


#endif /* EndScene_hpp */
