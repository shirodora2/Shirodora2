//
//  CharacterAggregate_Player2Tag.hpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/07/31.
//
//

#ifndef CharacterAggregate_Player2Tag_hpp
#define CharacterAggregate_Player2Tag_hpp

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
// キャラ集合_プレイヤー２
//
//=========================================================================
class CCharacterAggregate_Player2Tag : public CCharacterAggregate {
public :
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
    /**
     *  @desc   コンストラクタ
     */
    CCharacterAggregate_Player2Tag(std::vector<CCharacter*> *pAggre) ;
    
    /**
     *  @desc   デストラクタ
     */
    ~CCharacterAggregate_Player2Tag() ;
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
    /**
     *  @desc   開始イテレーターの取得
     *  @return イテレーター
     */
    virtual std::shared_ptr<CIteratorTemplate<CCharacter*>> iterator() override ;
    
};

#endif /* SummonAggregate_Player2Tag_hpp */
