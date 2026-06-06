//oldwoman.c

#include <ansi.h>

inherit NPC;
void create()
{
    set_name("賣魚老婦",({"oldwoman"}));
    set("title", "奇怪的");
    set("gender", "女性");
    set("age",72);
    set("attitude","friendly");
    set("long",@LONG
奇怪的老婦人!!她總是說她是賣魚的,可是卻從來沒有人買到魚.....

LONG);
 
    set("combat_exp",50);
    set("str",10);
    set("con",5);
    set("int",10);
    set("per",8);
    set("cps",3);
    set("kar",8);
    set("chat_chance",30);   
    set("chat_msg", ({
     HIC+"老婦說: 破邪洞窟?很恐怖的!!千萬不要進去呀!!\n"+NOR,
             "老婦說: 聽說聖火教主很喜歡到裡面去練功\喔!!\n",
          HIC+"老婦說: 聖火教裡面應該有通往洞窟的密道吧!!\n"+NOR,
    }) );
    set("inquiry",([
    "破邪洞窟":HIC+"先轉一下石頭(turn stone),再推開石壁(push wall)就可以進去了!!\n"+NOR,
 ])); 
    set_skill("dodge", 5);
    setup();
    add_money("coin", 15);
}
