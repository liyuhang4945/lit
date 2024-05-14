<%--
  Created by IntelliJ IDEA.
  User: user
  Date: 2024/5/6
  Time: 17:46
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>4_5two</title>
    <jsp:include page="head.txt"></jsp:include>
</head>
<body>
<h1> twojsp</h1>
<%
    String s = request.getParameter("number");
    response.getWriter().println("<br> 传过来的值是"+s);
%>
<img src="./images/bg1.jpg" width="<%=s%>" height="<%=s%>">
<p> <a href="4_5one.jsp">返回one页面</a> </p>
</body>
</html>
