//
//  Animation.cpp
//  BarrageGame
//
//  Created by Ryoutarou Onimura on 2016/06/29.
//
//

#include "Animation.hpp"

//=========================================================================
// 追加のインクルードはここから
//=========================================================================

//=========================================================================
//
// Animation
//
//=========================================================================
//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
/**
 *  @desc   constructor
 */
CAnimation::CAnimation(int interval, int number, bool isLoop) : m_interval(interval), m_number(number), m_isLoop(isLoop) {}

/**
 *  @desc   destructor
 */
CAnimation::~CAnimation(){}

//=========================================================================
// メンバ関数
//=========================================================================
// 現在フレームの取得
int CAnimation::getCurrentFrame() {return this->m_currentFrame ;}

// アニメーションが終了したかどうか
bool CAnimation::isEnd() {return this->m_isEnd ;}

/**
 *  @desc   カウンターや現在のフレーム数のクリア
 */
void CAnimation::clear() {
    this->m_counter = 0 ;
    this->m_currentFrame = 0 ;
}

/**
 *  @desc   アニメーションの更新処理
 *  @return 表示するフレーム数(-1...初期化がまだ行われていない)
 */
int CAnimation::update() {
    // アニメーションが終了していなければカウンターの更新を行う
    if(this->m_isEnd == false) {
        this->m_counter++ ;
        
        // カウンターの数がアニメーションさせる枚数以上になったらカウンターをリセットする
        if(this->m_counter >= this->m_interval * this->m_number) {
            if(this->m_isLoop == true) {
                // ループするアニメーションはカウンターをリセットする
                this->m_counter = 0 ;
            } else {
                // アニメーションが終了したかどうかのフラグに対してtrueを入れる
                this->m_isEnd = true ;
                
                // ループしないアニメーションに対しては飛び出たカウンターをデクリメントする
                this->m_counter-- ;
            }
        }
    }
    // 表示するフレーム数
    m_currentFrame = this->m_counter / this->m_interval ;
    
    return m_currentFrame ;
}

//=========================================================================
//
// ChipAnimation
//
//=========================================================================
//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
/**
 *  @desc   constructor
 */
CChipAnimation::CChipAnimation(int interval, int number, bool isLoop) : CAnimation(interval, number, isLoop) {}

/**
 *  @desc   destructor
 */
CChipAnimation::~CChipAnimation(){}

//=========================================================================
// メンバ関数
//=========================================================================
/**
 *  @desc   チップデータの追加
 *  @param  チップデータの
 */
void CChipAnimation::addChipData(CChip* pChip){
    this->m_pChip = pChip ;
}

/**
 *  @desc   現在のフレームのチップを取得
 */
CChip CChipAnimation::getCurrentChip(){
    CChip chip(
               m_pChip->size.width * m_currentFrame,
               m_pChip->origin.y,
               m_pChip->size.width,
               m_pChip->size.height
               ) ;
    return  chip ;
}

/**
 *  @desc   コピー生成
 *  @param  チップ原点座標移動ベクトル
 *  @return CAnimaation*
 *  @tips   チップの原点位置に変更があれば引数へ
 */
CChipAnimation *CChipAnimation::copy(const cocos2d::Vec2 &moveVec){
    CChipAnimation *pClone = new CChipAnimation(this->m_interval, this->m_number, this->m_isLoop) ;
    pClone->addChipData(new CChip(this->m_pChip->origin + moveVec, this->m_pChip->size)) ;
    return pClone ;
}

//=========================================================================
//
// ChipNotAnimation
//
//=========================================================================
//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
/**
 *  @desc   constructor
 */
CChipNotAnimation::CChipNotAnimation() : CChipAnimation(0, 0, false){}

/**
 *  @desc   destructor
 */
CChipNotAnimation::~CChipNotAnimation(){}

//=========================================================================
// メンバ関数
//=========================================================================
/**
 *  @desc   更新処理は行わず返す値は必ず1になる
 */
int CChipNotAnimation::update(){return 1 ;}

/**
 *  @desc   現在フレームのチップを取得する
 *  @return 現在フレームのチップ
 */
CChip CChipNotAnimation::getCurrentChip(){
    return (*this->m_pChip) ;
}

/**
 *  @desc   コピー生成
 *  @param  チップ原点座標移動ベクトル
 *  @return CAnimaation*
 *  @tips   チップの原点位置に変更があれば引数へ
 */
CChipNotAnimation *CChipNotAnimation::copy(const cocos2d::Vec2 &moveVec){
    CChipNotAnimation *pClone = new CChipNotAnimation() ;
    pClone->addChipData(new CChip(this->m_pChip->origin + moveVec, this->m_pChip->size)) ;
    return pClone ;
}

//=========================================================================
//
// ChipListAnimation
//
//=========================================================================
//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
/**
 *  @desc   constructor
 */
CChipListAnimation::CChipListAnimation(int interval, bool isLoop) : CAnimation(interval, 0, isLoop){}

/**
 *  @desc   destructor
 */
CChipListAnimation::~CChipListAnimation(){
    // チップの解放
    std::vector<CChip*>::iterator itr = this->m_chipList.begin() ;
    while(itr != this->m_chipList.end()) {
        if(*itr != NULL){
            delete *itr ;
            *itr = NULL ;
        }
        itr++ ;
    }
}

//=========================================================================
// メンバ関数
//=========================================================================
/**
 *  @desc   チップデータの追加
 *  @param  チップデータ
 */
void CChipListAnimation::addChipData(CChip* pChip){
    // チップデータを追加する
    this->m_chipList.push_back(pChip) ;
    
    // チップデータを追加したらアニメーションの最大数も更新する
    this->m_number = int(this->m_chipList.size()) ;
}

/**
 *  @desc   現在のフレームのチップを取得
 *  @return 現在のフレームのチップ
 */
CChip CChipListAnimation::getCurrentChip(){
    // 添字演算子で取得したデータ自体がCChip*なのでその中身を返す
    return *(this->m_chipList[this->m_currentFrame]) ;
}

/**
 *  @desc   コピー生成
 *  @param  チップ原点座標移動ベクトル
 *  @return CAnimaation*
 *  @tips   チップの原点位置に変更があれば引数へ
 */
CChipListAnimation *CChipListAnimation::copy(const cocos2d::Vec2 &moveVec){
    CChipListAnimation *pClone = new CChipListAnimation(this->m_interval, this->m_isLoop) ;
    for(CChip *pChip : this->m_chipList){
        pClone->m_chipList.push_back(new CChip(pChip->origin + moveVec, pChip->size)) ;
    }
    return pClone ;
}