package com.myweb.bean;

import com.mysql.cj.jdbc.Driver;
import com.mysql.cj.protocol.Resultset;

import java.sql.*;

public class DBcon {
    private static final String DRIVER_CLASS = "com.mysql.cj.jdbc.Driver";
    private static final String USER = "root";
    private static final String PWD = "123456";
    private static final String URL = "jdbc:mysql://localhost:3306/test";

    public static Connection getConnection(){
        Connection conn = null;
        try {
            Class.forName(DRIVER_CLASS);
            conn = DriverManager.getConnection(URL, USER, PWD);
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
        return conn;
    }

    public static void closeConnection(Connection conn){
        try {
            if(conn!=null&& !conn.isClosed()){
                conn.close();
                conn=null;
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }
    public static void closeResultset(ResultSet rs){
        try {
            if (rs!=null){
                rs.close();
                rs=null;
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }
    public static void closeStatement(Statement st){
        try {
            if (st!=null&&!st.isClosed()){
                st.close();
                st=null;
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

}
