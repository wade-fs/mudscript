#include <ansi.h>
#include "/open/open.h"
inherit NPC;
void create()
{
        set_name("段家第十一代弟子",({"trainee"}));
         set("long","這是一名精壯的漢子, 正在和同伴練習六脈神劍的功\夫。\n");
        set("gender","男性");
        set("class","scholar");
        set("combat_exp", 40000);
        set("attitude","peaceful");
        set("age",23);
        set("force",300);
        set("max_force",300);
        set_skill("force",30);
        set_skill("unarmed",40);
        set_skill("sunforce",30);
        set_skill("linpo-steps",40);
        set_skill("six-fingers",40);
        map_skill("force","sunforce");
        map_skill("dodge","linpo-steps");
        map_skill("move","linpo-steps");
        map_skill("unarmed","six-fingers");
        map_skill("parry","six-fingers");
        set_temp("apply/dodge",30);
        setup();
        add_money("silver",20);
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
if(me->query("quest/start_game")< 9)
       {
        tell_object(me,HIY + "
恭喜" + HIW+me->query("name")+HIY + "挑戰" + HIG + "『" + HIR + "第八層試煉ソ塔" + HIG + "』" + HIY + "通過！！

" + HIW + "希望"+me->query("name")+"能不負眾望，勇闖" + HIG + "『" + HIY + "第九層試煉ソ塔" + HIG + "』" + HIW + "。
	" + NOR);
	me->set("quest/start_game",9);
        destruct (this_object ());
       }
{
        :: unconcious();
	tell_object(me,HIW + "系統：你已經通過測試，系統不做任何更改。\n" + NOR);
	destruct(this_object());
}
}
