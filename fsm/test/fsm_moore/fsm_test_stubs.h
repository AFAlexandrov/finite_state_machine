/*
 * Copyright © 2020 Feodor A. Alexandrov (feodor.alexandrov@yandex.ru)
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v3. See the file LICENSE in the top level
 * directory for more details.
 */

#ifndef _FSM_TEST_STUBS_H_
#define _FSM_TEST_STUBS_H_

#include <stdbool.h>
static bool state_applyed = false;
void test_state_1 (void) {
	state_applyed = true;
}

void test_state_2 (void) {
	test_state_1();
}

void reinit (void);

#define TEST_STATE_NUM 3
enum test_states {
	_1_st,
	_2_st,
	_reinit_st
};

static fsm_state_t test_state_list [TEST_STATE_NUM] = {
	[_1_st] = {
		.state = test_state_1,
		.next_state = &test_state_list[_2_st]
	},
	[_2_st] = {
		.state = test_state_2,
		.next_state = &test_state_list[_reinit_st]
	},
	[_reinit_st] = {
		.state = reinit,
		.next_state = NULL
	}
};

static bool another_state_applyed = false;
void another_state_1 (void) {
	another_state_applyed = true;
}

#define ANOTHER_TEST_STATE_NUM 1
enum another_test_states {
	_1_another_st,
	_2_another_st
};
static fsm_state_t another_state_list [ANOTHER_TEST_STATE_NUM] = {
	[_1_another_st] = {
		.state = another_state_1,
		.next_state = NULL
	}
};

void reinit (void) {
	fsm_create(another_state_list);
}

static void * some_pointer;

static bool
	circle_state_1_applyed = false,
	circle_state_2_applyed = false,
	circle_state_3_applyed = false;

void circle_state_1 (void) {
	circle_state_1_applyed = true;
	circle_state_3_applyed = false;
}

void circle_state_2 (void) {
	circle_state_2_applyed = true;
	circle_state_1_applyed = false;
}

void circle_state_3 (void) {
	circle_state_3_applyed = true;
	circle_state_2_applyed = false;
}

#define CIRCLE_STATE_NUM 3
enum circle_states {
	_circle_1,
	_circle_2,
	_circle_3
};
static fsm_state_t circle_state_list [TEST_STATE_NUM] = {
	[_circle_1] = {
		.state = circle_state_1,
		.next_state = &circle_state_list[_circle_2]
	},
	[_circle_2] = {
		.state = circle_state_2,
		.next_state = &circle_state_list[_circle_3]
	},
	[_circle_3] = {
		.state = circle_state_3,
		.next_state = &circle_state_list[_circle_1]
	}
};

#endif//_FSM_TEST_STUBS_H_
