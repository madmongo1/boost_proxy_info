//
// Copyright (c) 2021 Richard Hodges (hodges.r@gmail.com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Official repository: https://github.com/madmongo1/boost_proxy_info
//

#include <boost/proxy_info/proxy_info.hpp>


namespace boost {
namespace proxy_info {

proxy_infos
session::query(std::string const &hostname,
               std::string const &service)
{
    std::vector<proxy_info> result;

    return proxy_infos(std::move(result));
}

session &
default_session()
{
    static session def;

    return def;
}

proxy_infos
query(std::string const &hostname,
      std::string const &service,
      session &s)
{
    return s.query(hostname, service);
}

}
}