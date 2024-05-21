<%--
  Created by IntelliJ IDEA.
  User: user
  Date: 2024/5/11
  Time: 17:27
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<jsp:useBean id="st" class="com.myweb.bean.Student" scope="request"/>
<html>
<head>
    <title>receive</title>
</head>
<body>
直接从表单自动获取到的参数如下<br>
学号:<%=st.getXh()%><br>
姓名:<%=st.getName()%><br>
生日:<%=st.getBirthday()%><br>
通过request.getParameter获取到的参数“<br>
学号:<%=request.getParameter("xh")%><br>
姓名:<%=request.getParameter("name")%><br>
生日:<%=request.getParameter("birthday")%><br>
</body>
</html>
