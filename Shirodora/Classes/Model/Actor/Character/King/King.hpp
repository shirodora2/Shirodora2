//
//  King.hpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/07/14.
//
//

#ifndef King_hpp
#define King_hpp

#include <stdio.h>

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include "Character.hpp"

//=========================================================================
// 前方宣言
//=========================================================================
class CBody ;

enum class KING_STATE {
    NONE        = -1,
    IDLE,
    MAX
};


//=========================================================================
//
// King
//
//=========================================================================
class CKing : public CCharacter {
public :
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
    /**
     *  @desc   constructor
     */
    CKing() ;
    
    /**
     *  @desc   destructor
     */
    ~CKing() ;
    
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
     *  @param  KING_STATE
     */
    inline void setState(KING_STATE state){this->m_state = state ;}
    
    //=========================================================================
    // get
    //=========================================================================
    /**
     *  @desc   状態データ設定
     *  @param  KING_STATE
     */
    inline KING_STATE getState(){return this->m_state ;}
    
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
     *  @desc   反映処理
     */
    void apply() override ;
    
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
     *  @desc   イベントコールバック
     *  @tips   何か外部から呼び出す必要のあるアクションとか
     */
    void eventCallBack() override ;
    
protected :
    //=========================================================================
    // メンバ変数
    //=========================================================================
    // 状態
    KING_STATE m_state ;
    // 実体データ
    CBody *m_pCollisionBody {NULL} ;
    
};

#endif /* King_hpp */
