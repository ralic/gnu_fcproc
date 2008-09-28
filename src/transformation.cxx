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

#include "transformation.h"
#include "libs/misc/debug.h"
#include "libs/file/utils.h"

Transformation::Transformation(const std::string & tag,
			       char                separator) :
	tag_(tag),
	separator_(separator)
{
	std::string::size_type p;
	p = tag_.find(separator);
	if ((p < 0) || (p > tag_.size())) {
		throw Transformation::Exception("Missing separator in "
						"transformation " + tag_);
	}

	std::string tmp;
	tmp = tag_.substr(0, p);
	if (tmp.size() == 0) {
		throw Transformation::Exception("Missing input filename in "
						"transformation " + tag_);
	}
	input_ = new Transformation::File(tmp);
	BUG_ON(input_ == 0);

	tmp = tag_.substr(p + 1);
	if (tmp.size() == 0) {
		throw Transformation::Exception("Missing output filename in "
						"transformation " + tag_);
	}
	output_ = new Transformation::File(tmp);
	BUG_ON(output_ == 0);

	if (input_->name() == output_->name()) {
		throw Transformation::Exception("Input and output file are "
						"the same in "
						"transformation " + tag_);
	}
}

Transformation::~Transformation(void)
{
	delete input_;
	delete output_;
}

const Transformation::File & Transformation::input(void)
{
	return *input_;
}

const Transformation::File & Transformation::output(void)
{
	return *output_;
}

const std::string & Transformation::tag(void)
{
	return tag_;
}

bool Transformation::execute(void)
{
#if 0
	std::string input_filename  = input_;
	std::string output_filename = output_;

	TR_DBG("Transforming '%s' -> '%s':\n",
	       input_filename.c_str(), output_filename.c_str());

	TR_DBG("  Input  = ['%s','%s','%s']\n",
	       File::dirname(input_filename).c_str(),
	       File::basename(input_filename).c_str(),
	       File::extension(input_filename).c_str());

	TR_DBG("  Output = ['%s','%s','%s']\n",
	       File::dirname(output_filename).c_str(),
	       File::basename(output_filename).c_str(),
	       File::extension(output_filename).c_str());

	std::string input_tag;
	std::string output_tag;

	input_tag  = File::extension(input_filename).c_str();
	if (input_tag == "") {
		TR_ERR("Cannot detect '%s' file type\n",
		       input_filename.c_str());
		return false;
	}

	output_tag = File::extension(output_filename).c_str();
	if (output_tag == "") {
		TR_ERR("Cannot detect '%s' file type\n",
		       output_filename.c_str());
		return false;
	}

	if (input_tag == output_tag) {
		//
		// XXX FIXME:
		//   Add code in order to support copy
		//   operations too
		//
		TR_ERR("Useless transformation '%s', "
		       "files have the same type\n",
		       (*iter)->tag().c_str());
		return false;
	}
#endif

	return true;
}

Transformation::File::File(const std::string & name) :
	name_(name)
{
	if (name_ == "") {
		throw Transformation::Exception("Missing file name");
	}

	dirname_   = ::File::dirname(name_);
	basename_  = ::File::basename(name_);
	extension_ = ::File::extension(name_);

	if (extension_ == "") {
		throw Transformation::Exception("Missing extension in "
						"filename " + name_);
	}
}

Transformation::File::~File(void)
{
}

const std::string & Transformation::File::type(void) const
{
	return extension_;
}

const std::string & Transformation::File::name(void) const
{
	return name_;
}