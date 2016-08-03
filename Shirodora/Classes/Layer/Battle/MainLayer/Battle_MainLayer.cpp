//
//  GameMainLayer.cpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/07/03.
//
//

#include "Shirodora.hpp"
#include "GameMode.hpp"


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
    // 発射台のクリア
    CLauncherManager::getInstance()->clear() ;
    
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
    this->m_pCharacters = new std::vector<CCharacter*>() ;
    CCharacterAggregate::getInstance()->setAggregate(this->m_pCharacters) ;
    
    // 召喚発射台を設置
    CLauncherManager::getInstance()->setLauncher(LAUNCHER_TYPE::SUMMON, this) ;
    
    // 発射トリガーを発射台にとりつけ
    SSummonLaunchData launchData(1000, SUMMON_TYPE::TEST, WINDOW_WIDTH * 0.5f, WINDOW_HEIGHT * 0.5f) ;
    CLauncherManager::getInstance()->setTrigger(new CSummonTrigger_Normal(launchData)) ;
    
    
    
    //ゲームモードの設定
    CGameMode::getInstance()->setGameMode(CGameMode::GAME_MODE::CHECK);
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
    
    // 発射台更新
    CLauncherManager::getInstance()->update() ;
    
    // 死んだキャラクターの取り外し
    this->checkAndRemove(this->m_pCharacters) ;
    
    //スクロール処理
    this->scroll();
    
    //入力処理
    this->inputFunc();
}

/**
 *  @desc
 *
 */
template <typename Ty>
void CBattele_MainLayer::checkAndRemove(std::vector<Ty*> *pVector){
    typename std::vector<Ty*>::iterator itr = pVector->begin() ;
    while(itr != pVector->end()){
        if((*itr)->isActive() == false){
            (*itr)->removeFromParent() ;
            pVector->erase(itr) ;
        }
        else{
            ++itr ;
        }
    }
}


/**
 *  @desc   レイヤーのスクロール
 */
void CBattele_MainLayer::scroll(){
    
    if(CCharacterAggregate::getInstance()->getTag(PLAYER_TAG)==NULL)
        return;
    
    //-----ゲームモードがノーマル時のとき-----
    if(CGameMode::GAME_MODE::NORMAL == CGameMode::getInstance()->getGameMode()){
        
        CCharacter *pPlayerChara = CCharacterAggregate::getInstance()->getTag(PLAYER_TAG);
        
        
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
        
        if(inputflag.m_left.isInputing() == true){
            this->setPosition(this->getPosition().x+10,this->getPosition().y);
        }
        if(inputflag.m_right.isInputing() == true){
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



