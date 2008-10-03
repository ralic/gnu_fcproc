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
#include <list>

#include "libs/misc/debug.h"
#include "dependency.h"

namespace FCP {
	Dependency::Dependency(void)
	{
	}

	Dependency::~Dependency(void)
	{
	}

	Dependency * Dependency::parent(void)
	{
		return parent_;
	}

	std::list<Dependency *> Dependency::children(void)
	{
		return children_;
	}

	void Dependency::child(Dependency * c)
	{
		BUG_ON(c == 0);
	}
};
