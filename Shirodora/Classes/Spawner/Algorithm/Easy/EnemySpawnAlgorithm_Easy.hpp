//
//  EnemySpawnAlgorithm_Easy.hpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/08/27.
//
//

#ifndef EnemySpawnAlgorithm_Easy_hpp
#define EnemySpawnAlgorithm_Easy_hpp

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include "EnemySpawnAlgorithm_Base.hpp"

//=========================================================================
//
//
//
//=========================================================================
class CEnemySpawnAlgorithm_Easy : public CEnemySpawnAlgorithm_Base {
public :
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
    
    CEnemySpawnAlgorithm_Easy() ;
    
    /**
     *  @desc   デストラクタ
     */
    virtual ~CEnemySpawnAlgorithm_Easy() ;
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
    /**
     *  @desc   更新処理
     */
    void update(int time, int cost) override ;
    
    /**
     *  @desc   敵のランチデータを返す
     *  @param  時間
     *  @param  コスト
     */
    void launchEnemy(int time, int cost) override ;
    
protected :
    //=========================================================================
    // メンバ変数
    //=========================================================================
    
};

#endif /* EnemySpawnAlgorithm_Easy_hpp */
