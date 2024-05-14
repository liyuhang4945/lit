<%--
  Created by IntelliJ IDEA.
  User: user
  Date: 2024/4/26
  Time: 20:25
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>中文处理示例</title>
</head>
<% request.setCharacterEncoding("UTF-8");%>
<body>
<form action="messy2.jsp" method="post">
    用户名:<input type="text" name="userName"><br>
    密 码:<input type="password" name="password"><br>
    <font size="2">（提交后 用户名将被存入session）</font>
    <input type="submit" value="提交">
</form>

<font size="2"> 下面是表单提交后取到的数据</font>
<%
    String userName = request.getParameter("userName");
    String password = request.getParameter("password");
    if (userName != null) {
        out.println("表单输入的username:" + userName);
        out.println("表单输入的password:" + password);
    } else {
        out.println("表单参数未提交");
    }
%>
</body>
</html>
