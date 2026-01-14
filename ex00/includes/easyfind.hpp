/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilveir <tsilveir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:29:01 by tsilveir          #+#    #+#             */
/*   Updated: 2026/01/14 18:20:30 by tsilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <stdexcept>
#include <string>

template<typename T> typename T::iterator easyfind(T& container, int search_num)
{
	typename T::iterator result = std::find(container.begin(), container.end(), search_num);
	if (result == container.end())
		throw std::runtime_error("No match found");
	return (result);
}