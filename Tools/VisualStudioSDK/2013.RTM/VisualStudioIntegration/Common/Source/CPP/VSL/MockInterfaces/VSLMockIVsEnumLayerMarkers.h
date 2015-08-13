/***************************************************************************

Copyright (c) Microsoft Corporation. All rights reserved.
This code is licensed under the Visual Studio SDK license terms.
THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF
ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY
IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR
PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT.

This code is a part of the Visual Studio Library.

***************************************************************************/

#ifndef IVSENUMLAYERMARKERS_H_10C49CA1_2F46_11D3_A504_00C04F5E0BA5
#define IVSENUMLAYERMARKERS_H_10C49CA1_2F46_11D3_A504_00C04F5E0BA5

#if _MSC_VER > 1000
#pragma once
#endif

#include "textmgr.h"

#pragma warning(push)
#pragma warning(disable : 4510) // default constructor could not be generated
#pragma warning(disable : 4610) // can never be instantiated - user defined constructor required
#pragma warning(disable : 4512) // assignment operator could not be generated
#pragma warning(disable : 6011) // Dereferencing NULL pointer (a NULL derference is just another kind of failure for a unit test

namespace VSL
{

class IVsEnumLayerMarkersNotImpl :
	public IVsEnumLayerMarkers
{

VSL_DECLARE_NONINSTANTIABLE_BASE_CLASS(IVsEnumLayerMarkersNotImpl)

public:

	typedef IVsEnumLayerMarkers Interface;

	STDMETHOD(Reset)()VSL_STDMETHOD_NOTIMPL

	STDMETHOD(Next)(
		/*[out]*/ IVsTextLayerMarker** /*ppRetval*/)VSL_STDMETHOD_NOTIMPL

	STDMETHOD(GetCount)(
		/*[out]*/ long* /*pcMarkers*/)VSL_STDMETHOD_NOTIMPL
};

class IVsEnumLayerMarkersMockImpl :
	public IVsEnumLayerMarkers,
	public MockBase
{

VSL_DECLARE_NONINSTANTIABLE_BASE_CLASS(IVsEnumLayerMarkersMockImpl)

public:

VSL_DEFINE_MOCK_CLASS_TYPDEFS(IVsEnumLayerMarkersMockImpl)

	typedef IVsEnumLayerMarkers Interface;
	struct ResetValidValues
	{
		HRESULT retValue;
	};

	STDMETHOD(Reset)()
	{
		VSL_DEFINE_MOCK_METHOD_NOARGS(Reset)

		VSL_RETURN_VALIDVALUES();
	}
	struct NextValidValues
	{
		/*[out]*/ IVsTextLayerMarker** ppRetval;
		HRESULT retValue;
	};

	STDMETHOD(Next)(
		/*[out]*/ IVsTextLayerMarker** ppRetval)
	{
		VSL_DEFINE_MOCK_METHOD(Next)

		VSL_SET_VALIDVALUE_INTERFACE(ppRetval);

		VSL_RETURN_VALIDVALUES();
	}
	struct GetCountValidValues
	{
		/*[out]*/ long* pcMarkers;
		HRESULT retValue;
	};

	STDMETHOD(GetCount)(
		/*[out]*/ long* pcMarkers)
	{
		VSL_DEFINE_MOCK_METHOD(GetCount)

		VSL_SET_VALIDVALUE(pcMarkers);

		VSL_RETURN_VALIDVALUES();
	}
};


} // namespace VSL

#pragma warning(pop)

#endif // IVSENUMLAYERMARKERS_H_10C49CA1_2F46_11D3_A504_00C04F5E0BA5
