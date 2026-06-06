inherit ROOM;
#include <ansi.h>

void create()
{
        set("short",YEL + "森林" + NOR);
        set("long",@LONG
四周已經被數木呈凹字形給阻隔住了, 除了你來時的路以外, 在
你的正前方, 站立著一個木像，木像由於受到風、雨水的侵襲，已經
變的有點斑黃老舊，樹林中，偶爾會傳來陣陣的吼叫聲，看來這裡似
乎有著不友善的動物...
LONG);
        set("item_desc",([
"木像":"你仔細的注視著木像, 發覺到雕像似乎缺少著一的部分...\n",
]));
        set("exits",([
"south":__DIR__"d-04",
]));
        set("objects",([
__DIR__"npc/wood-worm":5,
]));
        set("no_transmit",1);
        set("evil-area",1);
        set("wood-area",1);
        setup();
}

void init()
{
add_action("do_search","search");
}

int do_search(string arg)
{
object me=this_player();
        if(!arg || arg!="木像")
                return 0;
        tell_object(me,"
你發現木像缺失了一隻左手。\n");
        me->set_temp("evil/king/statue_search_wood",1);
        return 1;
}

