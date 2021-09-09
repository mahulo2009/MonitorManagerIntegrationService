// -*- C++ -*-
// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v2.2.0
 * TAO and the TAO IDL Compiler have been developed by:
 *       Center for Distributed Object Computing
 *       Washington University
 *       St. Louis, MO
 *       USA
 *       http://www.cs.wustl.edu/~schmidt/doc-center.html
 * and
 *       Distributed Object Computing Laboratory
 *       University of California at Irvine
 *       Irvine, CA
 *       USA
 * and
 *       Institute for Software Integrated Systems
 *       Vanderbilt University
 *       Nashville, TN
 *       USA
 *       http://www.isis.vanderbilt.edu/
 *
 * Information about TAO is available at:
 *     http://www.cs.wustl.edu/~schmidt/TAO.html
 **/

// TAO_IDL - Generated from
// be/be_codegen.cpp:461

#ifndef _TAO_IDL_IDLC___LINUX_MONITORMANAGERINTEGRATIONSERVICES_H_
#define _TAO_IDL_IDLC___LINUX_MONITORMANAGERINTEGRATIONSERVICES_H_


#include "MONITORMANAGERINTEGRATIONSERVICEC.h"
#include "DCFS.h"
#include "tao/PortableServer/Basic_SArguments.h"
#include "tao/PortableServer/Special_Basic_SArguments.h"
#include "tao/PortableServer/Fixed_Size_SArgument_T.h"
#include "tao/PortableServer/Var_Size_SArgument_T.h"
#include "tao/PortableServer/Object_SArg_Traits.h"
#include "tao/PortableServer/UB_String_SArguments.h"
#include "tao/PortableServer/get_arg.h"
#include "tao/Special_Basic_Arguments.h"
#include "tao/UB_String_Arguments.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/PortableServer/PortableServer.h"
#include "tao/PortableServer/Servant_Base.h"

// TAO_IDL - Generated from
// be/be_visitor_arg_traits.cpp:68

TAO_BEGIN_VERSIONED_NAMESPACE_DECL


// Arg traits specializations.
namespace TAO
{

  // TAO_IDL - Generated from
  // be/be_visitor_arg_traits.cpp:147

#if !defined (_MONITORMANAGERINTEGRATIONSERVICE_MONITORMANAGERINTEGRATIONSERVICE_IFCE__SARG_TRAITS_)
#define _MONITORMANAGERINTEGRATIONSERVICE_MONITORMANAGERINTEGRATIONSERVICE_IFCE__SARG_TRAITS_

  template<>
  class  SArg_Traits< ::MONITORMANAGERINTEGRATIONSERVICE::MonitorManagerIntegrationService_ifce>
    : public
        Object_SArg_Traits_T<
            ::MONITORMANAGERINTEGRATIONSERVICE::MonitorManagerIntegrationService_ifce_ptr,
            ::MONITORMANAGERINTEGRATIONSERVICE::MonitorManagerIntegrationService_ifce_var,
            ::MONITORMANAGERINTEGRATIONSERVICE::MonitorManagerIntegrationService_ifce_out,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

#endif /* end #if !defined */
}

TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// be/be_visitor_module/module_sh.cpp:38

namespace POA_MONITORMANAGERINTEGRATIONSERVICE
{
  

  // TAO_IDL - Generated from
  // be/be_visitor_interface/interface_sh.cpp:76

  class MonitorManagerIntegrationService_ifce;
  typedef MonitorManagerIntegrationService_ifce *MonitorManagerIntegrationService_ifce_ptr;

  class  MonitorManagerIntegrationService_ifce
    : public virtual POA_DCF::Device_ifce
  {
  protected:
    MonitorManagerIntegrationService_ifce (void);
  
  public:
    /// Useful for template programming.
    typedef ::MONITORMANAGERINTEGRATIONSERVICE::MonitorManagerIntegrationService_ifce _stub_type;
    typedef ::MONITORMANAGERINTEGRATIONSERVICE::MonitorManagerIntegrationService_ifce_ptr _stub_ptr_type;
    typedef ::MONITORMANAGERINTEGRATIONSERVICE::MonitorManagerIntegrationService_ifce_var _stub_var_type;

    MonitorManagerIntegrationService_ifce (const MonitorManagerIntegrationService_ifce& rhs);
    virtual ~MonitorManagerIntegrationService_ifce (void);

    virtual ::CORBA::Boolean _is_a (const char* logical_type_id);

    virtual void _dispatch (
        TAO_ServerRequest & req,
        TAO::Portable_Server::Servant_Upcall *servant_upcall);
    
    ::MONITORMANAGERINTEGRATIONSERVICE::MonitorManagerIntegrationService_ifce *_this (void);
    
    virtual const char* _interface_repository_id (void) const;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_sh.cpp:39

    virtual char * monitorsConfigurationPath (
      void) = 0;

    static void _get_monitorsConfigurationPath_skel (
        TAO_ServerRequest &server_request,
        TAO::Portable_Server::Servant_Upcall *servant_upcall,
        TAO_ServantBase *servant);

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_sh.cpp:39

    virtual void monitorsConfigurationPath (
      const char * monitorsConfigurationPath) = 0;

    static void _set_monitorsConfigurationPath_skel (
        TAO_ServerRequest &server_request,
        TAO::Portable_Server::Servant_Upcall *servant_upcall,
        TAO_ServantBase *servant);
  };

// TAO_IDL - Generated from
// be/be_visitor_module/module_sh.cpp:69

} // module MONITORMANAGERINTEGRATIONSERVICE

#endif /* ifndef */

