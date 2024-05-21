<%--
  Created by IntelliJ IDEA.
  User: user
  Date: 2024/5/12
  Time: 9:45
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>main</title>
</head>
<body>
<%=session.getAttribute("userName")%><br>
登录成功<br>
<a href="login.jsp"> 返回登录页面</a>
</body>
</html>
