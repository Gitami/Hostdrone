<%@ Language=C#%>
<%
  // Version
    Response.Write(Environment.Version.ToString());
    Response.Write(Environment.NewLine);

  // User
    Response.Write(Environment.UserDomainName.ToString() + "/" + Environment.UserName.ToString());
    Response.Write(Environment.NewLine);

  // MachineName
    Response.Write(Environment.MachineName.ToString());
    Response.Write(Environment.NewLine);

  // SystemDirectory
    Response.Write(Environment.SystemDirectory.ToString());
    Response.Write(Environment.NewLine);

  // WorkingSet
    Response.Write(Environment.WorkingSet.ToString());
    Response.Write(Environment.NewLine);

  // ProcessorCount
    Response.Write(Environment.ProcessorCount.ToString() + " CPU(s)");
    Response.Write(Environment.NewLine);

  // TickCount
    if (TimeSpan.FromMilliseconds(System.Environment.TickCount).Days != 0)
        {
            Response.Write(TimeSpan.FromMilliseconds(System.Environment.TickCount).Days.ToString() + "d ");
        }

    if (TimeSpan.FromMilliseconds(System.Environment.TickCount).Hours != 0)
        {
            Response.Write(TimeSpan.FromMilliseconds(System.Environment.TickCount).Hours.ToString() + "h ");
        }
    Response.Write(TimeSpan.FromMilliseconds(System.Environment.TickCount).Minutes.ToString() + "m ");
    Response.Write(TimeSpan.FromMilliseconds(System.Environment.TickCount).Seconds.ToString() + "s ");

    Response.Write(Environment.NewLine);


%>
