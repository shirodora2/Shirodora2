//
//  CollisionData.cpp
//  BarrageGame
//
//  Created by Ryoutarou Onimura on 2016/06/15.
//
//

#include "CollisionData.hpp"

//=========================================================================
// 追加のインクルードはここから
//=========================================================================

//=========================================================================
//
// CollisionData
//
//=========================================================================
/**
 *  @desc   constructor
 */
CCollisionData::CCollisionData() : m_position(0.0f, 0.0f){}

/**
 *  @desc   constructor
 *  @param  位置座標
 */
CCollisionData::CCollisionData(const cocos2d::Vec2 &position){
    this->setPosition(position) ;
}

/**
 *  @desc   constructor
 *  @param  自身の位置座標
 *  @param  自身の頂点座標群
 *  @param  対象の位置座標
 *  @param  対象の頂点座標群
 */
CCollisionData::CCollisionData(const cocos2d::Vec2 &position, const std::vector<cocos2d::Vec2> &apexs){
    this->set(position, apexs) ;
}

/**
 *  @desc   copy construcor
 *  @param  CCollisionData
 */
CCollisionData::CCollisionData(const CCollisionData &data){
    this->set(data) ;
}

/**
 *  @desc   destructor
 */
CCollisionData::~CCollisionData(){
    if(this->m_pApexs != NULL){
        delete this->m_pApexs ;
        this->m_pApexs = NULL ;
    }
}

//=========================================================================
// set
//=========================================================================
/**
 *  @desc   set
 *  @param  自身の位置座標
 *  @param  自身の頂点座標群
 *  @param  対象の位置座標
 *  @param  対象の頂点座標群
 */
void CCollisionData::set(const cocos2d::Vec2 &position, const std::vector<cocos2d::Vec2> &apexs){
    this->setPosition(position) ;
    this->setApexs(apexs) ;
}

/**
 *  @desc   setCollisionData
 *  @param  CCollisionData
 */
void CCollisionData::set(const CCollisionData &data){
    this->m_position = data.getPosition() ;
    this->setApexs(data.getApexs()) ;
}

/**
 *  @desc   setPosition
 *  @param  自身の位置座標
 */
void CCollisionData::setPosition(const cocos2d::Vec2 &position){
    this->m_position = position ;
}

/**
 *  @desc   setApexs
 *  @param  自身の位置座標
 */
void CCollisionData::setApexs(const std::vector<cocos2d::Vec2> &apexs){
    if(this->m_pApexs != NULL){
        delete this->m_pApexs ;
        this->m_pApexs = NULL ;
    }
    this->m_pApexs = new std::vector<cocos2d::Vec2>() ;
    for(cocos2d::Vec2 apex : apexs){
        this->m_pApexs->push_back(apex) ;
    }
}

/**
 *  @desc   setThick
 *  @param  太さ(円の半径)
 */
void CCollisionData::setThick(float thick){
    this->m_thick = thick ;
}

//=========================================================================
// get
//=========================================================================
/**
 *  @desc   getPosition
 *  @return 位置座標
 */
cocos2d::Vec2 CCollisionData::getPosition() const {
    return this->m_position ;
}

/**
 *  @desc   getApexs
 *  @return 頂点座標群
 */
std::vector<cocos2d::Vec2> &CCollisionData::getApexs() const {
    return *this->m_pApexs ;
}

/**
 *  @desc   getThick
 *  @return 太さ
 */
float CCollisionData::getThick() const {
    return this->m_thick ;
}

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
bool CCollisionData::collisionDecision(const CCollisionData &data) const {
    if(this->m_pApexs == NULL && data.m_pApexs == NULL){
        return this->m_position == data.m_position ;
    }
    return this->GJKAlgorithm(data) ;
}

//=========================================================================
// GJKアルゴリズム
//=========================================================================
/**
 *  @desc   GJKアルゴリズム
 *  @param  衝突データ
 *  @tips   座標データを弄くり回すので値渡し
 */
bool CCollisionData::GJKAlgorithm(CCollisionData data) const {
    // 自身と対象の位置のベクトル差
    cocos2d::Vec2 direction = data.m_position - this->m_position ;
    
    // 自身を原点とした座標系に移動させる
    data.m_position += direction ;
    if(data.m_pApexs != NULL){
        std::vector<cocos2d::Vec2>::iterator itr = data.m_pApexs->begin() ;
        while(itr != data.m_pApexs->end()){
            (*itr) += direction ;
            ++itr ;
        }
    }
    
    // 単体オブジェクトを生成
    CSimplex simplex ;
    
    // 最初の支点を追加
    simplex.add(this->getSupportMappingFulcrum(data, direction)) ;
    
    // 次の支点を決定するための方向ベクトル
    direction.negate() ;
    
    // !!!: while内で不具合が起こった時の保険用変数
    // こいつが一定値を超えたら強制的に抜けださせる
    const int MAX_COUNT = 20 ;
    int count = 0 ;
    
    // 原点に最も近い単体を探し出す
    //多くても頂点の数分回せば見つかるようになっている
    while(true){
        // !!!: 無限ループを防ぐための保険
        if(count >= MAX_COUNT){
            // こいつが表示されると何かしら問題があるよ
            printf("無限ループに陥りそうだったので強制終了させました\n") ;
            return false ;
        }
        
        // 単体に頂点を追加
        simplex.add(this->getSupportMappingFulcrum(data, direction)) ;
        
        // 次のサポート支点が得られるかを判定する
        if(simplex.getLastApex().dot(direction) <= 0.0f){
            //printf("これ以上原点を含む可能性のあるサポート支点が得られないため処理を終了します\n") ;
            return false ;
        }else{
            // 単体が原点座標を含むかを調べる
            if(simplex.isContainsPoint(cocos2d::Vec2::ZERO) == true){
                //printf("ミンコフスキー差が原点を含みました\n") ;
                return true ;
            }else{
                // 次のサポート支点を得るための方向ベクトルを決定する
                direction = this->getGJKNextDirection(simplex) ;
            }
        }
        // !!!: 無限ループを防ぐための保険
        ++count ;
    }
    printf("これが表示されることがあってはならない\n") ;
    return false ;
}

/**
 *  @desc   ミンコフスキー差におけるサポート支点座標を得る
 *  @param  ベクトル方向
 *  @return ミンコフスキー差サポート支点座標
 */
cocos2d::Vec2 CCollisionData::getSupportMappingFulcrum(const CCollisionData &data, const cocos2d::Vec2 &direction) const {
    // 自身と対象におけるサポート写像支点を求める
    cocos2d::Vec2 myPoint = this->getFarthestApexInDirection(cocos2d::Vec2::ZERO, this->m_pApexs, -direction) ;
    cocos2d::Vec2 objPoint = this->getFarthestApexInDirection(data.m_position, data.m_pApexs, direction) ;
    
    // ミンコフスキー差座標を求める
    cocos2d::Vec2 minkowskiDifferencePoint = objPoint - myPoint ;
    
    return minkowskiDifferencePoint ;
}

/**
 *  @desc   指定された頂点座標群から、指定されたベクトル方向における最も離れた頂点を求める
 *  @param  頂点座標群
 *  @param  ベクトル方向
 *  @return 頂点座標
 */
cocos2d::Vec2 CCollisionData::getFarthestApexInDirection(const cocos2d::Vec2 &position, const std::vector<cocos2d::Vec2> *pApexs, const cocos2d::Vec2 &direction) const {
    // 頂点座標群がなければ位置座標を返す
    if(pApexs == NULL) return position ;
    
    // 誤差を抑えるために方向ベクトルを正規化する
    cocos2d::Vec2 vec = direction.getNormalized() ;
    // 暫定戻り値座標と、その頂点までの長さを最初の頂点で登録する
    cocos2d::Vec2 result = (*pApexs)[0] ;
    float maxLength = (*pApexs)[0].dot(vec) ;
    
    // 登録されている全ての頂点と比べる
    for(cocos2d::Vec2 apex : (*pApexs)){
        float length = apex.dot(vec) ;
        if(maxLength < length){
            maxLength = length ;
            result = apex ;
        }
    }
    return result ;
}

/**
 *  @desc   次のミンコフスキー差サポート支点を得るためのベクトル方向を得る
 *  @param  CSimplex
 *  @return ベクトル方向
 *  @tips
 */
cocos2d::Vec2 CCollisionData::getGJKNextDirection(const CSimplex &simplex) const {
    // 結果となる座標
    cocos2d::Vec2 resultDirection ;
    
    // 登録されている頂点数で場合分けする
    // １つも登録されていない
    if(simplex.getCurrentArraySize() == 0){
        printf("呼ばれることはない箇所\n") ;
        // とりあえず原点を返す
        resultDirection = cocos2d::Vec2::ZERO ;
        
    }
    
    // 頂点が１つ
    else if(simplex.getCurrentArraySize() == 1){
        printf("呼ばれることはない箇所\n") ;
        return simplex.getApexAt(0) ;
        
    }
    
    // 頂点が２つ
    else if(simplex.getCurrentArraySize() == 2){
        CLine line(simplex.getApexAt(0), simplex.getApexAt(1)) ;
        resultDirection = line.getRecentlyPosition(cocos2d::Vec2::ZERO) ;
        
    }
    
    // 頂点が３つ
    else{
        // 頂点が３つで単体が完成している
        // 各辺上での最近点を比べて、最も近かったものを返す
        CLine line(simplex.getApexAt(2), simplex.getApexAt(0)) ;
        resultDirection = line.getRecentlyPosition(cocos2d::Vec2::ZERO) ;
        
        for(int i = 0 ; i < 3 - 1 ; ++i){
            line.set(simplex.getApexAt(i), simplex.getApexAt(i + 1)) ;
            cocos2d::Vec2 pos = line.getRecentlyPosition(cocos2d::Vec2::ZERO) ;
            if(resultDirection.getLength() > pos.getLength()) resultDirection = pos ;
        }
    }
    return -resultDirection ;
}