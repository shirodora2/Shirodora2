//
//  Summon.hpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/07/14.
//
//

#ifndef Summon_hpp
#define Summon_hpp

#include <stdio.h>

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include "Character.hpp"
#include "Body.hpp"

enum class SUMMON_STATE {
    NONE        = -1,
    IDLE,
    MAX
};

//=========================================================================
//
// Summon
//
//=========================================================================
class CSummon : public CCharacter {
public :
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
    /**
     *  @desc   constructor
     */
    CSummon() ;
    
    /**
     *  @desc   destructor
     */
    ~CSummon() ;
    
    //=========================================================================
    // init
    //=========================================================================
    /**
     *  @desc   init
     */
    virtual bool init() override ;
    
    //=========================================================================
    // set
    //=========================================================================
    /**
     *  @desc   プレイヤーNo設定
     *  @param  プレイヤーNo
     */
    inline void setPlayerNo(int no){this->m_playerNo = no ;}
    
    /**
     *  @desc   実体データ設定
     *  @param  CBody*
     */
    inline void setCollisionBody(CBody *pBody){this->m_pCollisionBody = pBody ;}
    
    /**
     *  @desc   攻撃範囲データ設定
     *  @param  CBody*
     */
    inline void setAttackBody(CBody *pBody){this->m_pAttackBody = pBody ;}
    
    /**
     *  @desc   状態データ設定
     *  @param  SUMMON_STATE
     */
    inline void setState(SUMMON_STATE state){this->m_state = state ;}
    
    //=========================================================================
    // get
    //=========================================================================
    /**
     *  @desc   プレイヤーNo取得
     *  @return プレイヤーNo
     */
    inline int getPlayerNo(){return this->m_playerNo ;}
    
    /**
     *  @desc   実体データ設定
     *  @param  CBody*
     */
    inline CBody *getCollisionBody(){return this->m_pCollisionBody ;}
    
    /**
     *  @desc   攻撃範囲データ設定
     *  @param  CBody*
     */
    inline CBody *getAttackBody(){return this->m_pAttackBody ;}
    
    /**
     *  @desc   状態データ設定
     *  @param  SUMMON_STATE
     */
    inline SUMMON_STATE getState(){return this->m_state ;}
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
    /**
     *  @desc   update
     *  @param  微小時間
     */
    virtual void update(float deltaTime) override ;
    
    /**
     *  @desc   アクション処理
     */
    void action() override ;
    
    /**
     *  @desc   移動処理
     */
    void move() override ;
    
    /**
     *  @desc   アニメーション処理
     */
    void animation() override ;
    
    /**
     *  @desc   衝突判定処理
     */
    void collision() override ;
    
    /**
     *  @desc   状態チェック処理
     */
    void checkState() override ;
    
    /**
     *  @desc   Character１体との衝突
     *  @param  CCharacter*
     */
    bool collisionAt(CCharacter *pChara) override ;
    
    /**
     *  @desc   衝突処理
     *  @param  CCharacter*
     */
    void hit(CCharacter *pChara) override ;
    
    /**
     *  @desc   反映処理
     */
    void apply() override ;
    
    /**
     *  @desc   イベントコールバック
     *  @tips   何か外部から呼び出す必要のあるアクションとか
     */
    void eventCallBack() override ;
    
protected :
    //=========================================================================
    // メンバ変数
    //=========================================================================
    // プレイヤーNo
    int m_playerNo ;
    // 状態
    SUMMON_STATE m_state ;
    // 実体データ
    CBody *m_pCollisionBody {NULL} ;
    // 攻撃範囲データ
    CBody *m_pAttackBody {NULL} ;
    
};

#endif /* Summon_hpp */
