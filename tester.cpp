#include <iostream>
#include <string>
#include <regex>
#include <iomanip>

int main ()
{
    const std::string rna = "2.2" ;
    std::cout << "rna: " << std::quoted(rna) << '\n' ;

    // [ACGTU]*? - non-greedy match for string between start/stop
    const std::regex re( "[-+]?\\d*\\.?\\d*$" ) ;

    std::smatch match ;
    if( std::regex_match( rna, match, re ) )
    {
        std::cout << "start: at " << match.position(1) << " found " << std::quoted( match[1].str() ) << '\n'
                  << "  end: at " << match.position(3) << " found " << std::quoted( match[3].str() ) << '\n'
                  << "sequence between start and stop: " << std::quoted( match[2].str() ) << '\n' ;
    }

    else std::cout << "invalid rna or no start-stop sequence\n" ;
}

