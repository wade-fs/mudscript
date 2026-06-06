inherit NPC;
#include <ansi.h>
void create()
{
        object ob;
        set_name("邪靈", ({ "evil-ghost","evil","ghost" }) );
        set("long",
                "出沒於死靈幽谷的€白洞€內, 時常會偷襲進入的人!!\n");
        set("title",HIW"(死神)"NOR);
        set("age", 1000);
        set("max_gin", 10000);
        set("max_kee", 10000);
        set("max_sen", 10000);
        set("max_force", 5000);
        set("force",5000);
        set("max_atman",5000);
        set("max_mana",5000);
        set("atman",5000);
        set("mana",5000);
        set("force_factor",30);
        set("str", 99);
        set("cor", 99);
        set("spi", 99);
        set("int", 99);
        set("bellicosity",3000);
        set_temp("apply/attack", 100);
        set_temp("apply/damage", 100);
        set_temp("apply/armor",  100);
        set_skill("move",150);
        set_skill("dodge",150);
        set_skill("parry",150);
        set_skill("force",100);
        set_skill("unarmed",150);
        set_skill("mogi-strike2",100);
        set_skill("mogi-steps",100);
        map_skill("dodge","mogi-steps");
        map_skill("move","mogi-steps");
        map_skill("unarmed","mogi-strike2");
        map_skill("parry","mogi-strike2");
        set("combat_exp", 3000000);
        setup();
        carry_object("/open/mogi/village/obj/mclaw")->wield();

}
void heart_beat()
{
        object env,mob,target,obj;
        mixed enemy;
        int i,hurt,j,k;
        mob = this_object();
        env = environment(mob);
        if(!env) return ;
        enemy = all_inventory( environment(mob) );
        i=sizeof(enemy);

        if (!mob->is_fighting())
        {
          for (j=0 ; j < i ; j++)
          {
            if (!enemy[j]->is_fighting() && enemy[j]->is_character() && !enemy[j]->is_corpse() && living(enemy[j]) && enemy[j]->query("id")!="evil-ghost") 
            {
              mob->kill_ob(enemy[j]);
              if( !mob->query("changed") )
              {
              k=enemy[j]->query("killgrow/evil_ghost");
              mob->set("eff_kee",mob->query("max_kee")+k*10);
              mob->set("eff_gin",mob->query("max_gin")+k*10);
              mob->set("eff_sen",mob->query("max_sen")+k*10);
              mob->set("max_force",mob->query("max_force")+k);
              mob->set("force",mob->query("max_force")+k*100);
              mob->set("combat_exp",mob->query("combat_exp")+k*10);
              mob->set("bellicosity",mob->query("bellicosity")+k*10);
              mob->add_temp("apply/defense",(int)(k/20));
              mob->add_temp("apply/attack",(int)(k/100));
              mob->add_temp("apply/dodge",(int)(k/20));
              mob->add_temp("apply/parry",(int)(k/20));
              mob->set("changed",1);
              }
            }
          }
        }
        if(random(10) > 2)
        {
        enemy = all_inventory( environment(mob) );
        i=sizeof(enemy);
          if (mob->is_fighting())
          {
          message_vision( HIW"\n地獄之火突然從地上冒出來, 你整個人被灼傷了!!\n"NOR,mob);
            for (j=0 ; j < i ; j++)
            {
              if( enemy[j]->is_character() && !enemy[j]->is_corpse() && living(enemy[j]) && enemy[j]->query("id")!="evil-ghost")
              {
              enemy[j]->add("kee",-300);
              COMBAT_D->report_status(enemy[j]);
              }
            }
          }
        }   
        set_heart_beat(1);
        ::heart_beat();
   
}

void die()
{
        object me=query_temp("last_damage_from");
        object ob,ob2;
        ob=this_object();
        ob2=new("/open/ghost-hole/obj/flute");
        if(me->query_temp("ghost-hole/evil-ghost-flute"))
        {
        me->add("killgrow/evil_ghost",1);
        :: die();
        }
        else if(!me->query_temp("ghost-hole/kill-evil-ghost"))
        {
        me->add("killgrow/evil_ghost",1);
        me->set_temp("ghost-hole/kill-evil-ghost",1);
        :: die();
        }
        else if(me->query_temp("ghost-hole/kill-evil-ghost")<10)
        {
        me->add("killgrow/evil_ghost",1);
        me->add_temp("ghost-hole/kill-evil-ghost",1);
        :: die();
        }
        else
        {
        ob2->move(environment(me));
        message_vision(HIW"邪靈受不了$N強大的攻擊力, 急急忙忙的逃走了!!\n"NOR,me);
        message_vision(HIR"由於逃跑的過於匆促, 不小心掉下了一件東西....\n"NOR,me);
        me->set_temp("ghost-hole/evil-ghost-flute",1);
        destruct(ob);
        }
}

