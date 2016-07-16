//
//  LauncherManager.hpp
//  BarrageGame
//
//  Created by Ryoutarou Onimura on 2016/07/13.
//
//

#ifndef LauncherManager_hpp
#define LauncherManager_hpp

#include <stdio.h>

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include "SingletonTemplate.hpp"
#include "LauncherTemplate.hpp"
#include "SummonLauncher.hpp"

//=========================================================================
// 前方宣言
//=========================================================================

//=========================================================================
// ランチャーの種類
//=========================================================================
enum class LAUNCHER_TYPE {
    NONE        = -1,
    SUMMON,
    MAX
};

//=========================================================================
//
// LauncherManager
// 出撃させるものの発射台をまとめたクラス
// 学校教材と違い、Launcher 自身が発射スケジュールを生成し、発射先のレイヤーのポインタを保持
// Launcher 自身がアップデート関数を所持して発射と発射したものの破棄を行う
// この砲台の要塞のようなマネージャーを、発射させるものがあるクラスのinitで必要な砲台を生成せ
// アップデートで呼び出してやれば良い
// ステージ切り替えがあったりした際には一度clearを呼ぶと安心
//
//=========================================================================
class CLauncherManager : public CSingletonTemplate<CLauncherManager> {
public :
    //=========================================================================
    // set
    //=========================================================================
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
    inline void setTrigger(CTriggerTemplate<CSummon> *pTrigger){this->m_pSummonLauncher->add(pTrigger) ;}
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
    /**
     *  @desc   clear
     */
    void clear() ;
    
    /**
     *  @desc   出撃スケジュールの更新処理
     */
    void update() ;
    
private :
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
    friend class CSingletonTemplate<CLauncherManager> ;
    
    /**
     *  @desc   constructor
     */
    CLauncherManager() ;
    
    /**
     *  @desc   copy constructor
     */
    CLauncherManager(const CLauncherManager &mgr) ;
    
    /**
     *  @desc   destructor
     */
    ~CLauncherManager() ;
    
    //=========================================================================
    // メンバ変数
    //=========================================================================
    // 召喚ランチャー
    CSummonLauncher *m_pSummonLauncher {NULL} ;
    
};

#endif /* LauncherManager_hpp */
