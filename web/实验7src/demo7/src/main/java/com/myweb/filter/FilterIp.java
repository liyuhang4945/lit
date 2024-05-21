package com.myweb.filter;

import jakarta.servlet.*;
import jakarta.servlet.annotation.WebFilter;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

import java.io.IOException;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import static java.util.regex.Pattern.*;

public class FilterIp implements Filter {

    FilterConfig filterConfig = null;

    @Override
    public void init(FilterConfig filterConfig) throws ServletException {
        this.filterConfig = filterConfig;
    }

    @Override
    public void doFilter(ServletRequest servletRequest, ServletResponse servletResponse, FilterChain filterChain) throws IOException, ServletException {
        HttpServletRequest request = (HttpServletRequest) servletRequest;
        HttpServletResponse response = (HttpServletResponse) servletResponse;

        String remoteHost = request.getRemoteHost();



        int remoteIntIp = 127001;
        int startIntIp;
        int endIntIp;
        try {
            remoteIntIp = Integer.parseInt(remoteHost.replace(",", ""));
        } catch (Exception e) {
            remoteHost="127.0.0.1";
        }
        request.setAttribute("remoteHost", remoteHost);
        String startIP = filterConfig.getInitParameter("startIP");
        String endIP = filterConfig.getInitParameter("endIP");
        request.setAttribute("startIP", startIP);
        request.setAttribute("endIP", endIP);
        //
        startIntIp = Integer.parseInt(startIP.replace(".", ""));
        endIntIp = Integer.parseInt(endIP.replace(".", ""));

        if (remoteIntIp > startIntIp && remoteIntIp < endIntIp) {
            filterChain.doFilter(request, response);
        } else {
            request.getRequestDispatcher("filtip.jsp").forward(servletRequest, servletResponse);
            response.getWriter().println("Access Denied");
        }
    }


}