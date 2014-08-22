#include <iostream>
#include <stdexcept>
#include <cmath>

#include "resultsmodel.h"

ResultsModel::ResultsModel()
{
}

QVariant ResultsModel::data(const QModelIndex& index, int role) const
{
    int col = index.column();
    const char* a;
    if (role == Qt::DisplayRole)
    {
        switch (col)
        {
        case 0:
            return QVariant(m_solves[index.row()].toString().c_str());
            break;
        case 1:
            return QVariant(m_ao5s[index.row()].toString().c_str());
            break;
        case 2:
            return QVariant(m_ao12s[index.row()].toString().c_str());
            break;
        default:
            break;
        }
    }
    return QVariant();
}

void ResultsModel::addSolution(const Solution& s)
{
    beginInsertRows(QModelIndex(), m_solves.size(), m_solves.size());
    m_solves.push_back(s);
    try
    {
        if (m_solves.size() >= 5)
        {
            m_ao5s.push_back(getWCAAvg(m_solves.size() - 5, 5));
        }
        else
        {
            m_ao5s.push_back(Average(0, NA));
        }

        if (m_solves.size() >= 12)
        {
            m_ao12s.push_back(getWCAAvg(m_solves.size() - 12, 12));
        }
        else
        {
            m_ao12s.push_back(Average(0, NA));
        }
    }
    catch (const char* p)
    {
        std::cerr << p << std::endl;
    }
    catch (...)
    {
        std::cerr << "UNHANDLED EXCEPTION in ResultsModel::addSolution!!!" << std::endl;
    }
    endInsertRows();
}

long int ResultsModel::getWCAAvg(size_t start, size_t num)
{
    if (num < 3)
    {
        throw "ResultsModel::getWCAAvg(): param num must be at least 3!";
    }
    if (num > m_solves.size())
    {
        throw std::out_of_range("ResultsModel::getWCAAvg(): param num must not be more"
                                "than the number of solves!");
    }
    size_t best = start;
    size_t worst = start;
    long int sum = 0;
    for (size_t i = start; i < start + num; ++i)
    {
        long int t = getSolution(i).getTime();
        sum += t;
        if (t < getSolution(best).getTime())
        {
            best = i;
        }
        if (t > getSolution(worst).getTime())
        {
            worst = i;
        }
    }
    sum -= (getSolution(best).getTime() + getSolution(worst).getTime());
    return (long int)((sum / (num - 2)) + 0.5);
}

long int ResultsModel::getMean(size_t start, size_t num)
{
    if (num < 1)
    {
        throw "ResultsModel::getMean(): param num must be at least 1!";
    }
    if (num > m_solves.size())
    {
        throw std::out_of_range("ResultsModel::getMean(): param num must not be more"
                                "than the number of solves!");
    }
    long int sum = 0;
    for (size_t i = start; i < start + num; ++i)
    {
        sum += m_solves.at(i).getTime();
    }
    return sum / num;
}
