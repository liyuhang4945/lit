<%--
  Created by IntelliJ IDEA.
  User: user
  Date: 2024/5/12
  Time: 13:40
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>显示过滤器结果</title>
</head>
<body>
你的ip地址<%=request.getAttribute("remoteHost")%><br>
不在服务范围内<hr>
合法范围是：<br>
startIP = <%=request.getAttribute("startIP")%><br>
endIP  = <%=request.getAttribute("endIP")%><br>
</body>
</html>
