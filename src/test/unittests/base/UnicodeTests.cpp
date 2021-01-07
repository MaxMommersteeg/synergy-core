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

#include <array>
#include "arch/IArchString.h"
#include "base/Unicode.h"
#include "test/global/gtest.h"

TEST(UnicodeTests, doUTF32ToUTF8_will_convert_simple_string)
{
    bool errors;
    auto result = Unicode::UTF32ToUTF8(String("h\0\0\0e\0\0\0l\0\0\0l\0\0\0o\0\0\0", 20), &errors);
    EXPECT_FALSE(errors);
    EXPECT_STREQ(result.c_str(), "hello");
}

TEST(UnicodeTests, doUCS2ToUTF8_will_convert_simple_string)
{
    bool errors;
    auto result = Unicode::textToUTF8("hello", &errors, IArchString::kUCS2);
    EXPECT_FALSE(errors);
    EXPECT_TRUE(result == String("h\0e\0l", 5)); // mixed-platform expected result
}
