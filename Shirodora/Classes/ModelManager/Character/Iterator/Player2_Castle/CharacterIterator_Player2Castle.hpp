//
//  CharacterIterator_Player2Castle.hpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/08/20.
//
//

#ifndef CharacterIterator_Player2Castle_hpp
#define CharacterIterator_Player2Castle_hpp

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
// キャライテレーター_プレイヤー2城
//
//=========================================================================
class CCharacterIterator_Player2Castle : public CIteratorTemplate<CCharacter*> {
public :
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
    /**
     *  @desc   コンストラクタ
     */
    CCharacterIterator_Player2Castle(IAggregateTemplate<CCharacter*> *pAggre) ;
    
    /**
     *  @desc   デストラクタ
     */
    ~CCharacterIterator_Player2Castle() ;
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
    /**
     *  @desc   次が存在するかどうかをチェック
     *  @return true...次がある false...次がない
     */
    bool hasNext() override ;
    
};

#endif /* CharacterIterator_Player2Castle_hpp */
