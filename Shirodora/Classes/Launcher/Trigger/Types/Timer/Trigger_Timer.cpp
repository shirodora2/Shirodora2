//
//  Trigger_Timer.cpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/07/26.
//
//

#include "Trigger_Timer.hpp"

//=========================================================================
//
// トリガー_タイマー
//
//=========================================================================
//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
/**
 *  @desc   コンストラクタ
 */
template<typename Ty>
CTrigger_Timer<Ty>::CTrigger_Timer(CLaunchData<Ty> *pData, int limit) : CTriggerTemplateBase<Ty>(pData), m_limite(limit){}

/**
 *  @desc   デストラクタ
 */
template<typename Ty>
CTrigger_Timer<Ty>::~CTrigger_Timer(){}

//=========================================================================
// メンバ関数
//=========================================================================
/**
 *  @desc   設定されているトリガーが発動できるかどうか
 *  @param  true...できる false...できない
 */
template<typename Ty>
bool CTrigger_Timer<Ty>::isReady(){
    // カウンターが発射限界を超えとき trueを返す
    if(this->m_limite <= this->m_counter) return true ;
    return false ;
}

/**
 *  @desc   トリガー更新処理
 */
template<typename Ty>
void CTrigger_Timer<Ty>::update(){
    // カウンター更新
    if(this->m_counter < this->m_limite) ++this->m_counter ;
}

// テンプレートの明示的インスタンス化
template class CTrigger_Timer<CSummon> ;

