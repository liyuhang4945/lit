<%--
  Created by IntelliJ IDEA.
  User: user
  Date: 2024/5/14
  Time: 21:44
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>checkUser</title>
</head>
<body>
<% String username = request.getParameter("username");
    session.setAttribute("username", username);
    response.sendRedirect(request.getContextPath() + "/main.jsp");
%>
</body>
</html>
