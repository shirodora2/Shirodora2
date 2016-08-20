//
//  CastleCreateFactory.hpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/08/20.
//
//

#ifndef CastleCreateFactory_hpp
#define CastleCreateFactory_hpp

//=========================================================================
// 前方宣言
//=========================================================================
class CCastle ;

//=========================================================================
//
// CCastleCreateFactory
//
//=========================================================================
class CCastleCreateFactory {
public :
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
    /**
     *  @desc   destructor
     */
    virtual ~CCastleCreateFactory() ;
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
    /**
     *  @desc   召喚生成
     *  @param  タグ
     *  @param  生成位置
     */
    CCastle *create(int tag, const cocos2d::Vec2 &position) ;
    
private :
    //=========================================================================
    // メンバ関数
    //=========================================================================
    /**
     *  @desc   召喚生成とメンバ変数取り付け
     */
    CCastle *create() ;
    
    /**
     *  @desc   位置データ設定
     *  @param  CCastle*
     */
    virtual void setMove(CCastle*) = 0 ;
    
    /**
     *  @desc   画像データ設定
     *  @param  CCastle*
     */
    virtual void setSprite(CCastle*) = 0 ;
    
    /**
     *  @desc   ステータス設定
     *  @param  CCastle*
     */
    virtual void setStatus(CCastle*) = 0 ;
    
    /**
     *  @desc   実体データ設定
     *  @param  CCastle*
     */
    virtual void setCollisionBody(CCastle*) = 0 ;
    
    /**
     *  @desc   攻撃範囲データ設定
     *  @param  CCastle*
     */
    virtual void setAttackBody(CCastle*) = 0 ;
    
    /**
     *  @desc   アニメーションデータ設定
     *  @param  CCastle*
     */
    virtual void setAnimation(CCastle*) = 0 ;
    
    /**
     *  @desc   アクションデータ設定
     *  @param  CCastle*
     */
    virtual void setAction(CCastle*) = 0 ;
    
};

#endif /* CastleCreateFactory_hpp */
