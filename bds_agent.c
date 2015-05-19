#include "stdio.h"
#include "datatype.h"
#include "commondata.h"

struct Plaintext * pPlaintextData;
struct Ciphertext * pCiphertextData;
struct msgStateType terminalState;
char bdtime[20];
struct userConfig userConfig;

pthread_mutex_t lock_Plaintext;
pthread_mutex_t lock_Ciphertext;
pthread_mutex_t lock_terminalState;
pthread_mutex_t lock_bdtime;
pthread_mutex_t lock_userConfig;


pthread_cond_t cond_Encryption;
pthread_cond_t cond_Report;
pthread_cond_t cond_TerminalState;
pthread_cond_t cond_Config;


void main()
{
	printf("hello,bds_agent...\r\n");
	return;
}
