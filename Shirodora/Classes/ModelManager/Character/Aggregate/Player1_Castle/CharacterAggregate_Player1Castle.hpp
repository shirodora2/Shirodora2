//
//  CharacterAggregate_Player1Castle.hpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/08/20.
//
//

#ifndef CharacterAggregate_Player1Castle_hpp
#define CharacterAggregate_Player1Castle_hpp

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
// キャラ集合_プレイヤー１城
//
//=========================================================================
class CCharacterAggregate_Player1Castle : public CCharacterAggregate {
    public :
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
    /**
     *  @desc   コンストラクタ
     */
    CCharacterAggregate_Player1Castle(std::vector<CCharacter*> *pAggre) ;
    
    /**
     *  @desc   デストラクタ
     */
    ~CCharacterAggregate_Player1Castle() ;
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
    /**
     *  @desc   開始イテレーターの取得
     *  @return イテレーター
     */
    virtual std::shared_ptr<CIteratorTemplate<CCharacter*>> iterator() override ;
    
};

#endif /* CharacterIterator_Player1Castle_hpp */
