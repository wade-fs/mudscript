#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", "房間");
  set ("long", @LONG
房間裡面的擺設雖然已經被弄亂了，但是你仍舊可以感覺的出來這間房間的主
人品味十分的高尚，輕紗四散、再加上一些簡單的房間裝飾品，你彷彿可以看到主
人生前的在此休息模樣，再仔細一看，散落的物品中，還夾雜著一些女紅、與刺繡
，看來你眼前的這具骨骸生前應該是個女的。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/corpse02" : 1,
]));
  set("no_fight", 1);
  set("no_kill", 1);
  set("no_magic", 1);
  set("no_quit", 1);
  set("no_spell", 1);
  set("no_recall", 1);

  setup();
}
void init()
{
add_action("do_search","search");
}
int do_search()
{
object me;
me=this_player();
if(me->query_temp("get_amulet") >= 1)
{
tell_object(me,"你什麼也沒有發現。\n");
return 1;
}
else
{
tell_object(me,"你從屍骨的身上發現了一個護身符。\n");
me->set_temp("get_amulet",1);
new(__DIR__"obj/amulet")->move(me);
return 1;
}
}
