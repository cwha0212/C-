/*
 * 파일이름:BankingCommonDecl.h
 * 작성자:하창완
 * 업데이트 정보:[2022.01.01] ver.07
 */

#ifndef __BANKING_COMMON_DECL_H__
#define __BANKING_COMMON_DECL_H__

#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN=20;

enum {MAKE=1 ,DEPOSIT, WITHDRAW, INQUIRE, EXIT}; //메뉴

enum {LEVEL_A=7, LEVEL_B=4, LEVEL_C=2};          //신용등급

enum {NORMAL=1, CREDIT};                         //계좌종류

#endif
