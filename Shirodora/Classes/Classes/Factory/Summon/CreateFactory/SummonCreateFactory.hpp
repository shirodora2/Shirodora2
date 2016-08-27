//
//  SummonCreateFactory.hpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/07/16.
//
//

#ifndef SummonCreateFactory_hpp
#define SummonCreateFactory_hpp

//=========================================================================
// 前方宣言
//=========================================================================
class CSummon ;

//=========================================================================
//
// SummonCreateFactory
//
//=========================================================================
class CSummonCreateFactory {
public :
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
    /**
     *  @desc   destructor
     */
    virtual ~CSummonCreateFactory() ;
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
    /**
     *  @desc   召喚生成
     *  @param  タグ
     *  @param  生成位置
     */
    CSummon *create(int tag, const cocos2d::Vec2 &position) ;
    
private :
    //=========================================================================
    // メンバ関数
    //=========================================================================
    /**
     *  @desc   召喚生成とメンバ変数取り付け
     */
    CSummon *create() ;
    
    /**
     *  @desc   位置データ設定
     *  @param  CSummon*
     */
    virtual void setMove(CSummon* , const cocos2d::Vec2 &position) = 0 ;
    
    /**
     *  @desc   画像データ設定
     *  @param  CSummon*
     */
    virtual void setSprite(CSummon*) = 0 ;
    
    /**
     *  @desc   ステータス設定
     *  @param  CSummon*
     */
    virtual void setStatus(CSummon*) = 0 ;
    
    /**
     *  @desc   実体データ設定
     *  @param  CSummon*
     */
    virtual void setCollisionBody(CSummon*) = 0 ;
    
    /**
     *  @desc   攻撃範囲データ設定
     *  @param  CSummon*
     */
    virtual void setAttackBody(CSummon*) = 0 ;
    
    /**
     *  @desc   アニメーションデータ設定
     *  @param  CSummon*
     */
    virtual void setAnimation(CSummon*) = 0 ;
    
    /**
     *  @desc   アクションデータ設定
     *  @param  CSummon*
     */
    virtual void setAction(CSummon*) = 0 ;
    
    /**
     *  @desc   タグ設定
     *  @param  タグNo
     */
    virtual void setTag(CSummon*, int tag) = 0 ;
    
};

#endif /* SummonCreateFactory_hpp */
