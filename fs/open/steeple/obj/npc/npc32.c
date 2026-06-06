inherit NPC;
#include <ansi.h>
inherit F_MASTER;
void create()
{
        set_name("莫無樂", ({ "run mou", "run", "mou" }));
        set("title",HIW"～幻影～"NOR"魔龍魔刀");
        set("nickname", "屍死無涯");
        set("gender", "男性");
        set("age", 40);
        set("attitude", "aggressive");
        set("long","莫無樂是莫無愁的同門，但想篡奪門主之位，而與獨孤嵊合作。\n");
        set("str", 45);
        set("cps", 45);
        set("cor", 45);
        set("have_book",1);
        set("mpower",1);
        set("env/魔性六斬","YES");
        set("bellicosity",3000);
        set("combat_exp",12000000);
        set("max_force", 500000);
        set("force", 500000);
        set("max_kee",50000);
        set("max_gin",10000);
        set("max_sen",10000);
        set("force_factor", 30);
        set_skill("force", 120);
        set_skill("parry",120);
        set_skill("dodge",120);
        set("functions/mdragon-dest/level",100);
        set_skill("blade",120);
        set_skill("dragon-blade",120);
        set_skill("powerforce",120);
        map_skill("force", "powerforce");
        map_skill("blade", "dragon-blade");
        map_skill("parry", "dragon-blade");
        set("chat_chance_combat",90);
        set("chat_msg_combat",({
            (: perform_action, "blade.mdragon-dest"   :)
        }));
        set_temp("apply/armor",100);
        set_temp("apply/defense",100);
        setup();
        carry_object("/daemon/class/blademan/obj/mar-blade")->wield();
        carry_object("/open/gblade/obj/dragon_book");
        add_money("gold",10);
}
void heart_beat()
{
 object env,mob,*enemy,target;
 int i;
 mob = this_object();
 env = environment(mob);
if( random(100) > 40)
 {
    enemy=mob->query_enemy();
    if(i=sizeof(enemy)) {
target=enemy[random(i)];
    if( env == environment(target) )
    {
message_vision(HIW"\n                        ～幻～影～心～訣～

"HIC"
莫無樂表情猙獰，施展出魔龍魔刀『屠人千萬～血流遍野』\n"+
"$N閃避不及，被打中要害，血流滿地\n"NOR,target);
	mob->add("kee",3000);
      target->receive_damage("kee",1400,mob);
      COMBAT_D->report_status(target,1);
    }
 }
}
   ::heart_beat();
}
int heal_up()
{
        if (!is_fighting() ) {
             message_vision (HIW"系統：戰鬥停止，$N回收中，。\n"NOR, this_object ());
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
if(me->query("quest/start_game")< 33)
       {
        tell_object(me,HIY"
恭喜"HIW+me->query("name")+HIY"挑戰"HIG"『"HIR"第三十二層試煉ソ塔"HIG"』"HIY"通過！！

"HIW"希望"+me->query("name")+"能不負眾望，勇闖"HIG"『"HIY"第三十三層試煉ソ塔"HIG"』"HIW"。
	"NOR);
	me->set("quest/start_game",33);
        destruct (this_object ());
       }
{
        :: unconcious();
	tell_object(me,HIW"系統：你已經通過測試，系統不做任何更改。\n"NOR);
	destruct(this_object());
}
}
