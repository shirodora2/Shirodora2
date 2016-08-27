//
//  CharacterIterator_Player2Tag.cpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/07/31.
//
//

#include "CharacterIterator_Player2Tag.hpp"

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include "Character.hpp"

//=========================================================================
//
// キャライテレーター_プレイヤー２タグ
//
//=========================================================================

//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
/**
 *  @desc   コンストラクタ
 */
CCharacterIterator_Player2Tag::CCharacterIterator_Player2Tag(IAggregateTemplate<CCharacter*> *pAggre) :
CIteratorTemplate<CCharacter*>(pAggre){}

/**
 *  @desc   デストラクタ
 */
CCharacterIterator_Player2Tag::~CCharacterIterator_Player2Tag(){}

//=========================================================================
// メンバ関数
//=========================================================================
/**
 *  @desc   次が存在するかどうかをチェック
 *  @return true...次がある false...次がない
 */
bool CCharacterIterator_Player2Tag::hasNext(){
    // 最大数を超えていたらfalse
    if(m_pAggre->getSize() <= this->m_currentIndex) {
        return false ;
    }
    
    CCharacter *pChara = this->m_pAggre->getAt(this->m_currentIndex) ;
    
    int tag = pChara->getPlayerTag() ;
    
    if(2000 <= tag && tag < 3000){
        return true ;
    }
    
    ++this->m_currentIndex ;
    return this->hasNext() ;
}