//
//  CharacterAggregate_Player1King.hpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/08/03.
//
//

#ifndef CharacterAggregate_Player1King_hpp
#define CharacterAggregate_Player1King_hpp

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
// キャラ集合_プレイヤー１キング
//
//=========================================================================
class CCharacterAggregate_Player1King : public CCharacterAggregate {
public :
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
    /**
     *  @desc   コンストラクタ
     */
    CCharacterAggregate_Player1King(std::vector<CCharacter*> *pAggre) ;
    
    /**
     *  @desc   デストラクタ
     */
    ~CCharacterAggregate_Player1King() ;
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
    /**
     *  @desc   開始イテレーターの取得
     *  @return イテレーター
     */
    virtual std::shared_ptr<CIteratorTemplate<CCharacter*>> iterator() override ;
    
};

#endif /* CharacterAggregate_Player1King_hpp */
