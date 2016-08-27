//
//  CharacterIterator_Player2King.hpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/08/03.
//
//

#ifndef CharacterIterator_Player2King_hpp
#define CharacterIterator_Player2King_hpp

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include "AggregateTemplate.hpp"

//=========================================================================
// 前方宣言
//=========================================================================
class CCharacter ;

//=========================================================================
//
// 召喚キャライテレーター_プレイヤー２キング
//
//=========================================================================
class CCharacterIterator_Player2King : public CIteratorTemplate<CCharacter*> {
    public :
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
    /**
     *  @desc   コンストラクタ
     */
    CCharacterIterator_Player2King(IAggregateTemplate<CCharacter*> *pAggre) ;
    
    /**
     *  @desc   デストラクタ
     */
    ~CCharacterIterator_Player2King() ;
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
    /**
     *  @desc   次が存在するかどうかをチェック
     *  @return true...次がある false...次がない
     */
    bool hasNext() override ;
    
};

#endif /* CharacterIterator_Player2King_hpp */
