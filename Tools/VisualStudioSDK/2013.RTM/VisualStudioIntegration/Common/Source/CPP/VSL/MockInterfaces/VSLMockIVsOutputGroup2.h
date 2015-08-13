/***************************************************************************

Copyright (c) Microsoft Corporation. All rights reserved.
This code is licensed under the Visual Studio SDK license terms.
THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF
ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY
IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR
PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT.

This code is a part of the Visual Studio Library.

***************************************************************************/

#ifndef IVSOUTPUTGROUP2_H_10C49CA1_2F46_11D3_A504_00C04F5E0BA5
#define IVSOUTPUTGROUP2_H_10C49CA1_2F46_11D3_A504_00C04F5E0BA5

#if _MSC_VER > 1000
#pragma once
#endif

#include "vsshell80.h"

#pragma warning(push)
#pragma warning(disable : 4510) // default constructor could not be generated
#pragma warning(disable : 4610) // can never be instantiated - user defined constructor required
#pragma warning(disable : 4512) // assignment operator could not be generated
#pragma warning(disable : 6011) // Dereferencing NULL pointer (a NULL derference is just another kind of failure for a unit test

namespace VSL
{

class IVsOutputGroup2NotImpl :
	public IVsOutputGroup2
{

VSL_DECLARE_NONINSTANTIABLE_BASE_CLASS(IVsOutputGroup2NotImpl)

public:

	typedef IVsOutputGroup2 Interface;

	STDMETHOD(get_KeyOutputObject)(
		/*[out]*/ IVsOutput2** /*ppKeyOutput*/)VSL_STDMETHOD_NOTIMPL

	STDMETHOD(get_Property)(
		/*[in]*/ LPCOLESTR /*pszProperty*/,
		/*[out]*/ VARIANT* /*pvar*/)VSL_STDMETHOD_NOTIMPL

	STDMETHOD(get_CanonicalName)(
		/*[out]*/ BSTR* /*pbstrCanonicalName*/)VSL_STDMETHOD_NOTIMPL

	STDMETHOD(get_DisplayName)(
		/*[out]*/ BSTR* /*pbstrDisplayName*/)VSL_STDMETHOD_NOTIMPL

	STDMETHOD(get_KeyOutput)(
		/*[out]*/ BSTR* /*pbstrCanonicalName*/)VSL_STDMETHOD_NOTIMPL

	STDMETHOD(get_ProjectCfg)(
		/*[out]*/ IVsProjectCfg2** /*ppIVsProjectCfg2*/)VSL_STDMETHOD_NOTIMPL

	STDMETHOD(get_Outputs)(
		/*[in]*/ ULONG /*celt*/,
		/*[in,out,size_is(celt)]*/ IVsOutput2*[] /*rgpcfg*/,
		/*[out,optional]*/ ULONG* /*pcActual*/)VSL_STDMETHOD_NOTIMPL

	STDMETHOD(get_DeployDependencies)(
		/*[in]*/ ULONG /*celt*/,
		/*[in,out,size_is(celt)]*/ IVsDeployDependency*[] /*rgpdpd*/,
		/*[out,optional]*/ ULONG* /*pcActual*/)VSL_STDMETHOD_NOTIMPL

	STDMETHOD(get_Description)(
		/*[out]*/ BSTR* /*pbstrDescription*/)VSL_STDMETHOD_NOTIMPL
};

class IVsOutputGroup2MockImpl :
	public IVsOutputGroup2,
	public MockBase
{

VSL_DECLARE_NONINSTANTIABLE_BASE_CLASS(IVsOutputGroup2MockImpl)

public:

VSL_DEFINE_MOCK_CLASS_TYPDEFS(IVsOutputGroup2MockImpl)

	typedef IVsOutputGroup2 Interface;
	struct get_KeyOutputObjectValidValues
	{
		/*[out]*/ IVsOutput2** ppKeyOutput;
		HRESULT retValue;
	};

	STDMETHOD(get_KeyOutputObject)(
		/*[out]*/ IVsOutput2** ppKeyOutput)
	{
		VSL_DEFINE_MOCK_METHOD(get_KeyOutputObject)

		VSL_SET_VALIDVALUE_INTERFACE(ppKeyOutput);

		VSL_RETURN_VALIDVALUES();
	}
	struct get_PropertyValidValues
	{
		/*[in]*/ LPCOLESTR pszProperty;
		/*[out]*/ VARIANT* pvar;
		HRESULT retValue;
	};

	STDMETHOD(get_Property)(
		/*[in]*/ LPCOLESTR pszProperty,
		/*[out]*/ VARIANT* pvar)
	{
		VSL_DEFINE_MOCK_METHOD(get_Property)

		VSL_CHECK_VALIDVALUE_STRINGW(pszProperty);

		VSL_SET_VALIDVALUE_VARIANT(pvar);

		VSL_RETURN_VALIDVALUES();
	}
	struct get_CanonicalNameValidValues
	{
		/*[out]*/ BSTR* pbstrCanonicalName;
		HRESULT retValue;
	};

	STDMETHOD(get_CanonicalName)(
		/*[out]*/ BSTR* pbstrCanonicalName)
	{
		VSL_DEFINE_MOCK_METHOD(get_CanonicalName)

		VSL_SET_VALIDVALUE_BSTR(pbstrCanonicalName);

		VSL_RETURN_VALIDVALUES();
	}
	struct get_DisplayNameValidValues
	{
		/*[out]*/ BSTR* pbstrDisplayName;
		HRESULT retValue;
	};

	STDMETHOD(get_DisplayName)(
		/*[out]*/ BSTR* pbstrDisplayName)
	{
		VSL_DEFINE_MOCK_METHOD(get_DisplayName)

		VSL_SET_VALIDVALUE_BSTR(pbstrDisplayName);

		VSL_RETURN_VALIDVALUES();
	}
	struct get_KeyOutputValidValues
	{
		/*[out]*/ BSTR* pbstrCanonicalName;
		HRESULT retValue;
	};

	STDMETHOD(get_KeyOutput)(
		/*[out]*/ BSTR* pbstrCanonicalName)
	{
		VSL_DEFINE_MOCK_METHOD(get_KeyOutput)

		VSL_SET_VALIDVALUE_BSTR(pbstrCanonicalName);

		VSL_RETURN_VALIDVALUES();
	}
	struct get_ProjectCfgValidValues
	{
		/*[out]*/ IVsProjectCfg2** ppIVsProjectCfg2;
		HRESULT retValue;
	};

	STDMETHOD(get_ProjectCfg)(
		/*[out]*/ IVsProjectCfg2** ppIVsProjectCfg2)
	{
		VSL_DEFINE_MOCK_METHOD(get_ProjectCfg)

		VSL_SET_VALIDVALUE_INTERFACE(ppIVsProjectCfg2);

		VSL_RETURN_VALIDVALUES();
	}
	struct get_OutputsValidValues
	{
		/*[in]*/ ULONG celt;
		/*[in,out,size_is(celt)]*/ IVsOutput2** rgpcfg;
		/*[out,optional]*/ ULONG* pcActual;
		HRESULT retValue;
	};

	STDMETHOD(get_Outputs)(
		/*[in]*/ ULONG celt,
		/*[in,out,size_is(celt)]*/ IVsOutput2* rgpcfg[],
		/*[out,optional]*/ ULONG* pcActual)
	{
		VSL_DEFINE_MOCK_METHOD(get_Outputs)

		VSL_CHECK_VALIDVALUE(celt);

		VSL_SET_VALIDVALUE_INTERFACEARRAY(rgpcfg, celt, validValues.celt);

		VSL_SET_VALIDVALUE(pcActual);

		VSL_RETURN_VALIDVALUES();
	}
	struct get_DeployDependenciesValidValues
	{
		/*[in]*/ ULONG celt;
		/*[in,out,size_is(celt)]*/ IVsDeployDependency** rgpdpd;
		/*[out,optional]*/ ULONG* pcActual;
		HRESULT retValue;
	};

	STDMETHOD(get_DeployDependencies)(
		/*[in]*/ ULONG celt,
		/*[in,out,size_is(celt)]*/ IVsDeployDependency* rgpdpd[],
		/*[out,optional]*/ ULONG* pcActual)
	{
		VSL_DEFINE_MOCK_METHOD(get_DeployDependencies)

		VSL_CHECK_VALIDVALUE(celt);

		VSL_SET_VALIDVALUE_INTERFACEARRAY(rgpdpd, celt, validValues.celt);

		VSL_SET_VALIDVALUE(pcActual);

		VSL_RETURN_VALIDVALUES();
	}
	struct get_DescriptionValidValues
	{
		/*[out]*/ BSTR* pbstrDescription;
		HRESULT retValue;
	};

	STDMETHOD(get_Description)(
		/*[out]*/ BSTR* pbstrDescription)
	{
		VSL_DEFINE_MOCK_METHOD(get_Description)

		VSL_SET_VALIDVALUE_BSTR(pbstrDescription);

		VSL_RETURN_VALIDVALUES();
	}
};


} // namespace VSL

#pragma warning(pop)

#endif // IVSOUTPUTGROUP2_H_10C49CA1_2F46_11D3_A504_00C04F5E0BA5
