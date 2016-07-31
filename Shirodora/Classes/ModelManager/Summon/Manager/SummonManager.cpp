//
//  SummonManager.cpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/07/31.
//
//

#include "SummonManager.hpp"

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include "Summon.hpp"
#include "SummonAggregate.hpp"
#include "SummonAggregate_Player1Tag.hpp"
#include "SummonAggregate_Player2Tag.hpp"

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
std::shared_ptr<CIteratorTemplate<CSummon*>> CSummonManager::iterator(SUMMON_AGGREGATE_TYPE type){
    if(this->m_pAggregates[(int)type] == NULL) this->setAggregate(type) ;
    return this->m_pAggregates[(int)type]->iterator() ;
}

//=========================================================================
// メンバ関数
//=========================================================================
/**
 *  @desc   召喚キャラの追加
 *  @param  CSummon*
 */
void CSummonManager::add(CSummon *pChara){
    this->m_pCharacters->push_back(pChara) ;
}

/**
 *  @desc   clear
 */
void CSummonManager::clear(){
    for(int i = 0 ; i < (int)SUMMON_AGGREGATE_TYPE::MAX ; ++i){
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
void CSummonManager::update(){
    std::vector<CSummon*>::iterator itr = this->m_pCharacters->begin() ;
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
CSummonManager::CSummonManager(){
    this->m_pCharacters = new std::vector<CSummon*>() ;
}

/**
 *  @desc   コピーコンストラクタ
 */
CSummonManager::CSummonManager(const CSummonManager &mgr){}

/**
 *  @desc   デストラクタ
 */
CSummonManager::~CSummonManager(){
    for(int i = 0 ; i < (int)SUMMON_AGGREGATE_TYPE::MAX ; ++i){
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
void CSummonManager::setAggregate(SUMMON_AGGREGATE_TYPE type){
    switch(type){
        case SUMMON_AGGREGATE_TYPE::ALL :
            this->m_pAggregates[(int)type] = new CSummonAggregate(this->m_pCharacters) ;
            break ;
            
        case SUMMON_AGGREGATE_TYPE::PLAYER_1 :
            this->m_pAggregates[(int)type] = new CSummonAggregate_Player1Tag(this->m_pCharacters) ;
            break ;
            
        case SUMMON_AGGREGATE_TYPE::PLAYER_2 :
            this->m_pAggregates[(int)type] = new CSummonAggregate_Player2Tag(this->m_pCharacters) ;
            break ;
            
        default :
            break ;
    }
}