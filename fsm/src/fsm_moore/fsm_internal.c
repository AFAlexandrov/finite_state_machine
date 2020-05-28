// #include "fsm_internal.h"
#include "../../inc/fsm_moore/fsm_internal.h"

static fsm_state_t * _state = NULL;

fsm_state_t * fsm_state (void) {
	return _state;
}

void fsm_set_state (fsm_state_t * state) {
	_state = state;
}
