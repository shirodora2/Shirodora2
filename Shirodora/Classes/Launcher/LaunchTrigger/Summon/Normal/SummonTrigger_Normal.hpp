//
//  SummonTrigger_Normal.hpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/07/16.
//
//

#ifndef SummonTrigger_Normal_hpp
#define SummonTrigger_Normal_hpp

#include <stdio.h>

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include "TriggerTemplate_Normal.hpp"
#include "LaunchDatas.hpp"
#include "Factory.hpp"

class CSummon ;

//=========================================================================
//
// SummonTrigger_Normal
//
//=========================================================================
class CSummonTrigger_Normal : public CTriggerTemplate_Normal<CSummon> {
public :
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
    /**
     *  @desc   constructor
     */
    CSummonTrigger_Normal(SSummonLaunchData launchData) : m_launchData(launchData){}
    
    /**
     *  @desc   destructor
     */
    virtual ~CSummonTrigger_Normal(){}
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
    /**
     *  @desc   トリガーの発射
     *  preturn 出撃させるもの
     */
    CSummon *launch(){
        CSummon *pSummon = CSummonFactoryManager::getInstance()->create(this->m_launchData.m_tag ,
                                                                        this->m_launchData.m_type,
                                                                        this->m_launchData.m_posX,
                                                                        this->m_launchData.m_posY
                                                                        ) ;
        
        this->m_isLaunched = true ;
        
        return pSummon ;
    }
    
protected :
    //=========================================================================
    // メンバ変数
    //=========================================================================
    SSummonLaunchData m_launchData ;
    
};

#endif /* SummonTrigger_Normal_hpp */
