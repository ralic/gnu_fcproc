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

#ifndef FILTER_H
#define FILTER_H

#include "config.h"

#include <string>

namespace FCP {
	class File {
	public:
		File(const std::string & name);
		~File(void);

		const std::string & name(void)      const;
		const std::string & dirname(void)   const;
		const std::string & basename(void)  const;
		const std::string & extension(void) const;

	protected:
		File(void);

	private:
		std::string name_;
		std::string dirname_;
		std::string basename_;
		std::string extension_;
	};

	class Filter {
	public:
		Filter(const FCP::File &   input,
		       const FCP::File &   output,
		       const std::string & command);
		~Filter(void);

		bool         execute(void);

	protected:
		Filter(void);

	private:
		FCP::File    input_;
		FCP::File    output_;
		std::string  command_;
	};
};

#endif // FILTER_H