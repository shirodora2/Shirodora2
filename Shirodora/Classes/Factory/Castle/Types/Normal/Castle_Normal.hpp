//
//  Castle_Normal.hpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/08/20.
//
//

#ifndef Castle_Normal_hpp
#define Castle_Normal_hpp

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include "CastleCreateFactory.hpp"

//=========================================================================
//
// CCastle_Normal
//
//=========================================================================
class CCastle_Normal : public CCastleCreateFactory {
public :
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
    /**
     *  @desc   constructor
     */
    CCastle_Normal() ;
    
    /**
     *  @desc   destructor
     */
    ~CCastle_Normal() ;
    
private :
    //=========================================================================
    // メンバ関数
    //=========================================================================
    /**
     *  @desc   位置データ設定
     *  @param  CCastle*
     */
    void setMove(CCastle *pCastle) override ;
    
    /**
     *  @desc   画像データ設定
     *  @param  CCastle*
     */
    void setSprite(CCastle *pCastle) override ;
    
    /**
     *  @desc   ステータス設定
     *  @param  CCastle*
     */
    void setStatus(CCastle *pCastle) override ;
    
    /**
     *  @desc   実体データ設定
     *  @param  CCastle*
     */
    void setCollisionBody(CCastle *pCastle) override ;
    
    /**
     *  @desc   攻撃範囲データ設定
     *  @param  CCastle*
     */
    void setAttackBody(CCastle *pCastle) override ;
    
    /**
     *  @desc   アニメーションデータ設定
     *  @param  CCastle*
     */
    void setAnimation(CCastle *pCastle) override ;
    
    /**
     *  @desc   アクションデータ設定
     *  @param  CCastle*
     */
    void setAction(CCastle *pCastle) override ;
    
};

#endif /* Castle_Normal_hpp */
