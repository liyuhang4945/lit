<%--
  Created by IntelliJ IDEA.
  User: me
  Date: 2024/4/26
  Time: 10:01
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>主要方法调用实例</title>
</head>
<body>
    <h1>request主要方法调用实例</h1>
<%
    request.setAttribute("attr","hello");
    out.println("attr属性值："+request.getAttribute("attr")+"<br>");
    out.println("上下文路径："+request.getContextPath()+"<br>");
    out.println("Cookies："+request.getCookies()+"<br>");
    out.println("Host："+request.getAttribute("attr")+"<br>");
    out.println("ServerName："+request.getServerName()+"<br>");
    out.println("ServerPort："+request.getServerPort()+"<br>");
    out.println("RemmoteAddr："+request.getRemoteAddr()+"<br>");
    out.println("属性移除操作后，attr属性值："+request.getAttribute("attr")+"<br>");
    out.println("web项目物理路径："+pageContext.getServletContext().getRealPath(""));

%>
</body>
</html>
