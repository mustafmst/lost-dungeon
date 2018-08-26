#pragma once
#include <SFML/Graphics.hpp>

#define FRAME_HEIGHT 36
#define FRAME_WIDTH 18

// IDLE
#define KNIGHT_IDLE_FRAME_1_R sf::IntRect(FRAME_WIDTH*0,FRAME_HEIGHT*0,FRAME_WIDTH,FRAME_HEIGHT)
#define KNIGHT_IDLE_FRAME_2_R sf::IntRect(FRAME_WIDTH*1,FRAME_HEIGHT*0,FRAME_WIDTH,FRAME_HEIGHT)
#define KNIGHT_IDLE_FRAME_3_R sf::IntRect(FRAME_WIDTH*2,FRAME_HEIGHT*0,FRAME_WIDTH,FRAME_HEIGHT)
#define KNIGHT_IDLE_FRAME_4_R sf::IntRect(FRAME_WIDTH*3,FRAME_HEIGHT*0,FRAME_WIDTH,FRAME_HEIGHT)

#define KNIGHT_IDLE_FRAME_1_L sf::IntRect(FRAME_WIDTH*3,FRAME_HEIGHT*1,FRAME_WIDTH,FRAME_HEIGHT)
#define KNIGHT_IDLE_FRAME_2_L sf::IntRect(FRAME_WIDTH*2,FRAME_HEIGHT*1,FRAME_WIDTH,FRAME_HEIGHT)
#define KNIGHT_IDLE_FRAME_3_L sf::IntRect(FRAME_WIDTH*1,FRAME_HEIGHT*1,FRAME_WIDTH,FRAME_HEIGHT)
#define KNIGHT_IDLE_FRAME_4_L sf::IntRect(FRAME_WIDTH*0,FRAME_HEIGHT*1,FRAME_WIDTH,FRAME_HEIGHT)

// WALK
#define KNIGHT_WALK_FRAME_1_R sf::IntRect(FRAME_WIDTH*0,FRAME_HEIGHT*2,FRAME_WIDTH,FRAME_HEIGHT)
#define KNIGHT_WALK_FRAME_2_R sf::IntRect(FRAME_WIDTH*1,FRAME_HEIGHT*2,FRAME_WIDTH,FRAME_HEIGHT)
#define KNIGHT_WALK_FRAME_3_R sf::IntRect(FRAME_WIDTH*2,FRAME_HEIGHT*2,FRAME_WIDTH,FRAME_HEIGHT)
#define KNIGHT_WALK_FRAME_4_R sf::IntRect(FRAME_WIDTH*3,FRAME_HEIGHT*2,FRAME_WIDTH,FRAME_HEIGHT)
#define KNIGHT_WALK_FRAME_5_R sf::IntRect(FRAME_WIDTH*4,FRAME_HEIGHT*2,FRAME_WIDTH,FRAME_HEIGHT)
#define KNIGHT_WALK_FRAME_6_R sf::IntRect(FRAME_WIDTH*5,FRAME_HEIGHT*2,FRAME_WIDTH,FRAME_HEIGHT)
#define KNIGHT_WALK_FRAME_7_R sf::IntRect(FRAME_WIDTH*6,FRAME_HEIGHT*2,FRAME_WIDTH,FRAME_HEIGHT)
#define KNIGHT_WALK_FRAME_8_R sf::IntRect(FRAME_WIDTH*7,FRAME_HEIGHT*2,FRAME_WIDTH,FRAME_HEIGHT)

#define KNIGHT_WALK_FRAME_1_L sf::IntRect(FRAME_WIDTH*7,FRAME_HEIGHT*3,FRAME_WIDTH,FRAME_HEIGHT)
#define KNIGHT_WALK_FRAME_2_L sf::IntRect(FRAME_WIDTH*6,FRAME_HEIGHT*3,FRAME_WIDTH,FRAME_HEIGHT)
#define KNIGHT_WALK_FRAME_3_L sf::IntRect(FRAME_WIDTH*5,FRAME_HEIGHT*3,FRAME_WIDTH,FRAME_HEIGHT)
#define KNIGHT_WALK_FRAME_4_L sf::IntRect(FRAME_WIDTH*4,FRAME_HEIGHT*3,FRAME_WIDTH,FRAME_HEIGHT)
#define KNIGHT_WALK_FRAME_5_L sf::IntRect(FRAME_WIDTH*3,FRAME_HEIGHT*3,FRAME_WIDTH,FRAME_HEIGHT)
#define KNIGHT_WALK_FRAME_6_L sf::IntRect(FRAME_WIDTH*2,FRAME_HEIGHT*3,FRAME_WIDTH,FRAME_HEIGHT)
#define KNIGHT_WALK_FRAME_7_L sf::IntRect(FRAME_WIDTH*1,FRAME_HEIGHT*3,FRAME_WIDTH,FRAME_HEIGHT)
#define KNIGHT_WALK_FRAME_8_L sf::IntRect(FRAME_WIDTH*0,FRAME_HEIGHT*3,FRAME_WIDTH,FRAME_HEIGHT)

// HIT
#define KNIGHT_HIT_FRAME_1_R sf::IntRect(FRAME_WIDTH*4,FRAME_HEIGHT*0,FRAME_WIDTH,FRAME_HEIGHT)
#define KNIGHT_HIT_FRAME_2_R sf::IntRect(FRAME_WIDTH*3,FRAME_HEIGHT*0,FRAME_WIDTH,FRAME_HEIGHT)

#define KNIGHT_HIT_FRAME_1_L sf::IntRect(FRAME_WIDTH*4,FRAME_HEIGHT*1,FRAME_WIDTH,FRAME_HEIGHT)
#define KNIGHT_HIT_FRAME_2_L sf::IntRect(FRAME_WIDTH*3,FRAME_HEIGHT*1,FRAME_WIDTH,FRAME_HEIGHT)

// ATTACK

#define AFB FRAME_HEIGHT*4
#define AFW 53
#define AFH 40

#define KNIGHT_ATTACK_FRAME_1_R sf::IntRect(AFW*0,AFB+AFH*0,AFW,AFH)
#define KNIGHT_ATTACK_FRAME_2_R sf::IntRect(AFW*1,AFB+AFH*0,AFW,AFH)
#define KNIGHT_ATTACK_FRAME_3_R sf::IntRect(AFW*2,AFB+AFH*0,AFW,AFH)
#define KNIGHT_ATTACK_FRAME_4_R sf::IntRect(AFW*3,AFB+AFH*0,AFW,AFH)
#define KNIGHT_ATTACK_FRAME_5_R sf::IntRect(AFW*4,AFB+AFH*0,AFW,AFH)
#define KNIGHT_ATTACK_FRAME_6_R sf::IntRect(AFW*5,AFB+AFH*0,AFW,AFH)
#define KNIGHT_ATTACK_FRAME_7_R sf::IntRect(AFW*6,AFB+AFH*0,AFW,AFH)
#define KNIGHT_ATTACK_FRAME_8_R sf::IntRect(AFW*7,AFB+AFH*0,AFW,AFH)
#define KNIGHT_ATTACK_FRAME_9_R sf::IntRect(AFW*8,AFB+AFH*0,AFW,AFH)
#define KNIGHT_ATTACK_FRAME_10_R sf::IntRect(AFW*9,AFB+AFH*0,AFW,AFH)

#define KNIGHT_ATTACK_FRAME_1_L sf::IntRect(AFW*0,AFB+AFH*1,AFW,AFH)
#define KNIGHT_ATTACK_FRAME_2_L sf::IntRect(AFW*1,AFB+AFH*1,AFW,AFH)
#define KNIGHT_ATTACK_FRAME_3_L sf::IntRect(AFW*2,AFB+AFH*1,AFW,AFH)
#define KNIGHT_ATTACK_FRAME_4_L sf::IntRect(AFW*3,AFB+AFH*1,AFW,AFH)
#define KNIGHT_ATTACK_FRAME_5_L sf::IntRect(AFW*4,AFB+AFH*1,AFW,AFH)
#define KNIGHT_ATTACK_FRAME_6_L sf::IntRect(AFW*5,AFB+AFH*1,AFW,AFH)
#define KNIGHT_ATTACK_FRAME_7_L sf::IntRect(AFW*6,AFB+AFH*1,AFW,AFH)
#define KNIGHT_ATTACK_FRAME_8_L sf::IntRect(AFW*7,AFB+AFH*1,AFW,AFH)
#define KNIGHT_ATTACK_FRAME_9_L sf::IntRect(AFW*8,AFB+AFH*1,AFW,AFH)
#define KNIGHT_ATTACK_FRAME_10_L sf::IntRect(AFW*9,AFB+AFH*1,AFW,AFH)