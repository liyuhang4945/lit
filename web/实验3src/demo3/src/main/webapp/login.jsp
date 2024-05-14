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
    <title>login</title>
</head>
<body>
    <font size="2">
        <form action="loginCheck.jsp" method="post">
            用户名:<input type="text" name="userName"><br>
            密 码:<input type="password" name="password"><br>
            <font size="2">（提交后 用户名将被存入session）</font>
            <input type="submit" value="提交">
        </form>
    </font>
</body>
</html>
