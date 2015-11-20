#ifndef DEBUG_HEADER
#define DEBUG_HEADER

#define DEBAs

#ifdef DEBA
	#define DEB(x) std::cout << #x" = " << x << std::endl
#endif
#ifndef DEBA
	#define DEB(x) std::cout << "";
#endif





#endif


