#ifndef _FSM_INTERNAL_H_
#define _FSM_INTERNAL_H_

#include "fsm.h"
#include <stddef.h>

fsm_state_t * fsm_state (void);
void fsm_set_state (fsm_state_t * state);

#endif//_FSM_INTERNAL_H_
