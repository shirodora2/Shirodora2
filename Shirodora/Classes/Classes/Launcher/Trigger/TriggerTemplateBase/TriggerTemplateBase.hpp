//
//  TriggerTemplateBase.hpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/07/25.
//
//

#ifndef TriggerTemplateBase_hpp
#define TriggerTemplateBase_hpp

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include "LaunchTemplate.hpp"

//=========================================================================
//
// トリガーテンプレート基底
//
//=========================================================================
template <typename Ty>
class CTriggerTemplateBase {
public :
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
    /**
     *  @desc   コンストラクタ
     */
    CTriggerTemplateBase(CLaunchData<Ty> *pData) ;
    
    /**
     *  @desc   デストラクタ
     */
    virtual ~CTriggerTemplateBase() ;
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
    /**
     *  @desc   発射したかどうか
     *  @return true...発射した false...発射してない
     */
    inline virtual bool isLaunched(){return this->m_launch.isLaunched() ; }
    
    /**
     *  @desc   トリガーの発射
     *  preturn 出撃させるもの
     */
    virtual Ty *launch() ;
    
    /**
     *  @desc   設定されているトリガーが発動できるかどうか
     *  @param  true...できる false...できない
     */
    virtual bool isReady() = 0 ;
    
    /**
     *  @desc   トリガー更新処理
     */
    virtual void update() = 0 ;
    
protected :
    //=========================================================================
    // メンバ変数
    //=========================================================================
    // 発射
    CLaunch<Ty> m_launch ;
    
};

#endif /* TriggerTemplateBase_hpp */
