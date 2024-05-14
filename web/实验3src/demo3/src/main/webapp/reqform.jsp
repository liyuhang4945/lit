<%--
  Created by IntelliJ IDEA.
  User: me
  Date: 2024/4/26
  Time: 10:33
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
</head>
<body>
<form action="req_rev.jsp" method="post">
    <table border="1">
        <tr><td>用户名：</td><td><input type="text" name="userName"></td></tr>
        <tr><td>密码:</td><td><input type="password" name="password"></td></tr>

        <tr><td colspan="2">
            <input type="checkbox" name="hobbies" value="骑车">骑自行车
            <input type="checkbox" name="hobbies" value="开车"> 开车

            <input>
        </td></tr>

        <tr align="center">
            <td colspan="2">
                <input type="submit" value="提交">
                <input type="reset" 取消>

            </td>
        </tr>
    </table>
</form>

</body>
</html>
