inherit ROOM;
#include <ansi.h>
void create ()
{
set("short",YEL + "雙冥祭台" + NOR);
set("long",@LONG
這裡是【生】冥王的祭台, 在你眼前有一個
小小的石板(stone),除此之外, 裡面還放置了許
許多多奇奇怪怪的工具, 看來可能都是祭祀用的
工具。
LONG);
set("item_desc",([
"stone":"誠心奉獻(g-sac)死冥王之頭者，吾人將以『生命之水』作為謝禮。\n",
"石板":"誠心奉獻(g-sac)死冥王之頭者，吾人將以『生命之水』作為謝禮。\n",
]));
set("no_light",1);
set("exits",([
"west":__DIR__"g-s01",
]));
set("objects",([
"/open/ghost-hole/npc/death.c":1,
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
string id;
me=this_player();
id = me->query("id");
ob=present("death-ghost-head",me);
ob2=new(__DIR__"obj/living-water");
//ob2=new("/open/ghost-hole/obj/living-water");
if(!arg)
return notify_fail("你要奉獻什麼東西??\n");
if(arg!="death-ghost-head"&&arg!="head")
return notify_fail("祭祀神台並不接受你所奉獻的物品!!\n");
if(!present("death-ghost-head",me))
return notify_fail("你身上並沒有死冥王的頭!!\n");
destruct(ob);
message_vision(HIY + "一道黃色的光芒從天而降, 光柱中緩緩落下了一滴
生命之水, 剛好落在$N的手中!!\n" + NOR,me);
ob2->move(me);
if(me->query_temp("quest/return_sha") && me->query_temp("quest/return_sha")==6)
 {
  message_vision(HIG + "$N低頭一看，正是自己要找的東西!!\n" + NOR,me);
  ob2->set_temp("finder",id);
 }
tell_object(me,HIY + "你得到了一滴生命之水\n" + NOR);
me->set_temp("ghost-hole/sac/death",1);
return 1;
}

