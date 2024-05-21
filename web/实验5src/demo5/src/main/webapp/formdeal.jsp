<jsp:useBean id="userFrom" scope="page" class="com.myweb.bean.UserFrom"/>
<jsp:setProperty name="userFrom" property="*"/>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@page isELIgnored="false" %>

<html>
<head>
    <title>deal</title>
</head>
<body>
<table border="1" align="center" cellpadding="0" >
    <tbody>
    <tr>
        <td>用户显示</td>
        <td>${userFrom.username}</td>
    </tr>
    <tr>
        <td>密码</td>
        <td>${userFrom.pwd}</td>
    </tr>
    <tr>
        <td>性别</td>
        <td>${userFrom.sex}</td>
    </tr>
    <tr>
        <td>爱好</td>
        <td>${userFrom.hobbies[0]} ${userFrom.hobbies[1]} ${userFrom.hobbies[2]}</td>
    </tr>
    <tr>
        <td colspan="2"><input name="button" type="button" value="返回" onclick="window.location.href='forminfo.jsp'"></td>
    </tr>
    </tbody>
    <colgroup>
        <col>
        <col>
    </colgroup>
</table>
</body>
</html>
