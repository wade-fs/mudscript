inherit ROOM;
#include <ansi.h>

void create()
{
	set("short","野人村　入口");
	set("long",@LONG
周圍圍繞著茂密的樹林跟一排排的木樁，所謂的道路，也不過是
一堆爛泥所鋪設成的走道，高大的木造房屋，粗糙的裝潢，顯露出未
開化的文明，路上行走的人十分稀少，大部份身上都掛著某種動物的
骨骸。
設置於進出村莊附近的哨站，野人村的戰士們在此輪替交換哨點。
LONG);
	set("exits",([
"south":__DIR__"e06",
"down":__DIR__"e13",
]));
	set("objects",([
__DIR__"npc/wild01":1,
]));
	set("mark",2);
	set("outdoors",1);
	setup();
}

int valid_leave(object me,string dir)
{
        if( dir == "down" )
        {
                if( present("wild soldier",environment(me)) && !me->query_temp("wild/mask") )
                {
                        message_vision(HIY + "野人哨兵擋住了你的去路！\n" + NOR,me);
                        return notify_fail(HIY + "你無法通過。\n" + NOR);
                }
                else
                        return 1;
        }
return 1;
}
