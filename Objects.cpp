//#include "Objects.h"

//GameObject* Me() {
//	return (GameObject*)* (DWORD*) (baseAddr + DWORD_LOCAL_PLAYER);
//}

//std::vector<GameObject*> GetChampions() {
//	GameObjectManager* GObjects = GObjectManager;
//	std::vector<GameObject*> Objects;
//
//	for(int i = 0; i < GObjects->HighestObjectID; i++) {
//		GameObject* Object = GObjects->objectArray[i];
//		if(Object != NULL && Object->IsHero())
//			Objects.push_back(Object);
//	}
//
//	return Objects;
//}
//
//std::vector<GameObject*> GetEnemyChampions() {
//	GameObjectManager* GObjects = GObjectManager;
//	std::vector<GameObject*> Objects;
//
//	for(int i = 0; i < GObjects->HighestObjectID; i++) {
//		GameObject* Object = GObjects->objectArray[i];
//		if(Object != NULL && Object->IsHero() && Object->IsEnemy())
//			Objects.push_back(Object);
//	}
//
//	return Objects;
//}
//
//std::vector<GameObject*> GetFriendlyChampions() {
//	GameObjectManager* GObjects = GObjectManager;
//	std::vector<GameObject*> Objects;
//
//	for(int i = 0; i < GObjects->HighestObjectID; i++) {
//		GameObject* Object = GObjects->objectArray[i];
//		if(Object != NULL && Object->IsHero() && Object->IsFriendly())
//			Objects.push_back(Object);
//	}
//
//	return Objects;
//}

//std::vector<GameObject*> GetBaron() {
//	GameObjectManager* GObjects = GObjectManager;
//	std::vector<GameObject*> Objects;
//
//	for(int i = 0; i < GObjects->HighestObjectID; i++) {
//		GameObject* Object = GObjects->objectArray[i];
//		if(Object != NULL && Object->IsBaron())
//			Objects.push_back(Object);
//	}
//
//	return Objects;
//}
//
//std::vector<GameObject*> GetDragon() {
//	GameObjectManager* GObjects = GObjectManager;
//	std::vector<GameObject*> Objects;
//
//	for(int i = 0; i < GObjects->HighestObjectID; i++) {
//		GameObject* Object = GObjects->objectArray[i];
//		if(Object != NULL && Object->IsDragon())
//			Objects.push_back(Object);
//	}
//
//	return Objects;
//}
//
//std::vector<GameObject*> GetMinions() {
//	GameObjectManager* GObjects = GObjectManager;
//	std::vector<GameObject*> Objects;
//
//	for(int i = 0; i < GObjects->HighestObjectID; i++) {
//		GameObject* Object = GObjects->objectArray[i];
//		if(Object != NULL && Object->IsMinion())
//			Objects.push_back(Object);
//	}
//
//	return Objects;
//}
//
//std::vector<GameObject*> GetEnemyMinions() {
//	GameObjectManager* GObjects = GObjectManager;
//	std::vector<GameObject*> Objects;
//
//	for(int i = 0; i < GObjects->HighestObjectID; i++) {
//		GameObject* Object = GObjects->objectArray[i];
//		if(Object != NULL && Object->IsMinion() && Object->IsEnemy())
//			Objects.push_back(Object);
//	}
//
//	return Objects;
//}
//
//std::vector<GameObject*> GetFriendlyMinions() {
//	GameObjectManager* GObjects = GObjectManager;
//	std::vector<GameObject*> Objects;
//
//	for(int i = 0; i < GObjects->HighestObjectID; i++) {
//		GameObject* Object = GObjects->objectArray[i];
//		if(Object != NULL && Object->IsMinion() && Object->IsFriendly())
//			Objects.push_back(Object);
//	}
//
//	return Objects;
//}
//
//std::vector<GameObject*> GetMonsters() {
//	GameObjectManager* GObjects = GObjectManager;
//	std::vector<GameObject*> Objects;
//
//	for(int i = 0; i < GObjects->HighestObjectID; i++) {
//		GameObject* Object = GObjects->objectArray[i];
//		if(Object != NULL && Object->IsMinion() && Object->IsNeutral())
//			if(Object->IsAlive())
//				Objects.push_back(Object);
//	}
//
//	return Objects;
//}
//
//std::vector<GameObject*> GetMissiles() {
//	GameObjectManager* GObjects = GObjectManager;
//	std::vector<GameObject*> Objects;
//
//	for(int i = 0; i < GObjects->HighestObjectID; i++) {
//		GameObject* Object = GObjects->objectArray[i];
//		if(Object != NULL && Object->IsMissile())
//			Objects.push_back(Object);
//	}
//
//	return Objects;
//}
//
//std::vector<GameObject*> GetEnemyMissiles() {
//	GameObjectManager* GObjects = GObjectManager;
//	std::vector<GameObject*> Objects;
//
//	for(int i = 0; i < GObjects->HighestObjectID; i++) {
//		GameObject* Object = GObjects->objectArray[i];
//		if(Object != NULL && Object->IsMissile() && Object->IsEnemy())
//			Objects.push_back(Object);
//	}
//
//	return Objects;
//}
//
//std::vector<GameObject*> GetFriendlyMissiles() {
//	GameObjectManager* GObjects = GObjectManager;
//	std::vector<GameObject*> Objects;
//
//	for(int i = 0; i < GObjects->HighestObjectID; i++) {
//		GameObject* Object = GObjects->objectArray[i];
//		if(Object != NULL && Object->IsMissile() && Object->IsFriendly())
//			Objects.push_back(Object);
//	}
//
//	return Objects;
//}

//std::vector<GameObject*> GetTroyEnts() {
//	GameObjectManager* GObjects = GObjectManager;
//	std::vector<GameObject*> Objects;
//
//	for(int i = 0; i < GObjects->HighestObjectID; i++) {
//		GameObject* Object = GObjects->objectArray[i];
//		if(Object != NULL && Object->IsTroyEnt())
//			Objects.push_back(Object);
//	}
//
//	return Objects;
//}
//
//std::vector<GameObject*> GetEnemyTroyEnts() {
//	GameObjectManager* GObjects = GObjectManager;
//	std::vector<GameObject*> Objects;
//
//	for(int i = 0; i < GObjects->HighestObjectID; i++) {
//		GameObject* Object = GObjects->objectArray[i];
//		if(Object != NULL && Object->IsTroyEnt() && Object->IsEnemy())
//			Objects.push_back(Object);
//	}
//
//	return Objects;
//}
//
//std::vector<GameObject*> GetFriendlyTroyEnts() {
//	GameObjectManager* GObjects = GObjectManager;
//	std::vector<GameObject*> Objects;
//
//	for(int i = 0; i < GObjects->HighestObjectID; i++) {
//		GameObject* Object = GObjects->objectArray[i];
//		if(Object != NULL && Object->IsTroyEnt() && Object->IsFriendly())
//			Objects.push_back(Object);
//	}
//
//	return Objects;
//}