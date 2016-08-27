//
//  Character.hpp
//  BarrageGame
//
//  Created by Ryoutarou Onimura on 2016/07/08.
//
//

#ifndef Character_hpp
#define Character_hpp

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include "Actor.hpp"

//=========================================================================
// 前方宣言
//=========================================================================
class CMove ;
class CStatusOfCharacter ;
class CBody ;
class CAnimation ;
class CAction ;

//=========================================================================
//
//=========================================================================
enum class STATE {
    NONE    = -1,
    IDLE,
    DEAD,
    MOVE,
    ATTACK,
    INPUTING,
    UNIQUE_1,
    UNIQUE_2,
    UNIQUE_3,
    MAX
};

//=========================================================================
//
// Character
//
//=========================================================================
class CCharacter : public CActor {
public :
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
    /**
     *  @desc   constructor
     */
    CCharacter() ;
    
    /**
     *  @desc   destructor
     */
    virtual ~CCharacter() ;
    
    
    //=========================================================================
    // set
    //=========================================================================
    /**
     *  @desc   状態設定
     *  @param  状態
     */
    inline void setState(STATE state){this->m_state = state ;}
    
    /**
     *  @desc   位置データ設定
     *  @param  CMove*
     */
    inline void setMove(CMove *pMove){this->m_pMove = pMove ;}
    
    /**
     *  @desc   画像設定
     *  @param  cocos2d::Sprite
     */
    inline void setSprite(cocos2d::Sprite *pSprite){this->m_pSprite = pSprite ; this->addChild(this->m_pSprite) ;}
    
    /**
     *  @desc   ステータス設定
     *  @param  CStatusOfObject
     */
    inline void setStatus(CStatusOfCharacter *pStatus){this->m_pStatus = pStatus ;}
    
    /**
     *  @desc   攻撃範囲データ設定
     *  @param  CBody*
     */
    inline void setAttackBody(CBody *pBody){this->m_pAttackBody = pBody ;}
    
    /**
     *  @desc   攻撃範囲位置座標設定
     *  @param  攻撃範囲位置座標
     */
    inline void setAttackPosition(const cocos2d::Vec2 &position){this->m_attackPosition = position ;}
    
    /**
     *  @desc   実体データ設定
     *  @param  CBody*
     */
    inline void setCollisionBody(CBody *pBody){this->m_pCollisionBody = pBody ;}
    
    /**
     *  @desc   アニメーションデータ群設定
     *  @param  std::vector<CAnimation*>*
     */
    inline void setAnimations(std::vector<CAnimation*> *pAnimations){this->m_pAnimations = pAnimations ;}
    
    /**
     *  @desc   アクションデーター群設定
     *  @param  std::vector<CAction*>*
     */
    inline void setActions(std::vector<CAction*> *pActions){this->m_pActions = pActions ;}
    
    /**
     *  @desc   タグ設定
     *  @param  タグ番号
     */
    inline void setPlayerTag(int tag){this->m_tag = tag ;}
    
    //=========================================================================
    // get
    //=========================================================================
    /**
     *  @desc   状態設定
     *  @return 状態
     */
    inline STATE getState(){return this->m_state ;}
    
    /**
     *  @desc   位置データ取得
     *  @return CMove*
     */
    inline CMove *getMove(){return this->m_pMove ;}
    
    /**
     *  @desc   画像取得
     *  @return cocos2d::Sprite*
     */
    inline cocos2d::Sprite *getSprite(){return this->m_pSprite ;}
    
    /**
     *  @desc   ステータス取得
     *  @return CStatusOfObject
     */
    inline CStatusOfCharacter *getStatus(){return this->m_pStatus ;}
    
    /**
     *  @desc   攻撃範囲データ取得
     *  @param  CBody*
     */
    inline CBody *getAttackBody(){return this->m_pAttackBody ;}
    
    /**
     *  @desc   攻撃範囲位置座標設定
     *  @return 攻撃範囲位置座標
     */
    inline cocos2d::Vec2 getAttackPosition(){return this->m_attackPosition ;}
    
    /**
     *  @desc   実体データ取得
     *  @param  CBody*
     */
    inline CBody *getCollisionBody(){return this->m_pCollisionBody ;}
    
    /**
     *  @desc   アニメーションデータ群取得
     *  @return std::vector<CAnimation*>*
     */
    inline std::vector<CAnimation*> *getAnimations(){return this->m_pAnimations ;}
    
    /**
     *  @desc   アクションデーター群取得
     *  @return std::vector<CAction*>*
     */
    inline std::vector<CAction*> *getActions(){return this->m_pActions ;}
    
    /**
     *  @desc   タグ設定
     *  @param  タグ番号
     */
    inline int getPlayerTag(){return this->m_tag ;}
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
    /**
     *  @desc   Character１体との衝突
     *  @param  CCharacter*
     */
    virtual bool collisionAt(CCharacter*) = 0 ;
    
    /**
     *  @desc   衝突処理
     *  @param  CCharacter*
     */
    virtual void hit(CCharacter*) = 0 ;
    
    /**
     *  @desc   イベントコールバック
     *  @tips   何か外部から呼び出す必要のあるアクションとか
     */
    virtual void eventCallBack() = 0 ;
    
protected :
    //=========================================================================
    // メンバ変数
    //=========================================================================
    // 状態
    STATE m_state ;
    // 位置データ
    CMove *m_pMove {NULL} ;
    // 画像データ
    cocos2d::Sprite *m_pSprite {NULL} ;
    // ステータス
    CStatusOfCharacter *m_pStatus {NULL} ;
    // 実体データ
    CBody *m_pCollisionBody {NULL} ;
    // 攻撃範囲データ
    CBody *m_pAttackBody {NULL} ;
    // 攻撃範囲位置データ
    cocos2d::Vec2 m_attackPosition = cocos2d::Vec2::ZERO ;
    // アニメーションデータ群
    std::vector<CAnimation*> *m_pAnimations {NULL} ;
    // アクションデータ群
    std::vector<CAction*> *m_pActions {NULL} ;
    // タグ
    int m_tag = 0 ;
    
};

#endif /* Character_hpp */
