#ifndef SOLUTION_H
#define SOLUTION_H

#include <iomanip>
#include <ctime>
#include <string>
#include <sstream>

enum SolveFlag
{
    NONE,
    PLUS2,
    DNF,
    NA
};

class Solution
{
private:
    time_t m_start;
    time_t m_end;

    std::string m_scramble;
    std::string m_comment;

public:
    Solution(time_t start, time_t end = 0, std::string scramble = "", std::string comment = "") :
        m_start(start), m_end(end), m_scramble(scramble), m_comment(comment) {}

    virtual ~Solution() {}

    //////////////////////
    //------------------//
    // Inline functions //
    //------------------//
    /////////////////////

    /**
     * @brief Gets the start of the solve.
     * @return The starting time of the solution in UNIX time.
     */
    time_t getStart() const
    {
        return m_start;
    }

    /**
     * @brief Sets the starting time of the solve.
     * @param start The starting time of the solution in UNIX time.
     */
    void setStart(time_t start)
    {
        m_start = start;
    }

    /**
     * @brief Gets the end of the solve.
     * @return The end time of the solution in UNIX time.
     */
    time_t getEnd() const
    {
        return m_end;
    }

    /**
     * @brief Sets the end time of the solve.
     * @param end The end time of the solution in UNIX time.
     */
    void setEnd(time_t end)
    {
        m_end = end;
    }

    /**
     * @brief Gets the scramble string of the solve.
     * @return The scramble string of the solve.
     */
    std::string getScramble() const
    {
        return m_scramble;
    }

    /**
     * @brief Sets the scramble string of this solve.
     * @param scramble The scramble string for this solve.
     */
    void setScramble(std::string scramble)
    {
        m_scramble = scramble;
    }

    /**
     * @brief Gets the comment for the solve (if any).
     * @return The comment for this solve.
     */
    std::string getComment() const
    {
        return m_comment;
    }

    /**
     * @brief Sets the comment string for the solve. This can contain anything.
     * @param comment The string to be used as a comment. It can be empty.
     */
    void setComment(std::string comment)
    {
        m_comment = comment;
    }

    /**
     * @brief Returns the time of this solve (end - start).
     * @return The time in ms for this solve.
     */
    long int getTime() const
    {
        if (m_end != 0)
        {
            return m_end - m_start;
        }
        else
        {
            // TODO
            throw "Unimplemented stuff in Solution::getTime()!!!";
        }
    }

    /**
     * @brief TimeToString Method to convert the time to some good-looking string.
     * @return A std::string representing the time in HH:MM:SS.MM format.
     *         The starting HH:MM: part is left out if not needed.
     */
    std::string toString() const
    {
        return TimeToString(getTime());
    }

    static std::string TimeToString(long int time)
    {
        long int hour, min, sec, ms;
        ms = time % 1000;
        hour = time / (1000 * 60 * 60);
        min = (time - hour * 1000 * 60 * 60) / (1000 * 60);
        sec = (time - hour * 1000 * 60 * 60 - min * 1000 * 60) / 1000;
        std::stringstream t_str;
        if (hour)
        {
            t_str << std::setw(2) << std::setfill('0') << hour << ":";
        }
        if (min || hour)
        {
            t_str << std::setw(2) << std::setfill('0') << min << ":";
        }
        t_str << std::setw(2) << std::setfill('0') << sec << "."
              << std::setw(2) << std::setfill('0') << ms / 10;
        return t_str.str().c_str();
    }

};

#endif // SOLUTION_H
