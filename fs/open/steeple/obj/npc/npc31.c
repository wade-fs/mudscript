#include <ansi.h>
inherit NPC;
void create() {
        
        set_name("赤衣魔將",({"seven-dark"}));
        set("long",
   "\n血氣紅衣, 霸氣不掩, 忠義之心直率的表露於外, 好個魔界漢子。\n");

        set("age",3121);
        set("str",35);
        set("cor",35);
        set("race","人類");
        set("gender","雄性");
        set("title",HIW"～幻影～"NOR);
        set("attitude","aggressive");
        set("class","fighter");
        set("bellicosity",1500);
        set("max_gin",9000);
        set("max_kee",50000);
        set("max_sen",9000);
        set("max_force",500000);
        set("force",500000);
        set("force_factor",38);
        set("combat_exp",13000000);
        set_skill("blade",120);
        set_skill("dodge",120);
        set_skill("mogi-steps",120);
        set_skill("move",80);
        set_skill("parry",120);
        set_skill("literate",150);
        set_skill("mogi-strike6",150);
        set_skill("force",130);
        set_skill("badforce",90);
        map_skill("blade", "mogi-strike6");
        map_skill("dodge","mogi-steps");
        map_skill("parry","mogi-strike6");
        map_skill("move","mogi-steps");
        map_skill("force","badforce");
        set("clan_kill",1);
        set("limbs",({"頭部","胸部","背部","腰部"}));
        setup();
        carry_object("/open/mogi/castle/obj/blade-1")->wield();
 }
void heart_beat()
{
 object env,mob,*enemy,target;
 int i,hellfire;

 mob = this_object(); 
 env = environment(mob);
 
 if( !query("wield") )
 {
   set("wield",1);
   command("wield all");
 }
 
 if( random(100) < 20)
 {
    enemy=mob->query_enemy();
    i=sizeof(enemy);
    target=enemy[random(i)];
    hellfire = target->query_condition("hellfire",1);
    if( env == environment(target) )
    {
      message_vision(HIW"\n                        ～幻～影～心～訣～

"HIR"\n
炎血之氣激出紅色的魔霧開始在空氣中沸騰，$N的力量隨著血氣激
增，而$n卻被血霧牽制得無法動彈
在$N的力量到達最高點的時候，只聽$N大喝『"HIW"破日天渦太陽斷"HIR"』， 
暴走的魔氣幻化成血龍奔向$n
\n"NOR,mob,target);
	mob->add("kee",1400);
      target->receive_damage("kee",1400);
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
if(me->query("quest/start_game")< 32)
       {
        message_vision(HIY"
恭喜"HIW+me->query("name")+HIY"挑戰"HIG"『"HIR"第三十一層試煉ソ塔"HIG"』"HIY"通過！！

"HIW"希望"+me->query("name")+"能不負眾望，勇闖"HIG"『"HIY"第三十二層試煉ソ塔"HIG"』"HIW"。
	"NOR,me);
	me->set("quest/start_game",32);
        destruct (this_object ());
       }
{
        :: unconcious();
	tell_object(me,HIW"系統：你已經通過測試，系統不做任何更改。\n"NOR);
	destruct(this_object());
}
}
