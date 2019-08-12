// Copyright (c) 2015-2016 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0
// http://vittorioromeo.info | vittorio.romeo@outlook.com

#pragma once

#include "./parameters.hpp"
#include <ecst/aliases.hpp>
#include <ecst/config.hpp>

ECST_INNER_PARALLELISM_COMPOSER_NAMESPACE
{
    namespace fixed_threshold
    {
        template <                     // .
            typename TEntityThreshold, // .
            typename TStrategyGreater, // .
            typename TStrategyLower    // .
            >
        constexpr auto v(TEntityThreshold, TStrategyGreater, TStrategyLower)
        {
            return impl::parameters< // .
                TEntityThreshold,    // .
                TStrategyGreater,    // .
                TStrategyLower       // .
                >{};
        }
    } // namespace fixed_threshold
}
ECST_INNER_PARALLELISM_COMPOSER_NAMESPACE_END
