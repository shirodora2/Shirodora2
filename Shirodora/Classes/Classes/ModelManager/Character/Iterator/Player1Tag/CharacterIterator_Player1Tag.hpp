//
//  CharacterIterator_Player1Tag.hpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/07/31.
//
//

#ifndef CharacterIterator_Player1Tag_hpp
#define CharacterIterator_Player1Tag_hpp

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
// 召喚キャライテレーター_プレイヤー１タグ
//
//=========================================================================
class CCharacterIterator_Player1Tag : public CIteratorTemplate<CCharacter*> {
public :
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
    /**
     *  @desc   コンストラクタ
     */
    CCharacterIterator_Player1Tag(IAggregateTemplate<CCharacter*> *pAggre) ;
    
    /**
     *  @desc   デストラクタ
     */
    ~CCharacterIterator_Player1Tag() ;
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
    /**
     *  @desc   次が存在するかどうかをチェック
     *  @return true...次がある false...次がない
     */
    bool hasNext() override ;
    
};

#endif /* CharacterIterator_Player1Tag_hpp */
