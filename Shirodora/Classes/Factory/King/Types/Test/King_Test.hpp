//
//  King_Test.hpp
//  Shirodora
//
//  Created by 服部優宇一 on 2016/08/20.
//
//

#ifndef King_Test_hpp
#define King_Test_hpp

#include <stdio.h>

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include "KingCreateFactory.hpp"

//=========================================================================
//
// SummonCreateFactory
//
//=========================================================================
class CKing_Test : public CKingCreateFactory {
    public :
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
    /**
     *  @desc   constructor
     */
    CKing_Test() ;
    
    /**
     *  @desc   destructor
     */
    virtual ~CKing_Test() ;
    
    private :
    //=========================================================================
    // メンバ関数
    //=========================================================================
    /**
     *  @desc   位置データ設定
     *  @param  CKing*
     */
    virtual void setMove(CKing *pKing , const cocos2d::Vec2 &position) override ;
    
    /**
     *  @desc   画像データ設定
     *  @param  CKing*
     */
    virtual void setSprite(CKing *pKing) override ;
    
    /**
     *  @desc   ステータス設定
     *  @param  CKing*
     */
    virtual void setStatus(CKing *pKing) override ;
    
    /**
     *  @desc   実体データ設定
     *  @param  CKing*
     */
    virtual void setCollisionBody(CKing *pKing) override ;
    
    /**
     *  @desc   攻撃範囲データ設定
     *  @param  CKing*
     */
    virtual void setAttackBody(CKing *pKing) override ;
    
    /**
     *  @desc   アニメーションデータ設定
     *  @param  CKing*
     */
    virtual void setAnimation(CKing *pKing) override ;
    
    /**
     *  @desc   アクションデータ設定
     *  @param  CKing*
     */
    virtual void setAction(CKing *pKing) override ;
    
    /**
     *  @desc   タグ設定
     *  @param  タグNo
     */
    virtual void setTag(CKing *pKing, int tag) override ;
    
};


#endif /* King_Test_hpp */
