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
    
    
    /**
     *  @desc   入力による移動
     */
    void moveInput();
    
    /*
     *  @desc   コストの回復
     *  @tips   一定時間ごとにコストを回復する
     */
    void recoverCost();
    
protected :
    //=========================================================================
    // メンバ変数
    //=========================================================================
    //コストの回復速度
    int m_costRecoverCounter = 0;
    int m_costRecoverInterval = 0;
    
};

#endif /* King_hpp */
