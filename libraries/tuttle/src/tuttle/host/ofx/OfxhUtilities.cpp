/*
 * Software License :
 *
 * Copyright (c) 2007-2009, The Open Effects Association Ltd. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 * Neither the name The Open Effects Association Ltd, nor the names of its
 * contributors may be used to endorse or promote products derived from this
 * software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "ofxCore.h"
#include "OfxhUtilities.hpp"

namespace tuttle {
namespace host {
namespace ofx {

/// get me deepest bit depth
std::string FindDeepestBitDepth( const std::string& s1, const std::string& s2 )
{
	if( s1 == kOfxBitDepthNone )
	{
		return s2;
	}
	else if( s1 == kOfxBitDepthByte )
	{
		if( s2 == kOfxBitDepthShort || s2 == kOfxBitDepthFloat )
			return s2;
		return s1;
	}
	else if( s1 == kOfxBitDepthShort )
	{
		if( s2 == kOfxBitDepthFloat )
			return s2;
		return s1;
	}
	else if( s1 == kOfxBitDepthFloat )
	{
		return s1;
	}
	else
	{
		return s2; // oooh this might be bad dad.
	}
}

const std::string mapStatusToString( const OfxStatus& stat )
{
	switch( stat )
	{
		case kOfxStatOK: return "kOfxStatOK";
		case kOfxStatFailed: return "kOfxStatFailed";
		case kOfxStatErrFatal: return "kOfxStatErrFatal";
		case kOfxStatErrUnknown: return "kOfxStatErrUnknown";
		case kOfxStatErrMissingHostFeature: return "kOfxStatErrMissingHostFeature";
		case kOfxStatErrUnsupported: return "kOfxStatErrUnsupported";
		case kOfxStatErrExists: return "kOfxStatErrExists";
		case kOfxStatErrFormat: return "kOfxStatErrFormat";
		case kOfxStatErrMemory: return "kOfxStatErrMemory";
		case kOfxStatErrBadHandle: return "kOfxStatErrBadHandle";
		case kOfxStatErrBadIndex: return "kOfxStatErrBadIndex";
		case kOfxStatErrValue: return "kOfxStatErrValue";
		case kOfxStatReplyYes: return "kOfxStatReplyYes";
		case kOfxStatReplyNo: return "kOfxStatReplyNo";
		case kOfxStatReplyDefault: return "kOfxStatReplyDefault";
		case kOfxStatErrImageFormat: return "kOfxStatErrImageFormat";
	}
	return "UNKNOWN_STATUS_CODE";
}

}
}
}