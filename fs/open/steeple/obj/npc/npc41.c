#include <ansi.h>
inherit NPC;
void create() {
        
        set_name("青衣魔將",({"seven-dark"}));
        set("long",
   "\n惱森青衣, 身形如雲過青空, 是七人之中身手最健者.\n");

        set("age",3121);
        set("str",35);
        set("cor",35);
        set("race","人類");
        set("gender","雄性");
        set("title",HIW + "～幻影～" + NOR);
        set("attitude","aggressive");
        set("class","fighter");
        set("bellicosity",7500);
        set("max_gin",13000);
        set("max_kee",50000);
        set("max_sen",13000);
        set("max_force",500000);
        set("force",500000);
        set("force_factor",95);
        set("combat_exp",6900000);
        set_skill("unarmed",100);
        set_skill("dodge",100);
        set_skill("mogi-steps",200);
        set_skill("move",80);
        set_skill("parry",100);
        set_skill("literate",130);
        set_skill("mogi-strike1",100);
        set_skill("force",120);
        set_skill("badforce",90);
        set("clan_kill",1);
        map_skill("unarmed", "mogi-strike1");
        map_skill("dodge","mogi-steps");
        map_skill("parry","mogi-strike1");
        map_skill("move","mogi-steps");
        map_skill("force","badforce");
        set("limbs",({"頭部","胸部","背部","腰部"}));
        setup();

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
 
 if( random(100) < 15)
 {
    enemy=mob->query_enemy();
    i=sizeof(enemy);
    target=enemy[random(i)];
    if( env == environment(target) )
    {
      message_vision(HIW + "\n                        ～幻～影～心～訣～

" + HIY + "\n
$N氣應魔元，狂風驟作，整個奈何之路均被籠罩其中，光漸漸地被 
黑闇吞沒了
暗雷轟動，一式" + HIM + "『魔龍捲雲  夜漠移換』" + HIY + "乍然發動了，魔氣在空中
狂奔蝕向所有人
\n" + NOR,mob,target);
	mob->add("kee",1900);
      target->receive_damage("kee",1900);
      target->start_busy(2);
      COMBAT_D->report_status(target, 1);
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
if(me->query("quest/start_game")< 42)
       {
        message_vision(HIY + "
恭喜" + HIW+me->query("name")+HIY + "挑戰" + HIG + "『" + HIR + "第四十一層試煉ソ塔" + HIG + "』" + HIY + "通過！！

" + HIW + "希望"+me->query("name")+"能不負眾望，勇闖" + HIG + "『" + HIY + "第四十二層試煉ソ塔" + HIG + "』" + HIW + "。
	" + NOR,me);
	me->set("quest/start_game",42);
        destruct (this_object ());
       }
{
        :: unconcious();
	tell_object(me,HIW + "系統：你已經通過測試，系統不做任何更改。\n" + NOR);
	destruct(this_object());
}
}
