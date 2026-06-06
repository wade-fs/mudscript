 inherit NPC;
#include <ansi.h>
void create()
{
        set_name("嬰兒",({"baby"}));
        set("long",@LONG
一個剛出生的嬰兒，不知得了什麼怪病，一直抖不停。
LONG);
        set("str",1);
        set("con",1);
        set("cor",1);
        set("int",1);
        set("max_kee",5);
        set("max_gin",5);
        set("max_sen",5);
        set("age",1);
        set("combat_exp",32);
        setup();
}

void heart_beat()
{
        object ob,me,obj;

        ob = this_object();

        if( ob->query_temp("cure") )
        {
                ob->add_temp("crying",1);
                if(ob->query_temp("crying") < 10 )
                {
                        message_vision(HIY"$N不斷的放聲大哭～！\n"NOR,ob);
                }
                else
                {
                        me = present(ob->query_temp("cure_id"),environment(ob));
                        message_vision(HIY"
[嗚哇‵哇～嗚哇‵哇～]$N放聲大哭～

突然間$N口中吐出一顆紅色的石頭！

隔壁鄰居　張大嘴的老婆跑了過來～對著你劈頭就罵～[小孩子哭成這樣你都不理！]

霹靂啪啦罵了一頓後，發現才發現了地上躺著周老的屍體，臉色十分恐慌！

$n趕忙的解釋了一陣，農婦才放心的說：[那這孩子就交給我照顧好了，總比跟著$n東奔西跑

居無定所來的好多了。]

說完便將嬰兒帶回隔壁家中．．
\n"NOR,ob,me);
        
                        obj = new(__DIR__"obj/red-stone");
                        obj->move(environment(ob));
                        destruct(ob);
                }
        }
        ::heart_beat();
}
