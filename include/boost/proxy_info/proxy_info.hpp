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

#include <iosfwd>
#include <string>
#include <vector>

namespace boost {
namespace proxy_info {

/// @brief  Contains the authentication credentials to use when connecting
///         through an authenticated proxy service
struct auth_info
{
    /// username to authenticate the proxy if the used field is true.
    std::string username;

    /// password to authenticate connection to the proxy if the used field is
    /// true.
    std::string password;

    /// If true, the username and password indicate the authentication
    /// credentials.
    bool used;
};

/// @brief Descibes the proxy information required to connect to a URL.
struct proxy_info
{
    /// The name of the proxy protocol
    std::string protocol;

    /// An optional set of credentials to be applied to each protocol.
    auth_info auth;

    /// The proxy hostname.
    std::string proxy_host;

    /// The proxy port. This may be the name of the service or the port number
    /// as a decimal alphanumeric string.
    std::string proxy_port;
};

/// @brief  An object representing an ordered list of proxy_info objects, or
///         an indication that no proxy is required
struct proxy_infos
{
    using const_iterator = std::vector<proxy_info>::const_iterator;

    proxy_infos(std::vector<proxy_info> infos = {})
            : infos_(std::move(infos))
    {
    }

    const_iterator
    begin() const
    {
        return infos_.begin();
    }

    const_iterator
    end() const
    {
        return infos_.end();
    }

    std::size_t
    size() const
    {
        return infos_.size();
    }

private:
    std::vector<proxy_info> infos_;
};

std::ostream &
operator<<(std::ostream &os, proxy_infos const &pis);

/// @brief Stream a printable
std::ostream &
operator<<(std::ostream &os, proxy_info const &pi);

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
    /// @brief      Query the internal caches and services for a given host name.
    ///
    /// @param      hostname is the fqdn or ip address of the host to be
    ///             contacted. If an IP address is specified it should be in
    ///             dotted decimal (IPV4) or hex (IPV6) format.
    ///
    /// @returns    An object describing how a client may reach the host. If an
    ///             empty object is returned, the URL should be contacted
    ///             directly.
    ///
    /// @throws     an exception derived from std::exception may be thrown if
    ///             there is an internal error or the URL is malformed.
    proxy_infos
    query_hostname(std::string const &hostname);
};

/// @brief  Return a reference to a singlton session object.
/// @note   The session object will be created on the first call to this function
///         in a thread-safe manner. The session will be automatically destroyed
///         some time after the program returns from the main() functrion.
/// @return a reference to a session.
session &
default_session();

proxy_infos
query_hostname(std::string const &hostname, session &s = default_session());

} // namespace proxy_info
} // namespace boost

#endif // BOOST_PROXY_INFO_INCLUDE_BOOST_PROXY_INFO_PROXY_INFO_HPP
