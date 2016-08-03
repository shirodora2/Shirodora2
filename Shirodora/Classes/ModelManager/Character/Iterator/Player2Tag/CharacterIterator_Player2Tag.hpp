//
//  CharacterIterator_Player2Tag.hpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/07/31.
//
//

#ifndef CharacterIterator_Player2Tag_hpp
#define CharacterIterator_Player2Tag_hpp

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
// キャライテレーター_プレイヤー２タグ
//
//=========================================================================
class CCharacterIterator_Player2Tag : public CIteratorTemplate<CCharacter*> {
public :
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
    /**
     *  @desc   コンストラクタ
     */
    CCharacterIterator_Player2Tag(IAggregateTemplate<CCharacter*> *pAggre) ;
    
    /**
     *  @desc   デストラクタ
     */
    ~CCharacterIterator_Player2Tag() ;
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
    /**
     *  @desc   次が存在するかどうかをチェック
     *  @return true...次がある false...次がない
     */
    bool hasNext() override ;
    
};

#endif /* CharacterIterator_Player2Tag_hpp */
