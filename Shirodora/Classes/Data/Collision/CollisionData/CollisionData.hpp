//
//  CollisionData.hpp
//  Experiment
//
//  Created by Ryoutarou Onimura on 2016/07/09.
//
//

#ifndef CollisionData_hpp
#define CollisionData_hpp

#include <stdio.h>

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
//#include "Shapes.hpp"
#include "Line.hpp"
#include "Simplex.hpp"

//=========================================================================
// 前方宣言
//=========================================================================
class CMove ;
class CBody ;

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
     *  @tips   位置座標(0.0f, 0.0f)の点として生成される
     */
    CCollisionData() ;
    
    /**
     *  @desc   constructer
     *  @param  CMove*
     *  @param  CBody*
     */
    CCollisionData(CMove *pMove, CBody *pBody) ;
    
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
    // 定数
    //=========================================================================
    // while内で不具合が起こった時の保険用変数
    const int MAX_COUNT = 20 ;
    
    //=========================================================================
    // set
    //=========================================================================
    /**
     *  @desc   位置座標設定
     *  @param  位置座標
     */
    inline void setPosition(const cocos2d::Vec2 &position){this->m_position = position ;}
    
    /**
     *  @desc   角度設定
     *  @param  回転角度 ディグリー角
     */
    inline void setAngle(float angle){this->m_angle = angle ;}
    
    /**
     *  @desc   頂点座標群設定
     *  @param  頂点座標群
     */
    void setApexs(const std::vector<cocos2d::Vec2> &apexs) ;
    
    /**
     *  @desc   太さ設定
     *  @param  太さ(円の半径)
     */
    inline void setRadius(float radius){this->m_radius = radius ;}
    
    /**
     *  @desc   set
     *  @param  CCollisionData
     */
    inline void set(const CCollisionData &data){
        this->m_position = data.getPosition() ;
        this->setApexs(*data.getApexs()) ;
        this->m_radius = data.getRadius() ;
        this->m_angle = data.getAngle() ;
    }
    
    //=========================================================================
    // get
    //=========================================================================
    /**
     *  @desc   位置座標取得
     *  @return 位置座標
     */
    inline cocos2d::Vec2 getPosition() const {return this->m_position ;}
    
    /**
     *  @desc   角度取得
     *  @return 角度 ディグリー角
     */
    inline float getAngle() const {return this->m_angle ;}
    
    /**
     *  @desc   頂点座標群取得
     *  @return 頂点座標群
     */
    inline std::vector<cocos2d::Vec2> *getApexs() const {return this->m_pApexs ;}
    
    /**
     *  @desc   太さ取得
     *  @return 太さ
     */
    inline float getRadius() const {return this->m_radius ;}
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
    /**
     *  @desc   座標回転
     */
    inline void rotateApexs(){
        if(this->m_angle == 0.0f) return ;
        
        // ディグリー角をラジアン角に変換
        float radian = -M_PI * (this->m_angle / 180.0f) ;
        
        std::vector<cocos2d::Vec2>::iterator itr = this->m_pApexs->begin() ;
        while(itr != this->m_pApexs->end()){
            (*itr).rotate(cocos2d::Vec2::ZERO, radian) ;
            itr++ ;
        }
    }
    
    //=========================================================================
    // 衝突関数
    //=========================================================================
    /**
     *  @desc   衝突判定
     *  @param  衝突データ
     */
    bool collisionDecision(CCollisionData data) ;
    
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
    // 角度 ディグリー角
    float m_angle = 0.0f ;
    // 頂点座標群
    std::vector<cocos2d::Vec2> *m_pApexs {NULL} ;
    // 太さ(円などに使用)
    float m_radius = 0.0f ;
    
};

#endif /* CollisionData_hpp */
