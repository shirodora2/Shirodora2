//
//  Simplex.hpp
//  BarrageGame
//
//  Created by Ryoutarou Onimura on 2016/06/23.
//
//

#ifndef Simplex_hpp
#define Simplex_hpp

#include <stdio.h>

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include "Shape.hpp"

//=========================================================================
//
// 単体クラス(２次元での最小単位形状クラス)
// キュー配列
//
//=========================================================================
class CSimplex {
public :
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
    /**
     *  @desc   constructor
     */
    CSimplex() ;
    
    /**
     *  @desc   destructor
     */
    virtual ~CSimplex() ;
    
    //=========================================================================
    // set
    //=========================================================================
    /**
     *  @desc   頂点を追加する
     *  @param  追加する頂点座標
     */
    void add(const cocos2d::Vec2 &apex) ;
    
    //=========================================================================
    // get
    //=========================================================================
    /**
     *  @desc   現在の配列サイズ取得
     *  @return 配列サイズ
     *  @tips   for文のお共にどうぞ
     */
    int getCurrentArraySize() const ;
    
    /**
     *  @desc   指定した添字の頂点座標取得
     *  @return 頂点座標
     */
    cocos2d::Vec2 getApexAt(int index) const ;
    
    /**
     *  @desc   最後尾添字番号取得
     *  @return 最後尾添字番号
     */
    int getLastIndex() const ;
    
    /**
     *  @desc   最後尾に格納されている頂点座標取得
     *  @return 頂点座標
     */
    cocos2d::Vec2 getLastApex() const ;
    
    /**
     *  @desc   配列がいっぱいかを返す
     *  @return true...いっぱい alse...いっぱいではない
     */
    bool isFull() const ;
    
    /**
     *  @desc   配列が空を返す
     *  @return true...いっぱい alse...いっぱいではない
     */
    bool isEmpty() const ;
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
    /**
     *  @desc   対象の点と単体での最近点を求める
     *  @param  対象の点座標
     *  @return 最近点
     */
    cocos2d::Vec2 getRecentlyPositionInSimplex(const cocos2d::Vec2 &point) const ;
    
    /**
     *  @desc   指定された直線と最も離れた位置の交点を取得する
     *  @param  線分
     */
    cocos2d::Vec2 getFarthestCrossPositionInSimplex(const CLine &line) const ;
    
    /**
     *  @desc   対象の点が単体内に含まれているかを調べる関数
     *  @param  対象の点座標
     *  @return true...含まれている, false...含まれていない
     */
    bool isContainsPoint(const cocos2d::Vec2 &point = cocos2d::Vec2::ZERO) const ;
    
    /**
     *  @desc   指定された座標が単体に登録されているかを返す
     *  @return true...登録されている false...登録されていない
     */
    bool isRegistered(const cocos2d::Vec2 &point) const ;
    
private :
    //=========================================================================
    // メンバ関数
    //=========================================================================
    /**
     *  @desc   配列を詰める
     */
    void closeArray() ;
    
    /**
     *  @desc   添字番号を増やす
     */
    void addIndex() ;
    
    /**
     *  @desc   添字番号を減らす
     */
    void subIndex() ;
    
    //=========================================================================
    // メンバ変数
    //=========================================================================
    // 配列サイズ
    const int ARRAY_SIZE = 3 ;
    // 配列がいっぱい
    bool m_isFull = false ;
    // 配列が空
    bool m_isEmpty = true ;
    // 現在格納できる配列の最後尾添字番号
    int m_currentIndex = 0 ;
    // 頂点座標配列
    cocos2d::Vec2 *m_apexs[3] {NULL} ;
    
};

#endif /* Simplex_hpp */