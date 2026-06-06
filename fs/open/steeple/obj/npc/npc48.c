inherit NPC;
#include <ansi.h>
void create()
{
        set("nickname",HIW + "黑白雙剎" + NOR);
        set_name("黑剎郎君", ({"black-ghost","ghost"}));
        set("age",8710);
        set("long","焚天魔王的兩大護法之一，練有極其陰寒的「葬列剖墳手」和「四燄魂舌」\n");
	set("title",HIW + "～幻影～" + NOR);
        set("gender","男姓");
        set("str",35);
        set("con",35);
        set("cor",30);
        set("cps",30);
        set("attitude","aggressive");
        set("bellicosity",6000);
        set("max_gin",7000);
        set("gin",7000);
        set("max_sen",7000);
        set("sen",7000);
        set("max_kee",100000);
        set("kee",100000);
        set("combat_exp",18000000);
        set("max_force",800000);
        set("force",4000000);
        set("force_factor",45);
        set("clan_kill",1);
        set_skill("dodge",130);
        set_skill("force",130);
        set_skill("badforce",130);
        set_skill("mogi-steps",130);
        set_skill("unarmed",150);
        set_skill("literate",200);
        set_skill("mogi-strike5",120);
        set_skill("parry",140);
        set_skill("move",140);
        map_skill("unarmed","mogi-strike5");
        map_skill("dodge","mogi-steps");
        map_skill("move","mogi-steps");
        map_skill("force","badforce");
        map_skill("parry","mogi-strike5");
  
        set_temp("apply/armor",70);
        set_temp("apply/damage",70);
        setup();
        
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
 if(str=="askgod ghost" || str=="askgod black-ghost"){
 write(HIY + "黑剎郎君冷笑：「在魔王的地盤上面前求神問卜!?先問問魔王還差不多。」去死吧!!\n" + NOR);
 ghost->kill_ob(who);
 return 1;                                                 
                  }
}

int accept_fight(object who)
{
return notify_fail("黑剎郎君說道 : 我沒空陪你玩。\n");
}


void heart_beat()
{
 object env,mob,*enemy,target;
 int i;

 mob = this_object(); 
 env = environment(mob);
 
 if( !query("wield") )
 {
   set("wield",1);
   command("wield all");
 }
 
 if( random(100) < 27)
 {
    enemy=mob->query_enemy();
        if( i = sizeof(enemy) ) {
    target=enemy[random(i)];
    if( env == environment(target) )
    {
      message_vision(HIW + "\n                        ～幻～影～心～訣～

" + HIM + "\n
$N四指一擦，紫黑色的魔界之火轟然而生, 彷彿不吸盡所有的光亮
絕不停止 
就在光線消失殆盡之際，$N踩影而遁，使出一式" + HIR + "「四燄魂舌」" + HIM + "朝
$n的眉心直直指去
\n" + NOR,mob,target);
      target->receive_wound("force",10000);
      target->receive_wound("kee",4000);
      COMBAT_D->report_status(target, 1);
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
if(me->query("quest/start_game")< 49)
       {
        tell_object(users(),HIY + "
恭喜" + HIW+me->query("name")+HIY + "挑戰" + HIG + "『" + HIR + "第四十八層試煉ソ塔" + HIG + "』" + HIY + "通過！！

" + HIW + "希望"+me->query("name")+"能不負眾望，勇闖" + HIG + "『" + HIY + "第四十九層試煉ソ塔" + HIG + "』" + HIW + "。
	" + NOR);
	me->set("quest/start_game",49);
        destruct (this_object ());
       }
{
        :: unconcious();
	tell_object(me,HIW + "系統：你已經通過測試，系統不做任何更改。\n" + NOR);
	destruct(this_object());
}
}
