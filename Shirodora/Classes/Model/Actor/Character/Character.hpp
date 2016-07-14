//
//  Character.hpp
//  BarrageGame
//
//  Created by Ryoutarou Onimura on 2016/07/08.
//
//

#ifndef Character_hpp
#define Character_hpp

#include <stdio.h>

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include "Actor.hpp"
#include "Animation.hpp"
#include "Body.hpp"
#include "Move.hpp"

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
     *  @desc   プレイヤーNo設定
     *  @param  プレイヤーNo
     */
    inline void setPlayerNo(int no){this->m_playerNo = no ;}
    
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
     *  @desc   アニメーションデータ群設定
     *  @param  std::vector<CAnimation*>*
     */
    inline void setAnimations(std::vector<CAnimation*> *pAnimations){this->m_pAnimations = pAnimations ;}
    
    /**
     *  @desc   タグ設定
     *  @param  タグ番号
     */
    inline void setTag(int tag){this->m_tag = tag ;}
    
    //=========================================================================
    // get
    //=========================================================================
    /**
     *  @desc   プレイヤーNo取得
     *  @return プレイヤーNo
     */
    inline int getPlayerNo(){return this->m_playerNo ;}
    
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
     *  @desc   アニメーションデータ群取得
     *  @return std::vector<CAnimation*>*
     */
    inline std::vector<CAnimation*> *getAnimations(){return this->m_pAnimations ;}
    
    /**
     *  @desc   タグ設定
     *  @param  タグ番号
     */
    inline int getTag(){return this->m_tag ;}
    
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
    // プレイヤーNo
    int m_playerNo ;
    // 位置データ
    CMove *m_pMove {NULL} ;
    // 画像データ
    cocos2d::Sprite *m_pSprite {NULL} ;
    // アニメーションデータ群
    std::vector<CAnimation*> *m_pAnimations {NULL} ;
    // ステータス
    // CStatus *m_pStatus {NULL} ;
    // タグ
    int m_tag = 0 ;
    
};

#endif /* Character_hpp */
