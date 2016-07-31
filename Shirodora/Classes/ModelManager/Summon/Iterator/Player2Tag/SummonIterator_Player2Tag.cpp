//
//  SummonIterator_Player2Tag.cpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/07/31.
//
//

#include "SummonIterator_Player2Tag.hpp"

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include "Summon.hpp"

//=========================================================================
//
// 召喚キャライテレーター_プレイヤー２タグ
//
//=========================================================================

//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
/**
 *  @desc   コンストラクタ
 */
CSummonIterator_Player2Tag::CSummonIterator_Player2Tag(IAggregateTemplate<CSummon*> *pAggre) :
CIteratorTemplate<CSummon *>(pAggre){}

/**
 *  @desc   デストラクタ
 */
CSummonIterator_Player2Tag::~CSummonIterator_Player2Tag(){}

//=========================================================================
// メンバ関数
//=========================================================================
/**
 *  @desc   次が存在するかどうかをチェック
 *  @return true...次がある false...次がない
 */
bool CSummonIterator_Player2Tag::hasNext(){
    // 最大数を超えていたらfalse
    if(m_pAggre->getSize() <= this->m_currentIndex) {
        return false ;
    }
    
    CSummon *pChara = this->m_pAggre->getAt(this->m_currentIndex) ;
    
    int tag = pChara->getPlayerTag() ;
    
    if(2000 <= tag && tag < 3000){
        return true ;
    }
    
    ++this->m_currentIndex ;
    return this->hasNext() ;
}