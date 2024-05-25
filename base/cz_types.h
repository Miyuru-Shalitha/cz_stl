#ifndef CZ_TYPES_H
#define CZ_TYPES_H

#ifdef _WIN32
	typedef signed char i8;
	typedef short i16;
	typedef int i32;
	typedef long long i64;

	typedef unsigned char u8;
	typedef unsigned short u16;
	typedef unsigned int u32;
	typedef unsigned long long u64;

	typedef float f32;
	typedef double f64;

	typedef size_t usize;

	#ifndef __cplusplus
		typedef u8 bool;
		#define true 1
		#define false 0
	#endif
#else
	#error "Platform not yet supported!"
#endif

#endif