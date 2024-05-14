<%--
  Created by IntelliJ IDEA.
  User: user
  Date: 2024/4/26
  Time: 19:50
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>loginCheck</title>
</head>
<body>
<%
    String userName = request.getParameter("userName");
    String password = request.getParameter("password");

    if(!userName.isEmpty() && !password.isEmpty()){
        session.setAttribute("uname",userName);
        response.sendRedirect("main.jsp");
    }else {
        response.sendRedirect("login.jsp");
    }
%>
</body>
</html>
