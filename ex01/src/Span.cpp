#include "../includes/Span.hpp"

Span::Span(void) : _capacity(0), _size(0), is_sorted(false)  {
	// std::cout << "[Span] Default constructor called. "
            // << "Capacity assigned: " << this->_capacity << ";\n";
  return;
}

Span::Span(unsigned int N) : _capacity(N), _size(0), is_sorted(false) {
  // std::cout << "[Span] Default constructor with specified Capacity called. "
            // << "Capacity assigned: " << this->_capacity << ";\n";
  return;
}


Span::Span(const Span &other) {
  *this = other;
  // std::cout << "[Span] Copy constructor called. "
            // << "Capacity assigned: " << this->_capacity << ";\n";
  return;
}

Span &Span::operator=(const Span &other) {
	if (this == &other)
		return (*this);

  this->_capacity = other._capacity;
  this->_capacity = other._size;
	this->num_container = other.num_container;
	this->is_sorted = other.is_sorted;
	  // std::cout << "[Span] Copy assignment operator called. "
            // << "Capacity assigned: " << this->_capacity << ";\n";
  return *this;
}

Span::~Span() { 
	// std::cout << "[Span] Destructor called" << std::endl;
}

unsigned int	Span::getSize()
{
	return (this->_size);
}


void	Span::addNumber(int num_to_append)
{
	if (this->_size >= this->_capacity)
		throw Span::SpanFull();
	this->num_container.push_back(num_to_append);
	this->_size++;
	this->is_sorted = false;
}

unsigned int Span::shortestSpan()
{
	// time_t time_start = time(NULL);

	if (this->_capacity <= 1)
		throw Span::SpanNotFound();

	if (this->is_sorted == false)
	{
		std::sort(this->num_container.begin(), this->num_container.end());
		this->is_sorted = true;
	}
	
	int	shortest_span = this->num_container[1] - this->num_container[0];
	for (size_t i = 0; i < this->_size - 1; i++)
	{
		if (this->num_container[i+1] - this->num_container[i] < shortest_span)
			shortest_span = this->num_container[i + 1] - this->num_container[i];
	}
	// std::cout << "(time spent in secs: " << time(NULL) - time_start<< ") ";
	return(shortest_span);
}

unsigned int Span::longestSpan()
{
	// time_t time_start = time(NULL);
	if (this->_capacity <= 1)
		throw Span::SpanNotFound();

	if(this->is_sorted)
		return(this->num_container[this->_size - 1] - this->num_container[0]);

	int min = this->num_container[0];
	int max = this->num_container[0];

	for (size_t i = 0; i < this->_size; i++)
	{
		if (this->num_container[i] < min)
			min = this->num_container[i];		
		if (this->num_container[i] > max)
			max = this->num_container[i];
	}
	// std::cout << "(time spent in secs: " << time(NULL) - time_start<< ") ";
	return ((max - min));
}

const char *Span::SpanFull::what(void) const throw() {
  return ("Span is full. No More elements can be added.");
}

const char *Span::SpanNotFound::what(void) const throw() {
  return ("Span was not found");
}
