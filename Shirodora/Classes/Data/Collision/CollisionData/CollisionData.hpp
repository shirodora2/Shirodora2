//
//  CollisionData.hpp
//  BarrageGame
//
//  Created by Ryoutarou Onimura on 2016/06/15.
//
//

#ifndef CollisionData_hpp
#define CollisionData_hpp

#include <stdio.h>

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include "Body.hpp"
#include "Move.hpp"
#include "Shape.hpp"

//=========================================================================
//
// CollisionData
//
//=========================================================================
class CCollisionData {
public :
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
    /**
     *  @desc   constructor
     */
    CCollisionData() ;
    
    /**
     *  @desc   constructor
     *  @param  位置座標
     */
    CCollisionData(const cocos2d::Vec2 &position) ;
    
    /**
     *  @desc   constructor
     *  @param  位置座標
     *  @param  頂点座標群
     */
    CCollisionData(const cocos2d::Vec2 &position, const std::vector<cocos2d::Vec2> &apexs) ;
    
    /**
     *  @desc   copy constructor
     *  @param  CCollisionData
     */
    CCollisionData(const CCollisionData &data) ;
    
    /**
     *  @desc   destructor
     */
    virtual ~CCollisionData() ;
    
    //=========================================================================
    // set
    //=========================================================================
    /**
     *  @desc   set
     *  @param  位置座標
     *  @param  頂点座標群
     */
    void set(const cocos2d::Vec2 &position, const std::vector<cocos2d::Vec2> &apexs) ;
    
    /**
     *  @desc   set
     *  @param  CCollisionData
     */
    void set(const CCollisionData &data) ;
    
    /**
     *  @desc   setPosition
     *  @param  位置座標
     */
    void setPosition(const cocos2d::Vec2 &position) ;
    
    /**
     *  @desc   setApexs
     *  @param  頂点座標群
     */
    void setApexs(const std::vector<cocos2d::Vec2> &apexs) ;
    
    /**
     *  @desc   setThick
     *  @param  太さ(円の半径)
     */
    void setThick(float thick) ;
    
    //=========================================================================
    // get
    //=========================================================================
    /**
     *  @desc   getPosition
     *  @return 位置座標
     */
    cocos2d::Vec2 getPosition() const ;
    
    /**
     *  @desc   getApexs
     *  @return 頂点座標群
     */
    std::vector<cocos2d::Vec2> &getApexs() const ;
    
    /**
     *  @desc   getThick
     *  @return 太さ
     */
    float getThick() const ;
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
    //=========================================================================
    // 衝突関数
    //=========================================================================
    /**
     *  @desc   衝突判定
     *  @param  衝突データ
     */
    bool collisionDecision(const CCollisionData &data) const ;
    
private :
    //=========================================================================
    // GJKアルゴリズム
    //=========================================================================
    /**
     *  @desc   GJKアルゴリズム
     *  @param  衝突データ
     *  @tips   座標データを弄くり回すので値渡し
     */
    bool GJKAlgorithm(CCollisionData data) const ;
    
    /**
     *  @desc   指定されたベクトル方向におけるミンコフスキー差におけるサポート支点座標を得る
     *  @param  ベクトル方向
     *  @return ミンコフスキー差サポート支点座標
     */
    cocos2d::Vec2 getSupportMappingFulcrum(const CCollisionData &data, const cocos2d::Vec2 &direction) const ;
    
    /**
     *  @desc   指定された頂点座標群から、指定されたベクトル方向における最も離れた頂点を求める
     *  @param  頂点座標群
     *  @param  ベクトル方向
     *  @return 頂点座標
     */
    cocos2d::Vec2 getFarthestApexInDirection(const cocos2d::Vec2 &position, const std::vector<cocos2d::Vec2> *pApexs, const cocos2d::Vec2 &direction) const ;
    
    /**
     *  @desc   次のサポート支点を得るためのベクトル方向を得る
     *  @param  CSimplex
     *  @return ベクトル方向
     *  @tips   return  する値を反転させたものが実際に使用するベクトルとなる
     */
    cocos2d::Vec2 getGJKNextDirection(const CSimplex &simplex) const ;
    
    //=========================================================================
    // メンバ変数
    //=========================================================================
    // 位置座標
    cocos2d::Vec2 m_position ;
    // 頂点座標群
    std::vector<cocos2d::Vec2> *m_pApexs {NULL} ;
    // 太さ(円などに使用)
    float m_thick = 0.0f ;
    
};

#endif /* CollisionData_hpp */
