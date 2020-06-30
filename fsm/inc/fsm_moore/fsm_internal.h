/*
 * Copyright © 2020 Feodor A. Alexandrov (feodor.alexandrov@yandex.ru)
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v3. See the file LICENSE in the top level
 * directory for more details.
 */

#ifndef _FSM_INTERNAL_H_
#define _FSM_INTERNAL_H_

#include "fsm.h"
#include <stddef.h>

fsm_state_t * fsm_state (void);
void fsm_set_state (fsm_state_t * state);

#endif//_FSM_INTERNAL_H_
