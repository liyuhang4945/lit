<%@ page import="java.util.ArrayList" %>
<%@ page import="java.util.List" %>
<%@ page import="java.util.Vector" %><%--
  Created by IntelliJ IDEA.
  User: user
  Date: 2024/4/26
  Time: 21:01
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>visitperson</title>
</head>
<body>
<%!
    int count = 0;
    Vector<String> person = null;

    public void judge() {
        if (count == 0) {
            person =new Vector<>();
        }
    }

    public void addPerson(String p) {
        person.add(p);
        count++;
    }
%>

<%
    String name = request.getParameter("name");
    if (name == null || name.isEmpty() || name.length() > 10) {
%>
<jsp:forward page="inputName.jsp"/>
<%

    }
    judge();
    addPerson(name);
%>

<br>
目前共有<%=count%>位访问过该站点，他们的名字是<br><br>
<table border="1">
    <tr>
        <td>位次</td>
        <td>名字</td>
    </tr>
    <%
        for (int i = 0; i < person.size(); i++) {
    %>
        <tr><td><%=i+1%></td><td><%=person.get(i)%></td></tr>
    <%
        }
    %>


</table>
<a href="inputName.jsp">返回inputName页面</a>
</body>
</html>
