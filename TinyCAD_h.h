

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Wed Jun 03 16:26:36 2015
 */
/* Compiler settings for .\TinyCAD.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __TinyCAD_h_h__
#define __TinyCAD_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ITinyCAD_FWD_DEFINED__
#define __ITinyCAD_FWD_DEFINED__
typedef interface ITinyCAD ITinyCAD;
#endif 	/* __ITinyCAD_FWD_DEFINED__ */


#ifndef __CTinyCADDoc_FWD_DEFINED__
#define __CTinyCADDoc_FWD_DEFINED__

#ifdef __cplusplus
typedef class CTinyCADDoc CTinyCADDoc;
#else
typedef struct CTinyCADDoc CTinyCADDoc;
#endif /* __cplusplus */

#endif 	/* __CTinyCADDoc_FWD_DEFINED__ */


#ifndef __ITinyCADZoomView_FWD_DEFINED__
#define __ITinyCADZoomView_FWD_DEFINED__
typedef interface ITinyCADZoomView ITinyCADZoomView;
#endif 	/* __ITinyCADZoomView_FWD_DEFINED__ */


#ifndef __TinyCADZoomView_FWD_DEFINED__
#define __TinyCADZoomView_FWD_DEFINED__

#ifdef __cplusplus
typedef class TinyCADZoomView TinyCADZoomView;
#else
typedef struct TinyCADZoomView TinyCADZoomView;
#endif /* __cplusplus */

#endif 	/* __TinyCADZoomView_FWD_DEFINED__ */


#ifndef __ITinyCADDrawEngine_FWD_DEFINED__
#define __ITinyCADDrawEngine_FWD_DEFINED__
typedef interface ITinyCADDrawEngine ITinyCADDrawEngine;
#endif 	/* __ITinyCADDrawEngine_FWD_DEFINED__ */


#ifndef __TinyCADDrawEngine_FWD_DEFINED__
#define __TinyCADDrawEngine_FWD_DEFINED__

#ifdef __cplusplus
typedef class TinyCADDrawEngine TinyCADDrawEngine;
#else
typedef struct TinyCADDrawEngine TinyCADDrawEngine;
#endif /* __cplusplus */

#endif 	/* __TinyCADDrawEngine_FWD_DEFINED__ */


#ifndef __ITinyCADCmdInput_FWD_DEFINED__
#define __ITinyCADCmdInput_FWD_DEFINED__
typedef interface ITinyCADCmdInput ITinyCADCmdInput;
#endif 	/* __ITinyCADCmdInput_FWD_DEFINED__ */


#ifndef __TinyCADCmdInput_FWD_DEFINED__
#define __TinyCADCmdInput_FWD_DEFINED__

#ifdef __cplusplus
typedef class TinyCADCmdInput TinyCADCmdInput;
#else
typedef struct TinyCADCmdInput TinyCADCmdInput;
#endif /* __cplusplus */

#endif 	/* __TinyCADCmdInput_FWD_DEFINED__ */


#ifndef __ITinyCADErrorOutput_FWD_DEFINED__
#define __ITinyCADErrorOutput_FWD_DEFINED__
typedef interface ITinyCADErrorOutput ITinyCADErrorOutput;
#endif 	/* __ITinyCADErrorOutput_FWD_DEFINED__ */


#ifndef __TinyCADErrorOutput_FWD_DEFINED__
#define __TinyCADErrorOutput_FWD_DEFINED__

#ifdef __cplusplus
typedef class TinyCADErrorOutput TinyCADErrorOutput;
#else
typedef struct TinyCADErrorOutput TinyCADErrorOutput;
#endif /* __cplusplus */

#endif 	/* __TinyCADErrorOutput_FWD_DEFINED__ */


#ifndef __ITinyCADAnimationFrame_FWD_DEFINED__
#define __ITinyCADAnimationFrame_FWD_DEFINED__
typedef interface ITinyCADAnimationFrame ITinyCADAnimationFrame;
#endif 	/* __ITinyCADAnimationFrame_FWD_DEFINED__ */


#ifndef __TinyCADAnimationFrame_FWD_DEFINED__
#define __TinyCADAnimationFrame_FWD_DEFINED__

#ifdef __cplusplus
typedef class TinyCADAnimationFrame TinyCADAnimationFrame;
#else
typedef struct TinyCADAnimationFrame TinyCADAnimationFrame;
#endif /* __cplusplus */

#endif 	/* __TinyCADAnimationFrame_FWD_DEFINED__ */


#ifndef __ITinyCADElementsDoc_FWD_DEFINED__
#define __ITinyCADElementsDoc_FWD_DEFINED__
typedef interface ITinyCADElementsDoc ITinyCADElementsDoc;
#endif 	/* __ITinyCADElementsDoc_FWD_DEFINED__ */


#ifndef __TinyCADElementsDoc_FWD_DEFINED__
#define __TinyCADElementsDoc_FWD_DEFINED__

#ifdef __cplusplus
typedef class TinyCADElementsDoc TinyCADElementsDoc;
#else
typedef struct TinyCADElementsDoc TinyCADElementsDoc;
#endif /* __cplusplus */

#endif 	/* __TinyCADElementsDoc_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __TinyCAD_LIBRARY_DEFINED__
#define __TinyCAD_LIBRARY_DEFINED__

/* library TinyCAD */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_TinyCAD;

#ifndef __ITinyCAD_DISPINTERFACE_DEFINED__
#define __ITinyCAD_DISPINTERFACE_DEFINED__

/* dispinterface ITinyCAD */
/* [uuid] */ 


EXTERN_C const IID DIID_ITinyCAD;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("FF8C90A9-C1B5-4F32-9A78-D4B5DBC6AF7D")
    ITinyCAD : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct ITinyCADVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITinyCAD * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITinyCAD * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITinyCAD * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITinyCAD * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITinyCAD * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITinyCAD * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITinyCAD * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } ITinyCADVtbl;

    interface ITinyCAD
    {
        CONST_VTBL struct ITinyCADVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITinyCAD_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITinyCAD_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITinyCAD_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITinyCAD_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITinyCAD_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITinyCAD_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITinyCAD_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __ITinyCAD_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_CTinyCADDoc;

#ifdef __cplusplus

class DECLSPEC_UUID("2983F10C-E6AB-4117-924C-28B52D4EDB80")
CTinyCADDoc;
#endif

#ifndef __ITinyCADZoomView_DISPINTERFACE_DEFINED__
#define __ITinyCADZoomView_DISPINTERFACE_DEFINED__

/* dispinterface ITinyCADZoomView */
/* [uuid] */ 


EXTERN_C const IID DIID_ITinyCADZoomView;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("A7758C35-992B-4A45-A61B-DBFFDBD3836B")
    ITinyCADZoomView : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct ITinyCADZoomViewVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITinyCADZoomView * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITinyCADZoomView * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITinyCADZoomView * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITinyCADZoomView * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITinyCADZoomView * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITinyCADZoomView * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITinyCADZoomView * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } ITinyCADZoomViewVtbl;

    interface ITinyCADZoomView
    {
        CONST_VTBL struct ITinyCADZoomViewVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITinyCADZoomView_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITinyCADZoomView_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITinyCADZoomView_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITinyCADZoomView_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITinyCADZoomView_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITinyCADZoomView_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITinyCADZoomView_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __ITinyCADZoomView_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_TinyCADZoomView;

#ifdef __cplusplus

class DECLSPEC_UUID("9514A8F8-6AC2-465F-886E-C710475D50AA")
TinyCADZoomView;
#endif

#ifndef __ITinyCADDrawEngine_DISPINTERFACE_DEFINED__
#define __ITinyCADDrawEngine_DISPINTERFACE_DEFINED__

/* dispinterface ITinyCADDrawEngine */
/* [uuid] */ 


EXTERN_C const IID DIID_ITinyCADDrawEngine;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("2521FC3C-70C2-4066-A7D9-8BF5F78044FB")
    ITinyCADDrawEngine : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct ITinyCADDrawEngineVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITinyCADDrawEngine * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITinyCADDrawEngine * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITinyCADDrawEngine * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITinyCADDrawEngine * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITinyCADDrawEngine * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITinyCADDrawEngine * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITinyCADDrawEngine * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } ITinyCADDrawEngineVtbl;

    interface ITinyCADDrawEngine
    {
        CONST_VTBL struct ITinyCADDrawEngineVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITinyCADDrawEngine_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITinyCADDrawEngine_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITinyCADDrawEngine_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITinyCADDrawEngine_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITinyCADDrawEngine_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITinyCADDrawEngine_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITinyCADDrawEngine_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __ITinyCADDrawEngine_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_TinyCADDrawEngine;

#ifdef __cplusplus

class DECLSPEC_UUID("E15E7D25-0EDB-412F-B600-D9346E13A54C")
TinyCADDrawEngine;
#endif

#ifndef __ITinyCADCmdInput_DISPINTERFACE_DEFINED__
#define __ITinyCADCmdInput_DISPINTERFACE_DEFINED__

/* dispinterface ITinyCADCmdInput */
/* [uuid] */ 


EXTERN_C const IID DIID_ITinyCADCmdInput;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("B31CC072-91FE-49ED-9D28-450D7DEB624B")
    ITinyCADCmdInput : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct ITinyCADCmdInputVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITinyCADCmdInput * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITinyCADCmdInput * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITinyCADCmdInput * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITinyCADCmdInput * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITinyCADCmdInput * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITinyCADCmdInput * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITinyCADCmdInput * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } ITinyCADCmdInputVtbl;

    interface ITinyCADCmdInput
    {
        CONST_VTBL struct ITinyCADCmdInputVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITinyCADCmdInput_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITinyCADCmdInput_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITinyCADCmdInput_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITinyCADCmdInput_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITinyCADCmdInput_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITinyCADCmdInput_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITinyCADCmdInput_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __ITinyCADCmdInput_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_TinyCADCmdInput;

#ifdef __cplusplus

class DECLSPEC_UUID("F4F73875-0E24-489E-9765-0C1C21B22DC9")
TinyCADCmdInput;
#endif

#ifndef __ITinyCADErrorOutput_DISPINTERFACE_DEFINED__
#define __ITinyCADErrorOutput_DISPINTERFACE_DEFINED__

/* dispinterface ITinyCADErrorOutput */
/* [uuid] */ 


EXTERN_C const IID DIID_ITinyCADErrorOutput;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("A31C5A0D-1923-42DD-BD75-DF36C3120919")
    ITinyCADErrorOutput : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct ITinyCADErrorOutputVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITinyCADErrorOutput * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITinyCADErrorOutput * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITinyCADErrorOutput * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITinyCADErrorOutput * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITinyCADErrorOutput * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITinyCADErrorOutput * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITinyCADErrorOutput * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } ITinyCADErrorOutputVtbl;

    interface ITinyCADErrorOutput
    {
        CONST_VTBL struct ITinyCADErrorOutputVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITinyCADErrorOutput_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITinyCADErrorOutput_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITinyCADErrorOutput_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITinyCADErrorOutput_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITinyCADErrorOutput_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITinyCADErrorOutput_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITinyCADErrorOutput_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __ITinyCADErrorOutput_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_TinyCADErrorOutput;

#ifdef __cplusplus

class DECLSPEC_UUID("0FD02C3A-F659-4906-8367-9B32E2F0EC9C")
TinyCADErrorOutput;
#endif

#ifndef __ITinyCADAnimationFrame_DISPINTERFACE_DEFINED__
#define __ITinyCADAnimationFrame_DISPINTERFACE_DEFINED__

/* dispinterface ITinyCADAnimationFrame */
/* [uuid] */ 


EXTERN_C const IID DIID_ITinyCADAnimationFrame;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("B501F7A9-9765-4C33-B0C6-252A688D100C")
    ITinyCADAnimationFrame : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct ITinyCADAnimationFrameVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITinyCADAnimationFrame * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITinyCADAnimationFrame * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITinyCADAnimationFrame * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITinyCADAnimationFrame * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITinyCADAnimationFrame * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITinyCADAnimationFrame * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITinyCADAnimationFrame * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } ITinyCADAnimationFrameVtbl;

    interface ITinyCADAnimationFrame
    {
        CONST_VTBL struct ITinyCADAnimationFrameVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITinyCADAnimationFrame_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITinyCADAnimationFrame_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITinyCADAnimationFrame_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITinyCADAnimationFrame_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITinyCADAnimationFrame_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITinyCADAnimationFrame_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITinyCADAnimationFrame_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __ITinyCADAnimationFrame_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_TinyCADAnimationFrame;

#ifdef __cplusplus

class DECLSPEC_UUID("48A0E6BC-DF57-4709-B468-DE9648A69C92")
TinyCADAnimationFrame;
#endif

#ifndef __ITinyCADElementsDoc_DISPINTERFACE_DEFINED__
#define __ITinyCADElementsDoc_DISPINTERFACE_DEFINED__

/* dispinterface ITinyCADElementsDoc */
/* [uuid] */ 


EXTERN_C const IID DIID_ITinyCADElementsDoc;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("ED192CCD-6C6C-4FC7-8461-743BD3AC2046")
    ITinyCADElementsDoc : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct ITinyCADElementsDocVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITinyCADElementsDoc * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITinyCADElementsDoc * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITinyCADElementsDoc * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITinyCADElementsDoc * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITinyCADElementsDoc * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITinyCADElementsDoc * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITinyCADElementsDoc * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } ITinyCADElementsDocVtbl;

    interface ITinyCADElementsDoc
    {
        CONST_VTBL struct ITinyCADElementsDocVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITinyCADElementsDoc_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITinyCADElementsDoc_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITinyCADElementsDoc_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITinyCADElementsDoc_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITinyCADElementsDoc_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITinyCADElementsDoc_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITinyCADElementsDoc_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __ITinyCADElementsDoc_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_TinyCADElementsDoc;

#ifdef __cplusplus

class DECLSPEC_UUID("6CC8DEBA-42B1-43E6-A905-EBAD8914D03B")
TinyCADElementsDoc;
#endif
#endif /* __TinyCAD_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


