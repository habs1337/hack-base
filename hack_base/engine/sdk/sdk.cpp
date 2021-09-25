#include "../../hack_includes.h"

bool c_sdk::initialize(c_offset& offsets) {



#ifndef SELL_BUILD
#ifdef CRT
	printf("sdk:\n");

#endif
#endif

	/*if (!IS_VALID_PTR()) {
		return false;
	}*/

	return true;
}


#ifndef SELL_BUILD
#ifdef CRT

void sdk::draw_matrix(g_cheat::sdk::c_matrix4x4 matrix)
{
	printf("[%f] [%f] [%f] [%f]\n", matrix.m[0][0], matrix.m[0][1], matrix.m[0][2], matrix.m[0][3]);

	printf("[%f] [%f] [%f] [%f]\n", matrix.m[1][0], matrix.m[1][1], matrix.m[1][2], matrix.m[1][3]);

	printf("[%f] [%f] [%f] [%f]\n", matrix.m[2][0], matrix.m[2][1], matrix.m[2][2], matrix.m[2][3]);

	printf("[%f] [%f] [%f] [%f]\n\n", matrix.m[3][0], matrix.m[3][1], matrix.m[3][2], matrix.m[3][3]);

}

void sdk::draw_vector(g_cheat::sdk::c_vec3 vector) {

	printf("[%f] [%f] [%f]\n", vector.get_x(), vector.get_y(), vector.get_z());

}

#endif
#endif