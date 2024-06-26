#pragma once

// macro #defines for min & max are usually bad news,
// the native CUDA versions compile to single instructions
#undef min
#undef max

// cuda includes
// #include "cuda_runtime.h"
// #include "device_launch_parameters.h"
// #include "helper_cuda.h"
// #include "thrust/device_vector.h"
// #include "thrust/host_vector.h"
// #include "thrust/system/cuda/experimental/pinned_allocator.h"
// C++ includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _USE_MATH_DEFINES
#include <float.h>  // for _controlfp_s
#include <math.h>

#include <algorithm>
// for openCV GUI etc (ASCII escape)
#define ESC 27

// these mimic CUDA vectors, e.g uchar4
using uchar = unsigned char;
using ushort = unsigned short;
using uint = unsigned int;

using ulong = unsigned long;
using ullong = unsigned long long;
using llong = long long;
// const versions of above
using cuchar = const unsigned char;
using cushort = const unsigned short;
using cuint = const unsigned int;
using culong = const unsigned long;
using cullong = const unsigned long long;
// const versions of native types
using cchar = const char;
using cshort = const short;
using cint = const int;
using cfloat = const float;
using clong = const long;
using cdouble = const double;
using cllong = const long long;
// for CUDA (incomplete add as necessary)
using cint3 = const int3;
using cfloat3 = const float3;
// These to reduce verbosity in pointer arguments
// pointer variable data variable
template <typename T>
using r_Ptr = T *__restrict__;
// pointer variable data constant
template <typename T>
using cr_Ptr = const T *__restrict__;
// pointer constant data variable
template <typename T>
using cvr_Ptr = T *const __restrict__;
// pointer constant data constant
template <typename T>
using ccr_Ptr = const T *const __restrict__;
// thrust vectors aliases
template <typename T>
using thrustHvecPin =
    thrust::host_vector<T, thrust::cuda::experimental::pinned_allocator<T>>;
template <typename T>
using thrustHvec = thrust::host_vector<T>;
template <typename T>
using thrustDvec = thrust::device_vector<T>;
// get pointer to thrust device array
template <typename T>
T *trDptr(thrustDvec<T> &a) {
    return a.data().get();
}
// template <typename T> T * trDptr(thrustDvec<T> &a) { return
// thrust::raw_pointer_cast(a.data()); }

namespace cx {  // NB these are inside cx namespace
// fancy definition of pi, (default float)
template <typename T = float>
constexpr T pi = (T)(3.1415926535897932385L);
template <typename T = float>
constexpr T pi2 = (T)(2.0L * pi<T>);
template <typename T = float>
constexpr T piby2 = (T)(0.5L * pi<T>);
// strip path from file name
const char *tail(cchar *s, char c) {
    const char *pch = strrchr(s, c);
    return (pch != nullptr) ? pch + 1 : s;
}
// Based on NVIDIA checkCudaErrors in helper_cuda.h
inline int codecheck(cudaError_t code, cchar *file, cint line, cchar *call) {
    if (code != cudaSuccess) {
        fprintf(stderr, "cx::ok error: %s at %s:%d %s \n",
                cudaGetErrorString(code), tail(file, '/'), line, call);
        exit(1);  // NB this to quit on error
        // return 1; // or this to continue on error
    }
    return 0;
}

// this during development
#define ok(cuda_call) codecheck((cuda_call), __FILE__, __LINE__, #cuda_call)
// or this for final release code
// #define ok(cuda_call) cuda_call;
}  // namespace cx