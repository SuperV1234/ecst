// Copyright (c) 2015-2016 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0
// http://vittorioromeo.info | vittorio.romeo@outlook.com

#pragma once

#include <ecst/config.hpp>

// If this macro is defined, `mingw-std-threads` will be used to implement
// `std::thread`, `std::mutex` and `std::condition_variable`.
#ifdef ECST_USE_MEGANZ_MINGW_THREAD

#pragma GCC system_header

#include <condition_variable>
#include <mutex>
#include <thread>

// https://github.com/meganz/mingw-std-threads
#include "./third_party/mingw-std-threads/mingw.condition_variable.h"
#include "./third_party/mingw-std-threads/mingw.mutex.h"
#include "./third_party/mingw-std-threads/mingw.thread.h"

#define _GLIBCXX_FUTURE 1

#endif

#include <atomic>
#include <chrono>
#include <condition_variable>
#include <mutex>
#include <thread>

namespace ecst
{
    namespace this_thread = std::this_thread;
    namespace chrono = std::chrono;
    using std::atomic;
    using std::condition_variable;
    using std::lock_guard;
    using std::mutex;
    using std::thread;
    using std::unique_lock;
} // namespace ecst
