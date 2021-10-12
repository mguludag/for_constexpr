/*****************************************************************************
 * for_constexpr.hpp
 *
 * Created: 10/12/2021 2021 by mguludag
 *
 * Copyright 2021 mguludag. All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *****************************************************************************/

#ifndef FOR_CONSTEXPR_HPP
#define FOR_CONSTEXPR_HPP
namespace stdx
{
  template<int i>
  class for_constexpr
  {
  public:
      template<typename Func, typename... Args>
      explicit for_constexpr(Func &&func, Args &&...args)
      {
          static for_constexpr<i - 1>(func, args...);
          func(args...);
      }
  };

  template<>
  class for_constexpr<0>
  {
  public:
      template<typename Func, typename... Args>
      explicit for_constexpr(Func && /*unused*/, Args &&.../*unused*/)
      {}
  };
}

#endif // FOR_CONSTEXPR_HPP
