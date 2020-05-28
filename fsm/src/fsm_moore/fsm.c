// #include "fsm_internal.h"
#include "../../inc/fsm_moore/fsm_internal.h"

void fsm_create (fsm_state_t * state_list) {
	fsm_set_state(state_list);
}

void fsm_delete (void) {
	fsm_set_state(NULL);
}

void fsm_moore (void) {
	void (* state) (void) = fsm_state()->state;
	fsm_set_state(fsm_state()->next_state);
	state();
}

/*
Note:
	in fsm_moore state changes before calling active state
	occure to provide opportunity of calling fsm_create as
	active state
	It means DO NOT TOUCH fsm_moore!
*/