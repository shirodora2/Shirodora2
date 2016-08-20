//
//  Title_UILayer.cpp
//  Shirodora
//
//  Created by 今西一喜 on 2016/08/13.
//
//

#include "Title_UILayer.hpp"
#include "InputManager.hpp"
#include "Constants.hpp"
#include "BattleScene.hpp"


//======================================================
//
// タイトルUIクラス
//
//======================================================
//コンストラクタ
CTitle_UILayer::CTitle_UILayer(){
}
//デストラクタ
CTitle_UILayer::~CTitle_UILayer(){
}

//初期化
bool CTitle_UILayer::init(){
    if(!Layer::init())return false;
    
    //================================================================
    //メニューに関するコードの追加
    //================================================================
    /*
     * @desc メニューアイテムの生成　終了ボタン
     * @param 通常の画面を設定
     * @param 押された時の画像を設定
     * @param 押された時に呼び出されるメンバ関数の設定
     */
    cocos2d::MenuItemImage* pStartBtnItem = cocos2d::MenuItemImage::create(
                                                         "TestMoveSprite.png",
                                                         "TestMoveSprite.png",
                                                         CC_CALLBACK_1(CTitle_UILayer::callbackChangeGameMain, this)
                                                         );
    
    //位置に設定
    pStartBtnItem->setPosition(WINDOW_WIDTH * 0.5f, WINDOW_HEIGHT * 0.4f) ;
    
    /*
     * @desc メニューアイテムの生成　終了ボタン
     * @param 通常の画面を設定
     * @param 押された時の画像を設定
     * @param 押された時に呼び出されるメンバ関数の設定
     */
    cocos2d::MenuItemImage* pEndBtnItem = cocos2d::MenuItemImage::create(
                                                       "TestMoveSprite.png",
                                                       "TestMoveSprite.png",
                                                       CC_CALLBACK_1(CTitle_UILayer::callbackEndGame, this)
                                                       );
    
    //位置に設定
    pEndBtnItem->setPosition(WINDOW_WIDTH * 0.5f, WINDOW_HEIGHT * 0.2f) ;
    
    //メニューの生成とメニューアイテムの登録
    cocos2d::Menu* pMenu = cocos2d::Menu::create(pStartBtnItem, pEndBtnItem, NULL) ;
    //位置の初期化
    pMenu->setPosition(0.0f, 0.0f) ;
    //レイヤーにメニューを登録する
    this->addChild(pMenu) ;
    
   
    scheduleUpdate();
    
    return true;
}


//更新処理
void CTitle_UILayer::update(float _dt){
   
    this->inputFunc();
}

/**
 *  @desc   入力処理
 */
void CTitle_UILayer::inputFunc(){
  
    //*****別のinputFunc間で同時に同じ入力情報は取得できない************
    //if(inputflag.m_z.isPressed() == true){
    if(inputflag.m_a.isPressed() == true){
        CCLOG("タイトルでaキー押した : UI");
    }
}

/**
 * @desc ゲームメインに遷移
 * @param タイトルレイヤーのインスタンス
 * @tips スタートボタンが押された時に呼び出される
 */
void CTitle_UILayer::callbackChangeGameMain(cocos2d::Ref* pSender){
    
    //シーンを生成する
    cocos2d::Scene* pScene = CCREATE_FUNC::create<CBattleScene>() ;
    //シーンを切り替える
    cocos2d::Director::getInstance()->replaceScene(pScene) ;
}

/**
 * @desc ゲーム終了
 * @param タイトルレイヤーのインスタンス
 * @tips ゲーム終了ボタンが押されたときに呼び出される
 */
void CTitle_UILayer::callbackEndGame(cocos2d::Ref *pSender){
    
    cocos2d::Director::getInstance()->end() ;
}





