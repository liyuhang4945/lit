<%@ page import="java.util.Calendar" %><%--
  Created by IntelliJ IDEA.
  User: user
  Date: 2024/4/26
  Time: 20:33
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>date</title>
</head>
<body>
<%
    Calendar date = Calendar.getInstance();
    int year = date.get(Calendar.YEAR);
    int month = date.get(Calendar.MONTH) + 1;
    int day = date.get(Calendar.DATE);
    int week = date.get(Calendar.DAY_OF_WEEK);
    String[] weekday = {"日", "一", "二", "三", "四", "五", "六"};
    int hour = date.get(Calendar.HOUR_OF_DAY);
    String welcome = null;
    if (hour > 0 && hour < 12) {
        welcome = "上午";
    } else if (hour > 12 && hour < 18) {
        welcome = "下午";
    } else {
        welcome = "晚上";
    }
%>
<%=welcome%>好！ 今天是<%=year%>年<%=month%>月<%=day%>日，星期<%=weekday[week]%>
</body>
</html>
