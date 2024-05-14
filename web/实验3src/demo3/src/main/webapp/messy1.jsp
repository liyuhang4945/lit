<%--
  Created by IntelliJ IDEA.
  User: user
  Date: 2024/4/26
  Time: 20:20
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;" language="java" %>
<html>
<head>
    <title>中文乱码</title>
</head>
<body>
    <%
        String parameter = request.getParameter("param");

    %>
    <a href="messy1.jsp?param='中文'">请点击这个link</a>
    你提交的参数为:<%=parameter%>
</body>
</html>
