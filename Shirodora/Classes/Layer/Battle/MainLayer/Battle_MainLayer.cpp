//
//  GameMainLayer.cpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/07/03.
//
//

#include "Shirodora.hpp"

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
    SSummonLaunchData launchData(SUMMON_TYPE::TEST, WINDOW_WIDTH * 0.5f, WINDOW_HEIGHT * 0.5f) ;
    CLauncherManager::getInstance()->setTrigger(new CSummonTrigger_Normal(launchData)) ;
    
    
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