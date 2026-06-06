inherit ITEM;
#include <ansi.h>
inherit F_AUTOLOAD;
void create()
{
                set_name(HIY + "魔龍鱗" + NOR, ({ "dragon scale","scale",}) ); 
                set_weight(50);
                set("long",
 "黃金甲龍身上的鱗片 ,具有特殊的魔力
拿來使用可以將人瞬間傳送到魔界(use scale)....\n"

);
                if( clonep() )
                        set_default_object(__FILE__);
                else {
                        set("unit", "片");
                        set("value", 5000);
                        set("no_drop",1);
                        set("no_insert",1);
                        set("no_auc", 1);
                        set("no_sell",1);
                        set("no_give",1);
                        set("no_out",1);


                }
}

void init()
{
      add_action("do_magic", "use");
}
int do_magic(string str)
{
        object me;
        me = this_player();

        if(!str || str != "scale")
            return notify_fail("你在作什麼啊 ?\n");
          message_vision( 
sprintf("一片" + HIY + "光幕" + NOR + "慢慢將你籠罩 ,$N回到魔界的村莊。\n"), this_player() );
        me->move("/open/mogi/village/room/room-05.c");
        message_vision( 
sprintf("天邊出現一道" + HIY + "閃光" + NOR + ",只見$N飛來了這裡。\n"),this_player());
        return 1;
}
int query_autoload()
{
        return 1;
}


