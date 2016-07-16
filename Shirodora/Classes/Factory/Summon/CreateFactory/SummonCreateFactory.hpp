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
// 追加のインクルードはここから
//=========================================================================

//=========================================================================
// 前方宣言
//=========================================================================
class CSummon ;

//=========================================================================
//
// EnemyUnitCreateFactory
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
     *  @desc   敵ユニット生成
     *  @param  生成位置
     */
    CSummon *create(const cocos2d::Vec2 &position) ;
    
private :
    //=========================================================================
    // メンバ関数
    //=========================================================================
    /**
     *  @desc   敵ユニット生成とメンバ変数取り付け
     */
    CSummon *create() ;
    
    /**
     *  @desc   位置データ設定
     *  @param  CEnemyUnit*
     */
    virtual void setMove(CSummon *pUnit , const cocos2d::Vec2 &position) = 0 ;
    
    /**
     *  @desc   画像データ設定
     *  @param  CEnemyUnit*
     */
    virtual void setSprite(CSummon*) = 0 ;
    
    /**
     *  @desc   ステータス設定
     *  @param  CEnemyUnit*
     */
    virtual void setStatus(CSummon*) = 0 ;
    
    /**
     *  @desc   実体データ設定
     *  @param  CEnemyUnit*
     */
    virtual void setCollisionBody(CSummon*) = 0 ;
    
    /**
     *  @desc   アニメーションデータ設定
     *  @param  CEnemyUnit*
     */
    virtual void setAnimation(CSummon*) = 0 ;
    
    /**
     *  @desc   アクションデータ設定
     *  @param  CEnemyUnit*
     */
    virtual void setAction(CSummon*) = 0 ;
    
};

#endif /* SummonCreateFactory_hpp */
