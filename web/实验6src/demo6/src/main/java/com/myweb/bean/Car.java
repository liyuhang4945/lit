package com.myweb.bean;

public class Car {
    private String number;
    private String name;
    private String madeTime;

    public Car() {
    }

    public Car(String number, String name, String madeTime) {
        this.number = number;
        this.name = name;
        this.madeTime = madeTime;
    }

    public String getNumber() {
        return number;
    }

    public void setNumber(String number) {
        this.number = number;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getMadeTime() {
        return madeTime;
    }

    public void setMadeTime(String madeTime) {
        this.madeTime = madeTime;
    }
}
