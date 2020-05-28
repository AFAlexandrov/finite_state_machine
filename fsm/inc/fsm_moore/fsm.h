#ifndef _FSM_H_
#define _FSM_H_

typedef struct fsm_state {
	void (* state) (void);
	struct fsm_state * next_state;
} fsm_state_t;

void fsm_create (fsm_state_t * state_list);
void fsm_delete (void);
void fsm_moore (void);

#endif//_FSM_H_
