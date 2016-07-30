//
//  CharacterIconSprite.cpp
//  Shirodora
//
//  Created by 毎床　公喜 on 2016/07/19.
//
//

#include "CharacterIconSprite.hpp"
USING_NS_CC;

CCharacterIcon::CCharacterIcon(){
    
}
CCharacterIcon::~CCharacterIcon(){
}

bool CCharacterIcon::init(){
    if(!Sprite::init())return false;
    
    
    
    return true;
}

void CCharacterIcon::update(float _dt){
}







bool CAttackIcon::init(){
    if(!CCharacterIcon::init())return false;
    setTexture("CharacterFrame_Red.png");
    return true;
}

bool CDefenceIcon::init(){
    if(!CCharacterIcon::init())return false;
    setTexture("CharacterFrame_Green.png");
    return true;
}