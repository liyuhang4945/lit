package com.myweb.bean;

import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;

public class MsgBoard {
    String name;
    String title;
    String content;
    StringBuffer allMessage;
    ArrayList<String> savedName;
    ArrayList<String> savedTitle;
    ArrayList<String> savedContent;
    ArrayList<String> savedTime;

    public MsgBoard() {
        savedName = new ArrayList<>();
        savedTitle = new ArrayList<>();
        savedContent = new ArrayList<>();
        savedTime = new ArrayList<>();
    }

    public void setName(String name) {
        this.name = name;
        savedName.add(this.name);
        Date time = new Date();
        SimpleDateFormat simpleDateFormat = new SimpleDateFormat("yyyy-MM-dd HH:mm:SS");
        String messTime = simpleDateFormat.format(time);
        savedTime.add(messTime);

    }


    public void setTitle(String title) {
        this.title = title;
        savedTitle.add(this.title);
    }

    public void setContent(String content) {
        this.content = content;
        savedContent.add(this.content);
    }

    public StringBuffer getAllMessage() {
        allMessage = new StringBuffer();
        allMessage.append("<table border=1>");
        allMessage.append("<tr>");
        allMessage.append("<th>留言者姓名</th>");
        allMessage.append("<th>留言者标题</th>");
        allMessage.append("<th>留言者内容</th>");
        allMessage.append("<th>留言者时间</th>");
        allMessage.append("</tr>");
        for (int i = 0; i < savedName.size(); i++) {
            allMessage.append("<tr>");
            allMessage.append("<td>");
            allMessage.append(savedName.get(i));
            allMessage.append("</td>");
            allMessage.append("<td>");
            allMessage.append(savedTitle.get(i));
            allMessage.append("</td>");
            allMessage.append("<td>");
            allMessage.append("<textarea>");
            allMessage.append(savedContent.get(i));
            allMessage.append("</textarea>");
            allMessage.append("</td>");
            allMessage.append("<td>");
            allMessage.append(savedTime.get(i));
            allMessage.append("</td>");
            allMessage.append("</tr>");

        }
        allMessage.append("</table>");
        return allMessage;
    }

}
