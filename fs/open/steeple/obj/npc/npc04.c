#include <ansi.h>

#include "/open/open.h"
inherit NPC;
void create()
{
        set_name("練習生", ({ "trainee" }) );
        set("title", "黑牙聯");
        set("gender", "男性");
        set("long", "這是殺手的練習生。\n");
        set("age",12);
        set("attitude", "heroism");
        set("kee",600);
        set("max_kee",600);
        set("combat_exp",6000);
        setup();
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
if(me->query("quest/start_game")< 5)
       {
        tell_object(me,HIY + "
恭喜"HIW+me->query("name")+HIY"挑戰" + HIG + "『" + HIR + "第四層試煉ソ塔" + HIG + "』" + HIY + "通過！！

" + HIW + "希望"+me->query("name")+"能不負眾望，勇闖" + HIG + "『" + HIY + "第五層試煉ソ塔" + HIG + "』" + HIW + "。
	" + NOR);
	me->set("quest/start_game",5);
        destruct (this_object ());
       }
{
        :: unconcious();
	tell_object(me,HIW + "系統：你已經通過測試，系統不做任何更改。\n" + NOR);
	destruct(this_object());
}
}
