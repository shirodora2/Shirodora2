//
//  GameMode.cpp
//  Shirodora
//
//  Created by 今西一喜 on 2016/07/30.
//
//

#include "GameMode.hpp"
#include "Constants.hpp"


//=================================================================
//  ゲームモード
//=================================================================
//コンストラクタ
CGameMode::CGameMode(){CCLOG("ゲームモードの生成");}
    
//デストラクタ
CGameMode::~CGameMode(){CCLOG("ゲームモードの破棄");}
    
    //インスタンスの取得
CGameMode* CGameMode::getInstance(){
    if(CGameMode::m_pSharedMgr == NULL){
        CGameMode::m_pSharedMgr = new CGameMode();
    }
    return CGameMode::m_pSharedMgr;
}
    
//インスタンスの破棄
void CGameMode::removeInstance(){
    CC_SAFE_DELETE(CGameMode::m_pSharedMgr);
}
    
//共有インスタンス
CGameMode* CGameMode::m_pSharedMgr = NULL;
