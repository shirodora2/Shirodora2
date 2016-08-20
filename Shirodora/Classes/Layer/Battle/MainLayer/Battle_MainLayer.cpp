//
//  GameMainLayer.cpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/07/03.
//
//

#include "Shirodora.hpp"
#include "GameMode.hpp"
#include "CharacterIconSprite.hpp"


//=========================================================================
//
// GameMainLayer
//
//=========================================================================
//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
/**
 *  @desc   constructor
 */
CBattele_MainLayer::CBattele_MainLayer(){}

/**
 *  @desc   destructor
 */
CBattele_MainLayer::~CBattele_MainLayer(){
    if(this->m_pCharacters != NULL){
        delete this->m_pCharacters ;
        this->m_pCharacters = NULL ;
    }
    // 召喚キャラ発射台のクリア
    CSummonLauncher::getInstance()->clear() ;
    
    //ゲームモードの破棄
    CGameMode::removeInstance();
}

//=========================================================================
// init
//=========================================================================
/**
 *  @desc   init
 */
bool CBattele_MainLayer::init(){
    if(CInputAndMouseLayer::init() == false) return false ;
    
    // !!!:テスト用背景
    cocos2d::Sprite *pBackGround = cocos2d::Sprite::create("gameMainBG.png") ;
    pBackGround->setPosition(WINDOW_WIDTH * 0.5f, WINDOW_HEIGHT * 0.5f) ;
    this->addChild(pBackGround) ;
    
    // !!!:テスト用カーソルスプライト
    this->m_pCursor = cocos2d::Sprite::create("Bone.png") ;
    this->m_pCursor->setColor(cocos2d::Color3B::MAGENTA) ;
    this->m_pCursor->setPosition(WINDOW_WIDTH * 0.5f, WINDOW_HEIGHT * 0.5f) ;
    this->addChild(this->m_pCursor) ;
    
    // キャラクター集合体を生成してキャラクター集合へ取り付け
    //this->m_pCharacters = new std::vector<CCharacter*>() ;
    //CCharacterAggregate::getInstance()->setAggregate(this->m_pCharacters) ;
    
    
    //-------------------------動作テスト用----------------------------------------

    // 召喚キャラ発射台を設定
    CSummonLauncher::getInstance()->setLayer(this) ;
    // 召喚キャラ発射データを生成
    CLaunchData<CSummon> *pSummonLaunchData = new CLaunchData<CSummon>(1000, SUMMON_TYPE::TEST, WINDOW_WIDTH * 0.5f, WINDOW_HEIGHT * 0.5f) ;
    // 召喚キャラ発射トリガーを生成
    CTrigger_Timer<CSummon> *pTrigger = new CTrigger_Timer<CSummon>(pSummonLaunchData, 10) ;
    // 発射トリガーを発射台に取り付け
    CSummonLauncher::getInstance()->add(pTrigger) ;
    
    
    CKing* pKing = CKingFactoryManager::getInstance()->create(1000, KING_TYPE::TEST, WINDOW_WIDTH * 0.7f, WINDOW_HEIGHT * 0.5f) ;
    
    CCharacterManager::getInstance()->add(pKing);
    this->addChild(pKing) ;
    
    //ゲームモードの設定
    CGameMode::getInstance()->setGameMode(CGameMode::GAME_MODE::NORMAL);
    this->m_gameMode = (int)CGameMode::getInstance()->getGameMode();
    
    

    // スケジューラーに登録
    this->scheduleUpdate() ;
    
    return true ;
}

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
void CBattele_MainLayer::update(float deltaTime){
    // カーソルスプライトをマウスマネージャーを使って位置設定させる
    this->m_pCursor->setPosition(mouse.getCurrentCursorPosition()) ;
    
    // 召喚キャラ発射台の更新
    CSummonLauncher::getInstance()->update() ;
    
    // 召喚キャラマネージャーの更新
    CCharacterManager::getInstance()->update() ;
    
    //スクロール処理
    this->scroll();
    
    //入力処理
    this->inputFunc();
}

/**
 *  @desc   レイヤーのスクロール
 */
void CBattele_MainLayer::scroll(){
    
    CCharacter *pPlayerChara {NULL} ;
    // プレイヤー１キングキャラクターの取得
    std::shared_ptr<CIteratorTemplate<CCharacter*>> itr = CCharacterManager::getInstance()->iterator(CHARACTER_AGGREGATE_TYPE::PLAYER_1_KING) ;
    while(itr->hasNext() == true){
        pPlayerChara = itr->next() ;
    }
    // プレイヤー１キングキャラクターが生成されていないなら飛ばす
    if(pPlayerChara == NULL) return ;
    
    //-----ゲームモードがノーマル時のとき-----
    if(CGameMode::GAME_MODE::NORMAL == CGameMode::getInstance()->getGameMode()){
        //現在位置の取得
        cocos2d::Vec2 pt = this->getPosition();
        cocos2d::Vec2 playerPos = pPlayerChara->getMove()->getPosition();
        
        
        //プレイヤーを中心にスクロールする(右へスクロール)
        if(pt.x > (WINDOW_WIDTH*1/2) - playerPos.x){
         
            pt.x = (WINDOW_WIDTH*1/2) - playerPos.x;
            this->setPosition(pt);
        }
         
        //プレイヤーを中心にスクロールする(左へスクロール)
        if(pt.x < (WINDOW_WIDTH*1/2) - playerPos.x){
         
            pt.x = (WINDOW_WIDTH*1/2) - playerPos.x;
            this->setPosition(pt);
        }
        
    
    //-----ゲームモードがチェック時のとき-----
        //レイヤーのみがスクロールする
    }else if(CGameMode::GAME_MODE::CHECK == CGameMode::getInstance()->getGameMode()){
        
        if(inputflag.m_a.isInputing() == true){
            this->setPosition(this->getPosition().x+10,this->getPosition().y);
        }
        if(inputflag.m_d.isInputing() == true){
            this->setPosition(this->getPosition().x-10,this->getPosition().y);
        }
        
    }
    

}


/**
 *  @desc   入力処理
 */
void CBattele_MainLayer::inputFunc(){
    
    //ゲームモードを切り替える
        //スペースキーでモードチェンジ
    if(inputflag.m_space.isReleased() == true){
        if(CGameMode::getInstance()->getGameMode()==CGameMode::GAME_MODE::NORMAL){
            CGameMode::getInstance()->setGameMode(CGameMode::GAME_MODE::CHECK);
        }else if(CGameMode::getInstance()->getGameMode()==CGameMode::GAME_MODE::CHECK){
            CGameMode::getInstance()->setGameMode(CGameMode::GAME_MODE::NORMAL);
        }
    }
    
}


/**
 *  @desc   クリック位置と矩形の判定
 *  @param  クリック位置
 *  @param  矩形
 *  @return 矩形内をクリックしたのかどうか
 *          true...矩形内だった、false...矩形外だった
 */
bool CBattele_MainLayer::checkCollisionMouseClickPoint(cocos2d::Vec2 clickPoint, cocos2d::Rect rect){
    
    
    //CCLOG("rect %f : %f : %f : %f",rect.getMinX(),rect.getMaxX(),rect.getMinY(),rect.getMaxY());

    if(clickPoint.x > rect.getMinX() && clickPoint.x < rect.getMaxX()){
        if(clickPoint.y > rect.getMinY() && clickPoint.y < rect.getMaxY()){
            return true;
        }
    }
    
    return false;
}

/**
 *  @desc   マウス入力処理
 *  @param  UIレイヤー
 *  @tips   シーンで呼び出す
 */
void CBattele_MainLayer::inputMauseUpdate(CUI_Layer* pUiLayer){
    
    //クリックされたら
    if(mouse.isClicked() == true){
        
        //クリック位置の取得
        cocos2d::Vec2 clickPoint = mouse.getClickPosition();
        
        //クリック位置によって挙動を変える
        if(clickPoint.y < 120 /*UI範囲なら*/){
            
            //アイコンの選択
            this->choiceIcon(pUiLayer, clickPoint);
            
        }else if(clickPoint.y > 120 /*フィールド範囲なら*/){
            
            //キャラクターの召喚
            this->createSummon(clickPoint);
        }
    }
}

/**
 *  @desc   マウス入力による召喚キャラクターの選択
 *  @param  UIレイヤー
 *  @param  クリック位置
 */
void CBattele_MainLayer::choiceIcon(CUI_Layer* pUiLayer, cocos2d::Vec2 clickPoint){
    
    //選択キャラタイプの初期化
    //this->m_choiceSummonType = SUMMON_TYPE::NONE;
    
    
    //CCLOG("クリックされた %f : %f",clickPoint.x,clickPoint.y);
    
    //アイコンの数だけ回す
    for(int i=0; i<CUI_Layer::MAXICON; ++i){
        
        if(pUiLayer->getCharaIconAt(i)==NULL)
            continue;
        
        //アイコンを取得
        CCharacterIcon* icon = pUiLayer->getCharaIconAt(i);
        
        //位置と矩形原点の取得
        cocos2d::Vec2 iconPos = icon->getPosition();
        float minX = iconPos.x - icon->getContentSize().width/2;
        float minY = iconPos.y - icon->getContentSize().height/2;
        
        //矩形の設定
        cocos2d::Rect iconPosRect;
        iconPosRect.setRect(minX, minY, icon->getContentSize().width, icon->getContentSize().height);
        
        //クリック位置とアイコンとの衝突判定
        if(this->checkCollisionMouseClickPoint(clickPoint, iconPosRect)){
            
            //召喚キャラタイプの設定
            this->m_choiceSummonType = icon->getType();
            CCLOG("アイコンをクリックした");
            
            /***********************************
             アイコン選択時に変化をつけるならここに記述
             **********************************/
            
        }
    }
}

/**
 *  @desc   マウス入力によるキャラクターの生成
 *  @param  クリック位置
 */
void CBattele_MainLayer::createSummon(cocos2d::Vec2 clickPoint){
    
    CCharacter *pPlayerChara {NULL} ;
    // プレイヤー１キングキャラクターの取得
    std::shared_ptr<CIteratorTemplate<CCharacter*>> itr = CCharacterManager::getInstance()->iterator(CHARACTER_AGGREGATE_TYPE::PLAYER_1_KING) ;
    while(itr->hasNext() == true){
        pPlayerChara = itr->next() ;
    }
    // プレイヤー１キングキャラクターが生成されていないなら飛ばす
    if(pPlayerChara == NULL) return ;

    
    //*******キングの召喚範囲内かどうかを確認********************
    //*******キングの位置からレイヤースクロール距離をさっ引く*******
    
    //------ゲームの仕様次第では下の方が楽かな--------------
    
    //*******キングx座標は中央固定なので、scrollの影響のないy座標と画面中央x座標から召喚範囲を得る************
    //*******召喚時はキング位置＋画面中央からの距離で算出*******

    
    
}

