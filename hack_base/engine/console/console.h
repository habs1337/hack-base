


#ifdef CRT
class c_console {
	FILE* m_write_stream = nullptr;
public:
	c_console() = default;
	bool initialize();
	bool disable();
};
#endif