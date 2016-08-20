//
//  CharacterIterator_Player1Castle.hpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/08/20.
//
//

#ifndef CharacterIterator_Player1Castle_hpp
#define CharacterIterator_Player1Castle_hpp

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
// キャライテレーター_プレイヤー1城
//
//=========================================================================
class CCharacterIterator_Player1Castle : public CIteratorTemplate<CCharacter*> {
    public :
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
    /**
     *  @desc   コンストラクタ
     */
    CCharacterIterator_Player1Castle(IAggregateTemplate<CCharacter*> *pAggre) ;
    
    /**
     *  @desc   デストラクタ
     */
    ~CCharacterIterator_Player1Castle() ;
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
    /**
     *  @desc   次が存在するかどうかをチェック
     *  @return true...次がある false...次がない
     */
    bool hasNext() override ;
    
};

#endif /* CharacterIterator_Player1Castle_hpp */
