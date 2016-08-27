//
//  GameMainLayer.hpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/07/03.
//
//

#ifndef GameMainLayer_hpp
#define GameMainLayer_hpp

#include <stdio.h>

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include "InputAndMouseLayer.hpp"
#include "SummonFactoryManager.hpp"

//=========================================================================
// 前方宣言
//=========================================================================
class CCharacter ;
class CUI_Layer ;
class CEnemySpawner ;

//=========================================================================
//
// Battele_MainLayer
//
//=========================================================================
class CBattele_MainLayer : public CInputAndMouseLayer {
public :
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
    /**
     *  @desc   constructor
     */
    CBattele_MainLayer() ;
    
    /**
     *  @desc   destructor
     */
    virtual ~CBattele_MainLayer() ;
    
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
    
    //=========================================================================
    // get
    //=========================================================================
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
    /**
     *  @desc   update
     *  @param  微小時間
     */
    virtual void update(float deltaTime) override ;
    
    /**
     *  @desc   レイヤーのスクロール
     */
    void scroll();
    
    /**
     *  @desc   入力処理
     */
    void inputFunc();
    
    
    /**
     *  @desc   クリック位置と矩形の判定
     *  @param  クリック位置
     *  @param  矩形
     *  @return 矩形内をクリックしたのかどうか
     *          true...矩形内だった、false...矩形外だった
     */
    bool checkCollisionMouseClickPoint(cocos2d::Vec2 clickPoint, cocos2d::Rect rect);
     
    /**
     *  @desc   マウス入力処理
     *  @param  UIレイヤー
     *  @tips   シーンで呼び出す
     */
    void inputMauseUpdate(CUI_Layer* pUiLayer);
    
    /**
     *  @desc   マウス入力による召喚キャラクターの選択
     *  @param  UIレイヤー
     *  @param  クリック位置
     */
    void choiceIcon(CUI_Layer* pUiLayer, cocos2d::Vec2 clickPoint);
    
    /**
     *  @desc   マウス入力によるキャラクターの生成
     *  @param  クリック位置
     */
    void createSummon(cocos2d::Vec2 clickPoint);
    
    //=========================================================================
    // メンバ変数
    //=========================================================================
    // !!!:テスト用マウスカーソルスプライト
    cocos2d::Sprite *m_pCursor {NULL} ;
    
    // TODO:多分画面スクロール時にいる気がする
    // カメラ座標
    cocos2d::Vec2 m_cameraPosition ;
    
    // キャラクター集合体
    std::vector<CCharacter*> *m_pCharacters {NULL} ;
    
    // 敵生成機
    CEnemySpawner *m_pSpawner {NULL} ;
    
    //ゲームモード
    int m_gameMode = 0;
    
    //選択中のキャラクタータイプ
    SUMMON_TYPE m_choiceSummonType { SUMMON_TYPE::NONE };

};

#endif /* GameMainLayer_hpp */
