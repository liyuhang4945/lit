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
    <title>main</title>
</head>
<body>
    <%
        String uname = (String)session.getAttribute("uname");
        if(uname!=null){
            out.print("欢迎"+uname+"登录");
        }else {
            response.sendRedirect("login.jsp");
        }

    %>
<h3>上述名字：<%=uname%>是从session 中取出来的</h3>
</body>
</html>
