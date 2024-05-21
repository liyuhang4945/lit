package com.myweb.bean;

public class Student {
    private String xh;
    private String name;
    private String birthday;

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

    public String getBirthday() {
        return birthday;
    }

    public void setBirthday(String birthday) {
        this.birthday = birthday;
    }

    public Student() {
    }

    public Student(String xh, String name, String birthday) {
        this.xh = xh;
        this.name = name;
        this.birthday = birthday;
    }
}
