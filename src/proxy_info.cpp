//
// Copyright (c) 2021 Richard Hodges (hodges.r@gmail.com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Official repository: https://github.com/madmongo1/boost_proxy_info
//

#include <boost/proxy_info/proxy_info.hpp>
#include <ostream>

namespace boost {
namespace proxy_info {

std::ostream &
operator<<(std::ostream &os, proxy_info const &pi)
{
    os << pi.protocol << "://";

    return os;
}


std::ostream &
operator<<(std::ostream &os, proxy_infos const &pis)
{
    if (pis.size() == 0)
    {
        return os << "direct://";
    }
    else
    {
        const char* sep = "[";
        for (auto&& e : pis)
        {
            os << sep << e;
            sep = ", ";
        }

        os << ']';
    }

    return os;
}

}
}