<%--
  Created by IntelliJ IDEA.
  User: user
  Date: 2024/5/11
  Time: 17:40
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<jsp:useBean id="car" class="com.myweb.bean.Car" scope="request"/>
<html>
<head>
    <title>input</title>
</head>
<body>
<form action="" method="post">
    汽车号牌:<input type="text" name="number"><br>
    汽车名称:<input type="text" name="name"><br>
    生产日期:<input type="text" name="madeTime"><br>
    <input type="submit" value="提交">

</form>

<jsp:setProperty name="car" property="*"/>
<table>
    <tbody>
    <tr>
        <td> 汽车号牌</td>
        <td>汽车名称</td>
        <td>生产日期</td>
    </tr>
    <tr>
        <td><jsp:getProperty name="car" property="number"/></td>
        <td><jsp:getProperty name="car" property="name"/></td>
        <td><jsp:getProperty name="car" property="madeTime"/></td>
    </tr>
    </tbody>
    <colgroup>
        <col>
        <col>
        <col>
    </colgroup>
</table>
</body>
</html>
