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
     *  @tips   頂点数0の原点のみの点として生成
     */
    CBody() ;
    
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
    inline void setCenterPosition(const cocos2d::Vec2 &center){
        this->m_centerPosition = center ;
    }
    
    /**
     *  @desc   座標設定
     *  @param  頂点座標群 std::vector
     */
    void setApexs(const std::vector<cocos2d::Vec2> &apexs) ;
    
    /**
     *  @desc   座標設定
     *  @param  頂点数
     *  @param  頂点座標配列
     */
    void setApexs(int apexSize, const cocos2d::Vec2 apexs[]) ;
    
    /**
     *  @desc   太さ設定
     *  @param  太さ
     */
    inline void setRadius(float radius){this->m_radius = radius ;}
    
    /**
     *  @desc   座標設定
     *  @param  CBody
     */
    void set(const CBody &body) ;
    
    //=========================================================================
    // get
    //=========================================================================
    /**
     *  @desc   頂点数取得
     *  @return 頂点数
     */
    inline int getApexSize() const {return this->m_pApexs->size() ;}
    
    /**
     *  @desc   頂点座標群取得
     *  @return std::vector<cocos2d::Vec2>*
     */
    inline std::vector<cocos2d::Vec2> *getApexs() const {return this->m_pApexs ;}
    
    /**
     *  @desc   頂点座標取得
     *  @param  添字番号
     *  @return 座標
     */
    inline cocos2d::Vec2 getApexAt(int index) const {return (*this->m_pApexs)[index] ;}
    
    /**
     *  @desc   中心座標取得
     *  @return cocos2d::Vec2
     */
    inline cocos2d::Vec2 getCenterPosition() const {return this->m_centerPosition ;}
    
    /**
     *  @desc   太さ取得
     *  @param  太さ
     */
    inline float getRadius() const {return this->m_radius ;}
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
    /**
     *  @desc   座標移動
     *  @param  移動ベクトル
     */
    void move(const cocos2d::Vec2 &vector) ;
    
    /**
     *  @desc   指定された向きで最も遠くにある頂点座標を返す
     *  @param  方向ベクトル
     *  @return 最も遠い頂点座標
     */
    cocos2d::Vec2 getFarthestPointInDirection(const cocos2d::Vec2 &direction) const ;
    
private :
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
    cocos2d::Vec2 m_centerPosition ;
    // 太さ
    float m_radius = 0.0f ;
};

#endif /* Body_hpp */
