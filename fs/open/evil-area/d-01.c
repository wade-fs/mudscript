inherit ROOM;
#include <ansi.h>

void create()
{
        set("short",HIC + "湖泊" + NOR);
        set("long",@LONG
四周已經被湖泊呈凹字形給阻隔住了，除了你來時的路以外，你
眼前的地上放置著一個有凹巢的石塊，凹巢內寫滿了許許多多密密麻
麻的文字，都是你前所未見過的字體，
LONG);
        set("item_desc",([
"石塊":"你仔細的注視著石塊, 似乎沒有什麼奇特的。\n",
"凹巢":"凹巢內沾有幾滴深藍色的液體，似乎曾經置放過什麼東西。\n",
]));
        set("exits",([
"north":__DIR__"d-02",
]));
        set("objects",([
__DIR__"npc/water-worm":5,
]));
        set("no_transmit",1);
        set("evil-area",1);
        set("water-area",1);
        setup();
}

void init()
{
add_action("do_search","search");
add_action("do_move","move");
}

int do_search(string arg)
{
object me=this_player();
        if(!arg || arg!="凹巢")
                return 0;
        tell_object(me,HIY + "
你仔細的搜尋著凹巢內部，突然發現了一個奇怪的地方～

        凹巢下似乎有另一個空間，裡面不時的傳來陣陣風聲

        或許\你可以將某樣液體放置於內。\n" + NOR);
        me->set_temp("evil/king/water_search",1);
        return 1;
}

int do_move(string arg)
{
object me,ob;
        me=this_player();
        ob=this_object();
        if(!arg || arg!="石塊")
                return 0;
        if(!me->query_temp("evil/king/water_search"))
                return notify_fail("你不曉得該往哪裡著手，移動了半天，石塊動都不動。\n");
        if(!ob->query_temp("can_move"))
        {
                message_vision("$N使勁了吃奶的力氣嘗試移動石塊，石塊卻動也不動。\n",me);
                return notify_fail("你累的一直喘～\n");
        }
        message_vision(HIC + "由於$N移動著石塊，放置於凹巢內的" + HIB + "水血" + HIC + "跟隨著晃動了起來～

        一瞬間" + HIB + "水血" + HIC + "突然暴漲出凹巢，將$N團團包住，吸入凹巢內～\n\n" + NOR,me);
        ob->delete_temp("can_move");
        me->delete_temp("evil/king/water_search");
        message_vision("$N從上方的通道掉下來，來到這裡。\n",me);
return 1;
}
