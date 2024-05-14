package com.jsp.bean;

public class Student {
    private String xh;
    private String name;
    private String teleno;

    public Student() {
    }

    public Student(String xh, String name, String teleno) {
        this.xh = xh;
        this.name = name;
        this.teleno = teleno;
    }

    public String getXh() {
        return xh;
    }

    public void setXh(String xh) {
        this.xh = xh;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getTeleno() {
        return teleno;
    }

    public void setTeleno(String teleno) {
        this.teleno = teleno;
    }
}
