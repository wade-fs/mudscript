//master of cure
//change by adam

#include <ansi.h>
#include "marksman.h"
inherit NPC;
inherit F_MASTER;
int time=0;

void create()
{
        set_name("黃忠",({"Master houng","master","houng"}) );
        set("long",
        "三國時代，劉備手下，五虎將之一，曾與武聖關公較量過，\n
        \n");
        set("nickname",HIC"百步穿揚"NOR);
        set("gender", "男性" );
        set("combat_exp",1000000);
        set("force"       , 4000);
        set("max_force"   , 4000);
        set("force_factor", 20);
        set("class","marksman");
        set("title","射日派開山祖師");
        set("family/family_name","射日派");
        set("guild_master",1);
        set_skill("unarmed",60);
        set_skill("parry",40);
set("no_lyssa",1);
        set_skill("dodge",60);
        set_skill("force", 60);
        set_skill("literate",60);
        set_skill("archery",100);
        set_skill("god-shooting", 80);
set("functions/ten_kee/level",100);
        set_skill("move",40);
        set_skill("rain-steps",80);
        map_skill("archery","god-shooting");
        map_skill("parry","rain-steps");
set("chat_chance_combat",1);
set("chat_msg_combat", ({
(: perform_action("archery.ten_kee") :),
}));

        setup();
carry_object(C_OBJ"/bow-10")->wield();
carry_object(C_OBJ"/arrow-9");
}

void init()
{
        add_action("do_join","join");
        set_heart_beat(1);
}

int do_join(string str)
{
        object me=this_player();
        if(str!=0)
          return notify_fail("請打\"join\"即可。\n");
        if(me->query("class")=="marksman")
        return notify_fail("你不要開玩笑了，你不是早就加入了嗎？\n");
if( me->query("class"))
return notify_fail("你已經加入了別的工會了。\n");
        me->set("class","marksman");

        tell_object(me,"恭禧你！你已經成為射手派的一員了，好好努力吧。\n");
         message("system",HIC "黃忠縱聲大笑 :\n
         歡迎" +this_player()->name()+ "加入射日派 !\n
         我們射手後繼有人了 !\n
         各位夥伴們 ,拭目以待吧 !!\n\n"NOR,users());
                
        
        
        return 1;
}
int accept_fight(object ob)
{
command("say 老夫很久沒動了.怕打不過你啦");
command("say 不過看這位俠客，如此有誠意，那就來會會你");
command("cmd holdup arrow with bow");
return 1;
}
int accept_kill(object ob)
{
command("say 老夫今天心情好.不至你於死地");
command("cmd holdup arrow with bow");
return 1;
}
