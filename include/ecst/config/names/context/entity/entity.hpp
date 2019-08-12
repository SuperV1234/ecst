// Copyright (c) 2015-2016 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0
// http://vittorioromeo.info | vittorio.romeo@outlook.com

#pragma once

#include <ecst/config/names/context/context.hpp>

#define ECST_IMPL_CONTEXT_ENTITY_NAMESPACE \
    ECST_CONTEXT_NAMESPACE                 \
    {                                      \
        namespace entity
#define ECST_IMPL_CONTEXT_ENTITY_NAMESPACE_END \
    }                                          \
    ECST_CONTEXT_NAMESPACE_END

/// @macro Opens the `ecst::context::entity` namespace.
#define ECST_CONTEXT_ENTITY_NAMESPACE ECST_IMPL_CONTEXT_ENTITY_NAMESPACE

/// @macro Closes the `ecst::context::entity` namespace.
#define ECST_CONTEXT_ENTITY_NAMESPACE_END ECST_IMPL_CONTEXT_ENTITY_NAMESPACE_END
