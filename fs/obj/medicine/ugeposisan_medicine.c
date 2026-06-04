// yu-poison.c for doctor 雲龜破氣散
#include <ansi.h>
inherit COMBINED_ITEM;
void create()
{
        set_name("雲龜破氣散",({"ugeposisan"}));
        set("unit", "包");
        set("base_unit", "份");
        set("base_weight", 1);
        set_amount(1);
        setup();
}
void init()
{      add_action("do_throw","throw");       }

int do_throw(string arg)
{
   object me,target;
   me = this_player();
   target = present(arg, environment(me));
   if (!target) return notify_fail("找不到這個生物.\n");
   if(!arg) return notify_fail("指令格式: throw <目標>。\n");
   if( !me->is_fighting() ) return notify_fail("雲龜破氣散只能在戰鬥中使用。\n");
   if( (int)me->query_skill("godcure") > (int)target->query_skill("move")/2)
{
   message_vision(HIC + "$N對著$n撒出雲龜破氣散。\n" + NOR,me,target);
   message_vision(HIC + "只見$n閃躲不及, 吸入了大量的毒散, 臉上泛起一陣青白。\n" + NOR,me,target);
   message_vision(HIW + "$n被毒散撒中, 以至於內力全失形同廢人。\n" + NOR,me,target);
   target->set("force",0);
   me->start_busy(1);
}   else {
   message_vision(HIC + "$N對著$n撒出雲龜破氣散。\n" + NOR,me,target);
   message_vision(HIC + "$N一擊不中, 只見$n身法輕靈地躲了開。\n" + NOR,me,target);
}

       add_amount(-1);
       return 1;
}


