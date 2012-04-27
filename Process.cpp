#include "Process.hpp"

Process::Process(const std::vector<char*>& path, bool verbose){
	m_pid = fork(m_status);
	execv(path,NULL);
}

Process::~Process(){
	wait(m_status);
}

Process::Process( Process &p )
{
	m_pid = p.m_pid;
}

Process& Process::operator= (const Process& p)
{
	m_pid = p.m_pid;
}

Process::Process(Process&& other)
{
	m_pid = other->m_pid;
}

Process& Process::operator=(Process&& other)
{
	m_pid = other->m_pid;
}