// Copyright (c) 2015-2016 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0
// http://vittorioromeo.info | vittorio.romeo@outlook.com

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <ecst/aliases.hpp>
#include <ecst/config.hpp>

namespace example
{
    namespace boilerplate
    {
        class app
        {
        protected:
            sf::RenderWindow& _window;

        public:
            inline app(sf::RenderWindow& window) noexcept : _window{window}
            {
            }

            inline void stop() noexcept
            {
                return _window.close();
            }

            template <typename... Ts>
            inline void render(Ts&&... xs) noexcept
            {
                _window.draw(FWD(xs)...);
            }

            inline auto& window() noexcept
            {
                return _window;
            }
            inline const auto& window() const noexcept
            {
                return _window;
            }
        };
    } // namespace boilerplate
} // namespace example
