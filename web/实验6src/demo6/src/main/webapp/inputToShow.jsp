<%--
  Created by IntelliJ IDEA.
  User: user
  Date: 2024/5/11
  Time: 17:45
  To change this template use File | Settings | File Templates.
--%>
<jsp:useBean id="car" class="com.myweb.bean.Car" scope="request"/>
<%@page import="com.myweb.bean.Car" %>
<jsp:setProperty name="car" property="*"/>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
</head>
<body>
<form action="show.jsp" method="post">
    汽车号牌:<input type="text" name="number"><br>
    汽车名称:<input type="text" name="name"><br>
    生产日期:<input type="text" name="madeTime"><br>
    <input type="submit" value="提交">

</form>
</body>
</html>
