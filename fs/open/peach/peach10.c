// Room: /u/w/whatup/peach/peach10
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "桃木林");
  set ("long", @LONG
一走進桃木林裡，映入眼簾的是一大片桃木，並且一直延伸下去
，也沒有明顯的道路痕跡，只能四處走走，期盼能快點找到出口，早
點離開這裡。路旁有顆大石頭(stone)，有個人正坐在那休息。
LONG);


  set("outdoors", "/u/b");
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"peach9.c",
]));

  setup();
}

void init()
{
add_action("do_look","look");
add_action("do_look","l");
}

int do_look(string str)
{
if(str!="stone") return 0;
{
  tell_object(this_player(),HIY + "那個人像似突然發現你一般，伸手招呼你走過去。\n" + NOR);
  this_player()->move(__DIR__"stone.c");
  tell_room(environment(this_player()),sprintf (HIW + "%s走了過來。\n" + NOR, this_player()->short()),this_player());
}
return 1;
}
