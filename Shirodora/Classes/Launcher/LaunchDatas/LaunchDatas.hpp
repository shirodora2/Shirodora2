//
//  LaunchDatas.hpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/07/16.
//
//

#ifndef LaunchDatas_hpp
#define LaunchDatas_hpp

//=========================================================================
// 前方宣言
//=========================================================================
enum class SUMMON_TYPE ;

//=========================================================================
// 召喚ランチデータ
//=========================================================================
struct SSummonLaunchData {
    SSummonLaunchData() ;
    SSummonLaunchData(int tag, SUMMON_TYPE type , float posX, float posY){
        this->m_tag = tag ;
        this->m_type = type ;
        this->m_posX = posX ;
        this->m_posY = posY ;
    }
    int m_tag ;
    SUMMON_TYPE m_type ;
    float m_posX ;
    float m_posY ;
};

#endif /* LaunchDatas_hpp */
