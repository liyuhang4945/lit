<%@ page import="java.util.Enumeration" %><%--
  Created by IntelliJ IDEA.
  User: me
  Date: 2024/4/26
  Time: 10:34
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>request对象测试</title>
</head>
<body>
<%
    request.setCharacterEncoding("utf-8");
    String parameterName = null;
%>
使用request.getParameter("userName")取出来的值:
<%
    out.println(request.getParameter("userName"));
%>
<br>
<p> 使用request.getParameterValues取出来的值</p>
<%
    Enumeration<String> parameterNames = request.getParameterNames();
    while (parameterNames.hasMoreElements()) {
        String s = parameterNames.nextElement();
        String[] parameterValue = request.getParameterValues(s);
        out.print("表单参数名称："+s+"=");
        if (parameterValue!=null){
            for(String value:parameterValue){
                out.print(value+",");
            }
        }
        out.println("<br>");
    }
%>
</body>
</html>
