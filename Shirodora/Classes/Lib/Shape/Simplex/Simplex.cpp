//
//  Simplex.cpp
//  BarrageGame
//
//  Created by Ryoutarou Onimura on 2016/06/23.
//
//

#include "Simplex.hpp"

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include "Constants.hpp"

//=========================================================================
//
// 単体クラス(各次元での最小形状)
//
//=========================================================================
//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
/**
 *  @desc   constructor
 */
CSimplex::CSimplex(){}

/**
 *  @desc   destructor
 */
CSimplex::~CSimplex(){
    for(int i = 0 ; i < 3 ; ++i){
        if(this->m_apexs[i] != NULL){
            delete this->m_apexs[i] ;
            this->m_apexs[i] = NULL ;
        }
    }
}

//=========================================================================
// set
//=========================================================================
/**
 *  @desc   頂点を追加する
 *  @param  追加する頂点座標
 */
void CSimplex::add(const cocos2d::Vec2 &apex){
    if(this->m_isFull == true){
        this->closeArray() ;
    }
    if(this->m_apexs[this->m_currentIndex] != NULL){
        printf("これが表示されるようでは問題がある\n") ;
    }
    this->m_apexs[this->m_currentIndex] = new cocos2d::Vec2(apex) ;
    this->addIndex() ;
}

/**
 *  @desc   配列を詰める
 */
void CSimplex::closeArray(){
    if(this->m_apexs[0] != NULL){
        delete this->m_apexs[0] ;
        this->m_apexs[0] = NULL ;
    }
    for(int i = 0 ; i < this->ARRAY_SIZE - 1 ; ++i){
        this->m_apexs[i] = this->m_apexs[i + 1] ;
    }
    this->m_apexs[this->ARRAY_SIZE - 1] = NULL ;
}

/**
 *  @desc   添字番号を増やす
 */
void CSimplex::addIndex(){
    if(this->m_isFull == true) return ;
    if(this->m_isEmpty == true) this->m_isEmpty = false ;
    ++this->m_currentIndex ;
    if(this->ARRAY_SIZE <= this->m_currentIndex){
        this->m_currentIndex = this->ARRAY_SIZE - 1 ;
        this->m_isFull = true ;
    }
}

/**
 *  @desc   添字番号を減らす
 */
void CSimplex::subIndex(){
    if(this->m_isEmpty == true) return ;
    if(this->m_isFull == true) this->m_isFull = false ;
    this->m_currentIndex-- ;
    if(this->m_currentIndex <= 0){
        this->m_currentIndex = 0 ;
        this->m_isEmpty = true ;
    }
}


//=========================================================================
// get
//=========================================================================
/**
 *  @desc   現在の配列サイズ取得
 *  @return 配列サイズ
 *  @tips   for文のお共にどうぞ
 */
int CSimplex::getCurrentArraySize() const {
    if(this->m_isFull == true) return this->ARRAY_SIZE ;
    if(this->m_isEmpty == true){printf("すまんが空じゃ\n") ; return 0 ;}
    return this->m_currentIndex ;
}

// TODO:配列のサイズ以上のものを要求された時に対応
/**
 *  @desc   指定した添字の頂点座標取得
 *  @return 頂点座標
 */
cocos2d::Vec2 CSimplex::getApexAt(int index) const {
    if(this->m_apexs[index] == NULL){
        printf("すまんが空じゃ\n") ;
        return cocos2d::Vec2::ZERO ;
    }
    return *(this->m_apexs[index]) ;
}

/**
 *  @desc   最後尾添字番号取得
 *  @return 最後尾添字番号
 */
int CSimplex::getLastIndex() const {
    if(this->m_isFull == true) return this->ARRAY_SIZE -1 ;
    if(this->m_isEmpty == true){printf("すまんが空じゃ\n") ; return -1 ;}
    return this->m_currentIndex - 1 ;
}

/**
 *  @desc   最後尾に格納されている頂点座標を返す
 *  @return 頂点座標
 */
cocos2d::Vec2 CSimplex::getLastApex() const {
    if(this->m_isFull == true) return *(this->m_apexs[this->ARRAY_SIZE -1]) ;
    if(this->m_isEmpty == true){printf("すまんが空じゃ\n") ; return cocos2d::Vec2::ZERO ;}
    return *(this->m_apexs[this->m_currentIndex - 1]) ;
}

/**
 *  @desc   配列がいっぱいかを返す
 *  @return true...いっぱい alse...いっぱいではない
 */
bool CSimplex::isFull() const {return this->m_isFull ;}

/**
 *  @desc   配列が空を返す
 *  @return true...空 alse...空ではない
 */
bool CSimplex::isEmpty() const {return this->m_isEmpty ;}

//=========================================================================
// メンバ関数
//=========================================================================
/**
 *  @desc   対象の点と単体上の最近点を求める
 *  @param  対象の点座標
 *  @return 最近点
 */
cocos2d::Vec2 CSimplex::getRecentlyPositionInSimplex(const cocos2d::Vec2 &point) const {
    // 結果となる座標
    cocos2d::Vec2 resultPos ;
    
    // 登録されている頂点数で場合分けする
    // １つも登録されていない
    if(this->getCurrentArraySize() == 0){
        printf("配列が空なので、次回はフラグチェックするように\n") ;
        // とりあえず原点を返す
        resultPos = cocos2d::Vec2::ZERO ;
        
    }
    // 頂点が１つ
    else if(this->getCurrentArraySize() == 1){
        return *(this->m_apexs[0]) ;
        
    }
    // 頂点が２つ
    else if(this->getCurrentArraySize() == 2){
        CLine line(*(this->m_apexs[0]), *(this->m_apexs[1])) ;
        resultPos = line.getRecentlyPositionInLine(point) ;
        
    }
    // 頂点が３つ
    else{
        // 頂点が３つで単体が完成している
        // 各辺上での最近点を比べて、最も近かったものを返す
        CLine line(*(this->m_apexs[2]), *(this->m_apexs[0])) ;
        resultPos = line.getRecentlyPositionInLine(point) ;
        
        for(int i = 0 ; i < this->ARRAY_SIZE - 1 ; ++i){
            line.set(*(this->m_apexs[i]), *(this->m_apexs[i + 1])) ;
            cocos2d::Vec2 pos = line.getRecentlyPositionInLine(point) ;
            if((resultPos - point).getLength() > (pos - point).getLength()) resultPos = pos ;
        }
    }
    return resultPos ;
}

/**
 *  @desc   指定された直線と最も離れた位置の交点を取得する
 *  @param  線分
 */
cocos2d::Vec2 CSimplex::getFarthestCrossPositionInSimplex(const CLine &line) const {
    // 結果となる座標
    cocos2d::Vec2 resultVector = cocos2d::Vec2::ZERO ;
    
    // 登録されている頂点数で場合分けする
    // １つも登録されていない
    if(this->getCurrentArraySize() == 0){
        printf("呼ばれることはない箇所\n") ;
        // とりあえず原点を返す
        resultVector = cocos2d::Vec2::ZERO ;
        
    }
    // 頂点が１つ
    else if(this->getCurrentArraySize() == 1){
        printf("呼ばれることはない箇所\n") ;
        // FIXME:
        // 方向ベクトルが頂点と合致した時にここを利用できるように
        return *(this->m_apexs[0]) ;
        
    }
    // 頂点が２つ
    else if(this->getCurrentArraySize() == 2){
        CLine sideLne(*(this->m_apexs[0]), *(this->m_apexs[1])) ;
        resultVector = sideLne.getCrossPositionInLine(line) - line.m_point[0] ;
    }
    // 頂点が３つ
    else{
        // 頂点が３つで単体が完成している
        // 各辺上での最近点を比べて、最も近かったものを返す
        CLine sideLine(*(this->m_apexs[2]), *(this->m_apexs[0])) ;
        CLine farthestLine = sideLine ;
        if(sideLine.isCrossed(line) == true && sideLine.isParallel(line) == false){
            resultVector = sideLine.getCrossPositionInLine(line) - line.m_point[0] ;
        }
        for(int i = 0 ; i < 3 - 1 ; ++i){
            sideLine.set(*(this->m_apexs[i]), *(this->m_apexs[i + 1])) ;
            if(sideLine.isCrossed(line) == true && sideLine.isParallel(line) == false){
                cocos2d::Vec2 crossPos = sideLine.getCrossPositionInLine(line) ;
                if(line.m_nVec.dot(resultVector) < line.m_nVec.dot(crossPos)){
                    farthestLine = sideLine ;
                    resultVector = farthestLine.getCrossPositionInLine(line) - line.m_point[0] ;
                }
            }
        }
        
    }
    return resultVector ;
}

/**
 *  @desc   対象の点が単体内に含まれているかを調べる関数
 *  @param  対象の点座標
 *  @return true...含まれている, false...含まれていない
 */
bool CSimplex::isContainsPoint(const cocos2d::Vec2 &point) const {
    // 単体が完成しているかどうか
    if(this->getCurrentArraySize() == 0){
        return false ;
    }
    else if(this->getCurrentArraySize() == 1){
        return point == *(this->m_apexs[0]) ;
    }
    else if(this->getCurrentArraySize() == 2){
        CLine line(*(this->m_apexs[0]), *(this->m_apexs[1])) ;
        return line.isContaintsPoint(point) ;
    }
    else{
        CLine line(*(this->m_apexs[2]), *(this->m_apexs[0])) ;
        int sign = line.getInOrOut(point) ;
        for(int i = 0 ; i < this->ARRAY_SIZE - 1 ; ++i){
            line.set(*(this->m_apexs[i]), *(this->m_apexs[i + 1])) ;
            int nextSign = line.getInOrOut(point) ;
            if(nextSign == 0.0f) return true ;
            if(sign != nextSign) return false ;
        }
        return true ;
    }
    return false ;
}

/**
 *  @desc   指定された座標が単体に登録されているかを返す
 *  @return true...登録されている false...登録されていない
 */
bool CSimplex::isRegistered(const cocos2d::Vec2 &point) const {
    for(int i = 0 ; i < this->getCurrentArraySize() ; ++i){
        if(*(this->m_apexs[i]) == point) return true ;
    }
    return false ;
}