// Copyright (c) 2015-2016 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0
// http://vittorioromeo.info | vittorio.romeo@outlook.com

#pragma once

#include "../defer.hpp"
#include "../main_storage.hpp"
#include "../step.hpp"
#include "../system_manager.hpp"
#include "./refresh_event.hpp"
#include <ecst/aliases.hpp>
#include <ecst/config.hpp>

namespace ecst::context
{
    namespace impl
    {
        template <typename TSettings>
        class data : public system_manager<TSettings>,
                     public main_storage<TSettings>
        {
            template <typename>
            friend class defer::proxy;

            template <typename>
            friend class step::proxy;

        public:
            using settings_type = TSettings;
            using handle = ecst::context::entity::impl::handle;

        private:
            using defer_proxy_type = defer::proxy<settings_type>;
            using step_proxy_type = step::proxy<settings_type>;
            using refresh_state_type = defer::refresh_state<settings_type>;

            // State keeping track of entities to match/kill during refreshes.
            refresh_state_type _refresh_state;

            /// @brief Executes all systems' deferred functions, sequentially.
            template <typename TRefreshState, typename TFRefresh>
            void refresh_impl_execute_deferred(
                TRefreshState& rs, TFRefresh&& f_refresh);

            /// @brief Unsubscribes dead entities from systems, in parallel.
            template <typename TRefreshState, typename TFRefresh>
            void refresh_impl_kill_entities(
                TRefreshState& rs, TFRefresh&& f_refresh);

            /// @brief Matches new/modified entities to systems, in parallel.
            template <typename TRefreshState, typename TFRefresh>
            void refresh_impl_match_entities(
                TRefreshState& rs, TFRefresh&& f_refresh);

            /// @brief Refreshes the context.
            template <typename TFRefresh>
            void refresh(TFRefresh&& f_refresh);

        public:
            template <typename TFStep, typename... TFsRefresh>
            auto step(TFStep&& f_step, TFsRefresh&&... fs_refresh);
        };
    } // namespace impl
} // namespace ecst::context
