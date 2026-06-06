#include "/open/open.h"
#include <command.h>

inherit NPC;

void create()
{
        set_name("巡邏禁衛軍",({"soldier"}) );
        set("gender","男性");
        set("age",25);
        set("class","soldier");
        set("str",40);
        set("long","京城內位階最低的軍官，負責城內的守衛及巡邏工作，一身軍服看起
來帥呆了。\n");
        set("max_kee",600);
        set("combat_exp", 8000);
        set("inquiry", ([
          "thief" : "這京城裡大盜也不是沒有過, 只是這次鬧的滿城風雨呀。",
        ]));
        set_skill("blade",40);
        set_skill("parry",30);
        set_skill("dodge",20);
        set_skill("her-blade",40);
        map_skill("blade","her-blade");
        set_temp("apply/damage",40);
        set_temp("apply/dodge",40);
        set_temp("apply/attack",40);

        setup();
        carry_object(CAPITAL_OBJ"Ns_suit")->wear();
        carry_object(CAPITAL_OBJ"Ns_boots")->wear();
        carry_object(CAPITAL_OBJ"Ns_hat")->wear();
        carry_object(CAPITAL_OBJ"Ns_blade")->wield();
}

void init()
{
        set_heart_beat(1);
        :: init();
}

void heart_beat()
{
        object ob=this_object();
        if( random(20) < 1 )
        if( !is_fighting() )
                GO_CMD->main(ob, environment(ob)->query("gopath"));
        :: heart_beat();
}

int accept_kill(object who)
{
        who->set_temp("殺京城巡邏禁衛軍",1);
        command("say 大膽"+RANK_D->query_rude(who)+who->name()+"﹐竟敢在天子腳下
搗亂。");
        return 1;
}
int accept_fight(object who)
{
        return notify_fail("禁衛軍說：對不起，我正在執行公務。\n");
}

void greeting(object who)
{
        int power;
        if( who->query("class") == "officer")
        {
           power = who->query("max_officer_power");
           if( power <1000)
           {
             command("say 大人進京面上啊!!");
           }else
           {
             command("bow "+getuid(who));
           }
           return;
        }

        if( who->query_temp("殺京城巡邏禁衛軍") )
        {
          command("angry "+getuid(who));
          command("say 你這個擾亂城內秩序的人，還不束手就擒。\n");
          kill_ob(who);
        }
        else
        {
          if( who->query_temp("有向城門守衛報告") )
                command("smile "+getuid(who));
          else
          {
                command("stare "+getuid(who));
                command("say 在京城裡要守規矩喔, 否則送入大牢, 絕無例外!!");
          }
        }
        return;
}
