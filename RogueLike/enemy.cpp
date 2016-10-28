#include "stdafx.h"
#include "enemy.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::SetAttackSequence(const int & attSeq) {
	attackSequence_ = attSeq;
}

void Enemy::SetMinDamage(const int & minDam) {
	minDamage_ = minDam;
}

void Enemy::SetMaxDamage(const int & maxDam) {
	maxDamage_ = maxDam;
}

Enemy* Enemy::Clone() {
	Enemy* enemy = new Enemy();
	enemy->SetAttack(GetAttack());
	enemy->SetAttackSequence(GetAttackSequence());
	enemy->SetDefence(GetDefence());
	enemy->SetHealth(GetHealth());
	enemy->SetLevel(GetLevel());
	enemy->SetMaxDamage(GetMaxDamage());
	enemy->SetMinDamage(GetMinDamage());
	enemy->SetName(GetName());
	return enemy;
}