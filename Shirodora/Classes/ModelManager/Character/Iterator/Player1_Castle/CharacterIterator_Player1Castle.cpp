//
//  CharacterIterator_Player1Castle.cpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/08/20.
//
//

#include "CharacterIterator_Player1Castle.hpp"

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include "Character.hpp"

//=========================================================================
//
// 召喚キャライテレーター_プレイヤー１キング
//
//=========================================================================

//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
/**
 *  @desc   コンストラクタ
 */
CCharacterIterator_Player1Castle::CCharacterIterator_Player1Castle(IAggregateTemplate<CCharacter*> *pAggre) :
CIteratorTemplate<CCharacter *>(pAggre){}

/**
 *  @desc   デストラクタ
 */
CCharacterIterator_Player1Castle::~CCharacterIterator_Player1Castle(){}

//=========================================================================
// メンバ関数
//=========================================================================
/**
 *  @desc   次が存在するかどうかをチェック
 *  @return true...次がある false...次がない
 */
bool CCharacterIterator_Player1Castle::hasNext(){
    // 最大数を超えていたらfalse
    if(m_pAggre->getSize() <= this->m_currentIndex) {
        return false ;
    }
    
    CCharacter *pChara = this->m_pAggre->getAt(this->m_currentIndex) ;
    
    int tag = pChara->getPlayerTag() ;
    
    if(tag == 1999){
        return true ;
    }
    
    ++this->m_currentIndex ;
    return this->hasNext() ;
}