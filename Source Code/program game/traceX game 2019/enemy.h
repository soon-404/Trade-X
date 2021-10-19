#pragma once
#include "entity.h"
#include "player.h"
class enemy : public entity
{
public:
	int movementSpeed = 1;
	int attackDamage = 1;

	int checkDirection;
	int blood = 10;
	bool attack = false;
	bool alive = true;
	
	//Monster Valuable
	int timeMonsterArrive;	
	int counterWalkingMonster = 0;
	int counterMonsterAttack = 0;
	int tempMonsterRand = 0;
	float timeMonsterATK;
	float afterMonsterArrive;
	bool monsterCanMoveUp = true;
	bool monsterCanMoveDown = true;
	bool monsterCanMoveLeft = true;
	bool monsterCanMoveRight = true;
	bool enterMonsterArrive = false;
	bool monsterAngry = false;
	bool enterMonsterAttack = false;
    
	//Shooter Valuable
	int counterWalkingShooter = 0;
	int timeShooterArrive;
	int tempShooterRand = 0;
	float timeShooterATK;
	float afterShooterArrive;
	bool shooterCanMoveUp = true;
	bool shooterCanMoveDown = true;
	bool shooterCanMoveLeft = true;
	bool shooterCanMoveRight = true;
	bool enterShooterArrive = false;
	bool shooterAngry = false;
	bool enterShooterAttack = false;

	//Lavar Valuable
	int timeLavarArrive;
	int counterWalkingLavar = 0;
	int counterLavarAttack = 0;
	int tempLavarRand = 0;
	float timeLavarATK;
	float afterLavarArrive;
	bool lavarCanMoveUp = true;
	bool lavarCanMoveDown = true;
	bool lavarCanMoveLeft = true;
	bool lavarCanMoveRight = true;
	bool enterLavarArrive = false;
	bool lavarAngry = false;
	bool enterLavarAttack = false;

	//Boss Valuable
	int timeBossArrive;
	int counterWalkingBoss = 0;
	int counterBossAttack = 0;
	int tempBossRand = 0;
	float timeBossATK;
	float afterBossArrive;
	bool bossCanMoveUp = true;
	bool bossCanMoveDown = true;
	bool bossCanMoveLeft = true;
	bool bossCanMoveRight = true;
	bool enterBossArrive = false;
	bool bossAngry = false;
	bool enterBossAttack = false;

	bool keyArrive = false;

    enemy();
	void update();
};

