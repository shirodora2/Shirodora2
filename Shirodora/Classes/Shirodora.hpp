//
//  Shirodora.hpp
//  Shirodora
//
//  Created by 今西一喜 on 2016/07/16.
//
//

#ifndef Shirodora_hpp
#define Shirodora_hpp


#include <stdio.h>


//*************** まとめ *************************
#include "Constants.hpp"
#include "Manager.hpp"
#include "Factory.hpp"


//*************** Factory ***********************
#include "SummonCreateFactory.hpp"
#include "SummonFactoryManager.hpp"
#include "SummonTypes.hpp"

//*************** Data **************************
//---- Action ----------------
#include "Action.hpp"
#include "AttackAction.hpp"
#include "MoveAction.hpp"

//---- Status ----------------
#include "Status.hpp"

//---- Animation -------------
#include "Animation.hpp"

//---- Collision -------------
#include "Body.hpp"
#include "CollisionData.hpp"

//---- Move ------------------
#include "Move.hpp"


//*************** Model *************************
#include "Actor.hpp"
#include "Character.hpp"
#include "King.hpp"
#include "Summon.hpp"
#include "Object.hpp"
#include "Pawn.hpp"


//************** ModelManager *******************
//- - - - - - - - - Summon - - - - - - - - - - -
#include "ModelManagers.hpp"

//*************** Aggregate *********************
#include "CharacterAggregate.hpp"


//*************** Launcher **********************
//- - - - - - - LaunchDatas- - - - - - - - - - -
#include "LaunchDatas.hpp"

//- - - - - - - - - Trigger - - - - - - - - - - -
#include "TriggerTypes.hpp"

//- - - - - - - - - Launcher - - - - - - - - - - -
#include "Launchers.hpp"


//*************** Layer *************************
//---- Battle ----------------
//#include "CastleHpBar.hpp"
//#include "TimeLabel.hpp"
#include "UI_Layer.hpp"
#include "Battle_MainLayer.hpp"

//*************** Lib ***************************
#include "Shape.hpp"
#include "InputManager.hpp"
#include "MouseManager.hpp"
#include "SingletonTemplate.hpp"






#endif /* Shirodora_hpp */
