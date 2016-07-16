//
//  Summon.hpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/07/14.
//
//

#ifndef Summon_hpp
#define Summon_hpp

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include "Character.hpp"

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
     *  @desc   状態データ設定
     *  @param  SUMMON_STATE
     */
    inline void setState(SUMMON_STATE state){this->m_state = state ;}
    
    //=========================================================================
    // get
    //=========================================================================
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
    // 状態
    SUMMON_STATE m_state ;
    
};

#endif /* Summon_hpp */
