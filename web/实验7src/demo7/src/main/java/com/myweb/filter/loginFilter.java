package com.myweb.filter;

import jakarta.servlet.*;
import jakarta.servlet.annotation.WebFilter;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

import java.io.IOException;


public class loginFilter implements Filter {

    @Override
    public void doFilter(ServletRequest servletRequest, ServletResponse servletResponse, FilterChain filterChain) throws IOException, ServletException {
        HttpServletRequest request = (HttpServletRequest) servletRequest;
        HttpServletResponse response = (HttpServletResponse) servletResponse;

        String username = (String) request.getSession().getAttribute("username");
        String basePath = request.getScheme() + "://" + request.getServerName() + ":" + request.getServerPort() + request.getContextPath() + "/";
        String url = request.getRequestURL().toString();

        // 检查session中是否保存有用户名，若没有则重定向到登录页面
        if (username != null ||url.equals(basePath + "loginform.html") || url.equals(basePath + "index.jsp")) {
            filterChain.doFilter(request, response);
        } else {

            response.sendRedirect(request.getContextPath()+"/loginform.html");
            System.out.println(username);
        }
    }

    @Override
    public void destroy() {
    }

}
