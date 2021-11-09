#--------------------------------------------------------------
# MonitorManagerIntegrationService Device profile
# File generated: 9/8/2021  
#--------------------------------------------------------------

[ Header MonitorManagerIntegrationService.header ]
instance   = MonitorManagerIntegrationService
class_name = MonitorManagerIntegrationService
version    = 0.1
panels     = gtc.AL.Inspector.Panels.Device
tabs       = Commands|Alarms|Configs|Monitors
ifr_id     = IDL:gtc/MONITORMANAGERINTEGRATIONSERVICE/MonitorManagerIntegrationService_ifce:1.0

#--------------------------------------------------------------
# Properties
#--------------------------------------------------------------
[ Property MonitorManagerIntegrationService.monitorsConfigurationPath ]
description = Monitor Configuration Path
units       = None
type        = string
max_value   = string : ""
min_value   = string : ""

#--------------------------------------------------------------
# Magnitudes
#--------------------------------------------------------------
#--------------------------------------------------------------
# Alarms
#--------------------------------------------------------------
#--------------------------------------------------------------
# Default configuration
#--------------------------------------------------------------
[ Configuration MonitorManagerIntegrationService.Default ]
monitorsConfigurationPath = string : /work/gcsop/etc/config/MonitorManagerIntegrationService/TelemetryList.yml
