#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <boost/core/noncopyable.hpp>

typedef std::vector<double> VInt;
typedef std::vector<VInt> VVInt;

typedef std::list<double> LInt;
typedef std::vector<LInt> VLInt;
typedef LInt::iterator LIter;
typedef std::vector<LIter> VLIter;

class CRelabelToFront : boost::noncopyable
{
public:
	CRelabelToFront(unsigned int numberVertex, std::vector<std::vector<double>> vertex);
	void PrintResult();
	void Ltf();

private:
	unsigned long m_edgeCount, m_n, m_src, m_dest;
	unsigned long m_maxStream;

	VVInt m_c, m_f;
	VInt m_h, m_e;
	VLInt m_nei;
	VLIter m_current;

	void lift(unsigned long u);
	void push(unsigned long u, unsigned long v);
	bool discharge(unsigned long u);
};

