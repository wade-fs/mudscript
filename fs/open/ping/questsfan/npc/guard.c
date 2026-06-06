//守衛  by dhk 2000.5.5
#include <ansi.h>
inherit NPC;
#include "/open/open.h"
inherit F_MASTER;

void create()
{
        set_name("山莊守衛",({"leespace guard","guard"}));
        set("gender","男性");
        set("age",40);
        set("class","blademan");
        set("force_factor",15);
        set("long","宏禧山莊看門守衛武士 ,過濾閒雜人物進入宏禧山莊內。\n");
	set("max_kee",1);
	set("kee",1);
        set("combat_exp",1000000);
/*
	set_skill("blade",100);
        set_skill("dodge",90);
        set_skill("parry",90);
        set_skill("gold-blade",100);
        set_skill("fast-blade",100);
        set_skill("fly-steps",900);
        set_skill("sixforce",100);
        map_skill("blade","fast-blade");
        map_skill("parry","gold-blade");
        map_skill("dodge","fly-steps");
        map_skill("move","fly-steps");
        map_skill("force","sixforce");
*/	
        setup();
        //carry_object("/open/gblade/obj/gold-boots")->wear();
        //carry_object("/open/gblade/obj/gold-robe")->wear();
        //carry_object("/open/gblade/obj/gold-armor")->wear();
        add_money("cash",5);
}


void init()
{
        object ob;
        ::init();
        if(interactive(ob =this_player()) && !is_fighting() )
        {
        remove_call_out("greeting");
        call_out("greeting",2,ob);
        add_action("do_nod","nod");
        }
}

int accept_fight(object who)
{
return notify_fail("山莊守衛說道 : 對不起 , 我沒空陪你磨菇。\n");
}

void greeting(object ob)
{
if(!ob) return ;
if(!ob->query("family/family_name")&&ob->query("class")=="blademan")
{
command("say 你是來拜師的嗎？\n");
}
        if( ob->query("family/family_name")=="金刀門")
        {
        command("smile "+ob->query("id"));
        }
        if( ob->query("class")=="poisoner" )
        kill_ob(ob);
        if( ob->query("class")=="killer" )
        kill_ob(ob);
}

 int do_nod()
 {
 object ob;
 ob=this_player();
        if(!ob->query("family/family_name")&&ob->query("class")=="blademan")
        call_out("do_act1",4,ob);
  return 0;
 }
int do_act1(object ob)
{

command("say 原來你是仰慕老爺而來拜會參觀的呀！很抱歉你不能進去。\n");
ob->set_temp("allow-enter",1);

}

