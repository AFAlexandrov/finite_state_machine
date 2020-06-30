/*
 * Copyright © 2020 Feodor A. Alexandrov (feodor.alexandrov@yandex.ru)
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v3. See the file LICENSE in the top level
 * directory for more details.
 */

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
