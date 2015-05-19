#ifndef __DATATYPE_H__
#define __DATATYPE_H__

#include <pthread.h>

typedef unsigned int 	UINT32;
typedef unsigned short 	UINT16;
typedef unsigned char 	UINT8;

typedef int 	INT32;
typedef short 	INT16;
typedef char 	INT8;

/****************************** 手机端 ********************************/
//消息头
struct	msgHeadType
{
	INT8	head[8]; // MBQBCJXT
	UINT32	msgLength;
	UINT8	msgType; 
	UINT8   reserve1; 
	UINT16  reserve2; 
	INT8	time[20]; // 2015-05-07 00:00:00
};
//安全认证
struct	msgSecureType
{
	INT8	Secureid[12];//手机ID
	UINT16	secureStatus; 
};
//代理终端状态
struct  msgStateType
{
	float  percent;
	float  gPercent;
	float  bdPercent;
	float  btoothPercent;
	float  altitude;
	float  longitude;
	float  latitude;
	UINT32	err;
};

/****************************** 代理终端 ********************************/
//明文结构
struct Plaintext
{
	UINT32 len;
	UINT8 * pData;
};
//密文结构
struct Ciphertext
{
	UINT32 len;
	UINT8 * pData;
};
//配置信息结构
struct userConfig
{
	UINT32 cmd;
	char wifiname[20];
	char wifipword[7];
	char btoothname[20];
	char btoothpword[8];
	char servicenum[12];
	char Secureid[12];
};
#endif
