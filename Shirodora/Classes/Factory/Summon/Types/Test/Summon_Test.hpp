//
//  Summon_Test.hpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/07/16.
//
//

#ifndef Summon_Test_hpp
#define Summon_Test_hpp

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include "SummonCreateFactory.hpp"

//=========================================================================
//
// SummonCreateFactory
//
//=========================================================================
class CSummon_Test : public CSummonCreateFactory {
public :
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
    /**
     *  @desc   constructor
     */
    CSummon_Test() ;
    
    /**
     *  @desc   destructor
     */
    virtual ~CSummon_Test() ;
    
private :
    //=========================================================================
    // メンバ関数
    //=========================================================================
    /**
     *  @desc   位置データ設定
     *  @param  CSummon*
     */
    virtual void setMove(CSummon *pSummon , const cocos2d::Vec2 &position) override ;
    
    /**
     *  @desc   画像データ設定
     *  @param  CSummon*
     */
    virtual void setSprite(CSummon *pSummon) override ;
    
    /**
     *  @desc   ステータス設定
     *  @param  CSummon*
     */
    virtual void setStatus(CSummon *pSummon) override ;
    
    /**
     *  @desc   実体データ設定
     *  @param  CSummon*
     */
    virtual void setCollisionBody(CSummon *pSummon) override ;
    
    /**
     *  @desc   攻撃範囲データ設定
     *  @param  CSummon*
     */
    virtual void setAttackBody(CSummon *pSummon) override ;
    
    /**
     *  @desc   アニメーションデータ設定
     *  @param  CSummon*
     */
    virtual void setAnimation(CSummon *pSummon) override ;
    
    /**
     *  @desc   アクションデータ設定
     *  @param  CSummon*
     */
    virtual void setAction(CSummon *pSummon) override ;
    
    /**
     *  @desc   タグ設定
     *  @param  タグNo
     */
    virtual void setTag(CSummon *pSummon) override ;
    
};

#endif /* Summon_Test_hpp */
