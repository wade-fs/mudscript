#include <ansi.h>
#include "/open/open.h"
inherit NPC;
void create()
{
        set_name("聖火使",({"prayer man","man"}));
        set("long","魔龍塔守護者，由幻影系統copy。\n");
        set("gender","男性");
        set("clan_kill",1);
        set("sec_kee","god");
        set("title",HIW + "～幻影～" + NOR);
        set("max_s_kee",1000);
        set("s_kee",1000);
        set("mpower",1);
        set("class","prayer");
        set("combat_exp",13000000);
        set("attitude","heroism");
        set("age",75);
        set("max_kee",50000);
        set("str", 60);
        set("cor", 60);
        set("cps", 60);
        set("force",500000);
        set("max_force",500000);
        set("force_factor", 30);
        set("max_gin",10000);
        set("max_sen",10000);
        set_skill("superforce", 250);
        set_skill("dodge", 120);
        set_skill("force",120);
        set_skill("move", 120);
        set_skill("literate",120);
        set_skill("parry", 120);
        set_skill("unarmed",120);
        set_skill("shift-steps",120);
        set_skill("universe",120);
        map_skill("force","superforce");
        map_skill("dodge","shift-steps");
        map_skill("move","shift-steps");
        map_skill("parry","universe");
        map_skill("unarmed","universe");
        set("functions/blood/level",200);
        set("functions/green/level",200);
        set("chat_chance_combat", 90);
                set("chat_msg_combat", ({
                (: perform_action("force.blood1") :),
                (: perform_action("force.blood2") :),
                (: perform_action("force.blood3") :),
        }));
        add_money("thousand-cash",20);
        set_temp("apply/defense",100);
        set_temp("apply/armor",100);
        setup();
        carry_object("/open/snow/obj/figring")->wield();
}
void heart_beat()
{
object me,room,*target;
int i,j;
me=this_object();
room=environment(me);
target=me->query_enemy(room);
if(i=sizeof(target)) {
if(random(100) > 50)
{
if(random(9) >= 5)
{
message_vision(HIY + "聖火使會心一擊『宇宙震爆』，頓時你狂吐鮮血！\n" + NOR,me);
for(j=0;j < i;j++) {
target[j]->add("kee",-2000); }
   }
   else
   {
message_vision(HIC + "聖火使仰天一笑，瞬時內息穩固。\n" + NOR,me);
me->receive_curing("kee",2000);
me->receive_heal("kee",2000);
if(random(9)>=5) {
    me->delete_busy();
}
    me->clear_condition();
   }
  }
}
  ::heart_beat();
  }
int accept_fight(object who)
{
 command("say 走開別煩我！\n");
 return 0;
}
int accept_kill(object who)
{
 who=this_player();
 command("kill "+who->query("id"));
 command("exert green");
 command("cmd god_kee");
 return 1;
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
if(me->query("quest/start_game")< 45)
       {
        message_vision(HIY + "
恭喜" + HIW+me->query("name")+HIY + "挑戰" + HIG + "『" + HIR + "第四十四層試煉ソ塔" + HIG + "』" + HIY + "通過！！

" + HIW + "希望"+me->query("name")+"能不負眾望，勇闖" + HIG + "『" + HIY + "第四十五層試煉ソ塔" + HIG + "』" + HIW + "。
	" + NOR,me);
	me->set("quest/start_game",45);
        destruct (this_object ());
       }
{
        :: unconcious();
	tell_object(me,HIW + "系統：你已經通過測試，系統不做任何更改。\n" + NOR);
	destruct(this_object());
}
}
