

// RooBarb
#include "XmlConfig.h"
#include "TaskEngine.h"
using namespace jdb;

// STL
#include <iostream>
#include <exception>


#include "PicoDstSkimmer/PicoDstSkimmer.h"
#include "mapping/Mapper_dEdx.h"

#define LOGURU_IMPLEMENTATION 1
#include "vendor/loguru.h"

int main( int argc, char* argv[] ) {
	loguru::add_file("everything.log", loguru::Truncate, loguru::Verbosity_MAX);


	TaskFactory::registerTaskRunner<PicoDstSkimmer>( "PicoDstSkimmer" );

	TaskEngine engine( argc, argv );

// Should get rid of the below once I have things figured.

	int i = 0;
	int j =1212;

	Mapper_dEdx mp( "/home/fs26/dedx_ana/quantile_dedx.root", "/home/fs26/dedx_ana/quantile_nsigmae.root" );

	float corr_dEdx = 0;
	float corr_nSigmaE = 0;
	mp.apply_map_dEdx_nsigmaE( 0.0, 0.5, 1, 0.5, 3.2, 2, corr_dEdx, corr_nSigmaE );

	LOG_F( INFO, "corr_dEdx = %f, corr_nSigmaE = %f", corr_dEdx, corr_nSigmaE );

// Stop getting rid of here.

	return 0;
}
