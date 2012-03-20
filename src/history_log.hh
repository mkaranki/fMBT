/*
 * fMBT, free Model Based Testing tool
 * Copyright (c) 2011, Intel Corporation.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU Lesser General Public License,
 * version 2.1, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for
 * more details.
 *
 * You should have received a copy of the GNU Lesser General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */
#include "history.hh"
#include "alphabet.hh"
#include <libxml/xmlreader.h>

class History_log: public History {
public:
  History_log(Log& l, std::string params = "");

  virtual void set_coverage(Coverage*,Alphabet* alpha);

protected:
  int alphabet_done;
  char* act;
  char* tag;
  void processNode(xmlTextReaderPtr reader);
  Coverage* c;
  Alphabet* a;
  void send_action();
  bool send_action(std::string& a,std::vector<std::string>& props);
  std::string file;
  std::vector<std::string> anames;
  std::vector<std::string> tnames;
};