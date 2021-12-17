//
// Copyright (c) 2021 Richard Hodges (hodges.r@gmail.com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Official repository: https://github.com/madmongo1/boost_proxy_info
//

#ifndef BOOST_PROXY_INFO_INCLUDE_BOOST_PROXY_INFO_PROXY_INFO_HPP
#define BOOST_PROXY_INFO_INCLUDE_BOOST_PROXY_INFO_PROXY_INFO_HPP

#include <boost/optional.hpp>

namespace boost {
namespace proxy_info {

/// @brief  Contains the authentication credentials to use when connecting
///         through an authenticated proxy service
struct auth_info
{
    std::string username, password;
};

/// @brief Descibes the proxy information required to connect to a URL.
struct proxy_info
{
    /// A collection of protocols that should be attempted, in order of priority
    std::vector <std::string> protocol;

    /// An optional set of credentials to be applied to each protocol.
    optional <auth_info> auth;

    /// The proxy hostname.
    std::string proxy_host;

    /// The proxy port. This may be the name of the service or the port number
    /// as a decimal alphanumeric string.
    std::string proxy_port;
};

/// @brief      A proxy_info session.
///
/// @details    The session object contains any necessary cached information and
///             manages threads for those services that need it.
///
/// @note       All methods of an object of this type are thread-safe.
/// @note       The session object must not be destroyed until all methods
///             called on it have returned.
/// @note       session objects are designed to be kept around and re-used.
///             Ideally the program will construct one and share it amongst all
///             components that need it.
struct session
{
    /// @brief      Query the internal caches and services for a given URL.
    ///
    /// @returns    a (possibly empty) vector of proxy_info objects that describe
    ///             how a client may reach the URL. If an empty vecotr is
    ///             returned, the URL should be contacted directly.
    ///
    /// @throws     an exception derived from std::exception may be thrown if
    ///             there is an internal error or the URL is malformed.
    std::vector <proxy_info>
    query_url(std::string const &url);
};

} // namespace proxy_info
} // namespace boost

#endif // BOOST_PROXY_INFO_INCLUDE_BOOST_PROXY_INFO_PROXY_INFO_HPP
