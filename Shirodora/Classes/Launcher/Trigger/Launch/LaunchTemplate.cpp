//
//  Launch.cpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/07/26.
//
//

#include "LaunchTemplate.hpp"

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include "SummonFactoryManager.hpp"

//=========================================================================
//
// 発射テンプレート
//
//=========================================================================
/**
 *  @desc   コンストラクタ
 */
template<typename Ty>
CLaunch<Ty>::CLaunch(CLaunchData<Ty> *pData) : m_pData(pData){}

/**
 *  @desc   デストラクタ
 */
template<typename Ty>
CLaunch<Ty>::~CLaunch(){
    if(this->m_pData != NULL){
        delete this->m_pData ;
        this->m_pData = NULL ;
    }
}

//=========================================================================
// メンバ関数
//=========================================================================
template<typename Ty>
Ty *CLaunch<Ty>::launch(){
    this->m_isLaunched = true ;
    return new Ty() ;
}

//=========================================================================
// テンプレートの部分特殊化
//=========================================================================
//=========================================================================
// プレイヤーユニット発射
//=========================================================================
template<>
CSummon *CLaunch<CSummon>::launch(){
    CSummon *pChara =
    CSummonFactoryManager::getInstance()->create(this->m_pData->tag, this->m_pData->type, this->m_pData->posX, this->m_pData->posY) ;
    this->m_isLaunched = true ;
    return pChara ;
}


// 明示的テンプレートのインスタンス化
template class CLaunch<CSummon> ;

