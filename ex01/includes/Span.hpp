/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilveir <tsilveir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:29:01 by tsilveir          #+#    #+#             */
/*   Updated: 2026/01/15 20:27:36 by tsilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <vector>
#include <iterator>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>


class Span {
private:
  unsigned int _capacity;
  unsigned int _size;
	bool is_sorted;
  std::vector<int> num_container;
public:
  Span();
  Span(const Span &other);
  Span(unsigned int N);
  ~Span();

  Span &operator=(const Span &other);

	// Getter
	unsigned int	getSize();

	// Methods
	void	addNumber(int num_to_append);

	template<typename Iterator> void addNumber(Iterator first, Iterator last)
	{
		unsigned int elements_to_add = std::distance(first, last);

		if (num_container.size() + elements_to_add > this->_capacity)
			throw Span::SpanFull();
		num_container.insert(num_container.end(), first, last);
		_size = num_container.size();
	}

  unsigned int shortestSpan();
  unsigned int longestSpan();

  class SpanFull : public std::exception {
  public:
    virtual const char *what() const throw();
  };
  class SpanNotFound : public std::exception {
  public:
    virtual const char *what() const throw();
  };
};
