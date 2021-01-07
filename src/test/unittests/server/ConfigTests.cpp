/*
 * synergy -- mouse and keyboard sharing utility
 * Copyright (C) 2014-2016 Symless Ltd.
 * 
 * This package is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * found in the file LICENSE that should have accompanied this file.
 * 
 * This package is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "lib/server/Config.h"
#include "test/global/gtest.h"

TEST(ServerConfigTests, serverconfig_will_deem_inequal_configs_with_different_map_size)
{
    Config a(nullptr);
    Config b(nullptr);
    a.addScreen("screenA");
    EXPECT_FALSE(a == b);
    EXPECT_FALSE(b == a);
}

TEST(ServerConfigTests, serverconfig_will_deem_inequal_configs_with_different_cell_names)
{
    Config a(nullptr);
    Config b(nullptr);
    a.addScreen("screenA");
    b.addScreen("screenB");
    EXPECT_FALSE(a == b);
    EXPECT_FALSE(b == a);
}

TEST(ServerConfigTests, serverconfig_will_deem_equal_configs_with_same_cell_names)
{
    Config a(nullptr);
    Config b(nullptr);
    a.addScreen("screenA");
    b.addScreen("screenA");
    EXPECT_TRUE(a == b);
    EXPECT_TRUE(b == a);
}
