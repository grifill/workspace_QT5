/**
 * ---------------------------------------------------------------------------
 * Copyright (c) 2025 Gregory Filatov
 * All rights reserved.
 *
 * \file   companyTableArea.h
 * \author Gregory Filatov
 * \date   30 May 2025
 * \version 1.0
 *
 * \brief  Contains company table area data
 *
 * Module: companyTableArea.h
 *
 * Purpose: MyClass - file
 *
 * Functionality:
 *     Environment
 * ---------------------------------------------------------------------------
 */
#ifndef COMPANYTABLEAREA_H
#define COMPANYTABLEAREA_H

#include <QtCore/QAbstractTableModel>
#include <QtCore/QHash>
#include <QtCore/QRect>

class CustomTable : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit CustomTable(QObject *parent = 0);
    virtual ~CustomTable();

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
    Qt::ItemFlags flags(const QModelIndex &index) const;

    void addMapping(QString color, QRect area);
    void clearMapping() { m_mapping.clear(); }

private:
    QList<QVector<qreal> * > m_data;
    QHash<QString, QRect> m_mapping;
    int m_columnCount;
    int m_rowCount;
};

#endif // COMPANYTABLEAREA_H
