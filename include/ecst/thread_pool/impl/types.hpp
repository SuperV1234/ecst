// Copyright (c) 2015-2016 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0
// http://vittorioromeo.info | vittorio.romeo@outlook.com

#pragma once

#include "../third_party.hpp"
#include <ecst/aliases.hpp>
#include <ecst/config.hpp>
#include <ecst/utils.hpp>

namespace etp
{
    using ecst::sz_t;

    using task = ecst::fixed_function<void(), 128>;
    using task_queue = moodycamel::BlockingConcurrentQueue<task>;
    using task_queue_consumer_token = moodycamel::ConsumerToken;
    using task_queue_producer_token = moodycamel::ProducerToken;
} // namespace etp
