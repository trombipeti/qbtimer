#ifndef RESULTSMODEL_H
#define RESULTSMODEL_H

#include <QAbstractTableModel>
#include <vector>

#include "solution.hpp"
#include "average.hpp"

class ResultsModel : public QAbstractTableModel
{
private:
    std::vector<Solution> m_solves;
    std::vector<Average> m_ao5s;
    std::vector<Average> m_ao12s;

public:
    explicit ResultsModel();

    /// Realizing the interface

    int rowCount(const QModelIndex& parent = QModelIndex()) const
    {
        return m_solves.size();
    }

    int columnCount(const QModelIndex& parent = QModelIndex()) const
    {
        return 4;
    }

    QVariant data(const QModelIndex& index, int role) const;

    /// Own methods

    void addSolution(const Solution& s);

    const Solution& getSolution(size_t index)
    {
        return m_solves.at(index);
    }

    /**
     * @brief getWCAAvg Gets the average of @num number of solves, starting with @start.
     * @param start The index of the first solve to count in.
     * @param num The number of solves to count in. Must be at least 3!
     * @return The average of the solves, as defined by WCA, which is:
     *         (sum_of_all_times - best_time - worst_time) / (number_of_times - 2).
     */
    long int getWCAAvg(size_t start, size_t num);

    /**
     * @brief getMean Gets the mean of @num number of solves, starting with @start.
     * @param start The index of the first solve to count in.
     * @param num The number of the solves to count in. Must be at least 1 :)
     * @return The mean of the solves. This actually means sum/num.
     */
    long int getMean(size_t start, size_t num);
};

#endif // RESULTSMODEL_H
