/**********************************************************************************
 * Created by Atlantis Specialist Technologies
 * by James Blakey-Milner, 1 Aug 2017.
 * Note! this file is in early development
 * (alpha) and is likely to change without notice.
 **********************************************************************************/

#include "AST_RS485.h"

void rsInit(void){
  pinMode(RS485_RE,OUTPUT);
  pinMode(RS485_SHDN,OUTPUT);
  digitalWrite(RS485_RE,HIGH);
  digitalWrite(RS485_SHDN,HIGH);
}