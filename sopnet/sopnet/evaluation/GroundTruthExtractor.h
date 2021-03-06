#ifndef SOPNET_GROUND_TRUTH_EXTRACTOR_H__
#define SOPNET_GROUND_TRUTH_EXTRACTOR_H__

#include <vector>

#include <boost/shared_ptr.hpp>

#include <pipeline/all.h>
#include <imageprocessing/ImageStack.h>
#include <sopnet/segments/Segments.h>

// forward declarations
class ImageExtractor;
template <typename Precision> class SliceExtractor;
class GroundTruthSegmentExtractor;

class GroundTruthExtractor : public pipeline::ProcessNode {

public:

	/**
	 * Create a ground truth extractor.
	 *
	 * @param firstSection
	 *              The first section to use.
	 * @param lastSection
	 *              The last section to use.
	 * @param addIntensityBoundaries
	 *              Seperate regions of different intensities such that they end 
	 *              up in different slices.
	 */
	GroundTruthExtractor(int firstSection = -1, int lastSection = -1, bool addIntensityBoundaries = true);

private:

	class SegmentsAssembler : public pipeline::SimpleProcessNode<> {

	public:

		SegmentsAssembler();

	private:

		void updateOutputs();

		pipeline::Inputs<Segments> _segments;

		pipeline::Output<Segments> _allSegments;
	};

	void onInputSet(const pipeline::InputSet<ImageStack>& signal);

	void createPipeline();

	// the ground truth images
	pipeline::Input<ImageStack> _groundTruthSections;

	// update signal slot to explicitly update inputs
	signals::Slot<pipeline::Update> _update;

	// ground truth sections to image converter
	boost::shared_ptr<ImageExtractor> _sectionExtractor;

	// slice extractors to get the slices per section
	std::vector<boost::shared_ptr<SliceExtractor<unsigned short> > > _sliceExtractors;

	// extract segments from the components found by the sliceExtractors
	std::vector<boost::shared_ptr<GroundTruthSegmentExtractor> > _segmentExtractors;

	// collects all segments
	boost::shared_ptr<SegmentsAssembler> _segmentsAssembler;

	int _firstSection;

	int _lastSection;

	bool _addIntensityBoundaries;
};

#endif // SOPNET_GROUND_TRUTH_EXTRACTOR_H__

