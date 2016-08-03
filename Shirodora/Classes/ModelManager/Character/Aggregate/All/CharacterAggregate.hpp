//
//  CharacterAggregate.hpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/07/31.
//
//

#ifndef CharacterAggregate_hpp
#define CharacterAggregate_hpp

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
// 召喚キャラ集合
//
//=========================================================================
class CCharacterAggregate : public IAggregateTemplate<CCharacter*> {
public :
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
    /**
     *  @desc   コンストラクタ
     */
    CCharacterAggregate(std::vector<CCharacter*> *pAggre) ;
    
    /**
     *  @desc   デストラクタ
     */
    virtual ~CCharacterAggregate() ;
    
    //=========================================================================
    // get
    //=========================================================================
    /**
     *  @desc   最大サイズの取得
     */
    inline virtual int getSize() override {return this->m_pAggregate->size() ;}
    
    /**
     *  @desc   要素の取得
     *  @param  添字番号
     */
    inline virtual CCharacter *getAt(int index) override {return (*this->m_pAggregate)[index] ;}
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
    /**
     *  @desc   開始イテレーターの取得
     *  @return イテレーター
     */
    virtual std::shared_ptr<CIteratorTemplate<CCharacter*>> iterator() override ;
    
protected :
    //=========================================================================
    // メンバ変数
    //=========================================================================
    // 集合体
    std::vector<CCharacter*> *m_pAggregate {NULL} ;
};

#endif /* CharacterAggregate_hpp */
