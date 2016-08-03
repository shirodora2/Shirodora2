//
//  CharacterManager.hpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/07/31.
//
//

#ifndef CharacterManager_hpp
#define CharacterManager_hpp

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include "SingletonTemplate.hpp"
#include "AggregateTemplate.hpp"

//=========================================================================
// 前方宣言
//=========================================================================
class CCharacter ;
class CCharacterAggregate ;

enum class CHARACTER_AGGREGATE_TYPE {
    NONE        = -1,
    ALL,
    PLAYER_1,
    PLAYER_2,
    PLAYER_1_KING,
    PLAYER_2_KING,
    MAX
};

//=========================================================================
//
// キャラ管理
//
//=========================================================================
class CCharacterManager : public CSingletonTemplate<CCharacterManager> {
public :
    //=========================================================================
    // get
    //=========================================================================
    /**
     *  @desc   iteratorの取得
     *  @param  欲しいiterator集合体の種類
     *  @return iterator
     */
    std::shared_ptr<CIteratorTemplate<CCharacter*>> iterator(CHARACTER_AGGREGATE_TYPE type) ;
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
    /**
     *  @desc   キャラの追加
     *  @param  CCharacter*
     */
    void add(CCharacter *pChara) ;
    
    /**
     *  @desc   clear
     */
    void clear() ;
    
    /**
     *  @desc   update
     */
    void update() ;
    
    
private :
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
    friend class CSingletonTemplate<CCharacterManager> ;
    /**
     *  @desc   コンストラクタ
     */
    CCharacterManager() ;
    
    /**
     *  @desc   コピーコンストラクタ
     */
    CCharacterManager(const CCharacterManager &mgr) ;
    
    /**
     *  @desc   デストラクタ
     */
    ~CCharacterManager() ;
    
    //=========================================================================
    // set
    //=========================================================================
    /**
     *  @desc   集合体設定
     *  @param  集合体の種類
     */
    void setAggregate(CHARACTER_AGGREGATE_TYPE type) ;
    
    //=========================================================================
    // メンバ変数
    //=========================================================================
    // 集合体群
    CCharacterAggregate *m_pAggregates[(int)CHARACTER_AGGREGATE_TYPE::MAX] {NULL} ;
    // キャラクター群
    std::vector<CCharacter*> *m_pCharacters {NULL} ;
};

#endif /* CharacterManager_hpp */
