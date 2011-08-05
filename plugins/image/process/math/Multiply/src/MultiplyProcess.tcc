
#include "MultiplyPlugin.hpp"

namespace tuttle {
namespace plugin {
namespace multiply {

template<class View>
MultiplyProcess<View>::MultiplyProcess( MultiplyPlugin &effect )
: ImageGilFilterProcessor<View>( effect )
, _plugin( effect )
{
}

template<class View>
void MultiplyProcess<View>::setup( const OFX::RenderArguments& args )
{
	ImageGilFilterProcessor<View>::setup( args );
	_params = _plugin.getProcessParams( args.renderScale );
}

/**
 * @brief Function called by rendering thread each time a process must be done.
 * @param[in] procWindowRoW  Processing window
 */
template<class View>
void MultiplyProcess<View>::multiThreadProcessImages( const OfxRectI& procWindowRoW )
{
	using namespace boost::gil;
	MultiplyProcessParams<MultiplyPlugin::Scalar> params = _plugin.getProcessParams();
	OfxRectI procWindowOutput                  = this->translateRoWToOutputClipCoordinates( procWindowRoW );
	rgba32f_pixel_t wpix;

	for( int y = procWindowOutput.y1;
	     y < procWindowOutput.y2;
	     ++y )
	{
		typename View::x_iterator src_it = this->_srcView.x_at( procWindowOutput.x1, y );
		typename View::x_iterator dst_it = this->_dstView.x_at( procWindowOutput.x1, y );
		for( int x = procWindowOutput.x1;
		     x < procWindowOutput.x2;
		     ++x, ++src_it, ++dst_it )
		{
			color_convert( *src_it, wpix );
			
			wpix[ 0 ] = wpix[ 0 ] * params.iRMultiply ;
			wpix[ 1 ] = wpix[ 1 ] * params.iGMultiply ;
			wpix[ 2 ] = wpix[ 2 ] * params.iBMultiply ;
			wpix[ 3 ] = wpix[ 3 ] * params.iAMultiply ;
			
			color_convert( wpix, *dst_it );
		}
		if( this->progressForward() )
			return;
	}

}

}
}
}
