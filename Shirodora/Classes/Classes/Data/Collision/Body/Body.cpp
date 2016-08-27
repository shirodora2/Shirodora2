//
//  Body.cpp
//  BarrageGame
//
//  Created by Ryoutarou Onimura on 2016/06/14.
//
//

#include "Body.hpp"

//=========================================================================
//
// Body
//
//=========================================================================
//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
/**
 *  @desc   constructor
 *  @tips   頂点数0の原点のみの点として生成
 */
CBody::CBody() : m_centerPosition(0.0f, 0.0f){
    this->m_pApexs = new std::vector<cocos2d::Vec2>() ;
}

/**
 *  @desc   destructor
 */
CBody::~CBody(){
    if(this->m_pApexs != NULL){
        delete this->m_pApexs ;
        this->m_pApexs = NULL ;
    }
}

//=========================================================================
// set
//=========================================================================
/**
 *  @desc   座標設定
 *  @param  頂点座標群 std::vector
 */
void CBody::setApexs(const std::vector<cocos2d::Vec2> &apexs){
    if(apexs.empty() == true) return ;
    this->m_pApexs->erase(this->m_pApexs->begin(), this->m_pApexs->end()) ;
    for(cocos2d::Vec2 apex : apexs){
        this->addApex(apex) ;
    }
}

/**
 *  @desc   座標設定
 *  @param  頂点数
 *  @param  頂点座標配列
 */
void CBody::setApexs(int apexSize, const cocos2d::Vec2 apexs[]){
    if(apexSize == 0) return ;
    this->m_pApexs->erase(this->m_pApexs->begin(), this->m_pApexs->end()) ;
    for(int i = 0 ; i < apexSize ; ++i){
        this->addApex(apexs[i]) ;
    }
}

/**
 *  @desc   座標設定
 *  @param  CBody
 */
void CBody::set(const CBody &body){
    this->m_centerPosition = body.getCenterPosition() ;
    this->setApexs(*body.getApexs()) ;
    this->m_radius = body.getRadius() ;
}

//=========================================================================
// メンバ関数
//=========================================================================
/**
 *  @desc   座標移動
 *  @param  移動ベクトル
 */
void CBody::move(const cocos2d::Vec2 &vector){
    if(vector == cocos2d::Vec2::ZERO) return ;
    
    std::vector<cocos2d::Vec2>::iterator itr = this->m_pApexs->begin() ;
    while(itr != this->m_pApexs->end()){
        *itr += vector ;
        ++itr ;
    }
    this->m_centerPosition += vector ;
}

/**
 *  @desc   指定された向きで最も遠くにある頂点座標を返す
 *  @param  方向ベクトル
 *  @return 最も遠い頂点座標
 */
cocos2d::Vec2 CBody::getFarthestPointInDirection(const cocos2d::Vec2 &direction) const {
    // 中心点のみであればその点を返す
    if(this->m_pApexs == NULL) return this->m_centerPosition ;
    
    // 誤差を抑えるために方向ベクトルを正規化する
    cocos2d::Vec2 vec = direction.getNormalized() ;
    // 暫定戻り値座標と、その頂点までの長さを最初の頂点で登録する
    cocos2d::Vec2 result((*this->m_pApexs)[0]) ;
    float maxLength = (*this->m_pApexs)[0].dot(vec) ;
    // 登録されている全ての頂点と比べる
    for(cocos2d::Vec2 apex : (*this->m_pApexs)){
        float length = apex.dot(vec) ;
        if(maxLength < length){maxLength = length ; result = apex ;}
    }
    return result ;
}

//=========================================================================
// メンバ関数
//=========================================================================
/**
 *  @desc   頂点座標追加
 *  @param  頂点座標
 */
void CBody::addApex(const cocos2d::Vec2 &apex){
    if(this->m_pApexs == NULL) this->m_pApexs = new std::vector<cocos2d::Vec2>() ;
    this->m_pApexs->push_back(apex) ;
}