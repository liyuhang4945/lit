package com.myweb.bean;

public class UserFrom {
    private String username;
    private String pwd;
    private String sex;
    private String[] hobbies = null;

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public String getPwd() {
        return pwd;
    }

    public void setPwd(String pwd) {
        this.pwd = pwd;
    }

    public String getSex() {
        return sex;
    }

    public void setSex(String sex) {
        this.sex = sex;
    }

    public String[] getHobbies() {
        return hobbies;
    }

    public void setHobbies(String[] hobbies) {
        this.hobbies = hobbies;
    }

    public UserFrom(String username, String pwd, String sex, String[] hobbies) {
        this.username = username;
        this.pwd = pwd;
        this.sex = sex;
        this.hobbies = hobbies;
    }
    
    public UserFrom() {
    }
}
