/*
 * Copyright © 2020 Feodor A. Alexandrov (feodor.alexandrov@yandex.ru)
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v3. See the file LICENSE in the top level
 * directory for more details.
 */

// #include "fsm_internal.h"
#include "../../inc/fsm_moore/fsm_internal.h"

static fsm_state_t * _state = NULL;

fsm_state_t * fsm_state (void) {
	return _state;
}

void fsm_set_state (fsm_state_t * state) {
	_state = state;
}
