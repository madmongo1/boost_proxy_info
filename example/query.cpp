//
// Copyright (c) 2021 Richard Hodges (hodges.r@gmail.com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Official repository: https://github.com/madmongo1/boost_proxy_info
//

#include <boost/proxy_info.hpp>
#include <iostream>

int main()
{
    std::string host = "localhost";

    auto proxies = boost::proxy_info::query_hostname("localhost");
    std::cout << "proxies for " << host << ": " << proxies << '\n';
}