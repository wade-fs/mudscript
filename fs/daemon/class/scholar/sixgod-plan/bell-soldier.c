//By sueplan 提升殺氣50點 - 振軍計
//DELAY TIME 60秒

/*************************************************************************************
修改 By Kalin (2003-06-17)
a.增加限制-解過儒尊
b.增加限制-exp>500萬
c.提高殺氣上線為4000
d.一次增加殺氣提高為500
e.損失force調高為1000
*************************************************************************************/

#include <ansi.h>
inherit SSERVER;
 int delup(object me);
int perform(object me, object target)
{

        int bell=me->query("bellicosity");
		if( !me->query("quests/god-plan"))
			return notify_fail("你沒解過孔明兵法的謎，不給你用咧！！^_^\n");
		if(!me->query("mark/sixgod-plan"))
			return notify_fail("你還沒解過『六韜奇略』!");
		if(me->query("combat_exp")<5000000)
			return notify_fail("你的經驗值不夠!");
        if( target != me)
                return notify_fail("此計只能對自己用。\n");
        if(me->query("force")<1000)
                return notify_fail("你的內力不夠。\n");
        //if(me->query("bellicosity")>2000)
		if(me->query("bellicosity")>4000)
                return notify_fail("你已經無法在提升你的殺氣了。\n");
        if( me->query("family/family_name") != "儒門")
			return notify_fail("你並非儒門的人，不給你用咧！！^_^\n");
        if( me->query_temp("bellup"))
			return notify_fail("軍心已經振奮了, 短時間內是無法再振奮軍心的。\n");
        message_vision(
        HIY + "$N熟知『六韜奇略』中領兵之道在於氣﹐提起心中好戰的意志!!\n" + NOR,me);
        //me->add("bellicosity",50);
		me->add("bellicosity",500);
        me->set_temp("bellup",1);
        //me->add("force",-500);
		me->add("force",-1000);
		call_out("delup",20,me);
		return 1;
}
 int delup(object me)
{
        if(me)
		{
			me->delete_temp("bellup");
        }
        return 1;
}


