#include <ansi.h>
inherit NPC;

void create()
{
        set_name("丐幫門守",({"guard"}));
        set("long","他是丐幫的弟子\n");
        set("gender","男性");
        set("class","beggar");
        set("combat_exp",10000);
        set("attitude","friendly");
        set("age",40);
        set("str", 20);
        set("cor", 40);
        set("cps", 30);
        set("per", 35);
        set("spi", 20);
        set("con", 30);
        set("int", 30);
        set("kar", 30);
        set("inquiry",([
                "暗號" : "就是丐幫入幫暗號, 快回答【answer 暗號】我!!", 
        ]));
        set("max_gin",800);
        set("gin", 800);
        set("max_kee",1000);
        set("kee",1000);
        set("max_sen", 1000);
        set("sen", 1000);
        set("force",500);
        set("max_force",500);
        set_skill("staff",30);
        set_skill("pkdog-staff",10);
        map_skill("staff","pkdog-staff");
        set_skill("force",30);
        set_skill("pkdog-force",10);
        set_skill("pkdog-force",30);
        map_skill("force","pkdog-force");
        set("force_factor",3);
setup();
carry_object("/open/beggar/obj/staff.c")->wield();
}

void init()
{
        object ob;
        ::init();
        if(interactive(ob =this_player()) && !is_fighting() )
        {
          add_action("do_answer","answer");
        }
}


int do_answer(string arg)
{
  object me = this_player();
  if(arg != "一乞成名天下知")
        {
          command("say 你在說什麼玩意");
return 1;
        }
        else
        {
          command("say 您請進吧");
        me->set_temp("b_enter",1);
return 1;
        }
}

