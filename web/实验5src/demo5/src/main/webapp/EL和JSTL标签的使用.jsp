
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page language="java" contentType="text/html; charset=UTF-8"
         pageEncoding="UTF-8"%>
<%@page isELIgnored="false" %>

<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>EL和JSTL标签的使用.jsp</title>
    <style>
        .odd {
            background-color: red;
        }
        .even {
            background-color: white;
        }
    </style>
</head>
<body>
<table border="1">
    <c:forEach var="row" begin="1" end="10">
        <c:choose>
            <c:when test="${row % 2 == 1}">
                <tr class="odd">
            </c:when>
            <c:otherwise>
                <tr class="even">
            </c:otherwise>
        </c:choose>
        <c:forEach var="col" begin="1" end="5">
            <td>Row ${row} - Col ${col}</td>
        </c:forEach>
        </tr>
    </c:forEach>
</table>
</body>
</html>