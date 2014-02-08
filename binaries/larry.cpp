
#include <iostream>
#include <string>
#include <fstream>
#include <boost/thread.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/make_shared.hpp>
#include <boost/progress.hpp>

#include <imageprocessing/ImageStack.h>

#include <sopnet/Sopnet.h>

#include <pipeline/all.h>
#include <pipeline/Value.h>
#include <util/exceptions.h>
#include <imageprocessing/gui/ImageView.h>
#include <imageprocessing/gui/ImageStackView.h>
#include <imageprocessing/io/ImageHttpReader.h>
#include <imageprocessing/io/ImageFileReader.h>
#include <imageprocessing/io/ImageBlockStackReader.h>
#include <imageprocessing/io/ImageStackDirectoryReader.h>
#include <util/ProgramOptions.h>
#include <ImageMagick/Magick++.h>
#include <sopnet/sopnet/block/Block.h>
#include <sopnet/sopnet/block/Blocks.h>
#include <sopnet/sopnet/block/Box.h>
#include <sopnet/sopnet/block/BlockManager.h>
#include <sopnet/sopnet/block/LocalBlockManager.h>
#include <sopnet/inference/SegmentationCostFunctionParameters.h>

#include <imageprocessing/io/ImageBlockFileReader.h>
#include <util/point3.hpp>
#include <catmaidsopnet/SliceGuarantorParameters.h>
#include <catmaidsopnet/SliceGuarantor.h>
#include <catmaidsopnet/SegmentGuarantor.h>
#include <catmaidsopnet/persistence/SliceStore.h>
#include <catmaidsopnet/persistence/LocalSliceStore.h>
#include <catmaidsopnet/persistence/LocalSegmentStore.h>
#include <catmaidsopnet/persistence/SliceReader.h>
#include <catmaidsopnet/persistence/SegmentReader.h>
#include <catmaidsopnet/ConsistencyConstraintExtractor.h>


#include <boost/unordered_set.hpp>

using util::point3;
using std::cout;
using std::endl;
using namespace gui;
using namespace logger;

void handleException(boost::exception& e) {

	LOG_ERROR(out) << "[window thread] caught exception: ";

	if (boost::get_error_info<error_message>(e))
		LOG_ERROR(out) << *boost::get_error_info<error_message>(e);

	if (boost::get_error_info<stack_trace>(e))
		LOG_ERROR(out) << *boost::get_error_info<stack_trace>(e);

	LOG_ERROR(out) << std::endl;

	LOG_ERROR(out) << "[window thread] details: " << std::endl
	               << boost::diagnostic_information(e)
	               << std::endl;

	exit(-1);
}

void testSlice

int main(int optionc, char** optionv)
{
	util::ProgramOptions::init(optionc, optionv);
	LogManager::init();
	
	try
	{
		SegmentSet segmentSet;
		boost::shared_ptr<SegmentationCostFunctionParameters> segmentationCostParameters = 
			boost::make_shared<SegmentationCostFunctionParameters>();
		boost::shared_ptr<PriorCostFunctionParameters> priorCostFunctionParameters = 
			boost::make_shared<PriorCostFunctionParameters>();
		boost::shared_ptr<pipeline::Wrap<bool> > yep =
			boost::make_shared<pipeline::Wrap<bool> >(true);
		pipeline::Value<SegmentTrees> blockNeurons, sopnetNeurons;
		boost::shared_ptr<Segments> sopnetSegments = boost::make_shared<Segments>();
		boost::shared_ptr<Segments> blockSolverSegments = boost::make_shared<Segments>();
		
		
		std::string membranePath = "./membranes";
		std::string rawPath = "./raw";
		
		segmentationCostParameters->weightPotts = 0;
		segmentationCostParameters->weight = 0;
		segmentationCostParameters->priorForeground = 0.2;
		
		priorCostFunctionParameters->priorContinuation = -100;
		priorCostFunctionParameters->priorBranch = -100;


		
		
	}
	catch (Exception& e)
	{
		handleException(e);
	}
}
