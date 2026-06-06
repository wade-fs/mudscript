inherit NPC;
#include <ansi.h>
inherit F_MASTER;
void create()
{
        set_name("莫無歡", ({ "hun mou", "hun", "mou" }));
        set("title","魔龍狂刀");
        set("nickname", "血流成河");
        set("gender", "男性");
        set("age", 40);
        set("attitude","aggressive");
        set("long","莫無歡為莫無樂的弟弟，其幫助大哥，誓奪門主之位。\n");
        set("str", 45);
        set("cps", 45);
        set("int", 45);
        set("bellicosity",2500);
        set("env/魔性六斬","YES");
        set("have_book",1);
        set("mpower",1);
        set("combat_exp",5000000);
        set("max_force", 10000);
        set("force",    10000);
        set("max_kee",10000);
        set("max_gin",10000);
        set("max_sen",10000);
        set("force_factor", 30);
        set_skill("force", 100);
        set_skill("parry",100);
        set_skill("dodge",100);
        set_skill("blade",120);
        set_skill("dragon-blade",120);
        set_skill("powerforce",100);
        map_skill("force", "powerforce");
        map_skill("blade", "dragon-blade");
        map_skill("parry", "dragon-blade");
        set_temp("apply/armor",100);
        set_temp("apply/damage",100);
        setup();
        carry_object("/daemon/class/blademan/obj/kar-blade")->wield();
        add_money("gold",10);
}
void heart_beat()
{
 object env,mob,*enemy,target;
 int i;
 mob = this_object();
 env = environment(mob);
if( random(100) > 50)
 {
    enemy=mob->query_enemy();
    if(i=sizeof(enemy)) {
target=enemy[random(i)];
    if( env == environment(target) )
    {
message_vision(HIC"
莫無歡雙目怒視，施展出魔龍狂刀『屠人十百～屍體遍野』\n"+
"$N閃避不及，被打中要害，血流滿地\n"NOR,target);
      target->receive_damage("kee",500,mob);
      COMBAT_D->report_status(target,1);
    }
 }
}
   ::heart_beat();
}
