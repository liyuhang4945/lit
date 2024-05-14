package com.myweb;


import jakarta.servlet.ServletException;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpSession;

import java.io.IOException;

public class LoginServlet extends HttpServlet {
    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        String username = req.getParameter("username");
        String password = req.getParameter("password");
        //模拟连接数据库
//        String sql = "select * from userinfo where username = ? and password = ?";
        HttpSession session = req.getSession();
        if("liyuhang".equals(username)&&"123456".equals(password)){
            session.setAttribute("username",username);
            resp.sendRedirect(req.getContextPath()+"/welcome.jsp");
        }else {
            resp.sendRedirect(req.getContextPath()+"/loginfail.jsp");
        }


    }
}
