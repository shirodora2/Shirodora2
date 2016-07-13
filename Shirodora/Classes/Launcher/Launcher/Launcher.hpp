//
//  Launcher.hpp
//  BarrageGame
//
//  Created by Ryoutarou Onimura on 2016/07/13.
//
//

#ifndef Launcher_hpp
#define Launcher_hpp

#include <stdio.h>

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include "LaunchTrigger.hpp"

//=========================================================================
//
// Launcher
//
//=========================================================================
template<typename Ty = CPawn>
class CLauncher {
public :
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
    /**
     *  @desc   constructor
     */
    CLauncher(cocos2d::Layer *pLayer) ;
    
    /**
     *  @desc   destructor
     */
    ~CLauncher() ;
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
    /**
     *  @desc   update
     */
    void update() ;
    /**
     *  @desc   出撃トリガーを出撃スケジュールに追加する
     *  @param  出撃トリガー
     */
    inline void add(CLaunchTrigger<Ty> *pTrigger){this->m_pLaunchSchedule->push_back(pTrigger) ;}
    
private :
    //=========================================================================
    // メンバ変数
    //=========================================================================
    // 出撃スケジュール
    std::vector<CLaunchTrigger<Ty>*> *m_pLaunchSchedule {NULL} ;
    // 取り付けレイヤー
    cocos2d::Layer *m_pLayer {NULL} ;
    
};

#endif /* Launcher_hpp */
