
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "Library.h"
#ifdef __cplusplus
	};
#endif
/* TODO: Add your comment here */
void DoorStateMachine(struct DoorStateMachine* inst)
{
	/*TODO: Add your code here*/
	switch(inst->state)
	{
		case ST_INIT:
			{
				inst->state = ST_UNKNOWN;
				break;
			}
		
		case ST_UNKNOWN:
			{
				if(inst->direction == 0) {  
					inst->state = ST_OPEN;
				}  
				if (inst->direction == 1) { 
					inst->state = ST_CLOSE;
				}
				break;
			}
		
		case ST_OPEN:
			{
				inst->speed = 0;
				if(inst->direction == 0) {
					inst->state=ST_ACC_POS;
				}
				break;
			}
				
		case ST_ACC_POS:
			{
				inst->speed = 150;
				if(inst->sw2) { 
					inst->state = ST_POS;
				}
				if (inst->direction == 1) {
					inst->state = ST_DEC_NEG;
				}
				break;
			}
		
		case ST_POS:
			{
				inst->speed = 900;
				if(inst->sw3) {
					inst->state = ST_DEC_POS;
				}
				if(inst->direction == 1) {
					inst->state = ST_NEG;
				}
			}
			break;	
		
		case ST_DEC_POS:
			{
				inst->speed = 150;
				if(inst->sw4) {
					inst->state = ST_CLOSE;
				}
				break;
			}
		
		case ST_CLOSE:
			{
				inst->speed = 0;
				if(inst->direction == 1) {
					inst->state=ST_ACC_NEG;
				}
				break;
			}
		
		case ST_ACC_NEG:
			{
				inst->speed = -150;
				if(inst->sw3) {
					inst->state = ST_NEG;
				}
				if (inst->direction == 0) {
					inst->state = ST_DEC_POS;
				}
				break;
			}
		
		case ST_NEG:
			{
				inst->speed = -900;
				if(inst->sw2) {
					inst->state = ST_DEC_NEG;
				}
				if(inst->direction == 0) {
					inst->state = ST_POS;
				}
				break;
			}
		
		case ST_DEC_NEG:
			{
				inst->speed = -150;
				if(inst->sw1) {
					inst->state = ST_OPEN;
				}
				break;
			}
	}
}
