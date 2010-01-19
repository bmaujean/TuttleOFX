#ifndef DPXWRITER_PLUGIN_HPP
#define DPXWRITER_PLUGIN_HPP

#include <tuttle/common/utils/global.hpp>
#include <ofxsImageEffect.h>
#include <boost/gil/gil_all.hpp>
#include "../dpxEngine/dpxImage.hpp"

namespace tuttle {
namespace plugin {
namespace dpx {
namespace writer {

/**
 * @brief
 *
 */
class DPXWriterPlugin : public OFX::ImageEffect
{
public:
	DPXWriterPlugin( OfxImageEffectHandle handle );
	OFX::Clip* getSrcClip() const;
	OFX::Clip* getDstClip() const;

public:
	virtual void render( const OFX::RenderArguments& args );
	void         changedParam( const OFX::InstanceChangedArgs& args, const std::string& paramName );

protected:
	OFX::PushButtonParam* _renderButton;  ///< Render push button
	OFX::StringParam*  _filepath;         ///< Target file path
	// do not need to delete these, the ImageEffect is managing them for us
	OFX::Clip* _srcClip;       ///< Source image clip
	OFX::Clip* _dstClip;       ///< Ouput image clip
	bool _bRenderOnce;   ///< Avoid multiple useless writing

};

}
}
}
}

#endif