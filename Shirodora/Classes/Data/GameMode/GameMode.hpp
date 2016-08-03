//
//  GameMode.hpp
//  Shirodora
//
//  Created by 今西一喜 on 2016/07/30.
//
//

#ifndef GameMode_hpp
#define GameMode_hpp


//=================================================================
//  ゲームモード
//=================================================================
class CGameMode{
public:
    enum class GAME_MODE : int {
        NONE = -1,
        NORMAL,
        CHECK,
    };
    
private:
    //コンストラクタ
    CGameMode();
    
public:
    //デストラクタ
    ~CGameMode();
    
    //インスタンスの取得
    static CGameMode *getInstance();
       
    //インスタンスの破棄
    static void removeInstance();
    
    //ゲームモードの設定
    inline void setGameMode(GAME_MODE mode){this->m_gameMode = mode;}
    
    //ゲームモードの取得
    inline GAME_MODE getGameMode(){return this->m_gameMode;}
    
private:
    //共有インスタンス
    static CGameMode *m_pSharedMgr;
    
    //ゲームモード
    GAME_MODE m_gameMode = GAME_MODE::NONE;
};


#endif /* GameMode_hpp */
