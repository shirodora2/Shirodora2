//
//  CharacterIterator_Player1King.cpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/08/03.
//
//

#include "CharacterIterator_Player1King.hpp"

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
CCharacterIterator_Player1King::CCharacterIterator_Player1King(IAggregateTemplate<CCharacter*> *pAggre) :
CIteratorTemplate<CCharacter *>(pAggre){}

/**
 *  @desc   デストラクタ
 */
CCharacterIterator_Player1King::~CCharacterIterator_Player1King(){}

//=========================================================================
// メンバ関数
//=========================================================================
/**
 *  @desc   次が存在するかどうかをチェック
 *  @return true...次がある false...次がない
 */
bool CCharacterIterator_Player1King::hasNext(){
    // 最大数を超えていたらfalse
    if(m_pAggre->getSize() <= this->m_currentIndex) {
        return false ;
    }
    
    CCharacter *pChara = this->m_pAggre->getAt(this->m_currentIndex) ;
    
    int tag = pChara->getPlayerTag() ;
    
    // TODO: - - - - - - - - - - - - 変更予定 - - - - - - - - - - - - - - - - -
    // 多分プレイヤータグがConstants.hppに入る
    if(tag == 1000){
        return true ;
    }
    
    ++this->m_currentIndex ;
    return this->hasNext() ;
}