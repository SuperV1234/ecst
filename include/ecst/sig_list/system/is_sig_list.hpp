// Copyright (c) 2015-2016 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0
// http://vittorioromeo.info | vittorio.romeo@outlook.com

#pragma once

#include <ecst/config.hpp>
#include <ecst/mp/list.hpp>
#include <ecst/sig/system.hpp>

namespace ecst::sig_list::system
{
    /// @brief Returns `true` if the passed argument is a system signature list.
    template <typename T>
    constexpr auto valid(T&& x) noexcept
    {
        return bh::all_of(bh::transform(x, mp::unwrapped), // .
            sig::system::valid);
    }
} // namespace ecst::sig_list::system
