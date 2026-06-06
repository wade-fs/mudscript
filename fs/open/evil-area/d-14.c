inherit ROOM;
#include <ansi.h>

void create()
{
        set("short",HIY"沙漠"NOR);
        set("long",@LONG
四周已經被山壁呈凹字形給阻隔住了, 除了你來時的路以外, 在
你的正前方, 擺飾一個雕刻精美的木材雕像, 形狀彷彿是一個人形, 
可是又長著麒麟的頭角, 整體而言, 你可以很明顯的感覺到雕作者所
想表達的一股壓迫感, 莊嚴而肅靜的感覺不自主的由你最深沉的心底
升起, 不過, 你卻突然發現雕像彷彿有在移動著...
LONG);
        set("item_desc",([
"雕像":"你仔細的注視著雕像, 越看越覺得不對勁...\n",
]));
        set("exits",([
"south":__DIR__"d-13",
]));
        set("objects",([
__DIR__"npc/earth-worm":5,
]));
        set("no_transmit",1);
        set("evil-area",1);
        set("earth-area",1);
        setup();
}

void init()
{
add_action("do_search","search");
add_action("do_pull","pull");
add_action("do_push","push");
}

int do_search(string arg)
{
object me=this_player();
        if(!arg || arg!="雕像")
                return 0;
        tell_object(me,HIW"
你發現雕像的底盤部分並沒有完全著地, 也就是說, 雕像是漂浮著的!!

你再仔細的觀察了一次, 發覺雕像底下似乎有一個通道。\n"NOR);
        me->set_temp("evil/king/statue_search_earth",1);
        return 1;
}

int do_push(string arg)
{
object me=this_player();
        if(!arg || arg!="雕像")
                return 0;
        if(!me->query_temp("evil/king/statue_search_earth"))
                return notify_fail("你不曉得該往哪裡推，推了半天，雕像動都不動。\n");
        message_vision("$N使勁了吃奶的力氣推著雕像，雕像卻動也不動。\n",me);
return 1;
}

int do_pull(string arg)
{
object me,ob;
        me=this_player();
        ob=this_object();
        if(!arg || arg!="雕像")
                return 0;
        if(!me->query_temp("evil/king/statue_search_earth"))
                return notify_fail("你不曉得該往哪裡拉，拉了半天，雕像動都不動。\n");
        if(!ob->query_temp("can_pull"))
        {
                message_vision("$N使勁了吃奶的力氣拉著雕像，雕像卻動也不動。\n",me);
                return notify_fail("你累的一直喘～\n");
        }
        message_vision(YEL"雕像底盤的部分，受到土翎板的引響，被拉高騰空。

$N見機不可失，趕忙的走下了位於雕像底盤的通道。\n\n"NOR,me);
        ob->delete_temp("can_pull");
        me->delete_temp("evil/king/statue_search_earth");  
        message_vision("$N走下了通道，來到這裡。\n",me);
return 1;
}

