<%--
  Created by IntelliJ IDEA.
  User: user
  Date: 2024/5/11
  Time: 17:45
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
</head>
<body>
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
