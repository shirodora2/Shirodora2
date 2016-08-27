//
//  CreateFactory.hpp
//  Shirodora
//
//  Created by 服部優宇一 on 2016/08/20.
//
//

#ifndef KingCreateFactory_hpp
#define KingCreateFactory_hpp

#include <stdio.h>

//=========================================================================
// 前方宣言
//=========================================================================
class CKing ;

//=========================================================================
//
// SummonCreateFactory
//
//=========================================================================
class CKingCreateFactory {
    public :
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
    /**
     *  @desc   destructor
     */
    virtual ~CKingCreateFactory() ;
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
    /**
     *  @desc   キング生成
     *  @param  タグ
     *  @param  生成位置
     */
    CKing *create(int tag, const cocos2d::Vec2 &position) ;
    
    private :
    //=========================================================================
    // メンバ関数
    //=========================================================================
    /**
     *  @desc   キング生成とメンバ変数取り付け
     */
    CKing *create() ;
    
    /**
     *  @desc   位置データ設定
     *  @param  CKing*
     */
    virtual void setMove(CKing* , const cocos2d::Vec2 &position) = 0 ;
    
    /**
     *  @desc   画像データ設定
     *  @param  CKing*
     */
    virtual void setSprite(CKing*) = 0 ;
    
    /**
     *  @desc   ステータス設定
     *  @param  CKing*
     */
    virtual void setStatus(CKing*) = 0 ;
    
    /**
     *  @desc   実体データ設定
     *  @param  CKing*
     */
    virtual void setCollisionBody(CKing*) = 0 ;
    
    /**
     *  @desc   攻撃範囲データ設定
     *  @param  CKing*
     */
    virtual void setAttackBody(CKing*) = 0 ;
    
    /**
     *  @desc   アニメーションデータ設定
     *  @param  CKing*
     */
    virtual void setAnimation(CKing*) = 0 ;
    
    /**
     *  @desc   アクションデータ設定
     *  @param  CKing*
     */
    virtual void setAction(CKing*) = 0 ;
    
    /**
     *  @desc   タグ設定
     *  @param  タグNo
     */
    virtual void setTag(CKing*, int tag) = 0 ;
    
};


#endif /* KingCreateFactory_hpp */
