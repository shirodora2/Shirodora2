//
//  UI_Layer.hpp
//  Shirodora
//
//  Created by 毎床　公喜 on 2016/07/09.
//
//

#ifndef UI_Layer_hpp
#define UI_Layer_hpp

#include "cocos2d.h"

class CTimeLable;
class CCastleHpPlayerBar;
class CCastleHpEnemyBar;
class CCharacterIcon;
class CCostSprite;

enum class CZoderUI{
    Time = 0,
    Bar = 1,
    Cost = 2,
    Icons = 3,
};
    
enum class SYSTEM_MODE{
    NONE = -1,
    START ,     // 0
    PLAY ,      // 1
    END ,       // 2
    MAX ,
};

class CUI_Layer : public cocos2d::Layer{
public:
    //アイコン
    static const int MAXICON = 6;
    //コスト
    static const int MAXCOST = 10;
    
public:
    CUI_Layer();
    ~CUI_Layer();

public:
    //時間
    CTimeLable* getTimeLabel(){return m_pTimeLabel;}
    
    //ゲージ
    CCastleHpPlayerBar* getCastPlayerGage(){return m_pCastleHpPlayerBar;}
    CCastleHpEnemyBar* getCastEnemyGage(){return m_pCastleHpEnemyBar;}
    
    //キャラクターアイコンの取得
    inline CCharacterIcon* getCharaIconAt(int index){return this->m_charaIconBox[index];}
    
    bool init() override;
    void update(float _dt)override;
    CREATE_FUNC(CUI_Layer);
    
    //演出メソッド
    void StartProductionFunc(float _dt);
    void WinProductionFunc(float _dt);
    void LoseProductionFunc(float _dt);
    void DrowProductionFunc(float _dt);
    
    
    //コストの演出メソッド
    void costFunc();
    
private:
    //ゲームの状態
    SYSTEM_MODE m_systemMode;
    
    //キングの所持コスト
    int m_cost = 0;
    
    //制限時間
    CTimeLable* m_pTimeLabel = NULL;
    //城の耐久値
    CCastleHpPlayerBar* m_pCastleHpPlayerBar = NULL;
    CCastleHpEnemyBar* m_pCastleHpEnemyBar = NULL;
    //キャラアイコン
    CCharacterIcon* m_charaIconBox[MAXICON];
    //コスト画像
    CCostSprite* m_costBox[MAXCOST];

};

#endif /* UI_Layer_hpp */
