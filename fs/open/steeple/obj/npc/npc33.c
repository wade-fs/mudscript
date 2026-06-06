#include <ansi.h>
inherit NPC;
void create() {
    object ob;    
        set_name("紫衣魔將",({"seven-dark"}));
        set("long",
   "\n攝邪紫衣, 為人詭計多端, 城府極深, 戰於詭暗.\n");

        set("age",3121);
        set("str",35);
        set("cor",35);
        set("title",HIW + "～幻影～" + NOR);
        set("race","人類");
        set("gender","雄性");
        set("attitude","aggressive");
        set("class","fighter");
        set("bellicosity",1500);
        set("max_gin",13000);
        set("max_kee",50000);
        set("max_sen",13000);
        set("max_force",500000);
        set("force",500000);
        set("force_factor",17);
        set("combat_exp",13000000);
        set_skill("throwing",100);
        set_skill("dodge",100);
        set_skill("mogi-steps",100);
        set_skill("move",80);
        set_skill("parry",100);
        set_skill("literate",130);
        set_skill("mogi-strike4",100);
        set_skill("force",120);
        set_skill("badforce",90);
        map_skill("throwing", "mogi-strike4");
        map_skill("dodge","mogi-steps");
        map_skill("parry","mogi-strike4");
        map_skill("move","mogi-steps");
        map_skill("force","badforce");
        set("clan_kill",1);
        set("limbs",({"頭部","胸部","背部","腰部"}));
        ob=carry_object("/open/mogi/castle/obj/throw-1");
        ob->set_amount(300);
        ob->wield();
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
 
 if( random(100) < 18)
 {
    enemy=mob->query_enemy();
    i=sizeof(enemy);
    target=enemy[random(i)];
    if( env == environment(target) )
    {
      message_vision(HIW + "\n                        ～幻～影～心～訣～

" + HIB + "\n
$N魔氣盡放，瞬間妖氣滿溢，形成一個奇異的結界 
$N腳步輕點剎那間逼近了$n，左手食指往$n眉心點去
喝道一聲" + HIM + "『吞噬』" + HIB + "，$n的精氣神在眨眼間盡被吸入$N體內
\n" + NOR,mob,target);
      target->receive_damage("kee",1500);
	mob->add("kee",1500);
      target->add("force",-1800);
      target->set("mana",0);
      target->set("atman",0);
      target->add("sen",-550);
      target->add("gin",-550);
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
if(me->query("quest/start_game")< 34)
       {
        message_vision(HIY + "
恭喜" + HIW+me->query("name")+HIY + "挑戰" + HIG + "『" + HIR + "第三十三層試煉ソ塔" + HIG + "』" + HIY + "通過！！

" + HIW + "希望"+me->query("name")+"能不負眾望，勇闖" + HIG + "『" + HIY + "第三十五層試煉ソ塔" + HIG + "』" + HIW + "。
	" + NOR,me);
	me->set("quest/start_game",34);
        destruct (this_object ());
       }
{
        :: unconcious();
	tell_object(me,HIW + "系統：你已經通過測試，系統不做任何更改。\n" + NOR);
	destruct(this_object());
}
}
