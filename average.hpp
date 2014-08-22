#ifndef AVERAGE_HPP
#define AVERAGE_HPP

#include "solution.hpp"

class Average
{
private:
    long int m_time;
    SolveFlag m_flag;
public:
    Average(long int time, const SolveFlag& flag = NONE) : m_time(time), m_flag(flag) {}

    void setTime(long int time)
    {
        m_time = time;
    }

    long int getTime() const
    {
        return m_time;
    }

    void setFlag(const SolveFlag& flag)
    {
        m_flag = flag;
    }

    const SolveFlag& getFlag() const
    {
        return m_flag;
    }

    std::string toString() const
    {
        switch (m_flag)
        {
        case NONE:
            return Solution::TimeToString(m_time);
            break;
        case PLUS2:
            throw "Average cannot have a +2 penalty!";
            break;
        case DNF:
            return "DNF";
            break;
        case NA:
            return "N/A";
            break;
        default:
            return "";
            break;
        }
    }
};

#endif // AVERAGE_HPP
