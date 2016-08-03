//
//  CharacterAggregate_Player2King.hpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/08/03.
//
//

#ifndef CharacterAggregate_Player2King_hpp
#define CharacterAggregate_Player2King_hpp

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include "CharacterAggregate.hpp"

//=========================================================================
// 前方宣言
//=========================================================================
class CCharacter ;

//=========================================================================
//
// キャラ集合_プレイヤー２キング
//
//=========================================================================
class CCharacterAggregate_Player2King : public CCharacterAggregate {
    public :
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
    /**
     *  @desc   コンストラクタ
     */
    CCharacterAggregate_Player2King(std::vector<CCharacter*> *pAggre) ;
    
    /**
     *  @desc   デストラクタ
     */
    ~CCharacterAggregate_Player2King() ;
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
    /**
     *  @desc   開始イテレーターの取得
     *  @return イテレーター
     */
    virtual std::shared_ptr<CIteratorTemplate<CCharacter*>> iterator() override ;
    
};

#endif /* CharacterAggregate_Player2King_hpp */
