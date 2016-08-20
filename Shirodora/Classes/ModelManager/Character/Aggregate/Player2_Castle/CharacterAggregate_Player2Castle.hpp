//
//  CharacterAggregate_Player2Castle.hpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/08/20.
//
//

#ifndef CharacterAggregate_Player2Castle_hpp
#define CharacterAggregate_Player2Castle_hpp

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
// キャラ集合_プレイヤー２城
//
//=========================================================================
class CCharacterAggregate_Player2Castle : public CCharacterAggregate {
    public :
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
    /**
     *  @desc   コンストラクタ
     */
    CCharacterAggregate_Player2Castle(std::vector<CCharacter*> *pAggre) ;
    
    /**
     *  @desc   デストラクタ
     */
    ~CCharacterAggregate_Player2Castle() ;
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
    /**
     *  @desc   開始イテレーターの取得
     *  @return イテレーター
     */
    virtual std::shared_ptr<CIteratorTemplate<CCharacter*>> iterator() override ;
    
};

#endif /* CharacterAggregate_Player2Castle_hpp */
