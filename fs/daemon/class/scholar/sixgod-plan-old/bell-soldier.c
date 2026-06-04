//By sueplan 提升殺氣50點 - 振軍計
//DELAY TIME 60秒 
#include <ansi.h>
inherit SSERVER;
 int delup(object me);
int perform(object me, object target)
{
        int bell=me->query("bellicosity");
        if( target != me)
                return notify_fail("此計只能對自己用。\n");
        if(me->query("force")<1000)
                return notify_fail("你的內力不夠。\n");
        if(me->query("bellicosity")>2000)
                return notify_fail("你已經無法在提升你的殺氣了。\n");
        if( me->query("family/family_name") != "儒門")
        return notify_fail("你並非儒門的人，不給你用咧！！^_^\n");
        if( me->query_temp("bellup"))
        return notify_fail("軍心已經振奮了, 短時間內是無法再振奮軍心的。\n");
        message_vision(
        HIY + "$N熟知『六韜奇略』中領兵之道在於氣﹐提起心中好戰的意志!!\n" + NOR,me);
        me->add("bellicosity",50);
        me->set_temp("bellup",1);
        me->add("force",-500);
         call_out("delup",20,me);
        return 1;
}
 int delup(object me)
{
        if(me) {
        me->delete_temp("bellup");
        }
        return 1;
}


