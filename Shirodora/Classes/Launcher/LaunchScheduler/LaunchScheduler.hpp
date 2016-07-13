//
//  LaunchScheduler.hpp
//  BarrageGame
//
//  Created by Ryoutarou Onimura on 2016/07/13.
//
//

#ifndef LaunchScheduler_hpp
#define LaunchScheduler_hpp

#include <stdio.h>

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include "SingletonTemplate.hpp"
#include "Launcher.hpp"

//=========================================================================
// 前方宣言
//=========================================================================
class CBarrage ;
class CEnemyUnit ;
class CPlayerUnit ;

//=========================================================================
//
//=========================================================================
enum class LAUNCHER_TYPE {
    NONE        = -1,
    MAX
};

//=========================================================================
//
// LaunchScheduler
//
//=========================================================================
class CLaunchScheduler : public CSingletonTemplate<CLaunchScheduler> {
public :
    //=========================================================================
    // set
    //=========================================================================
    // 発射するものごとにいるかも
    /**
     *  @desc   発射台設定
     *  @param  設定する発射台の種類
     *  @param  発射台から出撃させるものを取り付けるレイヤーのポインタ
     */
    void setLauncher(LAUNCHER_TYPE type, cocos2d::Layer *pLayer) ;
    
    /**
     *  @desc   をトリガーに取り付け
     *  @param
     */
    //inline void setTrigger(CLaunchTrigger</**/> *pTrigger){this->m_p/**/Launcher->add(pTrigger) ;}
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
    /**
     *  @desc   出撃スケジュールの更新処理
     */
    void update() ;
    
private :
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
    friend class CSingletonTemplate<CLaunchScheduler> ;
    
    /**
     *  @desc   constructor
     */
    CLaunchScheduler() ;
    
    /**
     *  @desc   copy constructor
     */
    CLaunchScheduler(const CLaunchScheduler &sch) ;
    
    /**
     *  @desc   destructor
     */
    ~CLaunchScheduler() ;
    
    //=========================================================================
    // メンバ変数
    //=========================================================================
    
};

#endif /* LaunchScheduler_hpp */
