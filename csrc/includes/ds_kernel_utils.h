/*
Copyright 2022 The Microsoft DeepSpeed Team

Centralized header file for preprocessor macros and constants
used throughout the codebase.
*/

#pragma once

#include <cuda.h>

#ifdef __HIP_PLATFORM_HCC__

// constexpr variant of warpSize for templating
constexpr int hw_warp_size = 64;
#define HALF_PRECISION_AVAILABLE = 1
#include <hip/hip_cooperative_groups.h>

#else  // !__HIP_PLATFORM_HCC__

// constexpr variant of warpSize for templating
constexpr int hw_warp_size = 32;

#if __CUDA_ARCH__ >= 530
#define HALF_PRECISION_AVAILABLE = 1
#define PTX_AVAILABLE
#endif  // __CUDA_ARCH__ >= 530

#if __CUDA_ARCH__ >= 800
#define ASYNC_COPY_AVAILABLE
#define BF16_AVAILABLE
#endif  // __CUDA_ARCH__ >= 800

#include <cooperative_groups.h>

#define DS_HD_INLINE __host__ __device__ __forceinline__
#define DS_D_INLINE __device__ __forceinline__

#endif  //__HIP_PLATFORM_HCC__
