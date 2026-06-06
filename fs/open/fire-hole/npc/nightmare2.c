//by frequency
inherit NPC;
#include <ansi.h>
void create()
{
        set("nickname",HIC"氤氰染月"NOR);
        set_name("夜末氤", ({"nightmare en","nightmare en"}));        
        set("age",9700);
        set("long","吸收上古時期無盡玄陰之氣的夜之魂。 \n");
        set("title","夜夢雙妖");
        set("gender","女姓");
        set("str",35);
        set("con",35);
        set("cor",30);
        set("cps",30);
        set("per",50);
        set("clan_kill",1);
        set("bellicosity",9800);
        set("max_gin",10000);
        set("gin",10000);
        set("max_sen",10000);
        set("sen",10000);
        set("max_kee",40000);
        set("kee",40000);
        set("combat_exp",9000000);
        set("max_force",18000);
        set("force",54000);
        set("force_factor",50);
        set_skill("dodge",100);
        set_skill("force",450);
        set_skill("badforce",120);
        set_skill("mogi-steps",120);
        set_skill("unarmed",120);
        set_skill("mogi-strike8",130);
        set_skill("parry",120);
        set_skill("literate",150);
        set_skill("move",100);
        map_skill("unarmed","mogi-strike8");
        map_skill("dodge","mogi-steps");
        map_skill("move","mogi-steps");
        map_skill("force","badforce");
        map_skill("parry","mogi-strike8");
        set_temp("apply/armor",100);
        set_temp("apply/damage",100);
        set_temp("absorb",3);
        setup();
               
}

int accept_fight(object who)
{
return notify_fail("夜末氤說道 : 我沒空陪你玩。\n");
}
int accept_kill(object me)
{
    object ob,ghost;
    ob=this_object();
    ghost=present( "nightmare lan",environment(ob) );
     if( !present( "nightmare lan",environment(ob))||!living(ghost)) return 1;
    else {
     ghost->kill_ob(me);
    return 1;
   }
}

void heart_beat()
{
 object env,mob,*enemy,target;
 int i,force;
 mapping exit;
 string *exit_name;
 
 mob = this_object();
 
 env = environment(mob);
 
 if( !query("wield") )
 {
   set("wield",1);
   command("wield all");
 }
 
 if( random(100) < 33)
 {
    enemy=mob->query_enemy();
        if( i=sizeof(enemy) )
        {
    target=enemy[random(i)];
                force = target->query("force");
    if( env == environment(target))
    {
      message_vision(HIY"
$N步法漸快身影漸散，空氣之中香氣郁郁，撩人心神。使出了一式
"HIR"『太陰虛幻寶鑑之  氤之章』"HIY"郁郁香氣相四周迅速擴散，
$n忍不住吸了一口，登時有如沉醉在美夢中如癡如醉。
\n"NOR,mob,target);

    for(i=0;i<5;i++)    
 COMBAT_D->do_attack(mob, target, mob->query_temp("weapon"));
    target->start_busy(2);
    }
 }  
        }
   set_heart_beat(1);
   ::heart_beat();
   
}
