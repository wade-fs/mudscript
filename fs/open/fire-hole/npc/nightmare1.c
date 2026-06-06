//by frequency
inherit NPC;
inherit SSERVER;
#include <ansi.h>
void create()
{
        set("nickname",HIY"夢嵐舞空"NOR);
        set_name("夜無嵐", ({"nightmare lan","lan"}));        
        set("age",9700);
        set("long","吸收上古時期無盡玄陰之氣的夜之魂。 \n");
        set("title","夜夢雙妖");
        set("gender","女姓");
        set("attitude","heroism");
        set("str",35);
        set("con",35);
        set("cor",30);
        set("cps",30);
        set("per",50);
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
        set("force_factor",45);
        set("clan_kill",1);
        set_skill("dodge",120);
        set_skill("force",400);
        set_skill("badforce",300);
        set_skill("mogi-steps",120);
        set_skill("unarmed",120);
        set_skill("mogi-strike8",100);
        set_skill("parry",120);
        set_skill("literate",130);
        set_skill("move",120);
        map_skill("unarmed","mogi-strike8");
        map_skill("dodge","mogi-steps");
        map_skill("move","mogi-steps");
        map_skill("force","badforce");
        map_skill("parry","mogi-strike8");
        set_temp("apply/armor",90);
        set_temp("apply/damage",90);
        set_temp("absorb",3);
        setup();
        
}

void init()
{
	call_out("do_talk",10,this_player());
        ::init();
}
/*
void greeting()
{
	object ob,me;
        ob = this_player();
        me = this_object();
}
*/
int accept_kill(object me)
{
    object ob,ghost;
    ob=this_object();
    ghost=present( "nightmare en",environment(ob) );
     if( !present( "nightmare en",environment(ob))||!living(ghost)) return 1;
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
    i=sizeof(enemy);
   target=offensive_target(mob);
    if(!target) return ;
        force = target->query("force");
    if( env == environment(target) )
    {
      message_vision(HIW"
$N步法漸快身影漸散，空氣之中香氣郁郁，撩人心神。使
出了一式"HIY"『太陰虛幻神鑑●嵐之章』"HIW"
$N的一舉一動完全牽制住$n的所有動作，$n被困在舞陣之
中動彈不得 
\n"NOR,mob,target);
    
    for(i=0;i<5;i++)    
 COMBAT_D->do_attack(mob, target, mob->query_temp("weapon"));
     target->start_busy(2);
    }
 }  
   set_heart_beat(1);
   ::heart_beat();
   
}

void do_talk()
{
	object ob,me;
        ob = this_player();
        me = this_object();
        if(ob->query_temp("find_scroll") == 3)
        {
	 command("snort");
	 command("say 我以為是誰，原來是浪清心那小子的後輩。");
	 call_out("do_talk2",10,ob);
        }
}

int do_talk2()
{
	object ob,me;
        ob = this_player();
        me = this_object();
	command("say 我們姊妹自遠古以來所走，追求終極武道的路，就是被你的好師兄浪清心破壞的啊!!");
	call_out("do_talk3",10,ob);
        return 1;
}

int do_talk3()
{
	object ob,me;
        ob = this_player();
        me = this_object();
	command("say 原本這對武道的追求，應該在我們死時就跟著結束了。");
	call_out("do_talk4",10,ob);
        return 1;
}

int do_talk4()
{
	object ob,me;
        ob = this_player();
        me = this_object();
	command("say 但誰想得到，我們對你們聖火教的怨念實在太深了，嘿嘿，就算萬劫不復也要來報仇。");
	call_out("do_talk5",10,ob);
        return 1;
}

int do_talk5()
{
	object ob,me;
        ob = this_player();
        me = this_object();
	command("就是這樣，所以我們就找了兩個替死鬼來借屍還魂啦!!");
	call_out("do_talk6",10,ob);
        return 1;
}

int do_talk6()
{
	object ob,me;
        ob = this_player();
        me = this_object();
	command("say 而不巧又探聽到在這魔法陣的中心藏有你們聖火教的武學秘笈。");
	call_out("do_talk7",10,ob);
        return 1;
}

int do_talk7()
{
	object ob,me;
        ob = this_player();
        me = this_object();
	command("say 似乎保管秘笈的道士還有幾把刷子呢，但還是被我們兩三下擺\平了。");
	call_out("do_talk8",10,ob);
        return 1;
}

int do_talk8()
{
	object ob,me;
        ob = this_player();
        me = this_object();
	command("say 現在，我只要凝神把功\力全部傳輸(transfer)到眼前最亮的星辰(star)之中就能拿到手了!!");
	call_out("do_talk9",10,ob);
        return 1;
}

int do_talk9()
{
	object ob,me;
        ob = this_player();
        me = this_object();
	command("say 不過由於我實在對聖火教太過感冒了，因此決定先幹掉你再說...");
	call_out("do_talk10",10,ob);
        return 1;
}

int do_talk10()
{
	object ob,me;
        ob = this_player();
        me = this_object();
	command("say 所以現在...便給我去死吧!!");
	call_out("do_kill",5,ob);
        return 1;
}

int do_kill()
{
 	object ob,me,ghost;
        ob = this_player();
        me = this_object();
	ghost=present( "nightmare en",environment(me) );
        ghost->kill_ob(ob);
        me->kill_ob(ob);
        ob->delete_busy();
        return 1;
}
