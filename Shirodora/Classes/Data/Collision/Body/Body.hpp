//
//  Body.hpp
//  BarrageGame
//
//  Created by Ryoutarou Onimura on 2016/06/14.
//
//

#ifndef Body_hpp
#define Body_hpp

#include <stdio.h>

//=========================================================================
// 追加のインクルードはここから
//=========================================================================

//=========================================================================
// 関数やマクロ定義はここから
//=========================================================================

//=========================================================================
//
// Body
//
//=========================================================================
class CBody {
public :
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
    /**
     *  @desc   constructor
     */
    CBody() ;
    
    /**
     *  @desc   constructor
     */
    CBody(const cocos2d::Vec2 &center) ;
    
    /**
     *  @desc   constructor
     */
    CBody(const std::vector<cocos2d::Vec2> &apexs, const cocos2d::Vec2 &center = cocos2d::Vec2(0.0f, 0.0f)) ;
    
    /**
     *  @desc   constructor
     */
    CBody(int apexSize, const cocos2d::Vec2 apexs[], const cocos2d::Vec2 &center = cocos2d::Vec2(0.0f, 0.0f)) ;
    
    /**
     *  @desc   copy constructor
     */
    CBody(const CBody &body) ;
    
    /**
     *  @desc   destructor
     */
    virtual ~CBody() ;
    
    //=========================================================================
    // set
    //=========================================================================
    /**
     *  @desc   中心座標設定
     *  @param  中心座標
     */
    void set(const cocos2d::Vec2 &center) ;
    
    /**
     *  @desc   座標設定
     *  @param  頂点座標群
     *  @param  中心座標
     */
    void set(const std::vector<cocos2d::Vec2> &apexs, const cocos2d::Vec2 &center = cocos2d::Vec2(0.0f, 0.0f)) ;
    
    /**
     *  @desc   座標設定
     *  @param  頂点数
     *  @param  頂点座標配列
     *  @param  中心座標
     */
    void set(int apexSize, const cocos2d::Vec2 apexs[], const cocos2d::Vec2 &center = cocos2d::Vec2(0.0f, 0.0f)) ;
    
    /**
     *  @desc   座標設定
     *  @param  CBody
     */
    void set(const CBody &body) ;
    
    /**
     *  @desc   太さ設定
     *  @param  太さ
     */
    inline void setRadius(float radius){this->m_radius = radius ;}
    
    //=========================================================================
    // get
    //=========================================================================
    /**
     *  @desc   頂点数取得
     *  @return 頂点数
     */
    int getApexSize() const ;
    
    /**
     *  @desc   頂点座標群取得
     *  @return const std::vector<cocos2d::Vec2>*
     */
    const std::vector<cocos2d::Vec2>* getApexs() const ;
    
    /**
     *  @desc   頂点座標取得
     *  @param  添字番号
     *  @return array
     *  @tips   受け値は const float* apex ;
     */
    cocos2d::Vec2 getApexAt(int index) const ;
    
    /**
     *  @desc   中心座標取得
     *  @return cocos2d::Vec2
     */
    cocos2d::Vec2 getCenter() const ;
    
    /**
     *  @desc   太さ取得
     *  @param  太さ
     */
    inline float getRadius(){return this->m_radius ;}
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
    /**
     *  @desc   座標移動
     *  @param  移動ベクトル
     */
    void move(const cocos2d::Vec2 &vector) ;
    
    /**
     *  @desc   座標回転
     *  @param  回転角度
     */
    void rotate(float angle, const cocos2d::Vec2 &point = cocos2d::Vec2::ZERO) ;
    
    /**
     *  @desc   指定された向きで最も遠くにある頂点座標を返す
     *  @param  方向ベクトル
     *  @return 最も遠い頂点座標
     */
    cocos2d::Vec2 getFarthestPointInDirection(const cocos2d::Vec2 &direction) const ;
    
private :
    //=========================================================================
    // init
    //=========================================================================
    /**
     *  @desc   init
     *  @param  頂点座標群
     *  @param  中心座標
     */
    void init() ;
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
    /**
     *  @desc   頂点座標追加
     *  @param  頂点座標
     */
    void addApex(const cocos2d::Vec2 &apex) ;
    
    //=========================================================================
    // メンバ変数
    //=========================================================================
    // 頂点座標群
    std::vector<cocos2d::Vec2> *m_pApexs {NULL} ;
    // 中心座標
    cocos2d::Vec2 m_center ;
    // 太さ
    float m_radius = 0.0f ;
};

#endif /* Body_hpp */
