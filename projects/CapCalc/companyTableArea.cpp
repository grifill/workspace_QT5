/**
 * ---------------------------------------------------------------------------
 * Copyright (c) 2025 Gregory Filatov
 * All rights reserved.
 *
 * \file   companyTableArea.cpp
 * \author Gregory Filatov
 * \date   30 May 2025
 * \version 1.0
 *
 * \brief  Contains company table area data
 *
 * Module: companyTableArea.cpp
 *
 * Purpose: MyClass - file
 *
 * Functionality:
 *     Environment
 * ---------------------------------------------------------------------------
 */
#include "companyTableArea.h"
#include <QtCore/QVector>
#include <QtCore/QTime>
#include <QtCore/QRect>
#include <QtCore/QRandomGenerator>
#include <QtGui/QColor>


CompanyTableArea::CompanyTableArea(QObject *parent) :
    QAbstractTableModel(parent)
{
    m_columnCount = 5;
    m_rowCount = 6;

    // m_data
    for (int i = 0; i < m_rowCount; i++) {
        QVector<qreal>* dataVec = new QVector<qreal>(m_columnCount);
        for (int k = 0; k < dataVec->size(); k++) {
            if (k % 2 == 0)
                dataVec->replace(k, i * 50 + QRandomGenerator::global()->bounded(20));
            else
                dataVec->replace(k, QRandomGenerator::global()->bounded(100));
        }
        m_data.append(dataVec);
    }
}

CompanyTableArea::~CompanyTableArea()
{
    qDeleteAll(m_data);
}

int CompanyTableArea::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_data.count();
}

int CompanyTableArea::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_columnCount;
}

QVariant CompanyTableArea::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal)
        return QString("202%0").arg(section);
    else
        return QString("%1").arg(section + 1);
}

QVariant CompanyTableArea::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole) {
        return m_data[index.row()]->at(index.column());
    } else if (role == Qt::EditRole) {
        return m_data[index.row()]->at(index.column());
    } else if (role == Qt::BackgroundRole) {
        for (const QRect &rect : m_mapping) {
            if (rect.contains(index.column(), index.row()))
                return QColor(m_mapping.key(rect));
        }

        // cell not mapped return white color
        return QColor(Qt::white);
    }
    return QVariant();
}

bool CompanyTableArea::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == Qt::EditRole) {
        m_data[index.row()]->replace(index.column(), value.toDouble());
        emit dataChanged(index, index);
        return true;
    }
    return false;
}

Qt::ItemFlags CompanyTableArea::flags(const QModelIndex &index) const
{
    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

void CompanyTableArea::addMapping(QString color, QRect area)
{
    m_mapping.insertMulti(color, area);
}

