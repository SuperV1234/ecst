// Copyright (c) 2015-2016 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0
// http://vittorioromeo.info | vittorio.romeo@outlook.com

#pragma once

#include "./task_dependency_data.hpp"
#include <ecst/aliases.hpp>
#include <ecst/config.hpp>
#include <ecst/utils.hpp>

namespace ecst::scheduler::atomic_counter
{
    /// @brief Logic task, part of a group, that can be executed on a thread
    /// pool.
    template <typename TDependencyData>
    class task
    {
    private:
        /// @brief Dependency data for the task.
        TDependencyData _dependency_data;

    public:
        auto& dependency_data() noexcept
        {
            return _dependency_data;
        }

        /// @brief Executes the task at runtime.
        /// @param tg Parent task group.
        /// @param my_id ID of the current task.
        /// @param sp Parent context scheduler proxy.
        /// @param f Function that will be passed to the system context for
        /// execution.
        template <               // .
            typename TTaskGroup, // .
            typename TLatch,     // .
            typename TID,        // .
            typename TContext,   // .
            typename TF          // .
            >
        void run(           // .
            TTaskGroup& tg, // .
            TLatch& b,      // .
            TID my_id,      // .
            TContext& sp,   // .
            TF& f           // .
        );
    };
} // namespace ecst::scheduler::atomic_counter
