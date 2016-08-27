//
//  CharacterManager.cpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/07/31.
//
//

#include "CharacterManager.hpp"

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include "Character.hpp"
#include "CharacterAggregate.hpp"
#include "CharacterAggregate_Player1Tag.hpp"
#include "CharacterAggregate_Player2Tag.hpp"
#include "CharacterAggregate_Player1King.hpp"
#include "CharacterAggregate_Player2King.hpp"
#include "CharacterAggregate_Player1Castle.hpp"
#include "CharacterAggregate_Player2Castle.hpp"

//=========================================================================
//
// 召喚キャラ管理
//
//=========================================================================
//=========================================================================
// get
//=========================================================================
/**
 *  @desc   iteratorの取得
 *  @param  欲しいiterator集合体の種類
 *  @return iterator
 */
std::shared_ptr<CIteratorTemplate<CCharacter*>> CCharacterManager::iterator(CHARACTER_AGGREGATE_TYPE type){
    if(this->m_pAggregates[(int)type] == NULL) this->setAggregate(type) ;
    return this->m_pAggregates[(int)type]->iterator() ;
}

//=========================================================================
// メンバ関数
//=========================================================================
/**
 *  @desc   キャラの追加
 *  @param  CSummon*
 */
void CCharacterManager::add(CCharacter *pChara){
    this->m_pCharacters->push_back(pChara) ;
}

/**
 *  @desc   clear
 */
void CCharacterManager::clear(){
    for(int i = 0 ; i < (int)CHARACTER_AGGREGATE_TYPE::MAX ; ++i){
        if(this->m_pAggregates[i] != NULL){
            delete this->m_pAggregates[i] ;
            this->m_pAggregates[i] = NULL ;
        }
    }
    this->m_pCharacters->erase(this->m_pCharacters->begin(), this->m_pCharacters->end()) ;
}

/**
 *  @desc   update
 */
void CCharacterManager::update(){
    std::vector<CCharacter*>::iterator itr = this->m_pCharacters->begin() ;
    while(itr != this->m_pCharacters->end()){
        if((*itr)->isActive() == false){
            (*itr)->removeFromParent() ;
            this->m_pCharacters->erase(itr) ;
        }
        else{
            ++itr ;
        }
    }
}

//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
/**
 *  @desc   コンストラクタ
 */
CCharacterManager::CCharacterManager(){
    this->m_pCharacters = new std::vector<CCharacter*>() ;
}

/**
 *  @desc   コピーコンストラクタ
 */
CCharacterManager::CCharacterManager(const CCharacterManager &mgr){}

/**
 *  @desc   デストラクタ
 */
CCharacterManager::~CCharacterManager(){
    for(int i = 0 ; i < (int)CHARACTER_AGGREGATE_TYPE::MAX ; ++i){
        if(this->m_pAggregates[i] != NULL){
            delete this->m_pAggregates[i] ;
            this->m_pAggregates[i] = NULL ;
        }
    }
    if(this->m_pCharacters != NULL){
        delete this->m_pCharacters ;
        this->m_pCharacters = NULL ;
    }
}

//=========================================================================
// set
//=========================================================================
/**
 *  @desc   集合体設定
 *  @param  集合体の種類
 */
void CCharacterManager::setAggregate(CHARACTER_AGGREGATE_TYPE type){
    switch(type){
        case CHARACTER_AGGREGATE_TYPE::ALL :
            this->m_pAggregates[(int)type] = new CCharacterAggregate(this->m_pCharacters) ;
            break ;
            
        case CHARACTER_AGGREGATE_TYPE::PLAYER_1 :
            this->m_pAggregates[(int)type] = new CCharacterAggregate_Player1Tag(this->m_pCharacters) ;
            break ;
            
        case CHARACTER_AGGREGATE_TYPE::PLAYER_2 :
            this->m_pAggregates[(int)type] = new CCharacterAggregate_Player2Tag(this->m_pCharacters) ;
            break ;
            
        case CHARACTER_AGGREGATE_TYPE::PLAYER_1_KING :
            this->m_pAggregates[(int)type] = new CCharacterAggregate_Player1King(this->m_pCharacters) ;
            break ;
            
        case CHARACTER_AGGREGATE_TYPE::PLAYER_2_KING :
            this->m_pAggregates[(int)type] = new CCharacterAggregate_Player2King(this->m_pCharacters) ;
            break ;
            
        case CHARACTER_AGGREGATE_TYPE::PLAYER_1_CASTLE :
            this->m_pAggregates[(int)type] = new CCharacterAggregate_Player1Castle(this->m_pCharacters) ;
            break ;
            
        case CHARACTER_AGGREGATE_TYPE::PLAYER_2_CASTLE :
            this->m_pAggregates[(int)type] = new CCharacterAggregate_Player2Castle(this->m_pCharacters) ;
            break ;
            
        default :
            break ;
    }
}