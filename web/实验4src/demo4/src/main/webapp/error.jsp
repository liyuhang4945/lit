<%--
  Created by IntelliJ IDEA.
  User: user
  Date: 2024/5/6
  Time: 18:02
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
    <jsp:include page="head.txt"></jsp:include>
</head>
<body>
<h1> error.jsp</h1>
<%
    String s = request.getParameter("number");
    response.getWriter().println("信息格式异常");
%>
<img src="./images/bg2.png">
<p> <a href="4_5one.jsp">返回one页面</a> </p>
</body>
</html>
