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

#include <string>

#include "rule.h"

namespace FCP {
	Rule::Rule(const std::string & tag_in,
		   const std::string & tag_out,
		   const std::string & command) :
		tag_in_(tag_in),
		tag_out_(tag_out),
		command_(command)
	{
	}

	const std::string & Rule::input(void)
	{
		return tag_in_;
	}

	const std::string & Rule::output(void)
	{
		return tag_out_;
	}

	Rule::~Rule(void)
	{
	}
};

#include "config.h"
