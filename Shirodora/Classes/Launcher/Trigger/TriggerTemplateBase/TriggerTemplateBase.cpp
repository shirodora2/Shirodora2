//
//  TriggerTemplateBase.cpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/07/25.
//
//

#include "TriggerTemplateBase.hpp"

//=========================================================================
//
// トリガーテンプレート
//
//=========================================================================
//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
template <typename Ty>
CTriggerTemplateBase<Ty>::CTriggerTemplateBase(CLaunchData<Ty> *pData) : m_launch(pData){}

/**
 *  @desc   デストラクタ
 */
template <typename Ty>
CTriggerTemplateBase<Ty>::~CTriggerTemplateBase(){}

//=========================================================================
// メンバ関数
//=========================================================================
/**
 *  @desc   トリガーの発射
 *  preturn 出撃させるもの
 */
template <typename Ty>
Ty *CTriggerTemplateBase<Ty>::launch(){
    return this->m_launch.launch() ;
}

// テンプレートの明示的インスタンス化
template class CTriggerTemplateBase<CSummon> ;