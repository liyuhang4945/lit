package com.myweb;

import jakarta.servlet.ServletException;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.Enumeration;

public class showParameter extends HttpServlet {
    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        resp.setCharacterEncoding("UTF-8");
        resp.setContentType("text/html;charset= UTF-8");
        PrintWriter out = resp.getWriter();
        String title = "读取所有参数请求";
        out.println("<body bgcolor = \"#FDF5F6\">\n"+
                    "<H1 align = center>"+title+"</h1>\n"+
                "<table border = 1 align = center> \n"+
                "<tr bgcolor = \"FFAD00\">"+
                "<TH>参数名字<TH>参数值"
                );

        out.println("<h1></h1><br>");
        Enumeration<String> parameterNames = req.getParameterNames();
        while (parameterNames.hasMoreElements()) {
            String s = parameterNames.nextElement();
            out.println("<tr><td>"+s+"\n<td>");
            String[] parameterValues = req.getParameterValues(s);
            if (parameterValues.length == 1) {
                String parameterValue = parameterValues[0];
                if (parameterValue.isEmpty()) {
                    out.println("<I>NO Value</I>");
                } else {
                    out.println(parameterValue);
                }
            } else {
                out.println("<UL>");
                for (String parametervalue : parameterValues) {
                    out.println("<li>" + parametervalue+"</li>");
                }
                out.println("</ul>");
            }
        }
    }
}
