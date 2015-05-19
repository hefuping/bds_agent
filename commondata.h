#ifndef __COMMONDATA_H__
#define __COMMONDATA_H__

#include "datatype.h"


/***********************  数据  ***********************/

//说明：用户报文明文缓冲区指针
extern struct Plaintext * pPlaintextData;

//说明：用户报文密文缓冲区指针
extern struct Ciphertext * pCiphertextData;

//说明：终端状态数据，按照提供的接口互斥访问
extern struct msgStateType terminalState;

//说明:北斗时间，按照提供的接口互斥访问
extern char bdtime[20];

//说明：配置信息结构
extern struct userConfig userConfig;

/***********************  数据访问控制  ***********************/

//说明：用户报文明文缓冲区结构pPlaintextData访问锁定
extern pthread_mutex_t lock_Plaintext;

//说明：用户报文密文缓冲区结构pCiphertextData访问锁定
extern pthread_mutex_t lock_Ciphertext;

//说明：终端状态缓冲区结构terminalState访问锁定
extern pthread_mutex_t lock_terminalState;

//说明：时间缓冲区bdtime访问锁定
extern pthread_mutex_t lock_bdtime;

//说明：配置信息缓冲区结构userConfig访问锁定
extern pthread_mutex_t lock_userConfig;


/***********************  多任务同步控制  ***********************/
//说明：通知加密
extern pthread_cond_t cond_Encryption;

//说明：通知上报
extern pthread_cond_t cond_Report;

//说明：通知终端状态
extern pthread_cond_t cond_TerminalState;

//说明：通知配置
extern pthread_cond_t cond_Config;




/***********************  方法  ***********************/

//--------------初始化终端状态--------------
//返回值：无
void InitTerminalState();

//--------------初始化北斗时间--------------
//返回值：无
void InitBdTime();

//--------------设置电量--------------
//percent:电量，输入参数
//返回值：无
void SetBatteryPercent(float percent);

//-----------设置3G信号强度-----------
//3gPercent:3G信号强度，输入参数
//返回值：无
void Set3gPercent(float gPercent);

//-----------获得3G信号强度-----------
//返回值：3G信号强度
float Get3gPercent();

//-----------设置北斗信号强度----------
//bdPercent:北斗信号强度，输入参数
//返回值：无
void SetbdPercent(float bdPercent);

//-----------获得北斗信号强度----------
//返回值：北斗信号强度
float GetbdPercent();

//-----------设置蓝牙信号强度----------
//btoothPercent:蓝牙信号强度，输入参数
//返回值：无
void SetBtoothPercent(float btoothPercent);

//-----------------设置位置------------
//altitude：高度，输入参数
//longitude：经度，输入参数
//latitude：纬度，输入参数
//返回值：无
void SetLocation(float altitude,float longitude,float latitude);

//-------------设置错误码------------------
//err:错误码，输入参数
//返回值：无
void SetErr(UINT32 err);

//-------------获得终端状态数据------------------
//terminalState:终端状态，输出参数
//返回值：无
void GetTerminalSate(struct msgStateType *terminalState);

//-------------获得北斗时间------------------
//time:北斗时间，输出参数
//返回值：无
void GetBdTime(char *time);

//-------------更新北斗时间------------------
//time:北斗时间，输入参数
//返回值：无
void SetBdTime(char *time);


//--------------初始化配置信息变量--------------
//返回值：无
void InitUserConfig();

//-------------获得配置数据------------------
//pUserConfig:终端状态，输出参数
//返回值：0，成功；-1，失败
int GetUserConfig(struct userConfig *pUserConfig);

//-------------用户绑定号码检查------------------
//pSecureid:用户绑定号码，输入参数
//返回值：0，成功；-1，失败
int CmpSecureid(char *pSecureid);

//-------------获得用户绑定号码------------------
//pSecureid:用户绑定号码，输出参数
//返回值：无
int GetSecureid(char *pSecureid);


#endif
