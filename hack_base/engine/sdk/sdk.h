
namespace sdk {


#ifndef SELL_BUILD
#ifdef CRT

	void draw_matrix(g_cheat::sdk::c_matrix4x4 matrix);

	void draw_vector(g_cheat::sdk::c_vec3 vector);

#endif
#endif
}

class c_sdk {
public:



	c_sdk() = default;

	bool initialize(c_offset& offsets);

};