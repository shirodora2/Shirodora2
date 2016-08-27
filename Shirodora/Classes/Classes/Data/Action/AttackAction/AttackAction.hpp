//
//  AttackAction.hpp
//  Shirodora
//
//  Created by 服部優宇一 on 2016/07/16.
//
//

#ifndef AttackAction_hpp
#define AttackAction_hpp

#include <stdio.h>

class CCharacter ;
enum class CHARACTER_AGGREGATE_TYPE : int;

//===========================================
//移動に関するクラス
//===========================================
class CSimpleAttackAction : public CAction{
public:
    /**
     *@desc     コンストラクタ
     *@param    攻撃間隔
     *@param    攻撃対象
     */
    CSimpleAttackAction(int interval, CHARACTER_AGGREGATE_TYPE targetType) ;
    
    //アクションを開始
    void start() override ;
    /**
     * @desc 更新処理
     * @param アクションを取り付けるキャラクターのアドレス
     */
    void update(CCharacter* pChara) override ;
    //アクションを停止
    void stop() override ;
    void stop(CCharacter* pChara) override ;
    
    
private:
    //攻撃間隔
    int m_attackInterval = 0;
    int m_attackCounter = 0;
    
    //攻撃対象
    CHARACTER_AGGREGATE_TYPE m_targetType;
};



#endif /* AttackAction_hpp */
