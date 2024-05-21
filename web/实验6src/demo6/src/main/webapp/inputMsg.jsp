<%--
  Created by IntelliJ IDEA.
  User: user
  Date: 2024/5/11
  Time: 18:11
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<jsp:useBean id="board" class="com.myweb.bean.MsgBoard" scope="application"/>
<html>
<head>
    <title>Title</title>
</head>
<body>
<form action ="" method="post" name ="form">
输人您的名字：<br><input type="text" name="name"><br>
输人您的留言标题：<br><input type="text" name="title"> 输人您的留言：<br>
<textarea name="content" rows="10" cols="36" wrap="hard"></textarea><br>

<input type="submit" value = "提交信息" name = "submit">
</form>
<jsp:setProperty name="board" property="*"/>
<a href="showmsg.jsp">查看留言板</a>
</body>
</html>
