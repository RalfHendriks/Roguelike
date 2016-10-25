#include "stdafx.h"
#include "enemy.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::Attack()
{
}

void Enemy::SetName(const std::string & n)
{
	name_ = n;
}

void Enemy::SetLevel(const int & lvl)
{
	level_ = lvl;
}

void Enemy::SetAttack(const int & att) {
	attack_ = att;
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

void Enemy::SetDefence(const int & def) {
	defence_ = def;
}

void Enemy::SetHealth(const int & h) {
	health_ = h;
}