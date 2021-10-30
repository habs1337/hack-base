


#ifdef CRT
class c_console {
	FILE* m_write_stream = nullptr;
	bool m_is_opened_console = false;
public:
	c_console() = default;
	bool initialize();
	bool disable();
};
#endif