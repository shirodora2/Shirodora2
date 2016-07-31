//
//  SummonLauncher.cpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/07/31.
//
//

#include "SummonLauncher.hpp"

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include "SummonTriggerAggregate.hpp"
#include "SummonTriggerAggregate_ReadyAll.hpp"
#include "Summon.hpp"
#include "SummonManager.hpp"

//=========================================================================
//
// 弾幕管理
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
std::shared_ptr<CIteratorTemplate<CTriggerTemplateBase<CSummon>*>> CSummonLauncher::iterator(SUMMON_TRIGGER_AGGREGATE_TYPE type){
    if(this->m_pAggregates[(int)type] == NULL) this->setAggregate(type) ;
    return this->m_pAggregates[(int)type]->iterator() ;
}

//=========================================================================
// メンバ関数
//=========================================================================
/**
 *  @desc   トリガーの追加
 *  @param  トリガー
 */
void CSummonLauncher::add(CTriggerTemplateBase<CSummon> *pChara){
    this->m_pTriggers->push_back(pChara) ;
}

/**
 *  @desc   clear
 */
void CSummonLauncher::clear(){
    this->m_pLayer = NULL ;
    // 集合体の解放
    for(int i = 0 ; i < (int)SUMMON_TRIGGER_AGGREGATE_TYPE::MAX ; ++i){
        if(this->m_pAggregates[i] != NULL){
            delete this->m_pAggregates[i] ;
            this->m_pAggregates[i] = NULL ;
        }
    }
    this->m_pTriggers->erase(this->m_pTriggers->begin(), this->m_pTriggers->end()) ;
}

/**
 *  @desc   update
 */
void CSummonLauncher::update(){
    // トリガーの更新処理をかける
    for(CTriggerTemplateBase<CSummon> *pTrigger : (*this->m_pTriggers)){
        pTrigger->update() ;
    }
    // 発射処理
    this->launch() ;
    // 発射されたものを削除する
    this->erase() ;
}

//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
/**
 *  @desc   コンストラクタ
 */
CSummonLauncher::CSummonLauncher(){
    this->m_pTriggers = new std::vector<CTriggerTemplateBase<CSummon>*>() ;
}

/**
 *  @desc   コピーコンストラクタ
 */
CSummonLauncher::CSummonLauncher(const CSummonLauncher &mgr){}

/**
 *  @desc   デストラクタ
 */
CSummonLauncher::~CSummonLauncher(){
    // 集合体の解放
    for(int i = 0 ; i < (int)SUMMON_TRIGGER_AGGREGATE_TYPE::MAX ; ++i){
        if(this->m_pAggregates[i] != NULL){
            delete this->m_pAggregates[i] ;
            this->m_pAggregates[i] = NULL ;
        }
    }
    // トリガー群の解放
    if(this->m_pTriggers != NULL){
        delete this->m_pTriggers ;
        this->m_pTriggers = NULL ;
    }
}

//=========================================================================
// set
//=========================================================================
/**
 *  @desc   集合体設定
 *  @param  集合体の種類
 */
void CSummonLauncher::setAggregate(SUMMON_TRIGGER_AGGREGATE_TYPE type){
    switch(type){
        case SUMMON_TRIGGER_AGGREGATE_TYPE::ALL :
            this->m_pAggregates[(int)type] = new CSummonTriggerAggregate(this->m_pTriggers) ;
            break ;
            
        case SUMMON_TRIGGER_AGGREGATE_TYPE::READY_ALL :
            this->m_pAggregates[(int)type] = new CSummonTriggerAggregate_ReadyAll(this->m_pTriggers) ;
            break ;
            
        default :
            break ;
    }
}

//=========================================================================
// メンバ関数
//=========================================================================
/**
 *  @desc   トリガーの発射
 */
void CSummonLauncher::launch(){
    std::shared_ptr<CIteratorTemplate<CTriggerTemplateBase<CSummon>*>> itr =
    this->iterator(SUMMON_TRIGGER_AGGREGATE_TYPE::READY_ALL) ;
    while(itr->hasNext() == true){
        CTriggerTemplateBase<CSummon> *pTriiger = itr->next() ;
        CSummon *pChara = pTriiger->launch() ;
        if(this->m_pLayer == NULL){
            CCLOG("レイヤーが設定されていません") ;
            break ;
        }
        this->m_pLayer->addChild(pChara) ;
        CSummonManager::getInstance()->add(pChara) ;
    }
}

/**
 *  @desc   発射し終わったものをスケジュールから削除する
 */
void CSummonLauncher::erase(){
    std::vector<CTriggerTemplateBase<CSummon>*>::iterator itr = this->m_pTriggers->begin() ;
    while(itr != this->m_pTriggers->end()){
        if((*itr)->isLaunched() == true){
            delete *itr ;
            *itr = NULL ;
            this->m_pTriggers->erase(itr) ;
        }
        else{
            ++itr ;
        }
    }
}