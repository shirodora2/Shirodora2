//
//  Line.hpp
//  BarrageGame
//
//  Created by Ryoutarou Onimura on 2016/06/23.
//
//

#ifndef Line_hpp
#define Line_hpp

#include <stdio.h>

//=========================================================================
// 追加のインクルードはここから
//=========================================================================

//=========================================================================
//
// Line
//
//=========================================================================
class CLine {
public :
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
    /**
     *  @desc   constructor
     */
    CLine() ;
    
    /**
     *  @desc   constructor
     */
    CLine(const cocos2d::Vec2 &endPoint) ;
    
    /**
     *  @desc   constructor
     */
    CLine(const cocos2d::Vec2 &startPoint, const cocos2d::Vec2 &endPoint) ;
    
    /**
     *  @desc   destructor
     */
    virtual ~CLine() ;
    
    //=========================================================================
    // set
    //=========================================================================
    /**
     *  @desc   set
     *  @param  始点座標
     *  @param  終点座標
     */
    void set(const cocos2d::Vec2 &startPoint, const cocos2d::Vec2 &endPoint) ;
    
    //=========================================================================
    // get
    //=========================================================================
    // メンバ変数は public なので特になし
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
    /**
     *  @desc   点と線分上での最近点を求める
     *  @param  対象の点
     *  @return 最近点座標
     */
    cocos2d::Vec2 getRecentlyPosition(const cocos2d::Vec2 &point) const ;
    
    /**
     *  @desc   点と線分上での最近点を求める
     *  @param  対象の点
     *  @return 最近点座標
     *  @tips   直線上ではなく、線分上という限られた長さであることに注意
     */
    cocos2d::Vec2 getRecentlyPositionInLine(const cocos2d::Vec2 &point) const ;
    
    /**
     *  @desc   指定された直線と、自身の直線上での交点を取得する
     *  @param  直線
     *  @return 交点座標
     */
    cocos2d::Vec2 getCrossPosition(const CLine &line) const ;
    
    /**
     *  @desc   指定された直線と、自身の線分上での交点を取得する
     *  @param  直線
     *  @return 交点座標
     *  @tips   直線上での交点ではなく、線分上という点に注意
     */
    cocos2d::Vec2 getCrossPositionInLine(const CLine &line) const ;
    
    /**
     *  @desc   指定された座標がベクトルの内外どちらにあるか
     *  @return 1...外 -1...内 0...線上
     */
    int getInOrOut(const cocos2d::Vec2 &point) const ;
    
    /**
     *  @desc   平行かどうか
     *  @param  線分
     *  @return true...平行 false...平行ではない
     */
    bool isParallel(const CLine &line) const ;
    
    /**
     *  @desc   指定された直線が自身の線分上で交差するかを取得
     *  @param  線分
     *  @return true...交差しない false...交差する
     *  @tips   直線上で交差するかでなく、線分上というのに注意
     *  @tips   直線同士で交差するかなら、isParallel()で判断してください
     */
    bool isCrossed(const CLine &line) const ;
    
    /**
     *  @desc   線上に点が含まれているか
     *  @return true...含まれている false...含まれていない
     */
    bool isContaintsPoint(const cocos2d::Vec2 &point) const ;
    
    //=========================================================================
    // メンバ変数
    //=========================================================================
    // 始点、終点
    cocos2d::Vec2 m_point[2] ;
    // 線分の正規ベクトル
    cocos2d::Vec2 m_nVec ;
    // 線分の長さ
    float m_length = 0.0f ;
};

#endif /* Line_hpp */
