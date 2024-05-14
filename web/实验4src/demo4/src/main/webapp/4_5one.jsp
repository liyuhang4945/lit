<%--
  Created by IntelliJ IDEA.
  User: user
  Date: 2024/5/6
  Time: 17:44
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>one</title>
    <jsp:include page="head.txt"/>
</head>
<body>
<form action="" method="get" name="form">
    请输入1——100之间的整数<br>
    并且显示图片，图片大小与输入的数值一直<br>
    （输入非数字则转error.jsp):<p>
    <label>
        <input type="text" name="number">
    </label>
    <p>
        <input type="submit" value="送出" name="submit">
    </p>
</form>

<%
    String num = request.getParameter("number");
    if (num == null) {
        num = "0";
    }

    try {
        int n = Integer.parseInt(num);
        if (n > 1 && n <= 50) {
%>
<jsp:forward page="4_5two.jsp">
    <jsp:param name="number" value="<%=n%>"/>
</jsp:forward>
<%
} else if (n > 50 && n <= 100) {

%>
<jsp:forward page="4_5three.jsp">
    <jsp:param name="number" value="<%=n%>"/>
</jsp:forward>

<%
    }
} catch (Exception e) {
%>
<jsp:forward page="error.jsp">
    <jsp:param name="mess" value="<%=e.toString()%>"/>
</jsp:forward>
<%
    }
%>
</body>
</html>
