//
//  SummonIterator_Player1Tag.cpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/07/31.
//
//

#include "CharacterIterator_Player1Tag.hpp"

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include "Character.hpp"

//=========================================================================
//
// 召喚キャライテレーター_プレイヤー１タグ
//
//=========================================================================

//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
/**
 *  @desc   コンストラクタ
 */
CCharacterIterator_Player1Tag::CCharacterIterator_Player1Tag(IAggregateTemplate<CCharacter*> *pAggre) :
CIteratorTemplate<CCharacter *>(pAggre){}

/**
 *  @desc   デストラクタ
 */
CCharacterIterator_Player1Tag::~CCharacterIterator_Player1Tag(){}

//=========================================================================
// メンバ関数
//=========================================================================
/**
 *  @desc   次が存在するかどうかをチェック
 *  @return true...次がある false...次がない
 */
bool CCharacterIterator_Player1Tag::hasNext(){
    // 最大数を超えていたらfalse
    if(m_pAggre->getSize() <= this->m_currentIndex) {
        return false ;
    }
    
    CCharacter *pChara = this->m_pAggre->getAt(this->m_currentIndex) ;
    
    int tag = pChara->getPlayerTag() ;
    
    if(1000 <= tag && tag < 2000){
        return true ;
    }
    
    ++this->m_currentIndex ;
    return this->hasNext() ;
}