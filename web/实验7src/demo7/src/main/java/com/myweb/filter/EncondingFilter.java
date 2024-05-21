package com.myweb.filter;


import jakarta.servlet.*;

import java.io.IOException;

public class EncondingFilter implements Filter {
    protected String encoding = null;
    protected FilterConfig config = null;

    @Override
    public void init(FilterConfig filterConfig) throws ServletException {
        this.config = filterConfig;
        this.encoding = config.getInitParameter("Encoding");
    }

    @Override
    public void doFilter(ServletRequest servletRequest, ServletResponse servletResponse, FilterChain filterChain) throws IOException, ServletException {
       if (encoding!=null){
           servletRequest.setCharacterEncoding(encoding);
           servletResponse.setCharacterEncoding(encoding);
       }
       filterChain.doFilter(servletRequest,servletResponse);
    }
}
