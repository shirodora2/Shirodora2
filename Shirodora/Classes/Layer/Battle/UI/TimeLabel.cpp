//
//  TimeLabel.cpp
//  Shirodora
//
//  Created by 毎床　公喜 on 2016/07/09.
//
//

#include "TimeLabel.hpp"
USING_NS_CC;

CTimeLable::CTimeLable(){
}
CTimeLable::~CTimeLable(){
}

bool CTimeLable::init(){
    if(!Label::init())return false;
    
    //ラベル生成
    
    //フォント
    setSystemFontName("Arial");
    //サイズ
    setSystemFontSize(10.f);
    //色
    setColor(Color3B::RED);
    setString(std::to_string(m_time));
    return true;
}

void CTimeLable::update(float _dt){
    setString(std::to_string(m_time));
}
