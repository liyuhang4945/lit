<%@ page import="com.myweb.bean.DBcon" %>
<%@ page import="java.sql.*" %><%--
  Created by IntelliJ IDEA.
  User: user
  Date: 2024/5/12
  Time: 9:44
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<jsp:useBean id="DB" class="com.myweb.bean.DBcon" scope="request"/>
<html>
<head>
    <title>check</title>
</head>
<body>
<%
    String username = request.getParameter("username");
    String password = request.getParameter("password");
%>
你输入的用户名是<%=username%><br>
<%
    Connection conn = DBcon.getConnection();
    PreparedStatement st = null;
    ResultSet resultSet = null;
    String sql = "select * from student where username= ? and password = ?";
    try {
        st = conn.prepareStatement(sql);
        st.setString(1, username);
        st.setString(2, password);
        resultSet = st.executeQuery();
        if (resultSet.next()) {
            session.setAttribute("userName", username);
            response.sendRedirect("main.jsp");
        } else {
            response.getWriter().println("无该用户");
            response.getWriter().println("<a href='login.jsp'>重新登录<//a>");
        }
    } catch (SQLException e) {
        throw new RuntimeException(e);
    }

%>
</body>
</html>
