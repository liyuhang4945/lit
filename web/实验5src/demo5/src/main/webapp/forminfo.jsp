<%--
  Created by IntelliJ IDEA.
  User: me
  Date: 2024/4/30
  Time: 16:57
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@page isELIgnored="false" %>
<html>
<head>
    <title>forminfo</title>
</head>
<body>
<h1>请填写表单信息</h1>
<form action="formdeal.jsp" method="post">
    用户名:<input type="text" name="username"><br>
    密 码:<input type="password" name="pwd"><br>
    确认密码:<input type="password" name="repwd"><br>
    性别:<input type="radio" name="sex" value="男">男
    <input type="radio" name="sex" value="女">女<br>
    爱好:<input type="checkbox" name="hobbies" value="体育">体育
    <input type="checkbox" name="hobbies" value="美术">美术
    <input type="checkbox" name="hobbies" value="音乐">音乐
    <input type="submit" value="提交">
    <input type="reset" value="重置">
    <br>
    该表单信息将提交给deal.jsp
</form>
</body>
</html>
