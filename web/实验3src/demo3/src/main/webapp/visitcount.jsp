<%--
  Created by IntelliJ IDEA.
  User: user
  Date: 2024/4/26
  Time: 20:14
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>利用application实现计数器</title>
</head>
<body>
<%
    int count = 0;
    if(application.getAttribute("count")==null){//不存在就创建一个
        count=count+1;
        application.setAttribute("count",count);
    }else{
        count = Integer.parseInt(application.getAttribute("count").toString());
        count++;
        application.setAttribute("count" ,count);
    }

    out.print("您是本系统的第"+count+"位访问者 ");
%>
</body>
</html>
