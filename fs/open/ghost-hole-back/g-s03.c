inherit ROOM;
#include <ansi.h>
void create ()
{
set("short",HIB"死冥王祭台"NOR);
set("long",@LONG
這裡是【死】冥王的祭台, 在你眼前有一個
小小的石板(stone),除此之外, 裡面還放置了許
許多多奇奇怪怪的工具, 看來可能都是祭祀用的
工具。
LONG);
set("item_desc",([
"stone":"誠心奉獻(g-sac)生冥王之頭者，吾人將以『死蝶』作為謝禮。\n",
"石板":"誠心奉獻(g-sac)生冥王之頭者，吾人將以『死蝶』作為謝禮。\n",
]));
set("no_light",1);
set("exits",([
"east":__DIR__"g-s01",
]));
set("no_transmit",1);
setup();
}

void init()
{
add_action("do_gsac","g-sac");
}

int do_gsac(string arg)
{
object ob,ob2,me;
me=this_player();
ob=present("life-ghost-head",me);
ob2=new(__DIR__"obj/death-butterfly");
if(!arg)
return notify_fail("你要奉獻什麼東西??\n");
if(arg!="life-ghost-head"&&arg!="head")
return notify_fail("祭祀神台並不接受你所奉獻的物品!!\n");
if(!present("life-ghost-head",me))
return notify_fail("你身上並沒有生冥王的頭!!\n");
destruct(ob);
message_vision(HIB"一道藍色的光芒從天而降, 光柱中緩緩飄落一隻
蝴蝶, 剛好落在$N的手中!!\n"NOR,me);
ob2->move(me);
tell_object(me,HIY"你得到了一隻死蝶\n"NOR);
me->set_temp("ghost-hole/sac/life",1);
return 1;
}

