

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.xx.xxxx */
/* at a redacted point in time
 */
/* Compiler settings for ../../edge_embedded_browser/client/win/current/webview2experimental.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.xx.xxxx 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */


#ifndef __webview2experimental_h__
#define __webview2experimental_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef DECLSPEC_XFGVIRT
#if defined(_CONTROL_FLOW_GUARD_XFG)
#define DECLSPEC_XFGVIRT(base, func) __declspec(xfg_virtual(base, func))
#else
#define DECLSPEC_XFGVIRT(base, func)
#endif
#endif

/* Forward Declarations */ 

#ifndef __ICoreWebView2Experimental5_FWD_DEFINED__
#define __ICoreWebView2Experimental5_FWD_DEFINED__
typedef interface ICoreWebView2Experimental5 ICoreWebView2Experimental5;

#endif 	/* __ICoreWebView2Experimental5_FWD_DEFINED__ */


#ifndef __ICoreWebView2Experimental16_FWD_DEFINED__
#define __ICoreWebView2Experimental16_FWD_DEFINED__
typedef interface ICoreWebView2Experimental16 ICoreWebView2Experimental16;

#endif 	/* __ICoreWebView2Experimental16_FWD_DEFINED__ */


#ifndef __ICoreWebView2Experimental19_FWD_DEFINED__
#define __ICoreWebView2Experimental19_FWD_DEFINED__
typedef interface ICoreWebView2Experimental19 ICoreWebView2Experimental19;

#endif 	/* __ICoreWebView2Experimental19_FWD_DEFINED__ */


#ifndef __ICoreWebView2Experimental20_FWD_DEFINED__
#define __ICoreWebView2Experimental20_FWD_DEFINED__
typedef interface ICoreWebView2Experimental20 ICoreWebView2Experimental20;

#endif 	/* __ICoreWebView2Experimental20_FWD_DEFINED__ */


#ifndef __ICoreWebView2Experimental21_FWD_DEFINED__
#define __ICoreWebView2Experimental21_FWD_DEFINED__
typedef interface ICoreWebView2Experimental21 ICoreWebView2Experimental21;

#endif 	/* __ICoreWebView2Experimental21_FWD_DEFINED__ */


#ifndef __ICoreWebView2ExperimentalCompositionController4_FWD_DEFINED__
#define __ICoreWebView2ExperimentalCompositionController4_FWD_DEFINED__
typedef interface ICoreWebView2ExperimentalCompositionController4 ICoreWebView2ExperimentalCompositionController4;

#endif 	/* __ICoreWebView2ExperimentalCompositionController4_FWD_DEFINED__ */


#ifndef __ICoreWebView2ExperimentalClearCustomDataPartitionCompletedHandler_FWD_DEFINED__
#define __ICoreWebView2ExperimentalClearCustomDataPartitionCompletedHandler_FWD_DEFINED__
typedef interface ICoreWebView2ExperimentalClearCustomDataPartitionCompletedHandler ICoreWebView2ExperimentalClearCustomDataPartitionCompletedHandler;

#endif 	/* __ICoreWebView2ExperimentalClearCustomDataPartitionCompletedHandler_FWD_DEFINED__ */


#ifndef __ICoreWebView2ExperimentalEnvironment3_FWD_DEFINED__
#define __ICoreWebView2ExperimentalEnvironment3_FWD_DEFINED__
typedef interface ICoreWebView2ExperimentalEnvironment3 ICoreWebView2ExperimentalEnvironment3;

#endif 	/* __ICoreWebView2ExperimentalEnvironment3_FWD_DEFINED__ */


#ifndef __ICoreWebView2ExperimentalExecuteScriptResult_FWD_DEFINED__
#define __ICoreWebView2ExperimentalExecuteScriptResult_FWD_DEFINED__
typedef interface ICoreWebView2ExperimentalExecuteScriptResult ICoreWebView2ExperimentalExecuteScriptResult;

#endif 	/* __ICoreWebView2ExperimentalExecuteScriptResult_FWD_DEFINED__ */


#ifndef __ICoreWebView2ExperimentalExecuteScriptWithResultCompletedHandler_FWD_DEFINED__
#define __ICoreWebView2ExperimentalExecuteScriptWithResultCompletedHandler_FWD_DEFINED__
typedef interface ICoreWebView2ExperimentalExecuteScriptWithResultCompletedHandler ICoreWebView2ExperimentalExecuteScriptWithResultCompletedHandler;

#endif 	/* __ICoreWebView2ExperimentalExecuteScriptWithResultCompletedHandler_FWD_DEFINED__ */


#ifndef __ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventArgs_FWD_DEFINED__
#define __ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventArgs_FWD_DEFINED__
typedef interface ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventArgs ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventArgs;

#endif 	/* __ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventArgs_FWD_DEFINED__ */


#ifndef __ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventHandler_FWD_DEFINED__
#define __ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventHandler_FWD_DEFINED__
typedef interface ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventHandler ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventHandler;

#endif 	/* __ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventHandler_FWD_DEFINED__ */


#ifndef __ICoreWebView2ExperimentalScriptException_FWD_DEFINED__
#define __ICoreWebView2ExperimentalScriptException_FWD_DEFINED__
typedef interface ICoreWebView2ExperimentalScriptException ICoreWebView2ExperimentalScriptException;

#endif 	/* __ICoreWebView2ExperimentalScriptException_FWD_DEFINED__ */


#ifndef __ICoreWebView2ExperimentalProfile7_FWD_DEFINED__
#define __ICoreWebView2ExperimentalProfile7_FWD_DEFINED__
typedef interface ICoreWebView2ExperimentalProfile7 ICoreWebView2ExperimentalProfile7;

#endif 	/* __ICoreWebView2ExperimentalProfile7_FWD_DEFINED__ */


#ifndef __ICoreWebView2ExperimentalProfile10_FWD_DEFINED__
#define __ICoreWebView2ExperimentalProfile10_FWD_DEFINED__
typedef interface ICoreWebView2ExperimentalProfile10 ICoreWebView2ExperimentalProfile10;

#endif 	/* __ICoreWebView2ExperimentalProfile10_FWD_DEFINED__ */


#ifndef __ICoreWebView2ExperimentalProfileDeletedEventHandler_FWD_DEFINED__
#define __ICoreWebView2ExperimentalProfileDeletedEventHandler_FWD_DEFINED__
typedef interface ICoreWebView2ExperimentalProfileDeletedEventHandler ICoreWebView2ExperimentalProfileDeletedEventHandler;

#endif 	/* __ICoreWebView2ExperimentalProfileDeletedEventHandler_FWD_DEFINED__ */


#ifndef __ICoreWebView2ExperimentalUpdateRuntimeCompletedHandler_FWD_DEFINED__
#define __ICoreWebView2ExperimentalUpdateRuntimeCompletedHandler_FWD_DEFINED__
typedef interface ICoreWebView2ExperimentalUpdateRuntimeCompletedHandler ICoreWebView2ExperimentalUpdateRuntimeCompletedHandler;

#endif 	/* __ICoreWebView2ExperimentalUpdateRuntimeCompletedHandler_FWD_DEFINED__ */


#ifndef __ICoreWebView2ExperimentalUpdateRuntimeResult_FWD_DEFINED__
#define __ICoreWebView2ExperimentalUpdateRuntimeResult_FWD_DEFINED__
typedef interface ICoreWebView2ExperimentalUpdateRuntimeResult ICoreWebView2ExperimentalUpdateRuntimeResult;

#endif 	/* __ICoreWebView2ExperimentalUpdateRuntimeResult_FWD_DEFINED__ */


#ifndef __ICoreWebView2ExperimentalWebResourceRequestedEventArgs_FWD_DEFINED__
#define __ICoreWebView2ExperimentalWebResourceRequestedEventArgs_FWD_DEFINED__
typedef interface ICoreWebView2ExperimentalWebResourceRequestedEventArgs ICoreWebView2ExperimentalWebResourceRequestedEventArgs;

#endif 	/* __ICoreWebView2ExperimentalWebResourceRequestedEventArgs_FWD_DEFINED__ */


#ifndef __ICoreWebView2ExperimentalNavigationStartingEventArgs2_FWD_DEFINED__
#define __ICoreWebView2ExperimentalNavigationStartingEventArgs2_FWD_DEFINED__
typedef interface ICoreWebView2ExperimentalNavigationStartingEventArgs2 ICoreWebView2ExperimentalNavigationStartingEventArgs2;

#endif 	/* __ICoreWebView2ExperimentalNavigationStartingEventArgs2_FWD_DEFINED__ */


#ifndef __ICoreWebView2ExperimentalRenderAdapterLUIDChangedEventHandler_FWD_DEFINED__
#define __ICoreWebView2ExperimentalRenderAdapterLUIDChangedEventHandler_FWD_DEFINED__
typedef interface ICoreWebView2ExperimentalRenderAdapterLUIDChangedEventHandler ICoreWebView2ExperimentalRenderAdapterLUIDChangedEventHandler;

#endif 	/* __ICoreWebView2ExperimentalRenderAdapterLUIDChangedEventHandler_FWD_DEFINED__ */


#ifndef __ICoreWebView2ExperimentalTextureStream_FWD_DEFINED__
#define __ICoreWebView2ExperimentalTextureStream_FWD_DEFINED__
typedef interface ICoreWebView2ExperimentalTextureStream ICoreWebView2ExperimentalTextureStream;

#endif 	/* __ICoreWebView2ExperimentalTextureStream_FWD_DEFINED__ */


#ifndef __ICoreWebView2ExperimentalTexture_FWD_DEFINED__
#define __ICoreWebView2ExperimentalTexture_FWD_DEFINED__
typedef interface ICoreWebView2ExperimentalTexture ICoreWebView2ExperimentalTexture;

#endif 	/* __ICoreWebView2ExperimentalTexture_FWD_DEFINED__ */


#ifndef __ICoreWebView2ExperimentalTextureStreamErrorReceivedEventArgs_FWD_DEFINED__
#define __ICoreWebView2ExperimentalTextureStreamErrorReceivedEventArgs_FWD_DEFINED__
typedef interface ICoreWebView2ExperimentalTextureStreamErrorReceivedEventArgs ICoreWebView2ExperimentalTextureStreamErrorReceivedEventArgs;

#endif 	/* __ICoreWebView2ExperimentalTextureStreamErrorReceivedEventArgs_FWD_DEFINED__ */


#ifndef __ICoreWebView2ExperimentalTextureStreamErrorReceivedEventHandler_FWD_DEFINED__
#define __ICoreWebView2ExperimentalTextureStreamErrorReceivedEventHandler_FWD_DEFINED__
typedef interface ICoreWebView2ExperimentalTextureStreamErrorReceivedEventHandler ICoreWebView2ExperimentalTextureStreamErrorReceivedEventHandler;

#endif 	/* __ICoreWebView2ExperimentalTextureStreamErrorReceivedEventHandler_FWD_DEFINED__ */


#ifndef __ICoreWebView2ExperimentalTextureStreamStartRequestedEventHandler_FWD_DEFINED__
#define __ICoreWebView2ExperimentalTextureStreamStartRequestedEventHandler_FWD_DEFINED__
typedef interface ICoreWebView2ExperimentalTextureStreamStartRequestedEventHandler ICoreWebView2ExperimentalTextureStreamStartRequestedEventHandler;

#endif 	/* __ICoreWebView2ExperimentalTextureStreamStartRequestedEventHandler_FWD_DEFINED__ */


#ifndef __ICoreWebView2ExperimentalTextureStreamStoppedEventHandler_FWD_DEFINED__
#define __ICoreWebView2ExperimentalTextureStreamStoppedEventHandler_FWD_DEFINED__
typedef interface ICoreWebView2ExperimentalTextureStreamStoppedEventHandler ICoreWebView2ExperimentalTextureStreamStoppedEventHandler;

#endif 	/* __ICoreWebView2ExperimentalTextureStreamStoppedEventHandler_FWD_DEFINED__ */


#ifndef __ICoreWebView2ExperimentalTextureStreamWebTextureReceivedEventArgs_FWD_DEFINED__
#define __ICoreWebView2ExperimentalTextureStreamWebTextureReceivedEventArgs_FWD_DEFINED__
typedef interface ICoreWebView2ExperimentalTextureStreamWebTextureReceivedEventArgs ICoreWebView2ExperimentalTextureStreamWebTextureReceivedEventArgs;

#endif 	/* __ICoreWebView2ExperimentalTextureStreamWebTextureReceivedEventArgs_FWD_DEFINED__ */


#ifndef __ICoreWebView2ExperimentalTextureStreamWebTextureReceivedEventHandler_FWD_DEFINED__
#define __ICoreWebView2ExperimentalTextureStreamWebTextureReceivedEventHandler_FWD_DEFINED__
typedef interface ICoreWebView2ExperimentalTextureStreamWebTextureReceivedEventHandler ICoreWebView2ExperimentalTextureStreamWebTextureReceivedEventHandler;

#endif 	/* __ICoreWebView2ExperimentalTextureStreamWebTextureReceivedEventHandler_FWD_DEFINED__ */


#ifndef __ICoreWebView2ExperimentalTextureStreamWebTextureStreamStoppedEventHandler_FWD_DEFINED__
#define __ICoreWebView2ExperimentalTextureStreamWebTextureStreamStoppedEventHandler_FWD_DEFINED__
typedef interface ICoreWebView2ExperimentalTextureStreamWebTextureStreamStoppedEventHandler ICoreWebView2ExperimentalTextureStreamWebTextureStreamStoppedEventHandler;

#endif 	/* __ICoreWebView2ExperimentalTextureStreamWebTextureStreamStoppedEventHandler_FWD_DEFINED__ */


#ifndef __ICoreWebView2ExperimentalWebTexture_FWD_DEFINED__
#define __ICoreWebView2ExperimentalWebTexture_FWD_DEFINED__
typedef interface ICoreWebView2ExperimentalWebTexture ICoreWebView2ExperimentalWebTexture;

#endif 	/* __ICoreWebView2ExperimentalWebTexture_FWD_DEFINED__ */


#ifndef __ICoreWebView2ExperimentalEnvironment12_FWD_DEFINED__
#define __ICoreWebView2ExperimentalEnvironment12_FWD_DEFINED__
typedef interface ICoreWebView2ExperimentalEnvironment12 ICoreWebView2ExperimentalEnvironment12;

#endif 	/* __ICoreWebView2ExperimentalEnvironment12_FWD_DEFINED__ */


/* header files for imported files */
#include "webview2.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __WebView2Experimental_LIBRARY_DEFINED__
#define __WebView2Experimental_LIBRARY_DEFINED__

/* library WebView2Experimental */
/* [version][uuid] */ 



































typedef /* [v1_enum] */ 
enum COREWEBVIEW2_WEB_RESOURCE_REQUEST_SOURCE_KINDS
    {
        COREWEBVIEW2_WEB_RESOURCE_REQUEST_SOURCE_KINDS_NONE	= 0,
        COREWEBVIEW2_WEB_RESOURCE_REQUEST_SOURCE_KINDS_DOCUMENT	= 1,
        COREWEBVIEW2_WEB_RESOURCE_REQUEST_SOURCE_KINDS_SHARED_WORKER	= 2,
        COREWEBVIEW2_WEB_RESOURCE_REQUEST_SOURCE_KINDS_SERVICE_WORKER	= 4,
        COREWEBVIEW2_WEB_RESOURCE_REQUEST_SOURCE_KINDS_ALL	= 0xffffffff
    } 	COREWEBVIEW2_WEB_RESOURCE_REQUEST_SOURCE_KINDS;

DEFINE_ENUM_FLAG_OPERATORS(COREWEBVIEW2_WEB_RESOURCE_REQUEST_SOURCE_KINDS)
typedef struct COREWEBVIEW2_MATRIX_4X4
    {
    FLOAT _11;
    FLOAT _12;
    FLOAT _13;
    FLOAT _14;
    FLOAT _21;
    FLOAT _22;
    FLOAT _23;
    FLOAT _24;
    FLOAT _31;
    FLOAT _32;
    FLOAT _33;
    FLOAT _34;
    FLOAT _41;
    FLOAT _42;
    FLOAT _43;
    FLOAT _44;
    } 	COREWEBVIEW2_MATRIX_4X4;

typedef /* [v1_enum] */ 
enum COREWEBVIEW2_UPDATE_RUNTIME_STATUS
    {
        COREWEBVIEW2_UPDATE_RUNTIME_STATUS_LATEST_VERSION_INSTALLED	= 0,
        COREWEBVIEW2_UPDATE_RUNTIME_STATUS_UPDATE_ALREADY_RUNNING	= ( COREWEBVIEW2_UPDATE_RUNTIME_STATUS_LATEST_VERSION_INSTALLED + 1 ) ,
        COREWEBVIEW2_UPDATE_RUNTIME_STATUS_BLOCKED_BY_POLICY	= ( COREWEBVIEW2_UPDATE_RUNTIME_STATUS_UPDATE_ALREADY_RUNNING + 1 ) ,
        COREWEBVIEW2_UPDATE_RUNTIME_STATUS_FAILED	= ( COREWEBVIEW2_UPDATE_RUNTIME_STATUS_BLOCKED_BY_POLICY + 1 ) 
    } 	COREWEBVIEW2_UPDATE_RUNTIME_STATUS;

typedef /* [v1_enum] */ 
enum COREWEBVIEW2_MEMORY_USAGE_TARGET_LEVEL
    {
        COREWEBVIEW2_MEMORY_USAGE_TARGET_LEVEL_NORMAL	= 0,
        COREWEBVIEW2_MEMORY_USAGE_TARGET_LEVEL_LOW	= ( COREWEBVIEW2_MEMORY_USAGE_TARGET_LEVEL_NORMAL + 1 ) 
    } 	COREWEBVIEW2_MEMORY_USAGE_TARGET_LEVEL;

typedef /* [v1_enum] */ 
enum COREWEBVIEW2_NAVIGATION_KIND
    {
        COREWEBVIEW2_NAVIGATION_KIND_RELOAD	= 0,
        COREWEBVIEW2_NAVIGATION_KIND_BACK_OR_FORWARD	= 1,
        COREWEBVIEW2_NAVIGATION_KIND_NEW_DOCUMENT	= 2
    } 	COREWEBVIEW2_NAVIGATION_KIND;

typedef /* [v1_enum] */ 
enum COREWEBVIEW2_TEXTURE_STREAM_ERROR_KIND
    {
        COREWEBVIEW2_TEXTURE_STREAM_ERROR_NO_VIDEO_TRACK_STARTED	= 0,
        COREWEBVIEW2_TEXTURE_STREAM_ERROR_TEXTURE_ERROR	= ( COREWEBVIEW2_TEXTURE_STREAM_ERROR_NO_VIDEO_TRACK_STARTED + 1 ) ,
        COREWEBVIEW2_TEXTURE_STREAM_ERROR_TEXTURE_IN_USE	= ( COREWEBVIEW2_TEXTURE_STREAM_ERROR_TEXTURE_ERROR + 1 ) 
    } 	COREWEBVIEW2_TEXTURE_STREAM_ERROR_KIND;


EXTERN_C const IID LIBID_WebView2Experimental;

#ifndef __ICoreWebView2Experimental5_INTERFACE_DEFINED__
#define __ICoreWebView2Experimental5_INTERFACE_DEFINED__

/* interface ICoreWebView2Experimental5 */
/* [unique][object][uuid] */ 


EXTERN_C __declspec(selectany) const IID IID_ICoreWebView2Experimental5 = {0xE05E04CA,0x7924,0x4C04,{0xA8,0x4C,0xA9,0x05,0x72,0xDB,0xA2,0x2A}};

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E05E04CA-7924-4C04-A84C-A90572DBA22A")
    ICoreWebView2Experimental5 : public IUnknown
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_MemoryUsageTargetLevel( 
            /* [retval][out] */ COREWEBVIEW2_MEMORY_USAGE_TARGET_LEVEL *level) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_MemoryUsageTargetLevel( 
            /* [in] */ COREWEBVIEW2_MEMORY_USAGE_TARGET_LEVEL level) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICoreWebView2Experimental5Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreWebView2Experimental5 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreWebView2Experimental5 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreWebView2Experimental5 * This);
        
        DECLSPEC_XFGVIRT(ICoreWebView2Experimental5, get_MemoryUsageTargetLevel)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_MemoryUsageTargetLevel )( 
            ICoreWebView2Experimental5 * This,
            /* [retval][out] */ COREWEBVIEW2_MEMORY_USAGE_TARGET_LEVEL *level);
        
        DECLSPEC_XFGVIRT(ICoreWebView2Experimental5, put_MemoryUsageTargetLevel)
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_MemoryUsageTargetLevel )( 
            ICoreWebView2Experimental5 * This,
            /* [in] */ COREWEBVIEW2_MEMORY_USAGE_TARGET_LEVEL level);
        
        END_INTERFACE
    } ICoreWebView2Experimental5Vtbl;

    interface ICoreWebView2Experimental5
    {
        CONST_VTBL struct ICoreWebView2Experimental5Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreWebView2Experimental5_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreWebView2Experimental5_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreWebView2Experimental5_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreWebView2Experimental5_get_MemoryUsageTargetLevel(This,level)	\
    ( (This)->lpVtbl -> get_MemoryUsageTargetLevel(This,level) ) 

#define ICoreWebView2Experimental5_put_MemoryUsageTargetLevel(This,level)	\
    ( (This)->lpVtbl -> put_MemoryUsageTargetLevel(This,level) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreWebView2Experimental5_INTERFACE_DEFINED__ */


#ifndef __ICoreWebView2Experimental16_INTERFACE_DEFINED__
#define __ICoreWebView2Experimental16_INTERFACE_DEFINED__

/* interface ICoreWebView2Experimental16 */
/* [unique][object][uuid] */ 


EXTERN_C __declspec(selectany) const IID IID_ICoreWebView2Experimental16 = {0x679ddf3f,0x9044,0x486f,{0x84,0x58,0x16,0x65,0x3a,0x0e,0x16,0x03}};

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("679ddf3f-9044-486f-8458-16653a0e1603")
    ICoreWebView2Experimental16 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AddWebResourceRequestedFilterWithRequestSourceKinds( 
            /* [in] */ const LPCWSTR uri,
            /* [in] */ const COREWEBVIEW2_WEB_RESOURCE_CONTEXT resourceContext,
            /* [in] */ const COREWEBVIEW2_WEB_RESOURCE_REQUEST_SOURCE_KINDS requestSourceKinds) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveWebResourceRequestedFilterWithRequestSourceKinds( 
            /* [in] */ const LPCWSTR uri,
            /* [in] */ const COREWEBVIEW2_WEB_RESOURCE_CONTEXT resourceContext,
            /* [in] */ const COREWEBVIEW2_WEB_RESOURCE_REQUEST_SOURCE_KINDS requestSourceKinds) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICoreWebView2Experimental16Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreWebView2Experimental16 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreWebView2Experimental16 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreWebView2Experimental16 * This);
        
        DECLSPEC_XFGVIRT(ICoreWebView2Experimental16, AddWebResourceRequestedFilterWithRequestSourceKinds)
        HRESULT ( STDMETHODCALLTYPE *AddWebResourceRequestedFilterWithRequestSourceKinds )( 
            ICoreWebView2Experimental16 * This,
            /* [in] */ const LPCWSTR uri,
            /* [in] */ const COREWEBVIEW2_WEB_RESOURCE_CONTEXT resourceContext,
            /* [in] */ const COREWEBVIEW2_WEB_RESOURCE_REQUEST_SOURCE_KINDS requestSourceKinds);
        
        DECLSPEC_XFGVIRT(ICoreWebView2Experimental16, RemoveWebResourceRequestedFilterWithRequestSourceKinds)
        HRESULT ( STDMETHODCALLTYPE *RemoveWebResourceRequestedFilterWithRequestSourceKinds )( 
            ICoreWebView2Experimental16 * This,
            /* [in] */ const LPCWSTR uri,
            /* [in] */ const COREWEBVIEW2_WEB_RESOURCE_CONTEXT resourceContext,
            /* [in] */ const COREWEBVIEW2_WEB_RESOURCE_REQUEST_SOURCE_KINDS requestSourceKinds);
        
        END_INTERFACE
    } ICoreWebView2Experimental16Vtbl;

    interface ICoreWebView2Experimental16
    {
        CONST_VTBL struct ICoreWebView2Experimental16Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreWebView2Experimental16_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreWebView2Experimental16_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreWebView2Experimental16_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreWebView2Experimental16_AddWebResourceRequestedFilterWithRequestSourceKinds(This,uri,resourceContext,requestSourceKinds)	\
    ( (This)->lpVtbl -> AddWebResourceRequestedFilterWithRequestSourceKinds(This,uri,resourceContext,requestSourceKinds) ) 

#define ICoreWebView2Experimental16_RemoveWebResourceRequestedFilterWithRequestSourceKinds(This,uri,resourceContext,requestSourceKinds)	\
    ( (This)->lpVtbl -> RemoveWebResourceRequestedFilterWithRequestSourceKinds(This,uri,resourceContext,requestSourceKinds) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreWebView2Experimental16_INTERFACE_DEFINED__ */


#ifndef __ICoreWebView2Experimental19_INTERFACE_DEFINED__
#define __ICoreWebView2Experimental19_INTERFACE_DEFINED__

/* interface ICoreWebView2Experimental19 */
/* [unique][object][uuid] */ 


EXTERN_C __declspec(selectany) const IID IID_ICoreWebView2Experimental19 = {0x4C765E35,0x5BEB,0x4631,{0xB9,0x31,0x5E,0x52,0xD9,0xB0,0xA9,0xBE}};

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4C765E35-5BEB-4631-B931-5E52D9B0A9BE")
    ICoreWebView2Experimental19 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ExecuteScriptWithResult( 
            /* [in] */ LPCWSTR javaScript,
            /* [in] */ ICoreWebView2ExperimentalExecuteScriptWithResultCompletedHandler *handler) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICoreWebView2Experimental19Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreWebView2Experimental19 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreWebView2Experimental19 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreWebView2Experimental19 * This);
        
        DECLSPEC_XFGVIRT(ICoreWebView2Experimental19, ExecuteScriptWithResult)
        HRESULT ( STDMETHODCALLTYPE *ExecuteScriptWithResult )( 
            ICoreWebView2Experimental19 * This,
            /* [in] */ LPCWSTR javaScript,
            /* [in] */ ICoreWebView2ExperimentalExecuteScriptWithResultCompletedHandler *handler);
        
        END_INTERFACE
    } ICoreWebView2Experimental19Vtbl;

    interface ICoreWebView2Experimental19
    {
        CONST_VTBL struct ICoreWebView2Experimental19Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreWebView2Experimental19_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreWebView2Experimental19_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreWebView2Experimental19_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreWebView2Experimental19_ExecuteScriptWithResult(This,javaScript,handler)	\
    ( (This)->lpVtbl -> ExecuteScriptWithResult(This,javaScript,handler) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreWebView2Experimental19_INTERFACE_DEFINED__ */


#ifndef __ICoreWebView2Experimental20_INTERFACE_DEFINED__
#define __ICoreWebView2Experimental20_INTERFACE_DEFINED__

/* interface ICoreWebView2Experimental20 */
/* [unique][object][uuid] */ 


EXTERN_C __declspec(selectany) const IID IID_ICoreWebView2Experimental20 = {0x5A4D0ECF,0x3FE5,0x4456,{0xAC,0xE5,0xD3,0x17,0xCC,0xA0,0xEF,0xF1}};

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5A4D0ECF-3FE5-4456-ACE5-D317CCA0EFF1")
    ICoreWebView2Experimental20 : public IUnknown
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CustomDataPartitionId( 
            /* [retval][out] */ LPWSTR *customDataPartitionId) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_CustomDataPartitionId( 
            /* [in] */ LPCWSTR customDataPartitionId) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICoreWebView2Experimental20Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreWebView2Experimental20 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreWebView2Experimental20 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreWebView2Experimental20 * This);
        
        DECLSPEC_XFGVIRT(ICoreWebView2Experimental20, get_CustomDataPartitionId)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_CustomDataPartitionId )( 
            ICoreWebView2Experimental20 * This,
            /* [retval][out] */ LPWSTR *customDataPartitionId);
        
        DECLSPEC_XFGVIRT(ICoreWebView2Experimental20, put_CustomDataPartitionId)
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_CustomDataPartitionId )( 
            ICoreWebView2Experimental20 * This,
            /* [in] */ LPCWSTR customDataPartitionId);
        
        END_INTERFACE
    } ICoreWebView2Experimental20Vtbl;

    interface ICoreWebView2Experimental20
    {
        CONST_VTBL struct ICoreWebView2Experimental20Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreWebView2Experimental20_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreWebView2Experimental20_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreWebView2Experimental20_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreWebView2Experimental20_get_CustomDataPartitionId(This,customDataPartitionId)	\
    ( (This)->lpVtbl -> get_CustomDataPartitionId(This,customDataPartitionId) ) 

#define ICoreWebView2Experimental20_put_CustomDataPartitionId(This,customDataPartitionId)	\
    ( (This)->lpVtbl -> put_CustomDataPartitionId(This,customDataPartitionId) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreWebView2Experimental20_INTERFACE_DEFINED__ */


#ifndef __ICoreWebView2Experimental21_INTERFACE_DEFINED__
#define __ICoreWebView2Experimental21_INTERFACE_DEFINED__

/* interface ICoreWebView2Experimental21 */
/* [unique][object][uuid] */ 


EXTERN_C __declspec(selectany) const IID IID_ICoreWebView2Experimental21 = {0x30686d89,0x34fa,0x4327,{0xb5,0xa3,0xd5,0x99,0x54,0x20,0x3f,0x7c}};

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("30686d89-34fa-4327-b5a3-d59954203f7c")
    ICoreWebView2Experimental21 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE add_LaunchingExternalUriScheme( 
            /* [in] */ ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventHandler *eventHandler,
            /* [out] */ EventRegistrationToken *token) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE remove_LaunchingExternalUriScheme( 
            /* [in] */ EventRegistrationToken token) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICoreWebView2Experimental21Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreWebView2Experimental21 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreWebView2Experimental21 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreWebView2Experimental21 * This);
        
        DECLSPEC_XFGVIRT(ICoreWebView2Experimental21, add_LaunchingExternalUriScheme)
        HRESULT ( STDMETHODCALLTYPE *add_LaunchingExternalUriScheme )( 
            ICoreWebView2Experimental21 * This,
            /* [in] */ ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventHandler *eventHandler,
            /* [out] */ EventRegistrationToken *token);
        
        DECLSPEC_XFGVIRT(ICoreWebView2Experimental21, remove_LaunchingExternalUriScheme)
        HRESULT ( STDMETHODCALLTYPE *remove_LaunchingExternalUriScheme )( 
            ICoreWebView2Experimental21 * This,
            /* [in] */ EventRegistrationToken token);
        
        END_INTERFACE
    } ICoreWebView2Experimental21Vtbl;

    interface ICoreWebView2Experimental21
    {
        CONST_VTBL struct ICoreWebView2Experimental21Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreWebView2Experimental21_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreWebView2Experimental21_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreWebView2Experimental21_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreWebView2Experimental21_add_LaunchingExternalUriScheme(This,eventHandler,token)	\
    ( (This)->lpVtbl -> add_LaunchingExternalUriScheme(This,eventHandler,token) ) 

#define ICoreWebView2Experimental21_remove_LaunchingExternalUriScheme(This,token)	\
    ( (This)->lpVtbl -> remove_LaunchingExternalUriScheme(This,token) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreWebView2Experimental21_INTERFACE_DEFINED__ */


#ifndef __ICoreWebView2ExperimentalCompositionController4_INTERFACE_DEFINED__
#define __ICoreWebView2ExperimentalCompositionController4_INTERFACE_DEFINED__

/* interface ICoreWebView2ExperimentalCompositionController4 */
/* [unique][object][uuid] */ 


EXTERN_C __declspec(selectany) const IID IID_ICoreWebView2ExperimentalCompositionController4 = {0xe6041d7f,0x18ac,0x4654,{0xa0,0x4e,0x8b,0x3f,0x81,0x25,0x1c,0x33}};

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("e6041d7f-18ac-4654-a04e-8b3f81251c33")
    ICoreWebView2ExperimentalCompositionController4 : public IUnknown
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_AutomationProvider( 
            /* [retval][out] */ IUnknown **provider) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateCoreWebView2PointerInfoFromPointerId( 
            /* [in] */ UINT pointerId,
            /* [in] */ HWND parentWindow,
            /* [in] */ struct COREWEBVIEW2_MATRIX_4X4 transform,
            /* [retval][out] */ ICoreWebView2PointerInfo **pointerInfo) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICoreWebView2ExperimentalCompositionController4Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreWebView2ExperimentalCompositionController4 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreWebView2ExperimentalCompositionController4 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreWebView2ExperimentalCompositionController4 * This);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalCompositionController4, get_AutomationProvider)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_AutomationProvider )( 
            ICoreWebView2ExperimentalCompositionController4 * This,
            /* [retval][out] */ IUnknown **provider);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalCompositionController4, CreateCoreWebView2PointerInfoFromPointerId)
        HRESULT ( STDMETHODCALLTYPE *CreateCoreWebView2PointerInfoFromPointerId )( 
            ICoreWebView2ExperimentalCompositionController4 * This,
            /* [in] */ UINT pointerId,
            /* [in] */ HWND parentWindow,
            /* [in] */ struct COREWEBVIEW2_MATRIX_4X4 transform,
            /* [retval][out] */ ICoreWebView2PointerInfo **pointerInfo);
        
        END_INTERFACE
    } ICoreWebView2ExperimentalCompositionController4Vtbl;

    interface ICoreWebView2ExperimentalCompositionController4
    {
        CONST_VTBL struct ICoreWebView2ExperimentalCompositionController4Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreWebView2ExperimentalCompositionController4_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreWebView2ExperimentalCompositionController4_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreWebView2ExperimentalCompositionController4_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreWebView2ExperimentalCompositionController4_get_AutomationProvider(This,provider)	\
    ( (This)->lpVtbl -> get_AutomationProvider(This,provider) ) 

#define ICoreWebView2ExperimentalCompositionController4_CreateCoreWebView2PointerInfoFromPointerId(This,pointerId,parentWindow,transform,pointerInfo)	\
    ( (This)->lpVtbl -> CreateCoreWebView2PointerInfoFromPointerId(This,pointerId,parentWindow,transform,pointerInfo) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreWebView2ExperimentalCompositionController4_INTERFACE_DEFINED__ */


#ifndef __ICoreWebView2ExperimentalClearCustomDataPartitionCompletedHandler_INTERFACE_DEFINED__
#define __ICoreWebView2ExperimentalClearCustomDataPartitionCompletedHandler_INTERFACE_DEFINED__

/* interface ICoreWebView2ExperimentalClearCustomDataPartitionCompletedHandler */
/* [unique][object][uuid] */ 


EXTERN_C __declspec(selectany) const IID IID_ICoreWebView2ExperimentalClearCustomDataPartitionCompletedHandler = {0xFE753727,0x5758,0x4FEA,{0x8C,0xAD,0x1E,0x68,0x5B,0x9C,0x3A,0xE8}};

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FE753727-5758-4FEA-8CAD-1E685B9C3AE8")
    ICoreWebView2ExperimentalClearCustomDataPartitionCompletedHandler : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Invoke( 
            /* [in] */ HRESULT errorCode) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICoreWebView2ExperimentalClearCustomDataPartitionCompletedHandlerVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreWebView2ExperimentalClearCustomDataPartitionCompletedHandler * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreWebView2ExperimentalClearCustomDataPartitionCompletedHandler * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreWebView2ExperimentalClearCustomDataPartitionCompletedHandler * This);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalClearCustomDataPartitionCompletedHandler, Invoke)
        HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICoreWebView2ExperimentalClearCustomDataPartitionCompletedHandler * This,
            /* [in] */ HRESULT errorCode);
        
        END_INTERFACE
    } ICoreWebView2ExperimentalClearCustomDataPartitionCompletedHandlerVtbl;

    interface ICoreWebView2ExperimentalClearCustomDataPartitionCompletedHandler
    {
        CONST_VTBL struct ICoreWebView2ExperimentalClearCustomDataPartitionCompletedHandlerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreWebView2ExperimentalClearCustomDataPartitionCompletedHandler_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreWebView2ExperimentalClearCustomDataPartitionCompletedHandler_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreWebView2ExperimentalClearCustomDataPartitionCompletedHandler_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreWebView2ExperimentalClearCustomDataPartitionCompletedHandler_Invoke(This,errorCode)	\
    ( (This)->lpVtbl -> Invoke(This,errorCode) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreWebView2ExperimentalClearCustomDataPartitionCompletedHandler_INTERFACE_DEFINED__ */


#ifndef __ICoreWebView2ExperimentalEnvironment3_INTERFACE_DEFINED__
#define __ICoreWebView2ExperimentalEnvironment3_INTERFACE_DEFINED__

/* interface ICoreWebView2ExperimentalEnvironment3 */
/* [unique][object][uuid] */ 


EXTERN_C __declspec(selectany) const IID IID_ICoreWebView2ExperimentalEnvironment3 = {0x9A2BE885,0x7F0B,0x4B26,{0xB6,0xDD,0xC9,0x69,0xBA,0xA0,0x0B,0xF1}};

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9A2BE885-7F0B-4B26-B6DD-C969BAA00BF1")
    ICoreWebView2ExperimentalEnvironment3 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE UpdateRuntime( 
            /* [in] */ ICoreWebView2ExperimentalUpdateRuntimeCompletedHandler *handler) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICoreWebView2ExperimentalEnvironment3Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreWebView2ExperimentalEnvironment3 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreWebView2ExperimentalEnvironment3 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreWebView2ExperimentalEnvironment3 * This);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalEnvironment3, UpdateRuntime)
        HRESULT ( STDMETHODCALLTYPE *UpdateRuntime )( 
            ICoreWebView2ExperimentalEnvironment3 * This,
            /* [in] */ ICoreWebView2ExperimentalUpdateRuntimeCompletedHandler *handler);
        
        END_INTERFACE
    } ICoreWebView2ExperimentalEnvironment3Vtbl;

    interface ICoreWebView2ExperimentalEnvironment3
    {
        CONST_VTBL struct ICoreWebView2ExperimentalEnvironment3Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreWebView2ExperimentalEnvironment3_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreWebView2ExperimentalEnvironment3_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreWebView2ExperimentalEnvironment3_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreWebView2ExperimentalEnvironment3_UpdateRuntime(This,handler)	\
    ( (This)->lpVtbl -> UpdateRuntime(This,handler) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreWebView2ExperimentalEnvironment3_INTERFACE_DEFINED__ */


#ifndef __ICoreWebView2ExperimentalExecuteScriptResult_INTERFACE_DEFINED__
#define __ICoreWebView2ExperimentalExecuteScriptResult_INTERFACE_DEFINED__

/* interface ICoreWebView2ExperimentalExecuteScriptResult */
/* [unique][object][uuid] */ 


EXTERN_C __declspec(selectany) const IID IID_ICoreWebView2ExperimentalExecuteScriptResult = {0x0CE15963,0x3698,0x4DF7,{0x93,0x99,0x71,0xED,0x6C,0xDD,0x8C,0x9F}};

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0CE15963-3698-4DF7-9399-71ED6CDD8C9F")
    ICoreWebView2ExperimentalExecuteScriptResult : public IUnknown
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Succeeded( 
            /* [retval][out] */ BOOL *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ResultAsJson( 
            /* [retval][out] */ LPWSTR *jsonResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE TryGetResultAsString( 
            /* [out] */ LPWSTR *stringResult,
            /* [out] */ BOOL *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Exception( 
            /* [retval][out] */ ICoreWebView2ExperimentalScriptException **exception) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICoreWebView2ExperimentalExecuteScriptResultVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreWebView2ExperimentalExecuteScriptResult * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreWebView2ExperimentalExecuteScriptResult * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreWebView2ExperimentalExecuteScriptResult * This);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalExecuteScriptResult, get_Succeeded)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Succeeded )( 
            ICoreWebView2ExperimentalExecuteScriptResult * This,
            /* [retval][out] */ BOOL *value);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalExecuteScriptResult, get_ResultAsJson)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_ResultAsJson )( 
            ICoreWebView2ExperimentalExecuteScriptResult * This,
            /* [retval][out] */ LPWSTR *jsonResult);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalExecuteScriptResult, TryGetResultAsString)
        HRESULT ( STDMETHODCALLTYPE *TryGetResultAsString )( 
            ICoreWebView2ExperimentalExecuteScriptResult * This,
            /* [out] */ LPWSTR *stringResult,
            /* [out] */ BOOL *value);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalExecuteScriptResult, get_Exception)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Exception )( 
            ICoreWebView2ExperimentalExecuteScriptResult * This,
            /* [retval][out] */ ICoreWebView2ExperimentalScriptException **exception);
        
        END_INTERFACE
    } ICoreWebView2ExperimentalExecuteScriptResultVtbl;

    interface ICoreWebView2ExperimentalExecuteScriptResult
    {
        CONST_VTBL struct ICoreWebView2ExperimentalExecuteScriptResultVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreWebView2ExperimentalExecuteScriptResult_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreWebView2ExperimentalExecuteScriptResult_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreWebView2ExperimentalExecuteScriptResult_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreWebView2ExperimentalExecuteScriptResult_get_Succeeded(This,value)	\
    ( (This)->lpVtbl -> get_Succeeded(This,value) ) 

#define ICoreWebView2ExperimentalExecuteScriptResult_get_ResultAsJson(This,jsonResult)	\
    ( (This)->lpVtbl -> get_ResultAsJson(This,jsonResult) ) 

#define ICoreWebView2ExperimentalExecuteScriptResult_TryGetResultAsString(This,stringResult,value)	\
    ( (This)->lpVtbl -> TryGetResultAsString(This,stringResult,value) ) 

#define ICoreWebView2ExperimentalExecuteScriptResult_get_Exception(This,exception)	\
    ( (This)->lpVtbl -> get_Exception(This,exception) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreWebView2ExperimentalExecuteScriptResult_INTERFACE_DEFINED__ */


#ifndef __ICoreWebView2ExperimentalExecuteScriptWithResultCompletedHandler_INTERFACE_DEFINED__
#define __ICoreWebView2ExperimentalExecuteScriptWithResultCompletedHandler_INTERFACE_DEFINED__

/* interface ICoreWebView2ExperimentalExecuteScriptWithResultCompletedHandler */
/* [unique][object][uuid] */ 


EXTERN_C __declspec(selectany) const IID IID_ICoreWebView2ExperimentalExecuteScriptWithResultCompletedHandler = {0x1BB5317B,0x8238,0x4C67,{0xA7,0xFF,0xBA,0xF6,0x55,0x8F,0x28,0x9D}};

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1BB5317B-8238-4C67-A7FF-BAF6558F289D")
    ICoreWebView2ExperimentalExecuteScriptWithResultCompletedHandler : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Invoke( 
            /* [in] */ HRESULT errorCode,
            /* [in] */ ICoreWebView2ExperimentalExecuteScriptResult *result) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICoreWebView2ExperimentalExecuteScriptWithResultCompletedHandlerVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreWebView2ExperimentalExecuteScriptWithResultCompletedHandler * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreWebView2ExperimentalExecuteScriptWithResultCompletedHandler * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreWebView2ExperimentalExecuteScriptWithResultCompletedHandler * This);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalExecuteScriptWithResultCompletedHandler, Invoke)
        HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICoreWebView2ExperimentalExecuteScriptWithResultCompletedHandler * This,
            /* [in] */ HRESULT errorCode,
            /* [in] */ ICoreWebView2ExperimentalExecuteScriptResult *result);
        
        END_INTERFACE
    } ICoreWebView2ExperimentalExecuteScriptWithResultCompletedHandlerVtbl;

    interface ICoreWebView2ExperimentalExecuteScriptWithResultCompletedHandler
    {
        CONST_VTBL struct ICoreWebView2ExperimentalExecuteScriptWithResultCompletedHandlerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreWebView2ExperimentalExecuteScriptWithResultCompletedHandler_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreWebView2ExperimentalExecuteScriptWithResultCompletedHandler_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreWebView2ExperimentalExecuteScriptWithResultCompletedHandler_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreWebView2ExperimentalExecuteScriptWithResultCompletedHandler_Invoke(This,errorCode,result)	\
    ( (This)->lpVtbl -> Invoke(This,errorCode,result) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreWebView2ExperimentalExecuteScriptWithResultCompletedHandler_INTERFACE_DEFINED__ */


#ifndef __ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventArgs_INTERFACE_DEFINED__
#define __ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventArgs_INTERFACE_DEFINED__

/* interface ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventArgs */
/* [unique][object][uuid] */ 


EXTERN_C __declspec(selectany) const IID IID_ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventArgs = {0x07d1a6c3,0x7175,0x4ba1,{0x93,0x06,0xe5,0x93,0xca,0x07,0xe4,0x6c}};

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("07d1a6c3-7175-4ba1-9306-e593ca07e46c")
    ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventArgs : public IUnknown
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Uri( 
            /* [retval][out] */ LPWSTR *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_InitiatingOrigin( 
            /* [retval][out] */ LPWSTR *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_IsUserInitiated( 
            /* [retval][out] */ BOOL *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Cancel( 
            /* [retval][out] */ BOOL *value) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_Cancel( 
            /* [in] */ BOOL value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDeferral( 
            /* [retval][out] */ ICoreWebView2Deferral **value) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventArgsVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventArgs * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventArgs * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventArgs * This);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventArgs, get_Uri)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Uri )( 
            ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventArgs * This,
            /* [retval][out] */ LPWSTR *value);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventArgs, get_InitiatingOrigin)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_InitiatingOrigin )( 
            ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventArgs * This,
            /* [retval][out] */ LPWSTR *value);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventArgs, get_IsUserInitiated)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsUserInitiated )( 
            ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventArgs * This,
            /* [retval][out] */ BOOL *value);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventArgs, get_Cancel)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Cancel )( 
            ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventArgs * This,
            /* [retval][out] */ BOOL *value);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventArgs, put_Cancel)
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_Cancel )( 
            ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventArgs * This,
            /* [in] */ BOOL value);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventArgs, GetDeferral)
        HRESULT ( STDMETHODCALLTYPE *GetDeferral )( 
            ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventArgs * This,
            /* [retval][out] */ ICoreWebView2Deferral **value);
        
        END_INTERFACE
    } ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventArgsVtbl;

    interface ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventArgs
    {
        CONST_VTBL struct ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventArgsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventArgs_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventArgs_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventArgs_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventArgs_get_Uri(This,value)	\
    ( (This)->lpVtbl -> get_Uri(This,value) ) 

#define ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventArgs_get_InitiatingOrigin(This,value)	\
    ( (This)->lpVtbl -> get_InitiatingOrigin(This,value) ) 

#define ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventArgs_get_IsUserInitiated(This,value)	\
    ( (This)->lpVtbl -> get_IsUserInitiated(This,value) ) 

#define ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventArgs_get_Cancel(This,value)	\
    ( (This)->lpVtbl -> get_Cancel(This,value) ) 

#define ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventArgs_put_Cancel(This,value)	\
    ( (This)->lpVtbl -> put_Cancel(This,value) ) 

#define ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventArgs_GetDeferral(This,value)	\
    ( (This)->lpVtbl -> GetDeferral(This,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventArgs_INTERFACE_DEFINED__ */


#ifndef __ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventHandler_INTERFACE_DEFINED__
#define __ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventHandler_INTERFACE_DEFINED__

/* interface ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventHandler */
/* [unique][object][uuid] */ 


EXTERN_C __declspec(selectany) const IID IID_ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventHandler = {0x74f712e0,0x8165,0x43a9,{0xa1,0x3f,0x0c,0xce,0x59,0x7e,0x75,0xdf}};

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("74f712e0-8165-43a9-a13f-0cce597e75df")
    ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventHandler : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Invoke( 
            /* [in] */ ICoreWebView2 *sender,
            /* [in] */ ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventArgs *args) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventHandlerVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventHandler * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventHandler * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventHandler * This);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventHandler, Invoke)
        HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventHandler * This,
            /* [in] */ ICoreWebView2 *sender,
            /* [in] */ ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventArgs *args);
        
        END_INTERFACE
    } ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventHandlerVtbl;

    interface ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventHandler
    {
        CONST_VTBL struct ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventHandlerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventHandler_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventHandler_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventHandler_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventHandler_Invoke(This,sender,args)	\
    ( (This)->lpVtbl -> Invoke(This,sender,args) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreWebView2ExperimentalLaunchingExternalUriSchemeEventHandler_INTERFACE_DEFINED__ */


#ifndef __ICoreWebView2ExperimentalScriptException_INTERFACE_DEFINED__
#define __ICoreWebView2ExperimentalScriptException_INTERFACE_DEFINED__

/* interface ICoreWebView2ExperimentalScriptException */
/* [unique][object][uuid] */ 


EXTERN_C __declspec(selectany) const IID IID_ICoreWebView2ExperimentalScriptException = {0x054DAE00,0x84A3,0x49FF,{0xBC,0x17,0x40,0x12,0xA9,0x0B,0xC9,0xFD}};

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("054DAE00-84A3-49FF-BC17-4012A90BC9FD")
    ICoreWebView2ExperimentalScriptException : public IUnknown
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_LineNumber( 
            /* [retval][out] */ UINT32 *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ColumnNumber( 
            /* [retval][out] */ UINT32 *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ LPWSTR *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Message( 
            /* [retval][out] */ LPWSTR *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ToJson( 
            /* [retval][out] */ LPWSTR *value) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICoreWebView2ExperimentalScriptExceptionVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreWebView2ExperimentalScriptException * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreWebView2ExperimentalScriptException * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreWebView2ExperimentalScriptException * This);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalScriptException, get_LineNumber)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_LineNumber )( 
            ICoreWebView2ExperimentalScriptException * This,
            /* [retval][out] */ UINT32 *value);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalScriptException, get_ColumnNumber)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_ColumnNumber )( 
            ICoreWebView2ExperimentalScriptException * This,
            /* [retval][out] */ UINT32 *value);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalScriptException, get_Name)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            ICoreWebView2ExperimentalScriptException * This,
            /* [retval][out] */ LPWSTR *value);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalScriptException, get_Message)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Message )( 
            ICoreWebView2ExperimentalScriptException * This,
            /* [retval][out] */ LPWSTR *value);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalScriptException, get_ToJson)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_ToJson )( 
            ICoreWebView2ExperimentalScriptException * This,
            /* [retval][out] */ LPWSTR *value);
        
        END_INTERFACE
    } ICoreWebView2ExperimentalScriptExceptionVtbl;

    interface ICoreWebView2ExperimentalScriptException
    {
        CONST_VTBL struct ICoreWebView2ExperimentalScriptExceptionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreWebView2ExperimentalScriptException_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreWebView2ExperimentalScriptException_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreWebView2ExperimentalScriptException_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreWebView2ExperimentalScriptException_get_LineNumber(This,value)	\
    ( (This)->lpVtbl -> get_LineNumber(This,value) ) 

#define ICoreWebView2ExperimentalScriptException_get_ColumnNumber(This,value)	\
    ( (This)->lpVtbl -> get_ColumnNumber(This,value) ) 

#define ICoreWebView2ExperimentalScriptException_get_Name(This,value)	\
    ( (This)->lpVtbl -> get_Name(This,value) ) 

#define ICoreWebView2ExperimentalScriptException_get_Message(This,value)	\
    ( (This)->lpVtbl -> get_Message(This,value) ) 

#define ICoreWebView2ExperimentalScriptException_get_ToJson(This,value)	\
    ( (This)->lpVtbl -> get_ToJson(This,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreWebView2ExperimentalScriptException_INTERFACE_DEFINED__ */


#ifndef __ICoreWebView2ExperimentalProfile7_INTERFACE_DEFINED__
#define __ICoreWebView2ExperimentalProfile7_INTERFACE_DEFINED__

/* interface ICoreWebView2ExperimentalProfile7 */
/* [unique][object][uuid] */ 


EXTERN_C __declspec(selectany) const IID IID_ICoreWebView2ExperimentalProfile7 = {0x11A14762,0x7780,0x46A1,{0xA1,0xC3,0x73,0xDE,0x81,0x2D,0xAE,0x12}};

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("11A14762-7780-46A1-A1C3-73DE812DAE12")
    ICoreWebView2ExperimentalProfile7 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ClearCustomDataPartition( 
            /* [in] */ LPCWSTR customDataPartitionId,
            /* [in] */ ICoreWebView2ExperimentalClearCustomDataPartitionCompletedHandler *handler) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICoreWebView2ExperimentalProfile7Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreWebView2ExperimentalProfile7 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreWebView2ExperimentalProfile7 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreWebView2ExperimentalProfile7 * This);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalProfile7, ClearCustomDataPartition)
        HRESULT ( STDMETHODCALLTYPE *ClearCustomDataPartition )( 
            ICoreWebView2ExperimentalProfile7 * This,
            /* [in] */ LPCWSTR customDataPartitionId,
            /* [in] */ ICoreWebView2ExperimentalClearCustomDataPartitionCompletedHandler *handler);
        
        END_INTERFACE
    } ICoreWebView2ExperimentalProfile7Vtbl;

    interface ICoreWebView2ExperimentalProfile7
    {
        CONST_VTBL struct ICoreWebView2ExperimentalProfile7Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreWebView2ExperimentalProfile7_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreWebView2ExperimentalProfile7_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreWebView2ExperimentalProfile7_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreWebView2ExperimentalProfile7_ClearCustomDataPartition(This,customDataPartitionId,handler)	\
    ( (This)->lpVtbl -> ClearCustomDataPartition(This,customDataPartitionId,handler) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreWebView2ExperimentalProfile7_INTERFACE_DEFINED__ */


#ifndef __ICoreWebView2ExperimentalProfile10_INTERFACE_DEFINED__
#define __ICoreWebView2ExperimentalProfile10_INTERFACE_DEFINED__

/* interface ICoreWebView2ExperimentalProfile10 */
/* [unique][object][uuid] */ 


EXTERN_C __declspec(selectany) const IID IID_ICoreWebView2ExperimentalProfile10 = {0x172F43A5,0x8886,0x4D61,{0x95,0x64,0x57,0x9D,0xA2,0x93,0xBC,0x1D}};

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("172F43A5-8886-4D61-9564-579DA293BC1D")
    ICoreWebView2ExperimentalProfile10 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE add_Deleted( 
            /* [in] */ ICoreWebView2ExperimentalProfileDeletedEventHandler *eventHandler,
            /* [out] */ EventRegistrationToken *token) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE remove_Deleted( 
            /* [in] */ EventRegistrationToken token) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICoreWebView2ExperimentalProfile10Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreWebView2ExperimentalProfile10 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreWebView2ExperimentalProfile10 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreWebView2ExperimentalProfile10 * This);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalProfile10, Delete)
        HRESULT ( STDMETHODCALLTYPE *Delete )( 
            ICoreWebView2ExperimentalProfile10 * This);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalProfile10, add_Deleted)
        HRESULT ( STDMETHODCALLTYPE *add_Deleted )( 
            ICoreWebView2ExperimentalProfile10 * This,
            /* [in] */ ICoreWebView2ExperimentalProfileDeletedEventHandler *eventHandler,
            /* [out] */ EventRegistrationToken *token);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalProfile10, remove_Deleted)
        HRESULT ( STDMETHODCALLTYPE *remove_Deleted )( 
            ICoreWebView2ExperimentalProfile10 * This,
            /* [in] */ EventRegistrationToken token);
        
        END_INTERFACE
    } ICoreWebView2ExperimentalProfile10Vtbl;

    interface ICoreWebView2ExperimentalProfile10
    {
        CONST_VTBL struct ICoreWebView2ExperimentalProfile10Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreWebView2ExperimentalProfile10_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreWebView2ExperimentalProfile10_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreWebView2ExperimentalProfile10_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreWebView2ExperimentalProfile10_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define ICoreWebView2ExperimentalProfile10_add_Deleted(This,eventHandler,token)	\
    ( (This)->lpVtbl -> add_Deleted(This,eventHandler,token) ) 

#define ICoreWebView2ExperimentalProfile10_remove_Deleted(This,token)	\
    ( (This)->lpVtbl -> remove_Deleted(This,token) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreWebView2ExperimentalProfile10_INTERFACE_DEFINED__ */


#ifndef __ICoreWebView2ExperimentalProfileDeletedEventHandler_INTERFACE_DEFINED__
#define __ICoreWebView2ExperimentalProfileDeletedEventHandler_INTERFACE_DEFINED__

/* interface ICoreWebView2ExperimentalProfileDeletedEventHandler */
/* [unique][object][uuid] */ 


EXTERN_C __declspec(selectany) const IID IID_ICoreWebView2ExperimentalProfileDeletedEventHandler = {0xDF35055D,0x772E,0x4DBE,{0xB7,0x43,0x5F,0xBF,0x74,0xA2,0xB2,0x58}};

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DF35055D-772E-4DBE-B743-5FBF74A2B258")
    ICoreWebView2ExperimentalProfileDeletedEventHandler : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Invoke( 
            /* [in] */ ICoreWebView2Profile *sender,
            /* [in] */ IUnknown *args) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICoreWebView2ExperimentalProfileDeletedEventHandlerVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreWebView2ExperimentalProfileDeletedEventHandler * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreWebView2ExperimentalProfileDeletedEventHandler * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreWebView2ExperimentalProfileDeletedEventHandler * This);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalProfileDeletedEventHandler, Invoke)
        HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICoreWebView2ExperimentalProfileDeletedEventHandler * This,
            /* [in] */ ICoreWebView2Profile *sender,
            /* [in] */ IUnknown *args);
        
        END_INTERFACE
    } ICoreWebView2ExperimentalProfileDeletedEventHandlerVtbl;

    interface ICoreWebView2ExperimentalProfileDeletedEventHandler
    {
        CONST_VTBL struct ICoreWebView2ExperimentalProfileDeletedEventHandlerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreWebView2ExperimentalProfileDeletedEventHandler_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreWebView2ExperimentalProfileDeletedEventHandler_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreWebView2ExperimentalProfileDeletedEventHandler_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreWebView2ExperimentalProfileDeletedEventHandler_Invoke(This,sender,args)	\
    ( (This)->lpVtbl -> Invoke(This,sender,args) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreWebView2ExperimentalProfileDeletedEventHandler_INTERFACE_DEFINED__ */


#ifndef __ICoreWebView2ExperimentalUpdateRuntimeCompletedHandler_INTERFACE_DEFINED__
#define __ICoreWebView2ExperimentalUpdateRuntimeCompletedHandler_INTERFACE_DEFINED__

/* interface ICoreWebView2ExperimentalUpdateRuntimeCompletedHandler */
/* [unique][object][uuid] */ 


EXTERN_C __declspec(selectany) const IID IID_ICoreWebView2ExperimentalUpdateRuntimeCompletedHandler = {0xF1D2D722,0x3721,0x499C,{0x87,0xF5,0x4C,0x40,0x52,0x60,0x69,0x7A}};

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F1D2D722-3721-499C-87F5-4C405260697A")
    ICoreWebView2ExperimentalUpdateRuntimeCompletedHandler : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Invoke( 
            /* [in] */ HRESULT errorCode,
            /* [in] */ ICoreWebView2ExperimentalUpdateRuntimeResult *result) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICoreWebView2ExperimentalUpdateRuntimeCompletedHandlerVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreWebView2ExperimentalUpdateRuntimeCompletedHandler * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreWebView2ExperimentalUpdateRuntimeCompletedHandler * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreWebView2ExperimentalUpdateRuntimeCompletedHandler * This);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalUpdateRuntimeCompletedHandler, Invoke)
        HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICoreWebView2ExperimentalUpdateRuntimeCompletedHandler * This,
            /* [in] */ HRESULT errorCode,
            /* [in] */ ICoreWebView2ExperimentalUpdateRuntimeResult *result);
        
        END_INTERFACE
    } ICoreWebView2ExperimentalUpdateRuntimeCompletedHandlerVtbl;

    interface ICoreWebView2ExperimentalUpdateRuntimeCompletedHandler
    {
        CONST_VTBL struct ICoreWebView2ExperimentalUpdateRuntimeCompletedHandlerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreWebView2ExperimentalUpdateRuntimeCompletedHandler_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreWebView2ExperimentalUpdateRuntimeCompletedHandler_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreWebView2ExperimentalUpdateRuntimeCompletedHandler_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreWebView2ExperimentalUpdateRuntimeCompletedHandler_Invoke(This,errorCode,result)	\
    ( (This)->lpVtbl -> Invoke(This,errorCode,result) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreWebView2ExperimentalUpdateRuntimeCompletedHandler_INTERFACE_DEFINED__ */


#ifndef __ICoreWebView2ExperimentalUpdateRuntimeResult_INTERFACE_DEFINED__
#define __ICoreWebView2ExperimentalUpdateRuntimeResult_INTERFACE_DEFINED__

/* interface ICoreWebView2ExperimentalUpdateRuntimeResult */
/* [unique][object][uuid] */ 


EXTERN_C __declspec(selectany) const IID IID_ICoreWebView2ExperimentalUpdateRuntimeResult = {0xDD503E49,0xAB19,0x47C0,{0xB2,0xAD,0x6D,0xDD,0x09,0xCC,0x3E,0x3A}};

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DD503E49-AB19-47C0-B2AD-6DDD09CC3E3A")
    ICoreWebView2ExperimentalUpdateRuntimeResult : public IUnknown
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Status( 
            /* [retval][out] */ COREWEBVIEW2_UPDATE_RUNTIME_STATUS *status) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ExtendedError( 
            /* [retval][out] */ HRESULT *error) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICoreWebView2ExperimentalUpdateRuntimeResultVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreWebView2ExperimentalUpdateRuntimeResult * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreWebView2ExperimentalUpdateRuntimeResult * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreWebView2ExperimentalUpdateRuntimeResult * This);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalUpdateRuntimeResult, get_Status)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Status )( 
            ICoreWebView2ExperimentalUpdateRuntimeResult * This,
            /* [retval][out] */ COREWEBVIEW2_UPDATE_RUNTIME_STATUS *status);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalUpdateRuntimeResult, get_ExtendedError)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_ExtendedError )( 
            ICoreWebView2ExperimentalUpdateRuntimeResult * This,
            /* [retval][out] */ HRESULT *error);
        
        END_INTERFACE
    } ICoreWebView2ExperimentalUpdateRuntimeResultVtbl;

    interface ICoreWebView2ExperimentalUpdateRuntimeResult
    {
        CONST_VTBL struct ICoreWebView2ExperimentalUpdateRuntimeResultVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreWebView2ExperimentalUpdateRuntimeResult_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreWebView2ExperimentalUpdateRuntimeResult_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreWebView2ExperimentalUpdateRuntimeResult_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreWebView2ExperimentalUpdateRuntimeResult_get_Status(This,status)	\
    ( (This)->lpVtbl -> get_Status(This,status) ) 

#define ICoreWebView2ExperimentalUpdateRuntimeResult_get_ExtendedError(This,error)	\
    ( (This)->lpVtbl -> get_ExtendedError(This,error) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreWebView2ExperimentalUpdateRuntimeResult_INTERFACE_DEFINED__ */


#ifndef __ICoreWebView2ExperimentalWebResourceRequestedEventArgs_INTERFACE_DEFINED__
#define __ICoreWebView2ExperimentalWebResourceRequestedEventArgs_INTERFACE_DEFINED__

/* interface ICoreWebView2ExperimentalWebResourceRequestedEventArgs */
/* [unique][object][uuid] */ 


EXTERN_C __declspec(selectany) const IID IID_ICoreWebView2ExperimentalWebResourceRequestedEventArgs = {0x8f3ec528,0x0596,0x4d51,{0x9f,0x9e,0x2d,0xa5,0x80,0xac,0x97,0x87}};

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8f3ec528-0596-4d51-9f9e-2da580ac9787")
    ICoreWebView2ExperimentalWebResourceRequestedEventArgs : public IUnknown
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_RequestedSourceKind( 
            /* [retval][out] */ COREWEBVIEW2_WEB_RESOURCE_REQUEST_SOURCE_KINDS *requestedSourceKind) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICoreWebView2ExperimentalWebResourceRequestedEventArgsVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreWebView2ExperimentalWebResourceRequestedEventArgs * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreWebView2ExperimentalWebResourceRequestedEventArgs * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreWebView2ExperimentalWebResourceRequestedEventArgs * This);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalWebResourceRequestedEventArgs, get_RequestedSourceKind)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_RequestedSourceKind )( 
            ICoreWebView2ExperimentalWebResourceRequestedEventArgs * This,
            /* [retval][out] */ COREWEBVIEW2_WEB_RESOURCE_REQUEST_SOURCE_KINDS *requestedSourceKind);
        
        END_INTERFACE
    } ICoreWebView2ExperimentalWebResourceRequestedEventArgsVtbl;

    interface ICoreWebView2ExperimentalWebResourceRequestedEventArgs
    {
        CONST_VTBL struct ICoreWebView2ExperimentalWebResourceRequestedEventArgsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreWebView2ExperimentalWebResourceRequestedEventArgs_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreWebView2ExperimentalWebResourceRequestedEventArgs_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreWebView2ExperimentalWebResourceRequestedEventArgs_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreWebView2ExperimentalWebResourceRequestedEventArgs_get_RequestedSourceKind(This,requestedSourceKind)	\
    ( (This)->lpVtbl -> get_RequestedSourceKind(This,requestedSourceKind) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreWebView2ExperimentalWebResourceRequestedEventArgs_INTERFACE_DEFINED__ */


#ifndef __ICoreWebView2ExperimentalNavigationStartingEventArgs2_INTERFACE_DEFINED__
#define __ICoreWebView2ExperimentalNavigationStartingEventArgs2_INTERFACE_DEFINED__

/* interface ICoreWebView2ExperimentalNavigationStartingEventArgs2 */
/* [unique][object][uuid] */ 


EXTERN_C __declspec(selectany) const IID IID_ICoreWebView2ExperimentalNavigationStartingEventArgs2 = {0x924C5E75,0x3D03,0x44DE,{0xA4,0x4F,0xF5,0x8C,0x98,0x93,0x6E,0xD0}};

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("924C5E75-3D03-44DE-A44F-F58C98936ED0")
    ICoreWebView2ExperimentalNavigationStartingEventArgs2 : public IUnknown
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_NavigationKind( 
            /* [retval][out] */ COREWEBVIEW2_NAVIGATION_KIND *navigation_kind) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICoreWebView2ExperimentalNavigationStartingEventArgs2Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreWebView2ExperimentalNavigationStartingEventArgs2 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreWebView2ExperimentalNavigationStartingEventArgs2 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreWebView2ExperimentalNavigationStartingEventArgs2 * This);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalNavigationStartingEventArgs2, get_NavigationKind)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_NavigationKind )( 
            ICoreWebView2ExperimentalNavigationStartingEventArgs2 * This,
            /* [retval][out] */ COREWEBVIEW2_NAVIGATION_KIND *navigation_kind);
        
        END_INTERFACE
    } ICoreWebView2ExperimentalNavigationStartingEventArgs2Vtbl;

    interface ICoreWebView2ExperimentalNavigationStartingEventArgs2
    {
        CONST_VTBL struct ICoreWebView2ExperimentalNavigationStartingEventArgs2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreWebView2ExperimentalNavigationStartingEventArgs2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreWebView2ExperimentalNavigationStartingEventArgs2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreWebView2ExperimentalNavigationStartingEventArgs2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreWebView2ExperimentalNavigationStartingEventArgs2_get_NavigationKind(This,navigation_kind)	\
    ( (This)->lpVtbl -> get_NavigationKind(This,navigation_kind) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreWebView2ExperimentalNavigationStartingEventArgs2_INTERFACE_DEFINED__ */


#ifndef __ICoreWebView2ExperimentalRenderAdapterLUIDChangedEventHandler_INTERFACE_DEFINED__
#define __ICoreWebView2ExperimentalRenderAdapterLUIDChangedEventHandler_INTERFACE_DEFINED__

/* interface ICoreWebView2ExperimentalRenderAdapterLUIDChangedEventHandler */
/* [unique][object][uuid] */ 


EXTERN_C __declspec(selectany) const IID IID_ICoreWebView2ExperimentalRenderAdapterLUIDChangedEventHandler = {0x431721e0,0x0f18,0x4d7b,{0xbd,0x4d,0xe5,0xb1,0x52,0x2b,0xb1,0x10}};

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("431721e0-0f18-4d7b-bd4d-e5b1522bb110")
    ICoreWebView2ExperimentalRenderAdapterLUIDChangedEventHandler : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Invoke( 
            /* [in] */ ICoreWebView2ExperimentalEnvironment12 *sender,
            /* [in] */ IUnknown *args) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICoreWebView2ExperimentalRenderAdapterLUIDChangedEventHandlerVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreWebView2ExperimentalRenderAdapterLUIDChangedEventHandler * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreWebView2ExperimentalRenderAdapterLUIDChangedEventHandler * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreWebView2ExperimentalRenderAdapterLUIDChangedEventHandler * This);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalRenderAdapterLUIDChangedEventHandler, Invoke)
        HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICoreWebView2ExperimentalRenderAdapterLUIDChangedEventHandler * This,
            /* [in] */ ICoreWebView2ExperimentalEnvironment12 *sender,
            /* [in] */ IUnknown *args);
        
        END_INTERFACE
    } ICoreWebView2ExperimentalRenderAdapterLUIDChangedEventHandlerVtbl;

    interface ICoreWebView2ExperimentalRenderAdapterLUIDChangedEventHandler
    {
        CONST_VTBL struct ICoreWebView2ExperimentalRenderAdapterLUIDChangedEventHandlerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreWebView2ExperimentalRenderAdapterLUIDChangedEventHandler_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreWebView2ExperimentalRenderAdapterLUIDChangedEventHandler_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreWebView2ExperimentalRenderAdapterLUIDChangedEventHandler_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreWebView2ExperimentalRenderAdapterLUIDChangedEventHandler_Invoke(This,sender,args)	\
    ( (This)->lpVtbl -> Invoke(This,sender,args) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreWebView2ExperimentalRenderAdapterLUIDChangedEventHandler_INTERFACE_DEFINED__ */


#ifndef __ICoreWebView2ExperimentalTextureStream_INTERFACE_DEFINED__
#define __ICoreWebView2ExperimentalTextureStream_INTERFACE_DEFINED__

/* interface ICoreWebView2ExperimentalTextureStream */
/* [unique][object][uuid] */ 


EXTERN_C __declspec(selectany) const IID IID_ICoreWebView2ExperimentalTextureStream = {0xafca8431,0x633f,0x4528,{0xab,0xfe,0x7f,0xc3,0xbe,0xdd,0x89,0x62}};

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("afca8431-633f-4528-abfe-7fc3bedd8962")
    ICoreWebView2ExperimentalTextureStream : public IUnknown
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Id( 
            /* [retval][out] */ LPWSTR *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddAllowedOrigin( 
            /* [in] */ LPCWSTR origin,
            /* [in] */ BOOL value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveAllowedOrigin( 
            /* [in] */ LPCWSTR origin) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE add_StartRequested( 
            /* [in] */ ICoreWebView2ExperimentalTextureStreamStartRequestedEventHandler *eventHandler,
            /* [out] */ EventRegistrationToken *token) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE remove_StartRequested( 
            /* [in] */ EventRegistrationToken token) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE add_Stopped( 
            /* [in] */ ICoreWebView2ExperimentalTextureStreamStoppedEventHandler *eventHandler,
            /* [out] */ EventRegistrationToken *token) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE remove_Stopped( 
            /* [in] */ EventRegistrationToken token) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateTexture( 
            /* [in] */ UINT32 widthInTexels,
            /* [in] */ UINT32 heightInTexels,
            /* [retval][out] */ ICoreWebView2ExperimentalTexture **texture) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAvailableTexture( 
            /* [retval][out] */ ICoreWebView2ExperimentalTexture **texture) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CloseTexture( 
            /* [in] */ ICoreWebView2ExperimentalTexture *texture) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PresentTexture( 
            /* [in] */ ICoreWebView2ExperimentalTexture *texture) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Stop( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE add_ErrorReceived( 
            /* [in] */ ICoreWebView2ExperimentalTextureStreamErrorReceivedEventHandler *eventHandler,
            /* [out] */ EventRegistrationToken *token) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE remove_ErrorReceived( 
            /* [in] */ EventRegistrationToken token) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetD3DDevice( 
            /* [in] */ IUnknown *d3dDevice) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE add_WebTextureReceived( 
            /* [in] */ ICoreWebView2ExperimentalTextureStreamWebTextureReceivedEventHandler *eventHandler,
            /* [out] */ EventRegistrationToken *token) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE remove_WebTextureReceived( 
            /* [in] */ EventRegistrationToken token) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE add_WebTextureStreamStopped( 
            /* [in] */ ICoreWebView2ExperimentalTextureStreamWebTextureStreamStoppedEventHandler *eventHandler,
            /* [out] */ EventRegistrationToken *token) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE remove_WebTextureStreamStopped( 
            /* [in] */ EventRegistrationToken token) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICoreWebView2ExperimentalTextureStreamVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreWebView2ExperimentalTextureStream * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreWebView2ExperimentalTextureStream * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreWebView2ExperimentalTextureStream * This);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalTextureStream, get_Id)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Id )( 
            ICoreWebView2ExperimentalTextureStream * This,
            /* [retval][out] */ LPWSTR *value);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalTextureStream, AddAllowedOrigin)
        HRESULT ( STDMETHODCALLTYPE *AddAllowedOrigin )( 
            ICoreWebView2ExperimentalTextureStream * This,
            /* [in] */ LPCWSTR origin,
            /* [in] */ BOOL value);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalTextureStream, RemoveAllowedOrigin)
        HRESULT ( STDMETHODCALLTYPE *RemoveAllowedOrigin )( 
            ICoreWebView2ExperimentalTextureStream * This,
            /* [in] */ LPCWSTR origin);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalTextureStream, add_StartRequested)
        HRESULT ( STDMETHODCALLTYPE *add_StartRequested )( 
            ICoreWebView2ExperimentalTextureStream * This,
            /* [in] */ ICoreWebView2ExperimentalTextureStreamStartRequestedEventHandler *eventHandler,
            /* [out] */ EventRegistrationToken *token);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalTextureStream, remove_StartRequested)
        HRESULT ( STDMETHODCALLTYPE *remove_StartRequested )( 
            ICoreWebView2ExperimentalTextureStream * This,
            /* [in] */ EventRegistrationToken token);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalTextureStream, add_Stopped)
        HRESULT ( STDMETHODCALLTYPE *add_Stopped )( 
            ICoreWebView2ExperimentalTextureStream * This,
            /* [in] */ ICoreWebView2ExperimentalTextureStreamStoppedEventHandler *eventHandler,
            /* [out] */ EventRegistrationToken *token);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalTextureStream, remove_Stopped)
        HRESULT ( STDMETHODCALLTYPE *remove_Stopped )( 
            ICoreWebView2ExperimentalTextureStream * This,
            /* [in] */ EventRegistrationToken token);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalTextureStream, CreateTexture)
        HRESULT ( STDMETHODCALLTYPE *CreateTexture )( 
            ICoreWebView2ExperimentalTextureStream * This,
            /* [in] */ UINT32 widthInTexels,
            /* [in] */ UINT32 heightInTexels,
            /* [retval][out] */ ICoreWebView2ExperimentalTexture **texture);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalTextureStream, GetAvailableTexture)
        HRESULT ( STDMETHODCALLTYPE *GetAvailableTexture )( 
            ICoreWebView2ExperimentalTextureStream * This,
            /* [retval][out] */ ICoreWebView2ExperimentalTexture **texture);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalTextureStream, CloseTexture)
        HRESULT ( STDMETHODCALLTYPE *CloseTexture )( 
            ICoreWebView2ExperimentalTextureStream * This,
            /* [in] */ ICoreWebView2ExperimentalTexture *texture);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalTextureStream, PresentTexture)
        HRESULT ( STDMETHODCALLTYPE *PresentTexture )( 
            ICoreWebView2ExperimentalTextureStream * This,
            /* [in] */ ICoreWebView2ExperimentalTexture *texture);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalTextureStream, Stop)
        HRESULT ( STDMETHODCALLTYPE *Stop )( 
            ICoreWebView2ExperimentalTextureStream * This);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalTextureStream, add_ErrorReceived)
        HRESULT ( STDMETHODCALLTYPE *add_ErrorReceived )( 
            ICoreWebView2ExperimentalTextureStream * This,
            /* [in] */ ICoreWebView2ExperimentalTextureStreamErrorReceivedEventHandler *eventHandler,
            /* [out] */ EventRegistrationToken *token);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalTextureStream, remove_ErrorReceived)
        HRESULT ( STDMETHODCALLTYPE *remove_ErrorReceived )( 
            ICoreWebView2ExperimentalTextureStream * This,
            /* [in] */ EventRegistrationToken token);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalTextureStream, SetD3DDevice)
        HRESULT ( STDMETHODCALLTYPE *SetD3DDevice )( 
            ICoreWebView2ExperimentalTextureStream * This,
            /* [in] */ IUnknown *d3dDevice);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalTextureStream, add_WebTextureReceived)
        HRESULT ( STDMETHODCALLTYPE *add_WebTextureReceived )( 
            ICoreWebView2ExperimentalTextureStream * This,
            /* [in] */ ICoreWebView2ExperimentalTextureStreamWebTextureReceivedEventHandler *eventHandler,
            /* [out] */ EventRegistrationToken *token);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalTextureStream, remove_WebTextureReceived)
        HRESULT ( STDMETHODCALLTYPE *remove_WebTextureReceived )( 
            ICoreWebView2ExperimentalTextureStream * This,
            /* [in] */ EventRegistrationToken token);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalTextureStream, add_WebTextureStreamStopped)
        HRESULT ( STDMETHODCALLTYPE *add_WebTextureStreamStopped )( 
            ICoreWebView2ExperimentalTextureStream * This,
            /* [in] */ ICoreWebView2ExperimentalTextureStreamWebTextureStreamStoppedEventHandler *eventHandler,
            /* [out] */ EventRegistrationToken *token);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalTextureStream, remove_WebTextureStreamStopped)
        HRESULT ( STDMETHODCALLTYPE *remove_WebTextureStreamStopped )( 
            ICoreWebView2ExperimentalTextureStream * This,
            /* [in] */ EventRegistrationToken token);
        
        END_INTERFACE
    } ICoreWebView2ExperimentalTextureStreamVtbl;

    interface ICoreWebView2ExperimentalTextureStream
    {
        CONST_VTBL struct ICoreWebView2ExperimentalTextureStreamVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreWebView2ExperimentalTextureStream_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreWebView2ExperimentalTextureStream_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreWebView2ExperimentalTextureStream_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreWebView2ExperimentalTextureStream_get_Id(This,value)	\
    ( (This)->lpVtbl -> get_Id(This,value) ) 

#define ICoreWebView2ExperimentalTextureStream_AddAllowedOrigin(This,origin,value)	\
    ( (This)->lpVtbl -> AddAllowedOrigin(This,origin,value) ) 

#define ICoreWebView2ExperimentalTextureStream_RemoveAllowedOrigin(This,origin)	\
    ( (This)->lpVtbl -> RemoveAllowedOrigin(This,origin) ) 

#define ICoreWebView2ExperimentalTextureStream_add_StartRequested(This,eventHandler,token)	\
    ( (This)->lpVtbl -> add_StartRequested(This,eventHandler,token) ) 

#define ICoreWebView2ExperimentalTextureStream_remove_StartRequested(This,token)	\
    ( (This)->lpVtbl -> remove_StartRequested(This,token) ) 

#define ICoreWebView2ExperimentalTextureStream_add_Stopped(This,eventHandler,token)	\
    ( (This)->lpVtbl -> add_Stopped(This,eventHandler,token) ) 

#define ICoreWebView2ExperimentalTextureStream_remove_Stopped(This,token)	\
    ( (This)->lpVtbl -> remove_Stopped(This,token) ) 

#define ICoreWebView2ExperimentalTextureStream_CreateTexture(This,widthInTexels,heightInTexels,texture)	\
    ( (This)->lpVtbl -> CreateTexture(This,widthInTexels,heightInTexels,texture) ) 

#define ICoreWebView2ExperimentalTextureStream_GetAvailableTexture(This,texture)	\
    ( (This)->lpVtbl -> GetAvailableTexture(This,texture) ) 

#define ICoreWebView2ExperimentalTextureStream_CloseTexture(This,texture)	\
    ( (This)->lpVtbl -> CloseTexture(This,texture) ) 

#define ICoreWebView2ExperimentalTextureStream_PresentTexture(This,texture)	\
    ( (This)->lpVtbl -> PresentTexture(This,texture) ) 

#define ICoreWebView2ExperimentalTextureStream_Stop(This)	\
    ( (This)->lpVtbl -> Stop(This) ) 

#define ICoreWebView2ExperimentalTextureStream_add_ErrorReceived(This,eventHandler,token)	\
    ( (This)->lpVtbl -> add_ErrorReceived(This,eventHandler,token) ) 

#define ICoreWebView2ExperimentalTextureStream_remove_ErrorReceived(This,token)	\
    ( (This)->lpVtbl -> remove_ErrorReceived(This,token) ) 

#define ICoreWebView2ExperimentalTextureStream_SetD3DDevice(This,d3dDevice)	\
    ( (This)->lpVtbl -> SetD3DDevice(This,d3dDevice) ) 

#define ICoreWebView2ExperimentalTextureStream_add_WebTextureReceived(This,eventHandler,token)	\
    ( (This)->lpVtbl -> add_WebTextureReceived(This,eventHandler,token) ) 

#define ICoreWebView2ExperimentalTextureStream_remove_WebTextureReceived(This,token)	\
    ( (This)->lpVtbl -> remove_WebTextureReceived(This,token) ) 

#define ICoreWebView2ExperimentalTextureStream_add_WebTextureStreamStopped(This,eventHandler,token)	\
    ( (This)->lpVtbl -> add_WebTextureStreamStopped(This,eventHandler,token) ) 

#define ICoreWebView2ExperimentalTextureStream_remove_WebTextureStreamStopped(This,token)	\
    ( (This)->lpVtbl -> remove_WebTextureStreamStopped(This,token) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreWebView2ExperimentalTextureStream_INTERFACE_DEFINED__ */


#ifndef __ICoreWebView2ExperimentalTexture_INTERFACE_DEFINED__
#define __ICoreWebView2ExperimentalTexture_INTERFACE_DEFINED__

/* interface ICoreWebView2ExperimentalTexture */
/* [unique][object][uuid] */ 


EXTERN_C __declspec(selectany) const IID IID_ICoreWebView2ExperimentalTexture = {0x0836f09c,0x34bd,0x47bf,{0x91,0x4a,0x99,0xfb,0x56,0xae,0x2d,0x07}};

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0836f09c-34bd-47bf-914a-99fb56ae2d07")
    ICoreWebView2ExperimentalTexture : public IUnknown
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Handle( 
            /* [retval][out] */ HANDLE *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Resource( 
            /* [retval][out] */ IUnknown **value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Timestamp( 
            /* [retval][out] */ UINT64 *value) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_Timestamp( 
            /* [in] */ UINT64 value) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICoreWebView2ExperimentalTextureVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreWebView2ExperimentalTexture * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreWebView2ExperimentalTexture * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreWebView2ExperimentalTexture * This);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalTexture, get_Handle)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Handle )( 
            ICoreWebView2ExperimentalTexture * This,
            /* [retval][out] */ HANDLE *value);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalTexture, get_Resource)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Resource )( 
            ICoreWebView2ExperimentalTexture * This,
            /* [retval][out] */ IUnknown **value);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalTexture, get_Timestamp)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Timestamp )( 
            ICoreWebView2ExperimentalTexture * This,
            /* [retval][out] */ UINT64 *value);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalTexture, put_Timestamp)
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_Timestamp )( 
            ICoreWebView2ExperimentalTexture * This,
            /* [in] */ UINT64 value);
        
        END_INTERFACE
    } ICoreWebView2ExperimentalTextureVtbl;

    interface ICoreWebView2ExperimentalTexture
    {
        CONST_VTBL struct ICoreWebView2ExperimentalTextureVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreWebView2ExperimentalTexture_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreWebView2ExperimentalTexture_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreWebView2ExperimentalTexture_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreWebView2ExperimentalTexture_get_Handle(This,value)	\
    ( (This)->lpVtbl -> get_Handle(This,value) ) 

#define ICoreWebView2ExperimentalTexture_get_Resource(This,value)	\
    ( (This)->lpVtbl -> get_Resource(This,value) ) 

#define ICoreWebView2ExperimentalTexture_get_Timestamp(This,value)	\
    ( (This)->lpVtbl -> get_Timestamp(This,value) ) 

#define ICoreWebView2ExperimentalTexture_put_Timestamp(This,value)	\
    ( (This)->lpVtbl -> put_Timestamp(This,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreWebView2ExperimentalTexture_INTERFACE_DEFINED__ */


#ifndef __ICoreWebView2ExperimentalTextureStreamErrorReceivedEventArgs_INTERFACE_DEFINED__
#define __ICoreWebView2ExperimentalTextureStreamErrorReceivedEventArgs_INTERFACE_DEFINED__

/* interface ICoreWebView2ExperimentalTextureStreamErrorReceivedEventArgs */
/* [unique][object][uuid] */ 


EXTERN_C __declspec(selectany) const IID IID_ICoreWebView2ExperimentalTextureStreamErrorReceivedEventArgs = {0x0e1730c1,0x03df,0x4ad2,{0xb8,0x47,0xbe,0x4d,0x63,0xad,0xf7,0x00}};

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0e1730c1-03df-4ad2-b847-be4d63adf700")
    ICoreWebView2ExperimentalTextureStreamErrorReceivedEventArgs : public IUnknown
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Kind( 
            /* [retval][out] */ COREWEBVIEW2_TEXTURE_STREAM_ERROR_KIND *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Texture( 
            /* [retval][out] */ ICoreWebView2ExperimentalTexture **value) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICoreWebView2ExperimentalTextureStreamErrorReceivedEventArgsVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreWebView2ExperimentalTextureStreamErrorReceivedEventArgs * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreWebView2ExperimentalTextureStreamErrorReceivedEventArgs * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreWebView2ExperimentalTextureStreamErrorReceivedEventArgs * This);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalTextureStreamErrorReceivedEventArgs, get_Kind)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Kind )( 
            ICoreWebView2ExperimentalTextureStreamErrorReceivedEventArgs * This,
            /* [retval][out] */ COREWEBVIEW2_TEXTURE_STREAM_ERROR_KIND *value);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalTextureStreamErrorReceivedEventArgs, get_Texture)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Texture )( 
            ICoreWebView2ExperimentalTextureStreamErrorReceivedEventArgs * This,
            /* [retval][out] */ ICoreWebView2ExperimentalTexture **value);
        
        END_INTERFACE
    } ICoreWebView2ExperimentalTextureStreamErrorReceivedEventArgsVtbl;

    interface ICoreWebView2ExperimentalTextureStreamErrorReceivedEventArgs
    {
        CONST_VTBL struct ICoreWebView2ExperimentalTextureStreamErrorReceivedEventArgsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreWebView2ExperimentalTextureStreamErrorReceivedEventArgs_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreWebView2ExperimentalTextureStreamErrorReceivedEventArgs_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreWebView2ExperimentalTextureStreamErrorReceivedEventArgs_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreWebView2ExperimentalTextureStreamErrorReceivedEventArgs_get_Kind(This,value)	\
    ( (This)->lpVtbl -> get_Kind(This,value) ) 

#define ICoreWebView2ExperimentalTextureStreamErrorReceivedEventArgs_get_Texture(This,value)	\
    ( (This)->lpVtbl -> get_Texture(This,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreWebView2ExperimentalTextureStreamErrorReceivedEventArgs_INTERFACE_DEFINED__ */


#ifndef __ICoreWebView2ExperimentalTextureStreamErrorReceivedEventHandler_INTERFACE_DEFINED__
#define __ICoreWebView2ExperimentalTextureStreamErrorReceivedEventHandler_INTERFACE_DEFINED__

/* interface ICoreWebView2ExperimentalTextureStreamErrorReceivedEventHandler */
/* [unique][object][uuid] */ 


EXTERN_C __declspec(selectany) const IID IID_ICoreWebView2ExperimentalTextureStreamErrorReceivedEventHandler = {0x52cb8898,0xc711,0x401a,{0x8f,0x97,0x36,0x46,0x83,0x1b,0xa7,0x2d}};

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("52cb8898-c711-401a-8f97-3646831ba72d")
    ICoreWebView2ExperimentalTextureStreamErrorReceivedEventHandler : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Invoke( 
            /* [in] */ ICoreWebView2ExperimentalTextureStream *sender,
            /* [in] */ ICoreWebView2ExperimentalTextureStreamErrorReceivedEventArgs *args) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICoreWebView2ExperimentalTextureStreamErrorReceivedEventHandlerVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreWebView2ExperimentalTextureStreamErrorReceivedEventHandler * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreWebView2ExperimentalTextureStreamErrorReceivedEventHandler * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreWebView2ExperimentalTextureStreamErrorReceivedEventHandler * This);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalTextureStreamErrorReceivedEventHandler, Invoke)
        HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICoreWebView2ExperimentalTextureStreamErrorReceivedEventHandler * This,
            /* [in] */ ICoreWebView2ExperimentalTextureStream *sender,
            /* [in] */ ICoreWebView2ExperimentalTextureStreamErrorReceivedEventArgs *args);
        
        END_INTERFACE
    } ICoreWebView2ExperimentalTextureStreamErrorReceivedEventHandlerVtbl;

    interface ICoreWebView2ExperimentalTextureStreamErrorReceivedEventHandler
    {
        CONST_VTBL struct ICoreWebView2ExperimentalTextureStreamErrorReceivedEventHandlerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreWebView2ExperimentalTextureStreamErrorReceivedEventHandler_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreWebView2ExperimentalTextureStreamErrorReceivedEventHandler_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreWebView2ExperimentalTextureStreamErrorReceivedEventHandler_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreWebView2ExperimentalTextureStreamErrorReceivedEventHandler_Invoke(This,sender,args)	\
    ( (This)->lpVtbl -> Invoke(This,sender,args) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreWebView2ExperimentalTextureStreamErrorReceivedEventHandler_INTERFACE_DEFINED__ */


#ifndef __ICoreWebView2ExperimentalTextureStreamStartRequestedEventHandler_INTERFACE_DEFINED__
#define __ICoreWebView2ExperimentalTextureStreamStartRequestedEventHandler_INTERFACE_DEFINED__

/* interface ICoreWebView2ExperimentalTextureStreamStartRequestedEventHandler */
/* [unique][object][uuid] */ 


EXTERN_C __declspec(selectany) const IID IID_ICoreWebView2ExperimentalTextureStreamStartRequestedEventHandler = {0x62d09330,0x00a9,0x41bf,{0xa9,0xae,0x55,0xaa,0xef,0x8b,0x3c,0x44}};

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("62d09330-00a9-41bf-a9ae-55aaef8b3c44")
    ICoreWebView2ExperimentalTextureStreamStartRequestedEventHandler : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Invoke( 
            /* [in] */ ICoreWebView2ExperimentalTextureStream *sender,
            /* [in] */ IUnknown *args) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICoreWebView2ExperimentalTextureStreamStartRequestedEventHandlerVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreWebView2ExperimentalTextureStreamStartRequestedEventHandler * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreWebView2ExperimentalTextureStreamStartRequestedEventHandler * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreWebView2ExperimentalTextureStreamStartRequestedEventHandler * This);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalTextureStreamStartRequestedEventHandler, Invoke)
        HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICoreWebView2ExperimentalTextureStreamStartRequestedEventHandler * This,
            /* [in] */ ICoreWebView2ExperimentalTextureStream *sender,
            /* [in] */ IUnknown *args);
        
        END_INTERFACE
    } ICoreWebView2ExperimentalTextureStreamStartRequestedEventHandlerVtbl;

    interface ICoreWebView2ExperimentalTextureStreamStartRequestedEventHandler
    {
        CONST_VTBL struct ICoreWebView2ExperimentalTextureStreamStartRequestedEventHandlerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreWebView2ExperimentalTextureStreamStartRequestedEventHandler_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreWebView2ExperimentalTextureStreamStartRequestedEventHandler_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreWebView2ExperimentalTextureStreamStartRequestedEventHandler_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreWebView2ExperimentalTextureStreamStartRequestedEventHandler_Invoke(This,sender,args)	\
    ( (This)->lpVtbl -> Invoke(This,sender,args) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreWebView2ExperimentalTextureStreamStartRequestedEventHandler_INTERFACE_DEFINED__ */


#ifndef __ICoreWebView2ExperimentalTextureStreamStoppedEventHandler_INTERFACE_DEFINED__
#define __ICoreWebView2ExperimentalTextureStreamStoppedEventHandler_INTERFACE_DEFINED__

/* interface ICoreWebView2ExperimentalTextureStreamStoppedEventHandler */
/* [unique][object][uuid] */ 


EXTERN_C __declspec(selectany) const IID IID_ICoreWebView2ExperimentalTextureStreamStoppedEventHandler = {0x4111102a,0xd19f,0x4438,{0xaf,0x46,0xef,0xc5,0x63,0xb2,0xb9,0xcf}};

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4111102a-d19f-4438-af46-efc563b2b9cf")
    ICoreWebView2ExperimentalTextureStreamStoppedEventHandler : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Invoke( 
            /* [in] */ ICoreWebView2ExperimentalTextureStream *sender,
            /* [in] */ IUnknown *args) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICoreWebView2ExperimentalTextureStreamStoppedEventHandlerVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreWebView2ExperimentalTextureStreamStoppedEventHandler * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreWebView2ExperimentalTextureStreamStoppedEventHandler * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreWebView2ExperimentalTextureStreamStoppedEventHandler * This);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalTextureStreamStoppedEventHandler, Invoke)
        HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICoreWebView2ExperimentalTextureStreamStoppedEventHandler * This,
            /* [in] */ ICoreWebView2ExperimentalTextureStream *sender,
            /* [in] */ IUnknown *args);
        
        END_INTERFACE
    } ICoreWebView2ExperimentalTextureStreamStoppedEventHandlerVtbl;

    interface ICoreWebView2ExperimentalTextureStreamStoppedEventHandler
    {
        CONST_VTBL struct ICoreWebView2ExperimentalTextureStreamStoppedEventHandlerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreWebView2ExperimentalTextureStreamStoppedEventHandler_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreWebView2ExperimentalTextureStreamStoppedEventHandler_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreWebView2ExperimentalTextureStreamStoppedEventHandler_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreWebView2ExperimentalTextureStreamStoppedEventHandler_Invoke(This,sender,args)	\
    ( (This)->lpVtbl -> Invoke(This,sender,args) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreWebView2ExperimentalTextureStreamStoppedEventHandler_INTERFACE_DEFINED__ */


#ifndef __ICoreWebView2ExperimentalTextureStreamWebTextureReceivedEventArgs_INTERFACE_DEFINED__
#define __ICoreWebView2ExperimentalTextureStreamWebTextureReceivedEventArgs_INTERFACE_DEFINED__

/* interface ICoreWebView2ExperimentalTextureStreamWebTextureReceivedEventArgs */
/* [unique][object][uuid] */ 


EXTERN_C __declspec(selectany) const IID IID_ICoreWebView2ExperimentalTextureStreamWebTextureReceivedEventArgs = {0xa4c2fa3a,0x295a,0x11ed,{0xa2,0x61,0x02,0x42,0xac,0x12,0x00,0x02}};

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("a4c2fa3a-295a-11ed-a261-0242ac120002")
    ICoreWebView2ExperimentalTextureStreamWebTextureReceivedEventArgs : public IUnknown
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_WebTexture( 
            /* [retval][out] */ ICoreWebView2ExperimentalWebTexture **value) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICoreWebView2ExperimentalTextureStreamWebTextureReceivedEventArgsVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreWebView2ExperimentalTextureStreamWebTextureReceivedEventArgs * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreWebView2ExperimentalTextureStreamWebTextureReceivedEventArgs * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreWebView2ExperimentalTextureStreamWebTextureReceivedEventArgs * This);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalTextureStreamWebTextureReceivedEventArgs, get_WebTexture)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_WebTexture )( 
            ICoreWebView2ExperimentalTextureStreamWebTextureReceivedEventArgs * This,
            /* [retval][out] */ ICoreWebView2ExperimentalWebTexture **value);
        
        END_INTERFACE
    } ICoreWebView2ExperimentalTextureStreamWebTextureReceivedEventArgsVtbl;

    interface ICoreWebView2ExperimentalTextureStreamWebTextureReceivedEventArgs
    {
        CONST_VTBL struct ICoreWebView2ExperimentalTextureStreamWebTextureReceivedEventArgsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreWebView2ExperimentalTextureStreamWebTextureReceivedEventArgs_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreWebView2ExperimentalTextureStreamWebTextureReceivedEventArgs_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreWebView2ExperimentalTextureStreamWebTextureReceivedEventArgs_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreWebView2ExperimentalTextureStreamWebTextureReceivedEventArgs_get_WebTexture(This,value)	\
    ( (This)->lpVtbl -> get_WebTexture(This,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreWebView2ExperimentalTextureStreamWebTextureReceivedEventArgs_INTERFACE_DEFINED__ */


#ifndef __ICoreWebView2ExperimentalTextureStreamWebTextureReceivedEventHandler_INTERFACE_DEFINED__
#define __ICoreWebView2ExperimentalTextureStreamWebTextureReceivedEventHandler_INTERFACE_DEFINED__

/* interface ICoreWebView2ExperimentalTextureStreamWebTextureReceivedEventHandler */
/* [unique][object][uuid] */ 


EXTERN_C __declspec(selectany) const IID IID_ICoreWebView2ExperimentalTextureStreamWebTextureReceivedEventHandler = {0x9ea4228c,0x295a,0x11ed,{0xa2,0x61,0x02,0x42,0xac,0x12,0x00,0x02}};

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9ea4228c-295a-11ed-a261-0242ac120002")
    ICoreWebView2ExperimentalTextureStreamWebTextureReceivedEventHandler : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Invoke( 
            /* [in] */ ICoreWebView2ExperimentalTextureStream *sender,
            /* [in] */ ICoreWebView2ExperimentalTextureStreamWebTextureReceivedEventArgs *args) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICoreWebView2ExperimentalTextureStreamWebTextureReceivedEventHandlerVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreWebView2ExperimentalTextureStreamWebTextureReceivedEventHandler * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreWebView2ExperimentalTextureStreamWebTextureReceivedEventHandler * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreWebView2ExperimentalTextureStreamWebTextureReceivedEventHandler * This);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalTextureStreamWebTextureReceivedEventHandler, Invoke)
        HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICoreWebView2ExperimentalTextureStreamWebTextureReceivedEventHandler * This,
            /* [in] */ ICoreWebView2ExperimentalTextureStream *sender,
            /* [in] */ ICoreWebView2ExperimentalTextureStreamWebTextureReceivedEventArgs *args);
        
        END_INTERFACE
    } ICoreWebView2ExperimentalTextureStreamWebTextureReceivedEventHandlerVtbl;

    interface ICoreWebView2ExperimentalTextureStreamWebTextureReceivedEventHandler
    {
        CONST_VTBL struct ICoreWebView2ExperimentalTextureStreamWebTextureReceivedEventHandlerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreWebView2ExperimentalTextureStreamWebTextureReceivedEventHandler_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreWebView2ExperimentalTextureStreamWebTextureReceivedEventHandler_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreWebView2ExperimentalTextureStreamWebTextureReceivedEventHandler_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreWebView2ExperimentalTextureStreamWebTextureReceivedEventHandler_Invoke(This,sender,args)	\
    ( (This)->lpVtbl -> Invoke(This,sender,args) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreWebView2ExperimentalTextureStreamWebTextureReceivedEventHandler_INTERFACE_DEFINED__ */


#ifndef __ICoreWebView2ExperimentalTextureStreamWebTextureStreamStoppedEventHandler_INTERFACE_DEFINED__
#define __ICoreWebView2ExperimentalTextureStreamWebTextureStreamStoppedEventHandler_INTERFACE_DEFINED__

/* interface ICoreWebView2ExperimentalTextureStreamWebTextureStreamStoppedEventHandler */
/* [unique][object][uuid] */ 


EXTERN_C __declspec(selectany) const IID IID_ICoreWebView2ExperimentalTextureStreamWebTextureStreamStoppedEventHandler = {0x77eb4638,0x2f05,0x11ed,{0xa2,0x61,0x02,0x42,0xac,0x12,0x00,0x02}};

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("77eb4638-2f05-11ed-a261-0242ac120002")
    ICoreWebView2ExperimentalTextureStreamWebTextureStreamStoppedEventHandler : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Invoke( 
            /* [in] */ ICoreWebView2ExperimentalTextureStream *sender,
            /* [in] */ IUnknown *args) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICoreWebView2ExperimentalTextureStreamWebTextureStreamStoppedEventHandlerVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreWebView2ExperimentalTextureStreamWebTextureStreamStoppedEventHandler * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreWebView2ExperimentalTextureStreamWebTextureStreamStoppedEventHandler * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreWebView2ExperimentalTextureStreamWebTextureStreamStoppedEventHandler * This);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalTextureStreamWebTextureStreamStoppedEventHandler, Invoke)
        HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICoreWebView2ExperimentalTextureStreamWebTextureStreamStoppedEventHandler * This,
            /* [in] */ ICoreWebView2ExperimentalTextureStream *sender,
            /* [in] */ IUnknown *args);
        
        END_INTERFACE
    } ICoreWebView2ExperimentalTextureStreamWebTextureStreamStoppedEventHandlerVtbl;

    interface ICoreWebView2ExperimentalTextureStreamWebTextureStreamStoppedEventHandler
    {
        CONST_VTBL struct ICoreWebView2ExperimentalTextureStreamWebTextureStreamStoppedEventHandlerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreWebView2ExperimentalTextureStreamWebTextureStreamStoppedEventHandler_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreWebView2ExperimentalTextureStreamWebTextureStreamStoppedEventHandler_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreWebView2ExperimentalTextureStreamWebTextureStreamStoppedEventHandler_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreWebView2ExperimentalTextureStreamWebTextureStreamStoppedEventHandler_Invoke(This,sender,args)	\
    ( (This)->lpVtbl -> Invoke(This,sender,args) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreWebView2ExperimentalTextureStreamWebTextureStreamStoppedEventHandler_INTERFACE_DEFINED__ */


#ifndef __ICoreWebView2ExperimentalWebTexture_INTERFACE_DEFINED__
#define __ICoreWebView2ExperimentalWebTexture_INTERFACE_DEFINED__

/* interface ICoreWebView2ExperimentalWebTexture */
/* [unique][object][uuid] */ 


EXTERN_C __declspec(selectany) const IID IID_ICoreWebView2ExperimentalWebTexture = {0xb94265ae,0x4c1e,0x11ed,{0xbd,0xc3,0x02,0x42,0xac,0x12,0x00,0x02}};

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("b94265ae-4c1e-11ed-bdc3-0242ac120002")
    ICoreWebView2ExperimentalWebTexture : public IUnknown
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Handle( 
            /* [retval][out] */ HANDLE *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Resource( 
            /* [retval][out] */ IUnknown **value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Timestamp( 
            /* [retval][out] */ UINT64 *value) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICoreWebView2ExperimentalWebTextureVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreWebView2ExperimentalWebTexture * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreWebView2ExperimentalWebTexture * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreWebView2ExperimentalWebTexture * This);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalWebTexture, get_Handle)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Handle )( 
            ICoreWebView2ExperimentalWebTexture * This,
            /* [retval][out] */ HANDLE *value);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalWebTexture, get_Resource)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Resource )( 
            ICoreWebView2ExperimentalWebTexture * This,
            /* [retval][out] */ IUnknown **value);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalWebTexture, get_Timestamp)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Timestamp )( 
            ICoreWebView2ExperimentalWebTexture * This,
            /* [retval][out] */ UINT64 *value);
        
        END_INTERFACE
    } ICoreWebView2ExperimentalWebTextureVtbl;

    interface ICoreWebView2ExperimentalWebTexture
    {
        CONST_VTBL struct ICoreWebView2ExperimentalWebTextureVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreWebView2ExperimentalWebTexture_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreWebView2ExperimentalWebTexture_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreWebView2ExperimentalWebTexture_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreWebView2ExperimentalWebTexture_get_Handle(This,value)	\
    ( (This)->lpVtbl -> get_Handle(This,value) ) 

#define ICoreWebView2ExperimentalWebTexture_get_Resource(This,value)	\
    ( (This)->lpVtbl -> get_Resource(This,value) ) 

#define ICoreWebView2ExperimentalWebTexture_get_Timestamp(This,value)	\
    ( (This)->lpVtbl -> get_Timestamp(This,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreWebView2ExperimentalWebTexture_INTERFACE_DEFINED__ */


#ifndef __ICoreWebView2ExperimentalEnvironment12_INTERFACE_DEFINED__
#define __ICoreWebView2ExperimentalEnvironment12_INTERFACE_DEFINED__

/* interface ICoreWebView2ExperimentalEnvironment12 */
/* [unique][object][uuid] */ 


EXTERN_C __declspec(selectany) const IID IID_ICoreWebView2ExperimentalEnvironment12 = {0x96c27a45,0xf142,0x4873,{0x80,0xad,0x9d,0x0c,0xd8,0x99,0xb2,0xb9}};

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("96c27a45-f142-4873-80ad-9d0cd899b2b9")
    ICoreWebView2ExperimentalEnvironment12 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CreateTextureStream( 
            /* [in] */ LPCWSTR streamId,
            /* [in] */ IUnknown *d3dDevice,
            /* [retval][out] */ ICoreWebView2ExperimentalTextureStream **value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_RenderAdapterLUID( 
            /* [retval][out] */ UINT64 *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE add_RenderAdapterLUIDChanged( 
            /* [in] */ ICoreWebView2ExperimentalRenderAdapterLUIDChangedEventHandler *eventHandler,
            /* [out] */ EventRegistrationToken *token) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE remove_RenderAdapterLUIDChanged( 
            /* [in] */ EventRegistrationToken token) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICoreWebView2ExperimentalEnvironment12Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreWebView2ExperimentalEnvironment12 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreWebView2ExperimentalEnvironment12 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreWebView2ExperimentalEnvironment12 * This);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalEnvironment12, CreateTextureStream)
        HRESULT ( STDMETHODCALLTYPE *CreateTextureStream )( 
            ICoreWebView2ExperimentalEnvironment12 * This,
            /* [in] */ LPCWSTR streamId,
            /* [in] */ IUnknown *d3dDevice,
            /* [retval][out] */ ICoreWebView2ExperimentalTextureStream **value);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalEnvironment12, get_RenderAdapterLUID)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_RenderAdapterLUID )( 
            ICoreWebView2ExperimentalEnvironment12 * This,
            /* [retval][out] */ UINT64 *value);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalEnvironment12, add_RenderAdapterLUIDChanged)
        HRESULT ( STDMETHODCALLTYPE *add_RenderAdapterLUIDChanged )( 
            ICoreWebView2ExperimentalEnvironment12 * This,
            /* [in] */ ICoreWebView2ExperimentalRenderAdapterLUIDChangedEventHandler *eventHandler,
            /* [out] */ EventRegistrationToken *token);
        
        DECLSPEC_XFGVIRT(ICoreWebView2ExperimentalEnvironment12, remove_RenderAdapterLUIDChanged)
        HRESULT ( STDMETHODCALLTYPE *remove_RenderAdapterLUIDChanged )( 
            ICoreWebView2ExperimentalEnvironment12 * This,
            /* [in] */ EventRegistrationToken token);
        
        END_INTERFACE
    } ICoreWebView2ExperimentalEnvironment12Vtbl;

    interface ICoreWebView2ExperimentalEnvironment12
    {
        CONST_VTBL struct ICoreWebView2ExperimentalEnvironment12Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreWebView2ExperimentalEnvironment12_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreWebView2ExperimentalEnvironment12_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreWebView2ExperimentalEnvironment12_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreWebView2ExperimentalEnvironment12_CreateTextureStream(This,streamId,d3dDevice,value)	\
    ( (This)->lpVtbl -> CreateTextureStream(This,streamId,d3dDevice,value) ) 

#define ICoreWebView2ExperimentalEnvironment12_get_RenderAdapterLUID(This,value)	\
    ( (This)->lpVtbl -> get_RenderAdapterLUID(This,value) ) 

#define ICoreWebView2ExperimentalEnvironment12_add_RenderAdapterLUIDChanged(This,eventHandler,token)	\
    ( (This)->lpVtbl -> add_RenderAdapterLUIDChanged(This,eventHandler,token) ) 

#define ICoreWebView2ExperimentalEnvironment12_remove_RenderAdapterLUIDChanged(This,token)	\
    ( (This)->lpVtbl -> remove_RenderAdapterLUIDChanged(This,token) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreWebView2ExperimentalEnvironment12_INTERFACE_DEFINED__ */

#endif /* __WebView2Experimental_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


