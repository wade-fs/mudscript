inherit ROOM;
#include <ansi.h>

void create()
{
        set("short","蛇寨 置物室");
        set("long",@LONG
在你眼前有一個蛇型的座椅，左右兩旁皆被石壁給包圍住，看起
來格外的擁擠。
LONG);
        set("item_desc",([
"座椅":"座椅的左手邊有著一塊蛇型的凹槽，大小約與項鍊差不多。\n",
"石壁":"石壁上並無值得注意的地方。\n",
]));
        set("no_transmit",1);
        set("objects",([
__DIR__"npc/hau_snake":1,
__DIR__"npc/snake_soldier":2,
]));
        set("exits",([
"south":__DIR__"r-19",
]));
        setup();
}

void init()
{
add_action("do_put","put");
}

int do_put(string arg)
{
object me,obj;

        me = this_player();

        if( !arg )
                return 0;
        if( arg != "snake gem" && arg!= "gem" )
                return 0;
        if( !present("snake gem",me) )
                return notify_fail("你怎麼裝也無法將項鍊塞入座椅的蛇型凹槽內，似乎不合。\n");

        message_vision(HIY"$N將蛇型項鍊放入了座椅的左扶手處。

突然$N角下的地板坍塌～$N一個站不穩，滑了下去～\n"NOR,me);
        destruct(present("snake gem",me));
        me->move(__DIR__"r-23");
        tell_room(__DIR__"r-23",HIY"鐺～的一聲，似乎有東西掉落下來～\n"NOR);
        obj=new(__DIR__"npc/obj/snake_gem");
        obj->move(environment(me));
return 1;
}

