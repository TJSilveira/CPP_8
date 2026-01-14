/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilveir <tsilveir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:29:14 by tsilveir          #+#    #+#             */
/*   Updated: 2026/01/14 18:35:51 by tsilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include "../includes/easyfind.hpp"


int main()
{
	std::cout << "[VECTOR Section]\n";
	std::vector<int> vec_num;

	for (size_t i = 0; i < 5; i++)
	{
		vec_num.push_back(i * 3);
	}
	
	std::cout << "It should print 6: " << *easyfind(vec_num, 6) << std::endl;
	std::cout << "It should print 12: " << *easyfind(vec_num, 12) << std::endl;

	try
	{
		std::vector<int>::iterator vec2 = easyfind(vec_num, 2);
		std::cout << "vec2 " << *vec2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n\n";
	
	std::cout << "[LIST Section]\n";
	
	std::list<int> list_num;

	for (size_t i = 0; i < 5; i++)
	{
		list_num.push_back(i * 4);
	}
	
	std::cout << "It should print 8: " << *easyfind(list_num, 8) << std::endl;
	std::cout << "It should print 16: " << *easyfind(list_num, 16) << std::endl;

	try
	{
		std::list<int>::iterator list2 = easyfind(list_num, 2);
		std::cout << "it2 " << *list2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n\n";
}