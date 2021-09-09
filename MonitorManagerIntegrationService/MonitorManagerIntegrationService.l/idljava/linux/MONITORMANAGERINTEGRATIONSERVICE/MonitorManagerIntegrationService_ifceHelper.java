package MONITORMANAGERINTEGRATIONSERVICE;


/**
* MONITORMANAGERINTEGRATIONSERVICE/MonitorManagerIntegrationService_ifceHelper.java .
* Generated by the IDL-to-Java compiler (portable), version "3.2"
* from MONITORMANAGERINTEGRATIONSERVICE.idl
* Thursday, September 9, 2021 2:20:16 PM UTC
*/

abstract public class MonitorManagerIntegrationService_ifceHelper
{
  private static String  _id = "IDL:gtc/MONITORMANAGERINTEGRATIONSERVICE/MonitorManagerIntegrationService_ifce:1.0";

  public static void insert (org.omg.CORBA.Any a, MONITORMANAGERINTEGRATIONSERVICE.MonitorManagerIntegrationService_ifce that)
  {
    org.omg.CORBA.portable.OutputStream out = a.create_output_stream ();
    a.type (type ());
    write (out, that);
    a.read_value (out.create_input_stream (), type ());
  }

  public static MONITORMANAGERINTEGRATIONSERVICE.MonitorManagerIntegrationService_ifce extract (org.omg.CORBA.Any a)
  {
    return read (a.create_input_stream ());
  }

  private static org.omg.CORBA.TypeCode __typeCode = null;
  synchronized public static org.omg.CORBA.TypeCode type ()
  {
    if (__typeCode == null)
    {
      __typeCode = org.omg.CORBA.ORB.init ().create_interface_tc (MONITORMANAGERINTEGRATIONSERVICE.MonitorManagerIntegrationService_ifceHelper.id (), "MonitorManagerIntegrationService_ifce");
    }
    return __typeCode;
  }

  public static String id ()
  {
    return _id;
  }

  public static MONITORMANAGERINTEGRATIONSERVICE.MonitorManagerIntegrationService_ifce read (org.omg.CORBA.portable.InputStream istream)
  {
    return narrow (istream.read_Object (_MonitorManagerIntegrationService_ifceStub.class));
  }

  public static void write (org.omg.CORBA.portable.OutputStream ostream, MONITORMANAGERINTEGRATIONSERVICE.MonitorManagerIntegrationService_ifce value)
  {
    ostream.write_Object ((org.omg.CORBA.Object) value);
  }

  public static MONITORMANAGERINTEGRATIONSERVICE.MonitorManagerIntegrationService_ifce narrow (org.omg.CORBA.Object obj)
  {
    if (obj == null)
      return null;
    else if (obj instanceof MONITORMANAGERINTEGRATIONSERVICE.MonitorManagerIntegrationService_ifce)
      return (MONITORMANAGERINTEGRATIONSERVICE.MonitorManagerIntegrationService_ifce)obj;
    else if (!obj._is_a (id ()))
      throw new org.omg.CORBA.BAD_PARAM ();
    else
    {
      org.omg.CORBA.portable.Delegate delegate = ((org.omg.CORBA.portable.ObjectImpl)obj)._get_delegate ();
      MONITORMANAGERINTEGRATIONSERVICE._MonitorManagerIntegrationService_ifceStub stub = new MONITORMANAGERINTEGRATIONSERVICE._MonitorManagerIntegrationService_ifceStub ();
      stub._set_delegate(delegate);
      return stub;
    }
  }

  public static MONITORMANAGERINTEGRATIONSERVICE.MonitorManagerIntegrationService_ifce unchecked_narrow (org.omg.CORBA.Object obj)
  {
    if (obj == null)
      return null;
    else if (obj instanceof MONITORMANAGERINTEGRATIONSERVICE.MonitorManagerIntegrationService_ifce)
      return (MONITORMANAGERINTEGRATIONSERVICE.MonitorManagerIntegrationService_ifce)obj;
    else
    {
      org.omg.CORBA.portable.Delegate delegate = ((org.omg.CORBA.portable.ObjectImpl)obj)._get_delegate ();
      MONITORMANAGERINTEGRATIONSERVICE._MonitorManagerIntegrationService_ifceStub stub = new MONITORMANAGERINTEGRATIONSERVICE._MonitorManagerIntegrationService_ifceStub ();
      stub._set_delegate(delegate);
      return stub;
    }
  }

}
