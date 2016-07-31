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
    // 召喚キャラ発射台のクリア
    CSummonLauncher::getInstance()->clear() ;
    
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
    
    
    CSummonLauncher::getInstance()->setLayer(this) ;
    
    CLaunchData<CSummon> *pSummonLaunchData = new CLaunchData<CSummon>(1000, SUMMON_TYPE::TEST, WINDOW_WIDTH * 0.5f, WINDOW_HEIGHT * 0.5f) ;
    CSummonLauncher::getInstance()->add(new CTrigger_Timer<CSummon>(pSummonLaunchData, 10)) ;
    
    // キャラクター集合体を生成してキャラクター集合へ取り付け
    //this->m_pCharacters = new std::vector<CCharacter*>() ;
    //CCharacterAggregate::getInstance()->setAggregate(this->m_pCharacters) ;
    
    
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
    CSummonManager::getInstance()->update() ;
}