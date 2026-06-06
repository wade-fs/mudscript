inherit NPC;
#include <ansi.h>
void create()
{
        set("nickname",HIW + "黑白雙剎" + NOR);
        set_name("白剎豔女", ({"white-ghost","ghost"}));
        set("age",8710);
        set("long","焚天魔王的兩大護法之一，長得極其美豔的女妖，練有陰毒邪\功\「髮天殺」和「亂雪冰天」\n");
        set("title",HIW + "～幻影～" + NOR);
        set("gender","女姓");
        set("str",35);
        set("con",35);
        set("cor",30);
        set("cps",30);
        set("attitude","aggressive");
        set("bellicosity",2000);
        set("max_gin",14000);
        set("gin",14000);
        set("max_sen",14000);
        set("sen",14000);
        set("max_kee",100000);
        set("kee",100000);
        set("combat_exp",14000000);
        set("max_force",500000);
        set("force",1000000);
        set("force_factor",40);
        set("clan_kill",1);
        set_skill("dodge",100);
        set_skill("force",100);
        set_skill("badforce",100);
        set_skill("mogi-steps",120);
        set_skill("unarmed",100);
        set_skill("mogi-strike3",120);
        set_skill("parry",100);
        set_skill("literate",180);
        set_skill("move",100);
        map_skill("unarmed","mogi-strike3");
        map_skill("dodge","mogi-steps");
        map_skill("move","mogi-steps");
        map_skill("force","badforce");
        map_skill("parry","mogi-strike3");
  
        set_temp("apply/armor",70);
        set_temp("apply/damage",70);
        setup();
        add_money("gold",25);
        
}

void init()
{
 ::init();
 add_action("do_cmd","cmd");
}

int do_cmd(string str){
 object who=this_player();
 object ob,ghost;
 ob=this_object();
 ghost=present( "ghost",environment(ob) );
 if(str=="askgod ghost" || str=="askgod white-ghost"){
 write(HIY + "白剎豔女冷笑：「在魔王的地盤上面前求神問卜!?先問問魔王還差不多。」去死吧!!\n" + NOR);
 ghost->kill_ob(who);
 return 1;                                                 
                  }
}

int accept_fight(object who)
{
return notify_fail("白剎豔女說道 : 我沒空陪你玩。\n");
}


void heart_beat()
{
 object env,mob,*enemy,target;
 int i,j,force;
 mapping exit;
 string *exit_name;
 
 mob = this_object();
 
 env = environment(mob);
 
 if( !query("wield") )
 {
   set("wield",1);
   command("wield all");
 }
 
 if( random(100) < 30)
 {
    enemy=mob->query_enemy();
        if( i = sizeof(enemy) ) {
    target=enemy[random(i)];
    if( env == environment(target) )
    {
      message_vision(HIW + "\n                        ～幻～影～心～訣～

" + HIW + "
瞬間, 冷雪紛紛, 陰風慘慘, 白霜如星落, 銀萃如光轉, 彷彿凍結
了血液一般, 凝止了一切
只見$N左手輕輕一拂, 漫天冰雪疾飛狂轉, 一式" + HIB + "「亂雪冰天」" + HIW + "
朝著所有有溫度之物襲去
\n" + NOR,mob);
	mob->add("kee",3000);
      for(j=0;j < i;j++){
      enemy[j]->start_busy(2);
      enemy[j]->add("kee",-3000);
      COMBAT_D->report_status(enemy[j], 1);
                        }
    }
        }
 }  
   set_heart_beat(1);
   ::heart_beat();
   
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
if(me->query("quest/start_game")< 46)
       {
        tell_object(users(),HIY + "
恭喜" + HIW+me->query("name")+HIY + "挑戰" + HIG + "『" + HIR + "第四十五層試煉ソ塔" + HIG + "』" + HIY + "通過！！

" + HIW + "希望"+me->query("name")+"能不負眾望，勇闖" + HIG + "『" + HIY + "第四十六層試煉ソ塔" + HIG + "』" + HIW + "。
	" + NOR);
	me->set("quest/start_game",46);
        destruct (this_object ());
       }
{
        :: unconcious();
	tell_object(me,HIW + "系統：你已經通過測試，系統不做任何更改。\n" + NOR);
	destruct(this_object());
}
}
