//
//  Line.cpp
//  BarrageGame
//
//  Created by Ryoutarou Onimura on 2016/06/23.
//
//

#include "Line.hpp"

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include "Constants.hpp"

//=========================================================================
//
// 線分クラス
//
//=========================================================================
//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
/**
 *  @desc   constructor
 */
CLine::CLine(){}

/**
 *  @desc   constructor
 */
CLine::CLine(const cocos2d::Vec2 &endPoint){
    this->set(cocos2d::Vec2::ZERO, endPoint) ;
}

/**
 *  @desc   constructor
 */
CLine::CLine(const cocos2d::Vec2 &startPoint, const cocos2d::Vec2 &endPoint){
    this->set(startPoint, endPoint) ;
}

/**
 *  @desc   destructor
 */
CLine::~CLine(){}

//=========================================================================
// set
//=========================================================================
/**
 *  @desc   set
 *  @param  始点座標
 *  @param  終点座標
 */
void CLine::set(const cocos2d::Vec2 &startPoint, const cocos2d::Vec2 &endPoint){
    this->m_point[0] = startPoint ;
    this->m_point[1] = endPoint ;
    this->m_nVec = (endPoint - startPoint).getNormalized() ;
    this->m_length = (endPoint - startPoint).getLength() ;
}

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
cocos2d::Vec2 CLine::getRecentlyPosition(const cocos2d::Vec2 &point) const {
    cocos2d::Vec2 vector = point - this->m_point[0] ;
    float distance = this->m_nVec.dot(vector) ;
    return this->m_point[0] + (this->m_nVec * distance) ;
}

/**
 *  @desc   点と線分上での最近点を求める
 *  @param  対象の点
 *  @return 最近点座標
 *  @tips   直線上ではなく、線分上という限られた長さであることに注意
 */
cocos2d::Vec2 CLine::getRecentlyPositionInLine(const cocos2d::Vec2 &point) const {
    cocos2d::Vec2 vector = point - this->m_point[0] ;
    float distance = this->m_nVec.dot(vector) ;
    if(this->m_length <= distance) return this->m_point[1] ;
    if(distance <= 0.0f) return this->m_point[0] ;
    return this->m_point[0] + (this->m_nVec * distance) ;
}

/**
 *  @desc   指定された直線と、自身の直線上での交点を取得する
 *  @param  直線
 *  @return 交点座標
 */
cocos2d::Vec2 CLine::getCrossPosition(const CLine &line) const {
    cocos2d::Vec2 result = cocos2d::Vec2::ZERO ;
    
    if(this->m_nVec.dot(line.m_nVec) == 0.0f){
        printf("２線分は平行\n") ;
        return result ;
    }
    
    float s = this->m_nVec.cross(line.m_point[0]) ;
    if(s == 0.0f) result = this->m_point[0] + (this->m_nVec * this->m_nVec.dot(line.m_point[0])) ;
    float t = this->m_nVec.cross(line.m_point[1]) ;
    if(t == 0.0f) result = this->m_point[0] + (this->m_nVec * this->m_nVec.dot(line.m_point[1])) ;
    
    if(0.0f < s * t){
        if(s < 0.0f && t < 0.0f){
            s = -s ;
            t = -t ;
        }
        result = line.m_point[0] + (line.m_nVec * (line.m_length * (s / (s - t)))) ;
    }
    
    // ２線分は交差している
    else if(s * t <= 0.0f){
        result = line.m_point[0] + (line.m_nVec * (line.m_length * (s / (s - t)))) ;
        result = line.m_point[0] + (line.m_nVec * (line.m_length * (s / (s - t)))) ;
    }
    return result ;
}

/**
 *  @desc   指定された直線と、自身の線分上での交点を取得する
 *  @param  直線
 *  @return 交点座標
 *  @tips   直線上での交点ではなく、線分上という点に注意
 */
cocos2d::Vec2 CLine::getCrossPositionInLine(const CLine &line) const {
    cocos2d::Vec2 result = cocos2d::Vec2::ZERO ;
    
    if(this->m_nVec.dot(line.m_nVec) == 0.0f && this->m_nVec.cross(line.m_nVec) == 0.0f){
        //printf("２線分は垂直\n") ;
        float l = line.m_nVec.dot(this->m_point[0] - line.m_point[0]) ;
        result = line.m_point[0] + (line.m_nVec * l) ;
        return result ;
    }
    
    float s = this->m_nVec.cross(line.m_point[0] - this->m_point[0]) ;
    if(s == 0.0f) result = this->m_point[0] + (this->m_nVec * this->m_nVec.dot(line.m_point[0])) ;
    float t = this->m_nVec.cross(line.m_point[1] - this->m_point[0]) ;
    if(t == 0.0f) result = this->m_point[0] + (this->m_nVec * this->m_nVec.dot(line.m_point[1])) ;
    
    if(0.0f < s * t){
        if(s < 0.0f && t < 0.0f){
            s = -s ;
            t = -t ;
        }
        result = line.m_point[0] + (line.m_nVec * (line.m_length * (s / (s - t)))) ;
        if(this->m_length <= this->m_nVec.dot(result - this->m_point[0])){
            result = this->m_point[1] ;
        }
        else if(this->m_nVec.dot(result - this->m_point[0]) <= 0.0f){
            result = this->m_point[0] ;
        }
    }
    
    // ２線分は交差している
    else if(s * t <= 0.0f){
        result = line.m_point[0] + (line.m_nVec * (line.m_length * (s / (s - t)))) ;
        result = line.m_point[0] + (line.m_nVec * (line.m_length * (s / (s - t)))) ;
    }
    return result ;
}

/**
 *  @desc   平行かどうか
 *  @param  線分
 *  @return true...平行 false...平行ではない
 */
bool CLine::isParallel(const CLine &line) const {
    if(this->m_nVec.cross(line.m_nVec) == 0.0f){
        return true ;
    }
    return false ;
}

/**
 *  @desc   指定された直線が自身の線分上で交差するかを取得
 *  @param  線分
 *  @return true...交差しない false...交差する
 *  @tips   直線上で交差するかでなく、線分上というのに注意
 *  @tips   直線同士で交差するかなら、isParallel()で判断してください
 */
bool CLine::isCrossed(const CLine &line) const {
    if(line.m_nVec.cross(this->m_point[0]) * line.m_nVec.cross(this->m_point[1]) <= 0){
        return true ;
    }
    return false ;
}

/**
 *  @desc   指定された座標がベクトルの内外どちらにあるか
 *  @return 1...外 -1...内 0...線上
 *   外
 *  --->
 *   内
 */
int CLine::getInOrOut(const cocos2d::Vec2 &point) const {
    float cross = this->m_nVec.cross(point - this->m_point[0]) ;
    return getSign(cross) ;
}

/**
 *  @desc   線上に点が含まれているか
 *  @return true...含まれている false...含まれていない
 */
bool CLine::isContaintsPoint(const cocos2d::Vec2 &point) const {
    float cross = this->m_nVec.cross(point - this->m_point[0]) ;
    if(-0.001f < cross && cross <= 0.001f){
        float dot = this->m_nVec.dot(point - this->m_point[0]) ;
        if(0.0f <= dot && dot <= this->m_length) return true ;
    }
    return false ;
}
