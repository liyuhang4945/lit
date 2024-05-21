<%--
  Created by IntelliJ IDEA.
  User: user
  Date: 2024/5/11
  Time: 18:16
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<jsp:useBean id="board" scope="application" class="com.myweb.bean.MsgBoard"/>

<html>
<head>
    <title>showmsg</title>
</head>
<body>
<jsp:getProperty name="board" property="allMessage"/>
<a href="inputMsg.jsp" >我要留言</a>
</body>
</html>
