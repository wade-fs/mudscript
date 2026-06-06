#include <ansi.h>
#include "/open/open.h"
inherit NPC;
string do_mdragon();
string do_mblade();
void create()
{
set_name("莫無愁",({"master mou","mou","master"}));
set("long","神秘老人的愛兒，二十餘年來忍辱偷生，為的是找尋獨孤愁，報其父債，其狂龍刀法以快
達到其父的水準，又因鑑於當初父親所犯下的錯誤，改良【狂龍怒斬】研發出【魔龍訣】
雖威力不及父親，但確有其隱藏的後勁，且立誓與獨孤愁後代傳人勢不兩立。\n");
set("gender","男性");
set("attitude","heroism");
set("age",35);
set("class","blademan");
set("nickname",HIR + "復仇魔刀" + NOR);
set("title",HIW + "～幻影～" + NOR + "魔刀門第二代掌門");
create_family("魔刀門",2,"掌門");
set("score",100000);
set("force",100000);
set("max_force",100000);
set("env/魔性六斬","YES");
set("max_kee",30000);
set("force_factor",25);
set("mpower",1);
set("cor", 35);
set("str", 35);
set("per", 20);
set("int", 25);
set("functions/mdragon-dest/level",100);
set("cps", 35);
set("con", 35);
set("spi", 25);
set("kar", 35);
set("combat_exp", 10000000);
set("bellicosity", 3000);
set_skill("riding",80);
set_skill("force", 90);
set_skill("parry", 90);
set_skill("move", 60);
set_skill("dodge", 60);
set_skill("cure", 50);
set_skill("dragon-blade",105);
set_skill("powerforce", 90);
set_skill("blade", 150);
set_skill("literate", 40);
set_skill("unarmed", 20);
set_skill("spells", 20);
set_skill("magic", 20);
map_skill("parry","dragon-blade");
map_skill("blade","dragon-blade");
map_skill("force","powerforce");
set("chat_chance_combat",100);
set("chat_msg_combat",({
(: perform_action, "blade.mdragon-dest" :),
}));
set_temp("apply/armor",65);
set_temp("apply/damage",65);
setup();
carry_object("/daemon/class/blademan/obj/ublade.c")->wield();
carry_object("/daemon/class/blademan/obj/shield.c")->wear();
carry_object("/daemon/class/blademan/obj/six-neck.c");
add_money("gold",10);
}


void heart_beat()
{
 object env,mob,*enemy,target;
 int i;
 mob = this_object();
 env = environment(mob);
   if( random(100) > 70)
 {
    enemy=mob->query_enemy();
        if( i = sizeof(enemy) ) {
    target=enemy[random(i)];
    if( env == environment(target) )
    {
message_vision(HIW + "\n                        ～幻～影～心～訣～

" + HIY + "
莫無愁施展出魔刀『三斬歸元～魚龍嗜元』\n"+
"．．．『魚龍毒鴆～～煌嵐叢滅』．．．\n"+
"$N閃避不及，被打中要害，血流滿地\n" + NOR,target);
   mob->add("kee",1800);
    target->receive_damage("kee",1800,mob);
      COMBAT_D->report_status(target,1);
    }
        }
 }
   ::heart_beat();
}
int accept_kill(object who)
{
who=this_player();
command("wear all");
command("kill "+who->query("id"));
command("perform blade.mdragon-dest");
return 1;
}
int accept_fight(object who)
{
who=this_player();
command("wear all");
command("kill "+who->query("id"));
command("perform blade.mdragon-dest");
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
if(me->query("quest/start_game")< 29)
       {
        message_vision(HIY + "
恭喜" + HIW+me->query("name")+HIY + "挑戰" + HIG + "『" + HIR + "第二十八層試煉ソ塔" + HIG + "』" + HIY + "通過！！

" + HIW + "希望"+me->query("name")+"能不負眾望，勇闖" + HIG + "『" + HIY + "第二十九層試煉ソ塔" + HIG + "』" + HIW + "。
	" + NOR,me);
	me->set("quest/start_game",29);
        destruct (this_object ());
       }
{
        :: unconcious();
	tell_object(me,HIW + "系統：你已經通過測試，系統不做任何更改。\n" + NOR);
	destruct(this_object());
}
}
