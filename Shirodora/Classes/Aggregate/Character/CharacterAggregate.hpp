//
//  CharacterAggregate.hpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/07/15.
//
//

#ifndef CharacterAggregate_hpp
#define CharacterAggregate_hpp

#include <stdio.h>

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include "SingletonTemplate.hpp"

//=========================================================================
// 前方宣言
//=========================================================================
class CCharacter ;

//=========================================================================
//
// CharacterAggregate
//
//=========================================================================
class CCharacterAggregate : public CSingletonTemplate<CCharacterAggregate> {
public :
    //=========================================================================
    // get
    //=========================================================================
    /**
     *  @desc   最大サイズの取得
     */
    inline int getSize(){return this->m_pAggregate->size() ;}
    
    /**
     *  @desc   要素の取得
     *  @param  添字番号
     */
    inline CCharacter *getAt(int index){return (*this->m_pAggregate)[index] ;}
    
    /**
     *  @desc   集合体の取得
     */
    inline std::vector<CCharacter*> *getAggregate(){return this->m_pAggregate ;}
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
    /**
     *  @desc   clear
     */
    void clear() ;
    
    /**
     *  @desc   update
     */
    void update() ;
    
    /**
     *  @desc   集合体への追加
     */
    void add(CCharacter *pChara) ;
    
private :
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
    friend class CSingletonTemplate<CCharacterAggregate> ;
    
    /**
     *  @desc   constructor
     */
    CCharacterAggregate() ;
    
    /**
     *  @desc   copy constructor
     */
    CCharacterAggregate(const CCharacterAggregate &aggre) ;
    
    /**
     *  @desc   destructor
     */
    ~CCharacterAggregate() ;
    
    //=========================================================================
    // メンバ変数
    //=========================================================================
    // 集合体
    std::vector<CCharacter*> *m_pAggregate {NULL} ;
};

#endif /* CharacterAggregate_hpp */
