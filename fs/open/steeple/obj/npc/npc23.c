#include <ansi.h>
#include "/open/open.h"
inherit NPC;
string retitle();

void create()
{
object ob;
set_name("葉秀殺",({"master yar","yar","master"}));
set("long","他是名震江湖的一代殺手﹐黑牙聯的頭目。\n");
set("gender","男性");
set("title",HIW + "～幻影～" + NOR);
set("class","killer");
set("nickname","殺眼無情");
set("combat_exp",8000000);
set("attitude","heroism");
set("age",36);
set("str", 45);
set("cor", 34);
set("cps", 18);
set("per", 24);
set("int", 42);
set("kee",10000);
set("max_kee",10000);
set("gin",1600);
set("max_gin",1600);
set("atman",1200);
set("max_atman",1200);
set("mana",1000);
set("max_mana",1000);
set("force",100000);
set("max_force",100000);
set("quest/rain",1);
set_skill("cure",50);
set_skill("magic",20);
set_skill("literate",30);
set_skill("force",80);
set_skill("move",80);
set_skill("parry",60);
set_skill("dagger",90);
set_skill("dodge",100);

set_skill("throwing",120);
set_skill("blackforce",95);
set_skill("shade-steps",100);
set_skill("rain-throwing",100);
set_skill("shadow-kill",90);
map_skill("throwing","rain-throwing");
map_skill("dodge","shade-steps");
map_skill("force","blackforce");
set("bellicosity",1500);
set_temp("apply/armor",70);
set("force_factor",15);
set("chat_chance_combat",45);
set("chat_msg_combat",({
(:perform_action,"throwing.manakee":),
}));
setup();
create_family("黑牙聯",2,"主席");
ob=carry_object("/open/killer/obj/hate_knife");
ob->set_amount(300);
ob->wield();
carry_object("/open/killer/weapon/k_cloth3.c")->wear();
carry_object("/open/killer/weapon/k_boot3.c")->wear();
carry_object("/open/killer/weapon/k_arm3.c")->wear();
carry_object("/open/killer/weapon/k_head3.c")->wear();
carry_object("/open/killer/obj/k_ring.c");
}

void init()
{
        add_action("do_join","join");
}

int accept_kill(object ob)
{
command("say 沒想到居然有人敢來這撒野！！");
message_vision( this_object()->name()+"突然變臉﹐臉上出現殺氣。\n",ob);
this_object()->set("bellicosity",8000);
command("cmd bellup");
command("wear bell_ring");
return 1;
}

void heart_beat()
{
        if( is_fighting() ){
                if( query("kee") < query("eff_kee") )
                        command("exert recover");
        }
        :: heart_beat();
}


int heal_up()
{
        if (!is_fighting() ) {
             message_vision (HIW + "系統：戰鬥停止，$N回收中，。\n" + NOR, this_object ());
             destruct(this_object());
             return 1;
        }
        return ::heal_up() + 1;
}
void unconcious ()
{
 object me=query_temp("last_damage_from");
if(!present("fight_card",me))
{
tell_object(me,"\n\n系統：由於你沒攜帶晶片，所以無法記錄戰績。\n");
destruct (this_object ());
}
else
if(!me->query("quest/start_game"))
{
tell_object(me,"\n\n系統：由於你沒有正式登記，資料無法傳輸。\n");
destruct (this_object ());
}
else
if(me->query("quest/start_game")< 24)
       {
        message_vision(HIY + "
恭喜" + HIW+me->query("name")+HIY + "挑戰" + HIG + "『" + HIR + "第二十三層試煉ソ塔" + HIG + "』" + HIY + "通過！！

" + HIW + "希望"+me->query("name")+"能不負眾望，勇闖" + HIG + "『" + HIY + "第二十四層試煉ソ塔" + HIG + "』" + HIW + "。
	" + NOR,me);
	me->set("quest/start_game",24);
        destruct (this_object ());
       }
{
        :: unconcious();
	tell_object(me,HIW + "系統：你已經通過測試，系統不做任何更改。\n" + NOR);
	destruct(this_object());
}
}
