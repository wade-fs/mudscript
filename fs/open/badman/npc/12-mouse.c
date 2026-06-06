#include <ansi.h>
#include "/open/open.h"
inherit NPC;

object ob=this_object();
string do_mention(object who);
int j=0 ,k=1;
void create()
{      object ob;
        set_name("魏無牙", ({ "wei wu-ya","wei","ya"}) );
        set("gender", "男性" );
        set("title","十二星象");
        set("nickname","鼠");
        set("age",59);
        set("str",30);
        set("cps",30);
        set("cor",30);
        set("per",30);
        set("int",30);
        set("spi",30);
        set("con",30);
        set("kar",30);
        set("force",3000);
        set("max_kee",3000);
        set("sen",3000);
        set("max_sen",3000);
        set("kee",3000);
        set("max_gin",3000);
        set("gin",3000);
        set_skill("rain-throwing",100);
        set_skill("blackforce",100);
        set_skill("shade-steps",100);
        set("max_force",3000);
        set_skill("move",100);
        set_skill("force",100);
        set_skill("dodge",100);
        set_skill("parry",100);
        set_skill("throwing",120);
        map_skill("dodge","shade-steps");
        map_skill("move","shade-steps");
        map_skill("force","blackforce");
        map_skill("throwing","rain-throwing");
        set_skill("unarmed",200);
        map_skill("parry","rain-throwing");
        set("force_factor",20);
        set("chat_chance",10);
        set("chat_chance_combat", 75),
        set("chat_msg_combat", ({
                (: this_object(), "special_att2" :),
                (: this_object(), "special_att" :),
                (: this_object(), "special_att3" :),
                "魏無牙全身散發出透骨的寒氣 !\n",
                               })); 
        set("combat_exp", 2000000);
        set("attitude", "heroism");
       
        setup();
        add_money("gold",10);
       ob=carry_object("/open/badman/obj/mouse_bite.c");
       ob->set_amount(600);
       ob->wield();

}

int special_att()
{
        object *me,one;
        int i,before,after;
        me=this_player()->query_enemy();
        i=sizeof(me);
        one=enemy[random(i)];
        before = me->query("kee");
       message_vision("魏無牙自殘己身,以殺意換成魔氣。\n
            ……魏無牙身上發出一股強大的魔氣……\n
    ■魏無牙身上魔氣逐漸地聚集在雙手,在雙手上形成兩團殺氣■\n
            魏無牙倏地大喝一聲––『魔氣殺』––\n\n",one);
      message_vision("魏無牙突然喉頭一動～～　只見魏無牙口中噴出一道血柱往$N射去～～\n
魏無牙使的乃魔氣殺之
              終極～必殺奧義 『魔血氣殺』\n
只見$N慘遭滅頂,而魏無牙亦身受重創。\n",one);
        after = me->query("kee");
        one->receive_wound("kee",50+random(120));
         COMBAT_D->report_status(one);
        one->start_busy(2);

        return 1;
}
int special_att2()
{
        object *me,one;
        int i,before,after;
        me=this_player()->query_enemy();
        i=sizeof(me);
        one=enemy[random(i)];
        before = me->query("kee");
       message_vision("魏無牙自殘己身,以殺意換成魔氣。\n
            ……魏無牙身上發出一股強大的魔氣……\n
    ■魏無牙身上魔氣逐漸地聚集在雙手,在雙手上形成兩團殺氣■\n
            $N倏地大喝一聲––『魔氣殺』––\n\n",one);
      message_vision("
              第九層 『風魔狂轉業』\n
結果對$N造成極其嚴重的創傷。\n",one);



        after = me->query("kee");
        one->receive_wound("kee",60+random(70));
         COMBAT_D->report_status(one);
        one->start_busy(1);

        return 1;
}
int special_att3()
{
        object *me,one;
        int i;
        me=this_player()->query_enemy();
        i=sizeof(me);
        one=enemy[random(i)];
       message_vision("魏無牙自殘己身,以殺意換成魔氣。\n
            ……魏無牙身上發出一股強大的魔氣……\n
    ■魏無牙身上魔氣逐漸地聚集在雙手,在雙手上形成兩團殺氣■\n
            $N倏地大喝一聲––『魔氣殺』––\n\n",one);
      message_vision("
              第八層 『鬥魔無生魂』\n
結果對$N造成極其嚴重的創傷。\n",one);


        one->receive_wound("kee",40+random(70));
        one->apply_condition("bleeding",10);
        one->start_busy(1);
        COMBAT_D->report_status(one);
        return 1;
}













