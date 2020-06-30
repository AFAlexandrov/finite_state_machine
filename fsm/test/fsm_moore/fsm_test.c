/*
 * Copyright © 2020 Feodor A. Alexandrov (feodor.alexandrov@yandex.ru)
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v3. See the file LICENSE in the top level
 * directory for more details.
 */

#include "unity_fixture.h"

#include "fsm_internal.h"
#include "fsm_test_stubs.h"

TEST_GROUP (fsm_moore);

TEST_SETUP (fsm_moore)
{
	fsm_create(test_state_list);
	state_applyed = false;
}

TEST_TEAR_DOWN (fsm_moore)
{
	state_applyed = false;
	fsm_delete();
}

TEST (fsm_moore, set_state) {
	fsm_set_state( (fsm_state_t *)some_pointer );

	TEST_ASSERT_EQUAL_PTR((fsm_state_t *)some_pointer, fsm_state());
}

TEST (fsm_moore, create) {
	fsm_create(test_state_list);

	TEST_ASSERT_EQUAL_PTR(test_state_list, fsm_state());
}

TEST (fsm_moore, delete) {
	fsm_create(test_state_list);
	fsm_delete();

	TEST_ASSERT_EQUAL_PTR(NULL, fsm_state());	
}

/*
[v] apply_state_exec_initial_state
[v] apply_state_set_next_state_as_initial
*/

TEST (fsm_moore, apply_state_exec_initial_state) {
	fsm_moore();

	TEST_ASSERT_TRUE(state_applyed);
}

TEST (fsm_moore, apply_state_set_next_state_as_initial) {
	fsm_moore();

	TEST_ASSERT_EQUAL_PTR(test_state_2, fsm_state()->state);
}

/*
[v] call_create_from_state
[v] apply_state_after_reinit
*/

TEST (fsm_moore, call_create_from_state) {
	fsm_moore(); // apply_state_1
	fsm_moore(); // apply_state_2
	fsm_moore(); // reinit_to_another_one

	TEST_ASSERT_EQUAL_PTR(another_state_1, fsm_state()->state);
}

TEST (fsm_moore, apply_state_after_reinit) {
	fsm_moore(); // apply_state_1
	fsm_moore(); // apply_state_2
	fsm_moore(); // reinit_to_another_one

	fsm_moore(); // apply_another_state_1

	TEST_ASSERT_TRUE(another_state_applyed);
}

/*
[] config_fsm_circle_works
*/

TEST (fsm_moore, circle_works) {
	fsm_create(circle_state_list);

	for (int lap = 0; lap < 1000; lap++) {
		fsm_moore(); //state 1
		TEST_ASSERT_TRUE(circle_state_1_applyed);
		TEST_ASSERT_FALSE(circle_state_2_applyed);
		TEST_ASSERT_FALSE(circle_state_3_applyed);

		fsm_moore(); //state 2
		TEST_ASSERT_FALSE(circle_state_1_applyed);
		TEST_ASSERT_TRUE(circle_state_2_applyed);
		TEST_ASSERT_FALSE(circle_state_3_applyed);

		fsm_moore(); //state 3
		TEST_ASSERT_FALSE(circle_state_1_applyed);
		TEST_ASSERT_FALSE(circle_state_2_applyed);
		TEST_ASSERT_TRUE(circle_state_3_applyed);
	}
}
