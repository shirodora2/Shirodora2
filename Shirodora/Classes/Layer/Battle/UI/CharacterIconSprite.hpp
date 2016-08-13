//
//  CharacterIconSprite.hpp
//  Shirodora
//
//  Created by 毎床　公喜 on 2016/07/19.
//
//

#ifndef CharacterIconSprite_hpp
#define CharacterIconSprite_hpp

//==========================
//インクルード
//==========================
#include "cocos2d.h"
#include "SummonFactoryManager.hpp" /* SUMMON_TYPE を使うため */


//=======================================================
//
//  キャラクターアイコンの規定クラス
//
//=======================================================
class CCharacterIcon : public cocos2d::Sprite{
public:
    CCharacterIcon();
    virtual ~CCharacterIcon();
    
    //コスト
    void setCost(int _cost){m_cost = _cost;}
    int getCost(){return m_cost;}
    
    //召喚可能数
    void setCount(int _count){m_cost = _count;}
    int getCount(){return m_count;}
    
    //キャラタイプ
    inline void setType(SUMMON_TYPE _type){this->m_summonType = _type;}
    inline SUMMON_TYPE getType(){return this->m_summonType;}
    
    
    bool init() override;
    void update(float _dt) override;
        
private:
    //召喚コスト
    int m_cost = 0;
    //召喚可能数
    int m_count = 0;
    //キャラクタータイプ
    SUMMON_TYPE m_summonType = SUMMON_TYPE::NONE;
};

//===================
//アタッカー
//===================
class CAttackIcon : public CCharacterIcon{
public:
    CAttackIcon(){}
    ~CAttackIcon(){}
    bool init() override;
    CREATE_FUNC(CAttackIcon);
};

//=====================
//ディフェンダー
//=====================
class CDefenceIcon : public CCharacterIcon{
public:
    CDefenceIcon(){}
    ~CDefenceIcon(){}
    bool init() override;
    CREATE_FUNC(CDefenceIcon);
};

#endif /* CharacterIconSprite_hpp */
