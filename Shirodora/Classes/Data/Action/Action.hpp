//
//  Action.hpp
//  Shirodora
//
//  Created by 服部優宇一 on 2016/07/16.
//
//

#ifndef Action_hpp
#define Action_hpp

#include <stdio.h>

//前方宣言
class CCharacter ;
//=========================================
//アクションの基底クラス
//=========================================
class CAction{
public:
    //アクションを開始
    virtual void start() = 0 ;
    /*
     * @desc 更新処理
     * @param アクションを取り付けるキャラクター
     */
    virtual void update(CCharacter* pChara) = 0 ;
    //アクションを停止
    virtual void stop() = 0 ;
};

#endif /* Action_hpp */
