<%
  ' ASP running
      Response.Write ScriptEngineMajorVersion & "." & ScriptEngineMinorVersion & vbCrLf

  ' GATEWAY_INTERFACE
      Response.Write Request.ServerVariables("GATEWAY_INTERFACE") & vbCrLf

  ' Server.ScriptTimeout
    Response.Write Server.ScriptTimeout & " sec." & vbCrLf

  ' Session.LCID
    Response.Write Session.LCID & vbCrLf

  ' w3Image
      On error resume next
      Set strObjectChk = CreateObject("W3Image.Image") 
      if err.number <> 0 then 
        Response.Write "0" & vbCrLf
      else 
        Response.Write "1" & vbCrLf
        Response.Write " (" & strObjectChk.Version & ")"
        set strObjectChk=nothing
      end if

  ' w3Upload
      On error resume next
      Set strObjectChk = CreateObject("w3.upload") 
      if err.number <> 0 then 
        Response.Write "0" & vbCrLf
      else 
        Response.Write "1" & vbCrLf
        Response.Write " (" & strObjectChk.Version & ")"
        set strObjectChk=nothing
      end if

  ' w3Jmail
      On error resume next
      Set strObjectChk = CreateObject("JMail.SMTPMail") 
      if err.number <> 0 then 
        Response.Write "0" & vbCrLf
      else 
        Response.Write "1" & vbCrLf
        Response.Write " (" & strObjectChk.Version & ")"
        set strObjectChk=nothing
      end if

  ' w3.netutils
      On error resume next
      Set strObjectChk = CreateObject("w3.netutils") 
      if err.number <> 0 then 
        Response.Write "0" & vbCrLf
      else 
        Response.Write "1" & vbCrLf
        Response.Write " (" & strObjectChk.Version & ")"
        set strObjectChk=nothing
      end if

  ' w3info.w3info.1
      On error resume next
      Set strObjectChk = CreateObject("w3info.w3info.1") 
      if err.number <> 0 then 
        Response.Write "0" & vbCrLf
      else 
        Response.Write "1" & vbCrLf
        Response.Write " (" & strObjectChk.Version & ")"
        set strObjectChk=nothing
      end if

  ' w3sitetree.tree
      On error resume next
      Set strObjectChk = CreateObject("w3sitetree.tree") 
      if err.number <> 0 then 
        Response.Write "0" & vbCrLf
      else 
        Response.Write "1" & vbCrLf
        Response.Write " (" & strObjectChk.Version & ")"
        set strObjectChk=nothing
      end if

  ' AspSmartUpload
      On error resume next
      Set strObjectChk = CreateObject("AspSmartUpload.SmartUpload") 
      if err.number <> 0 then 
        Response.Write "0" & vbCrLf
      else 
        Response.Write "1" & vbCrLf
        Response.Write " (" & strObjectChk.Version & ")"
        set strObjectChk=nothing
      end if

  ' AspImage
      On error resume next
      Set strObjectChk = CreateObject("AspImage") 
      if err.number <> 0 then 
        Response.Write "0" & vbCrLf
      else 
        Response.Write "1" & vbCrLf
        Response.Write " (" & strObjectChk.Version & ")"
        set strObjectChk=nothing
      end if

  ' ASPMail
      On error resume next
      Set strObjectChk = CreateObject("SMTPsvg.Mailer") 
      if err.number <> 0 then 
        Response.Write "0" & vbCrLf
      else 
        Response.Write "1" & vbCrLf
        Response.Write " (" & strObjectChk.Version & ")"
        set strObjectChk=nothing
      end if

  ' JRO.JetEngine
      On error resume next
      Set strObjectChk = CreateObject("JRO.JetEngine") 
      if err.number <> 0 then 
        Response.Write "0" & vbCrLf
      else 
        Response.Write "1" & vbCrLf
        Response.Write " (" & strObjectChk.Version & ")"
        set strObjectChk=nothing
      end if
    
  ' Persits.Aspemail
      On error resume next
      Set strObjectChk = CreateObject("Persits.Aspemail") 
      if err.number <> 0 then 
        Response.Write "0" & vbCrLf
      else 
        Response.Write "1" & vbCrLf
        Response.Write " (" & strObjectChk.Version & ")"
        set strObjectChk=nothing
      end if
    
  ' Persits.XUpload
      On error resume next
      Set strObjectChk = CreateObject("Persits.XUpload") 
      if err.number <> 0 then 
        Response.Write "0" & vbCrLf
      else 
        Response.Write "1" & vbCrLf
        Response.Write " (" & strObjectChk.Version & ")"
        set strObjectChk=nothing
      end if

  ' MSXML3.ServerXMLHTTP
      On error resume next
      Set strObjectChk = CreateObject("MSXML3.ServerXMLHTTP") 
      if err.number <> 0 then 
        Response.Write "0" & vbCrLf
      else 
        Response.Write "1" & vbCrLf
        Response.Write " (" & strObjectChk.Version & ")"
        set strObjectChk=nothing
      end if

  ' MSXML4.ServerXMLHTTP
      On error resume next
      Set strObjectChk = CreateObject("MSXML4.ServerXMLHTTP") 
      if err.number <> 0 then 
        Response.Write "0" & vbCrLf
      else 
        Response.Write "1" & vbCrLf
        Response.Write " (" & strObjectChk.Version & ")"
        set strObjectChk=nothing
      end if

  ' Hexillion.HexIcmp
      On error resume next
      Set strObjectChk = CreateObject("Hexillion.HexIcmp") 
      if err.number <> 0 then 
        Response.Write "0" & vbCrLf
      else 
        Response.Write "1" & vbCrLf
        Response.Write " (" & strObjectChk.Version & ")"
        set strObjectChk=nothing
      end if

  ' Hexillion.HexLookup
      On error resume next
      Set strObjectChk = CreateObject("Hexillion.HexLookup") 
      if err.number <> 0 then 
        Response.Write "0" & vbCrLf
      else 
        Response.Write "1" & vbCrLf
        Response.Write " (" & strObjectChk.Version & ")"
        set strObjectChk=nothing
      end if

  ' Hexillion.HexTcpQuery
      On error resume next
      Set strObjectChk = CreateObject("Hexillion.HexTcpQuery") 
      if err.number <> 0 then 
        Response.Write "0" & vbCrLf
      else 
        Response.Write "1" & vbCrLf
        Response.Write " (" & strObjectChk.Version & ")"
        set strObjectChk=nothing
      end if

  ' HexValidEmail.Connection
      On error resume next
      Set strObjectChk = CreateObject("HexValidEmail.Connection") 
      if err.number <> 0 then 
        Response.Write "0" & vbCrLf
      else 
        Response.Write "1" & vbCrLf
        Response.Write " (" & strObjectChk.Version & ")"
        set strObjectChk=nothing
      end if

%>
