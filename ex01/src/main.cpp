/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilveir <tsilveir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:29:14 by tsilveir          #+#    #+#             */
/*   Updated: 2026/01/15 20:33:39 by tsilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"
#define BIG_CAPACITY 20000

int main() {
	srand(time(NULL));

  std::cout << "\n[Subject Section]\n";
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

  std::cout << "\n[Capacity 0 Section]\n";

	Span a;

	try
	{
		std::cout <<"This is the longest Span: " << a.longestSpan() <<"\n";
		std::cout <<"This is the shortest Span: " << a.shortestSpan() <<"\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout <<"This is the shortest Span: " << a.shortestSpan() <<"\n";
		std::cout <<"This is the longest Span: " << a.longestSpan() <<"\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		a.addNumber(3);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

  std::cout << "\n[Capacity 1 Section]\n";

	Span b(1);
	b.addNumber(100);

	try
	{
		std::cout <<"This is the longest Span: " << b.longestSpan() <<"\n";
		std::cout <<"This is the shortest Span: " << b.shortestSpan() <<"\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout <<"This is the shortest Span: " << b.shortestSpan() <<"\n";
		std::cout <<"This is the longest Span: " << b.longestSpan() <<"\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		b.addNumber(3);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
  std::cout << "\n[Capacity +2 Section]\n";

	Span c(BIG_CAPACITY);
	for (int i = 0; i < BIG_CAPACITY / 4 * 3; i++)
	{
		if (i % 2)
			c.addNumber(rand() * (-1));
		else
			c.addNumber(rand());
	}
	std::vector<int> addon;
	for (int i = 0; i < BIG_CAPACITY / 10 ; i++)
	{
		if (i % 2)
			addon.push_back(rand() * (-1));
		else
			addon.push_back(rand());
	}
	std::cout << "This is the current size: " << c.getSize() <<"\n";

	c.addNumber(addon.begin(), addon.end());
	
	std::cout << "This is the current size: " << c.getSize() <<"\n";
	
	try
	{
		std::cout <<"This is the longest Span: " << c.longestSpan() <<"\n";
		std::cout <<"This is the shortest Span: " << c.shortestSpan() <<"\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout <<"This is the shortest Span: " << c.shortestSpan() <<"\n";
		std::cout <<"This is the longest Span: " << c.longestSpan() <<"\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::vector<int> addon2(BIG_CAPACITY, 0);
		c.addNumber(addon2.begin(), addon2.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
