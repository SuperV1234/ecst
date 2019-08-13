// Copyright (c) 2015-2016 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0
// http://vittorioromeo.info | vittorio.romeo@outlook.com

#pragma once

#if defined(ECST_LOG_ENABLED)

#include "./impl.hpp"
#include <ecst/aliases.hpp>
#include <ecst/config.hpp>

#define ECST_IMPL_DEFINE_LO(x)                          \
    auto& ECST_CONST_FN VRM_PP_CAT(lo, _, x)() noexcept \
    {                                                   \
        return impl::log(impl::x);                      \
    }

namespace ecst::debug
{
    ECST_IMPL_DEFINE_LO(entity)
    ECST_IMPL_DEFINE_LO(component)
    ECST_IMPL_DEFINE_LO(entity_memory)
    ECST_IMPL_DEFINE_LO(component_memory)
    ECST_IMPL_DEFINE_LO(thread_pool)
    ECST_IMPL_DEFINE_LO(instance)
    ECST_IMPL_DEFINE_LO(instance_parallelism)
    ECST_IMPL_DEFINE_LO(context_refresh)
    ECST_IMPL_DEFINE_LO(system_bitset)
    ECST_IMPL_DEFINE_LO(system_match)
    ECST_IMPL_DEFINE_LO(metadata_bitset)
} // namespace ecst::debug

#undef ECST_IMPL_DEFINE_LO

#endif
