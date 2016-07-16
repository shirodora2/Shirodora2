//
//  SummonLauncher.cpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/07/17.
//
//

#include "SummonLauncher.hpp"

#include "Summon.hpp"
#include "CharacterAggregate.hpp"

//=========================================================================
//
// SummonLauncher
//
//=========================================================================
//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
/**
 *  @desc   constructor
 */
CSummonLauncher::CSummonLauncher(cocos2d::Layer *pLayer) : CLauncher<CSummon>(pLayer){}

/**
 *  @desc   destructor
 */
CSummonLauncher::~CSummonLauncher(){}

//=========================================================================
// メンバ関数
//=========================================================================
/**
 *  @desc   発射
 */
void CSummonLauncher::launch(){
    // 発射可能なものを発射する
    for(CTriggerTemplate<CSummon> *pTrigger : (*this->m_pLaunchSchedule)){
        if(pTrigger->isReady() == true ){
            CSummon *pSummon {NULL} ;
            pSummon = pTrigger->launch() ;
            this->m_pLayer->addChild(pSummon) ;
            CCharacterAggregate::getInstance()->add(pSummon) ;
        }
    }
}