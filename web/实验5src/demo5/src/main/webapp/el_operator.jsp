<%--
  Created by IntelliJ IDEA.
  User: me
  Date: 2024/4/30
  Time: 16:31
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>

<%@ page isELIgnored="false" %>
<html>
<head>
    <title>el 表达式</title>
</head>
<table border="1">
    <thead>
    <td><b>EL Expression</b></td>
    <td><b>outcome</b></td>
    </thead>
    <tr>
        <td>\${1}</td>
        <td>${1}</td>
    </tr>
    <tr>
        <td>\${1 + 2}</td>
        <td>${1 + 2}</td>
    </tr>
    <tr>
        <td>\${1.2+ 2.3}</td>
        <td>${1.2+ 2.3}</td>
    </tr>
    <tr>
        <td>\${1.2E4 +1.4}</td>
        <td>${1.2E4 +1.4}</td>
    </tr>
    <tr>
        <td>\${-4 - 2}</td>
        <td>${-4-2}</td>
    </tr>
    <tr>
        <td>\${21 * 2}</td>
        <td>${21 * 2}</td>
    </tr>
    <tr>
        <td>\${3/4}</td>
        <td>${3/4}</td>
    </tr>
    <tr>
        <td>\${3 div 4}</td>
        <td>${3 div 4}</td>
    </tr>
    <tr>
        <td>\${3 / 0}</td>
        <td>${3 / 0}</td>
    </tr>
    <tr>
        <td>\${10 % 4}</td>
        <td>${2}</td>
    </tr>
    <tr>
        <td>\${10 % 4}</td>
        <td>${2}</td>
    </tr>
    <tr>
        <td>\${(1==2)?3: 4}</td>
        <td>${(1==2)?3: 4}</td>
    </tr>
</table>
<body>

</body>
</html>
