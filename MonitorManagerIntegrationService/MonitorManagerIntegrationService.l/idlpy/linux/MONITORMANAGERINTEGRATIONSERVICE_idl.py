# Python stubs generated by omniidl from /work/mhuertas/src_c++/gtc/MonitorManagerIntegrationService/MonitorManagerIntegrationService/MonitorManagerIntegrationService.l/MONITORMANAGERINTEGRATIONSERVICE.idl
# DO NOT EDIT THIS FILE!

import omniORB, _omnipy
from omniORB import CORBA, PortableServer
_0_CORBA = CORBA


_omnipy.checkVersion(4,2, __file__, 1)

try:
    property
except NameError:
    def property(*args):
        return None


# #include "DGT.idl"
import DGT_idl
_0_DGT = omniORB.openModule("DGT")
_0_DGT__POA = omniORB.openModule("DGT__POA")

# #include "MMCommon.idl"
import MMCommon_idl
_0_MM = omniORB.openModule("MM")
_0_MM__POA = omniORB.openModule("MM__POA")

# #include "MonitorManager.idl"
import MonitorManager_idl
_0_MM = omniORB.openModule("MM")
_0_MM__POA = omniORB.openModule("MM__POA")

# #include "CONFIG.idl"
import CONFIG_idl
_0_CONFIG = omniORB.openModule("CONFIG")
_0_CONFIG__POA = omniORB.openModule("CONFIG__POA")

# #include "DCF.idl"
import DCF_idl
_0_DCF = omniORB.openModule("DCF")
_0_DCF__POA = omniORB.openModule("DCF__POA")

#
# Start of module "MONITORMANAGERINTEGRATIONSERVICE"
#
__name__ = "MONITORMANAGERINTEGRATIONSERVICE"
_0_MONITORMANAGERINTEGRATIONSERVICE = omniORB.openModule("MONITORMANAGERINTEGRATIONSERVICE", r"/work/mhuertas/src_c++/gtc/MonitorManagerIntegrationService/MonitorManagerIntegrationService/MonitorManagerIntegrationService.l/MONITORMANAGERINTEGRATIONSERVICE.idl")
_0_MONITORMANAGERINTEGRATIONSERVICE__POA = omniORB.openModule("MONITORMANAGERINTEGRATIONSERVICE__POA", r"/work/mhuertas/src_c++/gtc/MonitorManagerIntegrationService/MonitorManagerIntegrationService/MonitorManagerIntegrationService.l/MONITORMANAGERINTEGRATIONSERVICE.idl")


# interface MonitorManagerIntegrationService_ifce
_0_MONITORMANAGERINTEGRATIONSERVICE._d_MonitorManagerIntegrationService_ifce = (omniORB.tcInternal.tv_objref, "IDL:gtc/MONITORMANAGERINTEGRATIONSERVICE/MonitorManagerIntegrationService_ifce:1.0", "MonitorManagerIntegrationService_ifce")
omniORB.typeMapping["IDL:gtc/MONITORMANAGERINTEGRATIONSERVICE/MonitorManagerIntegrationService_ifce:1.0"] = _0_MONITORMANAGERINTEGRATIONSERVICE._d_MonitorManagerIntegrationService_ifce
_0_MONITORMANAGERINTEGRATIONSERVICE.MonitorManagerIntegrationService_ifce = omniORB.newEmptyClass()
class MonitorManagerIntegrationService_ifce (_0_DCF.Device_ifce):
    _NP_RepositoryId = _0_MONITORMANAGERINTEGRATIONSERVICE._d_MonitorManagerIntegrationService_ifce[1]

    def __init__(self, *args, **kw):
        raise RuntimeError("Cannot construct objects of this type.")

    _nil = CORBA.Object._nil


_0_MONITORMANAGERINTEGRATIONSERVICE.MonitorManagerIntegrationService_ifce = MonitorManagerIntegrationService_ifce
_0_MONITORMANAGERINTEGRATIONSERVICE._tc_MonitorManagerIntegrationService_ifce = omniORB.tcInternal.createTypeCode(_0_MONITORMANAGERINTEGRATIONSERVICE._d_MonitorManagerIntegrationService_ifce)
omniORB.registerType(MonitorManagerIntegrationService_ifce._NP_RepositoryId, _0_MONITORMANAGERINTEGRATIONSERVICE._d_MonitorManagerIntegrationService_ifce, _0_MONITORMANAGERINTEGRATIONSERVICE._tc_MonitorManagerIntegrationService_ifce)

# MonitorManagerIntegrationService_ifce operations and attributes
MonitorManagerIntegrationService_ifce._d__get_monitorsConfigurationPath = ((),((omniORB.tcInternal.tv_string,0),),None)
MonitorManagerIntegrationService_ifce._d__set_monitorsConfigurationPath = (((omniORB.tcInternal.tv_string,0),),(),None)

# MonitorManagerIntegrationService_ifce object reference
class _objref_MonitorManagerIntegrationService_ifce (_0_DCF._objref_Device_ifce):
    _NP_RepositoryId = MonitorManagerIntegrationService_ifce._NP_RepositoryId

    def __init__(self, obj):
        _0_DCF._objref_Device_ifce.__init__(self, obj)

    def _get_monitorsConfigurationPath(self, *args):
        return self._obj.invoke("_get_monitorsConfigurationPath", _0_MONITORMANAGERINTEGRATIONSERVICE.MonitorManagerIntegrationService_ifce._d__get_monitorsConfigurationPath, args)

    def _set_monitorsConfigurationPath(self, *args):
        return self._obj.invoke("_set_monitorsConfigurationPath", _0_MONITORMANAGERINTEGRATIONSERVICE.MonitorManagerIntegrationService_ifce._d__set_monitorsConfigurationPath, args)

    monitorsConfigurationPath = property(_get_monitorsConfigurationPath, _set_monitorsConfigurationPath)


omniORB.registerObjref(MonitorManagerIntegrationService_ifce._NP_RepositoryId, _objref_MonitorManagerIntegrationService_ifce)
_0_MONITORMANAGERINTEGRATIONSERVICE._objref_MonitorManagerIntegrationService_ifce = _objref_MonitorManagerIntegrationService_ifce
del MonitorManagerIntegrationService_ifce, _objref_MonitorManagerIntegrationService_ifce

# MonitorManagerIntegrationService_ifce skeleton
__name__ = "MONITORMANAGERINTEGRATIONSERVICE__POA"
class MonitorManagerIntegrationService_ifce (_0_DCF__POA.Device_ifce):
    _NP_RepositoryId = _0_MONITORMANAGERINTEGRATIONSERVICE.MonitorManagerIntegrationService_ifce._NP_RepositoryId


    _omni_op_d = {"_get_monitorsConfigurationPath": _0_MONITORMANAGERINTEGRATIONSERVICE.MonitorManagerIntegrationService_ifce._d__get_monitorsConfigurationPath, "_set_monitorsConfigurationPath": _0_MONITORMANAGERINTEGRATIONSERVICE.MonitorManagerIntegrationService_ifce._d__set_monitorsConfigurationPath}
    _omni_op_d.update(_0_DCF__POA.Device_ifce._omni_op_d)

MonitorManagerIntegrationService_ifce._omni_skeleton = MonitorManagerIntegrationService_ifce
_0_MONITORMANAGERINTEGRATIONSERVICE__POA.MonitorManagerIntegrationService_ifce = MonitorManagerIntegrationService_ifce
omniORB.registerSkeleton(MonitorManagerIntegrationService_ifce._NP_RepositoryId, MonitorManagerIntegrationService_ifce)
del MonitorManagerIntegrationService_ifce
__name__ = "MONITORMANAGERINTEGRATIONSERVICE"

#
# End of module "MONITORMANAGERINTEGRATIONSERVICE"
#
__name__ = "MONITORMANAGERINTEGRATIONSERVICE_idl"

_exported_modules = ( "MONITORMANAGERINTEGRATIONSERVICE", )

# The end.
