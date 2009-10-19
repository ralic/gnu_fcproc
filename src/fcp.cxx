// -*- c++ -*-

//
// Copyright (C) 2008, 2009 Francesco Salvestrini
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

#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <set>

#include <getopt.h>
#include <sys/types.h>
#include <unistd.h>

#include "libs/misc/debug.h"
#include "libs/misc/environment.h"
#include "libs/conf/configuration.h"
#include "libs/misc/exception.h"
#include "libs/fs/file.h"
#include "libs/fs/directory.h"
#include "rules.h"
#include "transformation.h"

#define PROGRAM_NAME "fcp"

void version()
{
        std::cout
                << PROGRAM_NAME << " (" << PACKAGE_NAME  << ") " << PACKAGE_VERSION <<
                std::endl
                <<
                std::endl
                << "Copyright (C) 2008, 2009 Francesco Salvestrini" <<
                std::endl
                <<
                std::endl
                << "This is free software.  You may redistribute copies of it under the terms of" <<
                std::endl
                << "the GNU General Public License <http://www.gnu.org/licenses/gpl.html>." <<
                std::endl
                << "There is NO WARRANTY, to the extent permitted by law." <<
                std::endl;
}

#define USE_CONFIGURATION_FILE 0

char          separator          = ':';
#if USE_CONFIGURATION_FILE
std::string   configuration_file = (Environment::get("HOME") +
                                    std::string("/") +
                                    std::string(".") +
                                    std::string(PACKAGE_TARNAME) +
                                    std::string("/") +
                                    std::string("configuration"));
#endif
#define       DFLT_RULES                        \
        (Environment::get("HOME") +             \
         std::string("/") +                     \
         std::string(".") +                     \
         std::string(PACKAGE_TARNAME) +         \
         std::string("/") +                     \
         std::string("rules"))
int           max_depth          = 16;

void help()
{
        std::cout
                << "Usage: " << PROGRAM_NAME << " [OPTION]... [TRANSFORMATION]..." <<
                std::endl
                <<
                std::endl
                << "Options: " <<
                std::endl
#if USE_CONFIGURATION_FILE
                << "  -c, --config=FILE       use alternate configuration file" <<
                std::endl
                << "                          (the default is `$HOME/." << PACKAGE_TARNAME << "/configuration')" <<
                std::endl
#endif
                << "  -r, --rules=FILE        use alternate rules file" <<
                std::endl
                << "                          (the default is `$HOME/." << PACKAGE_TARNAME << "/rules')" <<
                std::endl
                << "  -m, --max-depth=NUM     use NUM as max filter-chains depth" <<
                std::endl
                << "                          (the default is `" << max_depth << "')" <<
                std::endl
                << "  -t, --temp-dir=DIR      use DIR as temporary directory" <<
                std::endl
                << "                          (the default is `$HOME/." << PACKAGE_TARNAME << "/tmp')" <<
                std::endl
                << "  -s, --separator=CHAR    use CHAR as INPUT/OUTPUT separator" <<
                std::endl
                << "                          (the default is `" << separator << "')" <<
                std::endl
                << "  -q, --no-std-rules      do not load standard rules" <<
                std::endl
                << "  -b, --dump-rules        dump rules base, then exit" <<
                std::endl
                << "  -n, --dry-run           display commands without modifying any files" <<
                std::endl
                << "  -f, --force             consider all files out of date" <<
                std::endl
                << "  -d, --debug             enable debugging traces" <<
                std::endl
                << "  -v, --verbose           verbosely report processing" <<
                std::endl
                << "  -h, --help              print this help, then exit" <<
                std::endl
                << "  -V, --version           print version number, then exit" <<
                std::endl
                <<
                std::endl
                << "Specify TRANSFORMATION using the format:" <<
                std::endl
                <<
                std::endl
                << "  INPUTFILE[%TYPE]<SEPARATOR>OUTPUTFILE[%TYPE]" <<
                std::endl
                <<
                std::endl
                << "Default SEPARATOR is '" << separator << "'. INPUTFILE and OUTPUTFILE must be different." <<
                std::endl
                << "File TYPE is optional and it will be guessed if not provided." <<
                std::endl
                <<
                std::endl
                << "Report bugs to <" << PACKAGE_BUGREPORT << ">" <<
                std::endl;
}

void hint(const std::string & message)
{
        BUG_ON(message.size() == 0);

        std::cout
                << message <<                                                 std::endl
                << "Try `" << PROGRAM_NAME << " -h' for more information." << std::endl;
}

int main(int argc, char * argv[])
{
        TR_CONFIG_LVL(TR_LVL_DEFAULT);
        TR_CONFIG_PFX(PROGRAM_NAME);

        try {
                bool                     dry_run       = false;
                bool                     force         = false;
                bool                     dump_rules    = false;

                std::vector<std::string> rules_all;
                std::vector<std::string> rules_default;
                std::vector<std::string> rules_user;

                std::string              temp_dir_name;

                // Useless
                rules_all.clear();
                rules_default.clear();
                rules_user.clear();

                // Push default rules
                rules_default.push_back(DFLT_RULES);

                int c;
                // int digit_optind = 0;
                while (1) {
                        // int this_option_optind = optind ? optind : 1;
                        int option_index       = 0;

                        static struct option long_options[] = {
                                { "temp-dir",     1, 0, 't' },
                                { "config",       1, 0, 'c' },
                                { "rules",        1, 0, 'r' },
                                { "max-depth",    1, 0, 'm' },
                                { "separator",    1, 0, 's' },
                                { "no-std-rules", 0, 0, 'q' },
                                { "dump-rules",   0, 0, 'b' },
                                { "force",        0, 0, 'f' },
                                { "dry-run",      0, 0, 'n' },
                                { "debug",        0, 0, 'd' },
                                { "verbose",      0, 0, 'v' },
                                { "version",      0, 0, 'V' },
                                { "help",         0, 0, 'h' },
                                { 0,              0, 0, 0   }
                        };

#if USE_CONFIGURATION_FILE
                        c = getopt_long(argc, argv, "t:c:r:m:s:qbfndvVh",
                                        long_options, &option_index);
#else
                        c = getopt_long(argc, argv, "t:r:m:s:qbfndvVh",
                                        long_options, &option_index);
#endif
                        if (c == -1) {
                                break;
                        }

                        TR_DBG("Handling option character '%c'\n", c);

                        switch (c) {
#if USE_CONFIGURATION_FILE
                                case 'c':
                                        configuration_file = optarg;
                                        break;
#endif
                                case 'r':
                                        rules_user.push_back(optarg);
                                        break;
                                case 't':
                                        temp_dir_name = std::string(optarg);
                                        break;
                                case 's':
                                        if (strlen(optarg) > 1) {
                                                hint("Separator too long");
                                                return 1;
                                        }
                                        separator = optarg[0];
                                        break;
                                case 'q':
                                        rules_default.clear();
                                        break;
                                case 'm':
                                        max_depth = atoi(optarg);
                                        if (max_depth < 1) {
                                                hint("Wrong max-depth");
                                                return 1;
                                        }
                                        break;
                                case 'b':
                                        dump_rules = true;
                                        break;
                                case 'f':
                                        force = true;
                                        break;
                                case 'n':
                                        dry_run = true;
                                        break;
                                case 'd':
                                        TR_CONFIG_LVL(TR_LVL_DEBUG);
                                        break;
                                case 'v':
                                        TR_CONFIG_LVL(TR_LVL_VERBOSE);
                                        break;
                                case 'V':
                                        version();
                                        return 0;
                                case 'h':
                                        help();
                                        return 0;
                                case '?':
                                        hint("Unrecognized option");
                                        return 1;
                                default:
                                        BUG();
                                        return 1;
                        }
                }

                TR_DBG("Separator     '%c'\n", separator);
#if USE_CONFIGURATION_FILE
                TR_DBG("Configuration '%s'\n", configuration_file.c_str());
                BUG_ON(configuration_file.size() == 0);
#endif
                TR_DBG("Max depth     '%d'\n", max_depth);
                BUG_ON(max_depth <= 0);

                // Insert default rules
                rules_all.insert(rules_all.end(),
                                 rules_default.begin(),
                                 rules_default.end());
                // Insert user rules
                rules_all.insert(rules_all.end(),
                                 rules_user.begin(),
                                 rules_user.end());

                if (rules_all.size() == 0) {
                        // Hmmmm is this a real error ?
                        hint("No rules available");
                        return 1;
                }

                TR_DBG("You have %d rules\n", rules_all.size());
                BUG_ON(rules_all.size() == 0);

                // Read rules file
                FCP::Rules * rules;

                try {
                        rules = new FCP::Rules(rules_all);
                } catch (std::exception & e) {
                        TR_ERR("%s\n", e.what());
                        return 1;
                }
                BUG_ON(rules == 0);

                if (dump_rules) {
                        TR_VRB("Rules:\n");
                        std::cout << (*rules);
                        return 0;
                }

                // Check if at least a transformation is available
                if (optind >= argc) {
                        hint("Missing transformation(s)");
                        return 1;
                }
                BUG_ON((argc - optind) < 0);

                // Setup working and temporary directories
                bool remove_temp_dir = false;
                bool remove_work_dir = false;

                if (temp_dir_name.empty()) {
                        char template_dir[] = "/tmp/" PROGRAM_NAME "-XXXXXX";

                        if (!mkdtemp(template_dir)) {
                                TR_ERR("Cannot create temporary directory\n");
                                return 1;
                        }
                        // The directory is created by mkdtemp()
                        remove_temp_dir = true;

                        temp_dir_name = std::string(template_dir);
                }
                BUG_ON(temp_dir_name.empty());

                FS::Directory temp_dir(temp_dir_name);
                if (!temp_dir.exists()) {
                        // We created that directory
                        temp_dir.create();
                        remove_temp_dir = true;
                }

                TR_DBG("Temporary dir '%s' (%s)\n",
                       temp_dir.name().c_str(),
                       remove_temp_dir ? "to be removed" : "to keep");

                FS::Directory work_dir(temp_dir.name() +
                                       "/" +
                                       std::string(PROGRAM_NAME) +
                                       "-" +
                                       String::itos(getpid()));
                if (!work_dir.exists()) {
                        work_dir.create();
                        remove_work_dir = true;
                }

                TR_DBG("Working dir   '%s' (%s)\n",
                       work_dir.name().c_str(),
                       remove_work_dir ? "to be removed" : "to keep");

                std::vector<FCP::Transformation *>           transformations;
                std::vector<FCP::Transformation *>::iterator it;

                transformations.resize(argc - optind);

                TR_DBG("Transformations:\n");
                int i;
                for (i = optind; i < argc; i++) {
                        int j;

                        j = i - optind;
                        try {
                                FCP::Transformation * t;

                                t = new FCP::Transformation(argv[i],
                                                            separator,
                                                            *rules,
                                                            max_depth,
                                                            work_dir);
                                BUG_ON(t == 0);

                                // XXX FIXME: Use an exception
                                if (t->input().name() == t->output().name()) {
                                        throw Exception("Transformation "
                                                        "'" + t->tag() + "' "
                                                        "input and output "
                                                        "must be different");
                                }

                                transformations[j] = t;

                        } catch (std::exception & e) {
                                TR_ERR("%s\n", e.what());
                                return 1;
                        }
                }
                BUG_ON(transformations.size() == 0);

                // We don't need rules anymore ...
                delete rules;
                rules = 0; // Catch bugs as soon as possible :-)

#if USE_CONFIGURATION_FILE
                // Read configuration file
                try {
                        Configuration::File config;
                        std::ifstream       stream(configuration_file.c_str());

                        stream >> config;

                } catch (std::exception & e) {
                        TR_ERR("%s\n", e.what());
                        return 1;
                }
#endif

                TR_VRB("Performing %d transformation(s)\n",
                       transformations.size());

                try {
                        // Run all transformations
                        for (it  = transformations.begin();
                             it != transformations.end();
                             it++) {
                                TR_VRB("Running transformation '%s'\n",
                                       (*it)->tag().c_str());
                                (*it)->run(dry_run, force);
                        }
                } catch (std::exception & e) {
                        TR_ERR("%s\n", e.what());
                        if (remove_work_dir) {
                                work_dir.remove();
                        }
                        return 1;
                }

                TR_VRB("Operations complete\n");

                // Clean up everything
                try {
                        for (it  = transformations.begin();
                             it != transformations.end();
                             it++) {
                                delete (*it);
                        }

                        // Remove directories
                        if (remove_temp_dir) {
                                temp_dir.remove(true);
                        }

                        if (remove_work_dir) {
                                work_dir.remove(true);
                        }
                } catch (std::exception & e) {
                        TR_ERR("%s\n", e.what());
                        return 1;
                }

        } catch (std::exception & e) {
                TR_ERR("%s\n", e.what());
                return 1;
        } catch (...) {
                BUG();
                return 1; // Should be useless ...
        };

        return 0;
}
