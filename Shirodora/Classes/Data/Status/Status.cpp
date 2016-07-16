//
//  Status.cpp
//  Shirodora
//
//  Created by 服部優宇一 on 2016/07/16.
//
//

#include "Status.hpp"
#include <stdio.h>
enum class TYPE : int{
    NONE = 0,
    FIRE = 1,
    WATER = 2,
    PLANT = 3,
} ;
    
//縦のタイプ（自分）
//横のタイプ（相手）
//NONE		//FIRE	//WATER	//PLANT
static float typeArray[4][4] = {	{1.0f, 		1.0f, 		1.0f, 			1.0f},		//NONE
                                    {1.0f, 		1.0f, 		1.5f, 			0.5f},		//FIRE
                                    {1.0f, 		0.5f, 		1.0f, 			1.5f},		//WATER
                                    {1.0f, 		1.5f, 		0.5f, 			1.0f}} ;	//PLANT


class CStatusOfObject{
protected:
    //HP
    int m_hp = 0 ;
    //最大HP
    int m_maxHp = 0 ;
    //キャラクターのタイプ
    TYPE m_type = TYPE::NONE ;
    //防御力
    float m_defensePt = 0.0f ;
    
public:
    /**
     * @desc ステータスの設定
     * @param HP
     * @param 最大HP
     * @param キャラクターのタイプ
     * @param 防御力
     */
    void setStatus(int hp, int maxMp, TYPE type, float defensePt){
        this->m_hp = hp ;
        this->m_maxHp = hp ;
        this->m_type = type ;
        this->m_defensePt = defensePt ;
    }
    
    /**
     * @desc 受けるダメージの倍率を決める
     */
    float damagePt(TYPE type){
        return typeArray[(int)this->m_type][(int)type] ;
    }
    
    /**
     * @desc HPの減少
     * @param 相手の攻撃力
     * @param 相手のタイプ
     */
    void decreaseHp(float attackPt, TYPE type){
        this->m_hp +=   ( this->m_defensePt- attackPt * damagePt(type)) ;
    }
    
    /**
     * @desc HPを取得する関数
     */
    int getHp(){
        return this->m_hp ;
    }
    
    /**
     * @desc 最大HPを取得する関数
     */
    int getMaxHp(){
        return this->m_maxHp ;
    }
    
    /**
     * @desc キャラクタータイプを取得する関数
     */
    TYPE getType(){
        return this->m_type ;
    }
    
    /**
     * @desc 防御力を取得する関数
     */
    float getDefensePt(){
        return this->m_defensePt ;
    }
} ;


class	 CStatusOfCharacter : public CStatusOfObject{
private:
    //攻撃力
    float m_attackPt = 0.0f ;
    //コスト
    int m_cost = 0 ;
    //攻撃間隔
    int m_interval = 0 ;
public:
    
    /**
     * @desc ステータスの設定
     * @param HP
     * @param 最大HP
     * @param キャラクターのタイプ
     * @param 防御力
     * @param 攻撃力
     * @param コスト
     * @param 攻撃間隔
     */
    void setStatus(int hp, int maxMp, TYPE type, float defensePt, float attackPt, int cost, int interval){
        this->m_hp = hp ;
        this->m_maxHp = hp ;
        this->m_type = type ;
        this->m_defensePt = defensePt ;
        this->m_attackPt = attackPt ;
        this->m_cost = cost ;
        this->m_interval = interval ;
    }
    /**
     * @desc 攻撃力を取得する関数
     */
    float getAttackPt(){
        return this->m_attackPt ;
    }
    
    /**
     * @desc コストを取得する関数
     */
    int getCost(){
        return this->m_cost ;
    }
    
    /**
     * @desc 攻撃間隔を取得する関数
     */
    int getInterval(){
        return this->m_interval ;
    }
    
} ;						
