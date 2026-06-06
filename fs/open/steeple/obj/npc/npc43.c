#include <ansi.h>
inherit NPC;
void create() {
        
        set_name("碧衣魔將",({"seven-dark"}));
        set("long",
   "\n綠玉碧衣, 深沉而無語, 無法判斷他下一步的行動是什麼.\n");

        set("age",3121);
        set("str",35);
        set("title",HIW"～幻影～"NOR);
        set("cor",35);
        set("race","人類");
        set("gender","雄性");
        set("attitude","aggressive");
        set("class","fighter");
        set("bellicosity",7500);
        set("max_gin",9000);
        set("max_kee",50000);
        set("max_sen",9000);
        set("max_force",500000);
        set("force",500000);
        set("force_factor",65);
        set("combat_exp",13000000);
        set("clan_kill",1);
        set_skill("unarmed",100);
        set_skill("dodge",100);
        set_skill("mogi-steps",100);
        set_skill("move",80);
        set_skill("parry",100);
        set_skill("literate",130);
        set_skill("mogi-strike2",100);
        set_skill("force",120);
        set_skill("badforce",90);
        map_skill("unarmed", "mogi-strike2");
        map_skill("dodge","mogi-steps");
        map_skill("parry","badstrike");
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
      message_vision(HIW"\n                        ～幻～影～心～訣～

"HIB"\n
$N指圓為心，方圓百里的妖邪魂魄瞬間飛奔群聚於此，鬼哭獸吼直
竄腦中轟然欲裂
隨$N迅雷一指，一式"MAG"『千首積屍  天懲無視』"HIB"的噬血屍氣活若閻羅
直奔逼竄$n的七孔之中
\n"NOR,mob,target);
	mob->add("kee",2000);
      target->receive_damage("kee",2000);
      COMBAT_D->report_status(target, 1);
    }
 }  
   set_heart_beat(1);
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
if(me->query("quest/start_game")< 44)
       {
        message_vision(HIY"
恭喜"HIW+me->query("name")+HIY"挑戰"HIG"『"HIR"第四十三層試煉ソ塔"HIG"』"HIY"通過！！

"HIW"希望"+me->query("name")+"能不負眾望，勇闖"HIG"『"HIY"第四十四層試煉ソ塔"HIG"』"HIW"。
	"NOR,me);
	me->set("quest/start_game",44);
        destruct (this_object ());
       }
{
        :: unconcious();
	tell_object(me,HIW"系統：你已經通過測試，系統不做任何更改。\n"NOR);
	destruct(this_object());
}
}
