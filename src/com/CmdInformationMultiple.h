/************************************************************************************
   Copyright (C) 2020 MariaDB Corporation AB

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public
   License along with this library; if not see <http://www.gnu.org/licenses>
   or write to the Free Software Foundation, Inc.,
   51 Franklin St., Fifth Floor, Boston, MA 02110, USA
*************************************************************************************/


#ifndef _CMDINFORMATIONMULTIPLE_H_
#define _CMDINFORMATIONMULTIPLE_H_

#include "Consts.h"

#include "CmdInformation.h"

namespace sql
{
namespace mariadb
{

class CmdInformationMultiple  : public CmdInformation {

  std::vector<int64_t>insertIds;
  std::vector<int64_t>updateCounts;
  int32_t expectedSize;
  int32_t autoIncrement;
  int64_t insertIdNumber ; /*0*/
  int32_t moreResultsIdx;
  bool hasException;
  bool rewritten;

public:
  CmdInformationMultiple(int32_t expectedSize,int32_t autoIncrement);
  void addErrorStat();
  void reset();
  void addResultSetStat();
  void addSuccessStat(int64_t updateCount,int64_t insertId);
  sql::Ints* getServerUpdateCounts();
  sql::Ints* getUpdateCounts();
  sql::Longs* getLargeUpdateCounts();
  int32_t getUpdateCount();
  int64_t getLargeUpdateCount();
  ResultSet* getBatchGeneratedKeys(Protocol* protocol);
  ResultSet* getGeneratedKeys(Protocol* protocol, const SQLString& sql);
  int32_t getCurrentStatNumber();
  bool moreResults();
  bool isCurrentUpdateCount();
  void setRewrite(bool rewritten);
  };
}
}
#endif