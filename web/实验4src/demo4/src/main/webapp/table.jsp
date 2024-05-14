<%@ page import="com.jsp.bean.Student" %>
<%@ page import="java.util.ArrayList" %>
<%@ page import="java.util.List" %>
<%@ page import="java.util.HashMap" %><%--
  Created by IntelliJ IDEA.
  User: user
  Date: 2024/4/26
  Time: 22:11
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>table jsp</title>
</head>
<body>
<%
    //数组数据
    Student[] stu = {new Student("001", "周一", "12231524213"),
            new Student("002", "吴二", "123124231"),
            new Student("003", "正三", "1232135421")
    };
    //list数据
    List<Student> lstu = new ArrayList();
    lstu.add(new Student("2101", "张三", "123214213"));
    lstu.add(new Student("2101", "李四", "213214521"));
    lstu.add(new Student("2101", "王五", "1232145123"));
%>
<table border="1" bgcolor="red">
    <tr>
        <td>学号</td>
        <td>姓名</td>
        <td>电话</td>
    </tr>
    <%
        for (int i = 0; i < stu.length; i++) {

    %>
    <tr>
        <td><%=stu[i].getXh()%>
        </td>
        <td><%=stu[i].getName()%>
        </td>
        <td><%=stu[i].getTeleno()%>
        </td>
    </tr>
    <%
        }
    %>
</table>

从list中读出
<table border="1" bgcolor="blue">
    <tr>
        <td>学号</td>
        <td>姓名</td>
        <td>电话</td>
    </tr>
    <%
        for (int i = 0; i < stu.length; i++) {
    %>
    <tr>
        <td><%=lstu.get(i).getXh()%>
        </td>
        <td><%=lstu.get(i).getName()%>
        </td>
        <td><%=lstu.get(i).getTeleno()%>
        </td>
    </tr>
    <%
        }
    %>
    <br>
</table>
{学号带超链接}
<table border="1" bgcolor="blue">
    <tr>
        <td>学号</td>
        <td>姓名</td>
        <td>电话</td>
    </tr>
    <%
        for (int i = 0; i < stu.length; i++) {
    %>
    <tr>
        <a href="detail.jsp?xh=<%=lstu.get(i).getXh()%>">
            <td><%=lstu.get(i).getXh()%>
            </td>
        </a>
        <td><%=lstu.get(i).getName()%>
        </td>
        <td><%=lstu.get(i).getTeleno()%>
        </td>
    </tr>
    <%
        }
    %>
    <br>
</table>

<br>
<%
    HashMap<String, Student> hashMap = new HashMap<>();
    hashMap.put("A01", new Student("2101", "张三", "123214213"));
    hashMap.put("A02", new Student("2101", "李四", "213214521"));
    hashMap.put("A03", new Student("2101", "王五", "1232145123"));
%>
map中取出的数据
<table border="1" bgcolor="blue">
    <tr>
        <td>学号</td>
        <td>姓名</td>
        <td>电话</td>
    </tr>
    <%
        Object[] keys = hashMap.keySet().toArray();

        for (Object key:keys){
            Student student = hashMap.get(key);
    %>
    <tr>
        <td><%=student.getXh()%>
        </td>
        <td><%=student.getName()%>
        </td>
        <td><%=student.getTeleno()%>
        </td>
    </tr>
    <%
        }
    %>
    <br>
</table>
</body>
</html>
