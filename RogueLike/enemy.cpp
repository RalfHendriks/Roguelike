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