//
// Copyright (C) 2007, 2008 Francesco Salvestrini
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
//

#include "config.h"

#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "libs/misc/debug.h"
#include "libs/misc/string.h"
#include "libs/misc/exception.h"
#include "chain.h"
#include "file.h"
#include "filter.h"

namespace FCP {
	Chain::Chain(const std::string &          id,
		     const FCP::File &            input,
		     std::vector<FCP::Filter *> & filters,
		     const FCP::File &            output) :
		id_(id),
		input_(input),
		output_(output),
		filters_(filters)
	{
	}

	Chain::~Chain(void)
	{
	}

	const std::string & Chain::id(void)
	{
		return id_;
	}

	void Chain::run(const std::string & dir,
			bool                dry)
	{
		std::vector<FCP::Filter *>::iterator i;
		for (i  = filters_.begin();
		     i != filters_.end();
		     i++) {
			(*i)->run(id_, input_, output_, dir, dry);
		}
	}
};
