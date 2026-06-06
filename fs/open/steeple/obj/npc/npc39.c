#include <ansi.h>
inherit NPC;
void create() {
        
        set_name("墨衣魔將",({"seven-dark"}));
        set("long",
   "\n黟夜黔衣, 擅使毒, 見聞世間百毒千草, 醫術亦更上一層.\n");

        set("age",3121);
       set("title",HIW + "～幻影～" + NOR);
        set("str",35);
        set("cor",35);
        set("race","人類");
        set("gender","雄性");
        set("attitude","aggressive");
        set("class","fighter");
        set("bellicosity",7500);
        set("max_gin",13300);
        set("max_kee",50000);
        set("max_sen",13300);
        set("max_force",500000);
        set("force",500000);
        set("force_factor",50);
        set("combat_exp",13000000);
        set_skill("unarmed",100);
        set_skill("dodge",90);
        set_skill("mogi-steps",80);
        set_skill("move",80);
        set_skill("parry",80);
        set_skill("literate",170);
        set_skill("mogi-strike5",100);
        set("clan_kill",1);
        set_skill("force",120);
        set_skill("badforce",90);
        map_skill("unarmed", "mogi-strike5");
        map_skill("dodge","mogi-steps");
        map_skill("parry","mogi-strike5");
        map_skill("move","mogi-steps");
        map_skill("force","badforce");
        set("limbs",({"頭部","胸部","背部","腰部","毒掌"}));
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
 
 if( random(100) < 30)
 {
    enemy=mob->query_enemy();
    i=sizeof(enemy);
    target=enemy[random(i)];
    if( env == environment(target) )
    {
      message_vision(HIW + "\n                        ～幻～影～心～訣～

" + HIM + "\n
一瞬間，魔氣暴漲，迴風如割，壓風如打，毒氣從地面上滲出，透進魔風之中
$N一聲低喊" + HIW + "『送葬行列  剖天墳地』" + HIM + "，頓時氣旋炸裂，$n無所遁逃
\n" + NOR,mob,target);
      target->add("force",-1800);
      target->receive_wound("kee",1800);
	mob->add("kee",1800);
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
if(me->query("quest/start_game")< 40)
       {
        message_vision(HIY + "
恭喜" + HIW+me->query("name")+HIY + "挑戰" + HIG + "『" + HIR + "第三十九層試煉ソ塔" + HIG + "』" + HIY + "通過！！

" + HIW + "希望"+me->query("name")+"能不負眾望，勇闖" + HIG + "『" + HIY + "第四十層試煉ソ塔" + HIG + "』" + HIW + "。
	" + NOR,me);
	me->set("quest/start_game",40);
        destruct (this_object ());
       }
{
        :: unconcious();
	tell_object(me,HIW + "系統：你已經通過測試，系統不做任何更改。\n" + NOR);
	destruct(this_object());
}
}
