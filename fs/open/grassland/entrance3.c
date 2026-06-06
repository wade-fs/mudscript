//排版與增加移動後用rumor廣告的趣味性 by blazakira 2011/10/12
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "斜坡");
  set( "build", 12 );
  set ("long", @LONG
這裡是高原邊緣的斜坡，沿路景觀隨著高度的提升而改變，
濕暖平地的闊葉林越來越稀少，取而代之的是針葉林和草本類。
道路在此已至盡頭，必須登山才能再往上爬。
LONG);
  set("outdoors", "/open/main");
  set("exits", ([ /* sizeof() == 1 */
    "southdown" : __DIR__"entrance2",
  ]));
  setup();
}

void init()
{
  add_action ("do_climb","climb");
}

int do_climb (string str)
{
  object me;
  me = this_player();
  if (!str || (str != "mount" && str != "mountain") && me->query_temp("path/entrance3/grassland/NG") < 3 ) {
    me->add_temp("path/entrance3/grassland/NG",1);
    message("rumor",HIB+"【謠言】某人: 哈哈～我看到"+sprintf ("%s" + HIB + "(%s" + HIB + ")從登上草原的山壁上摔下來了。\n" + NOR,me->name(),me->query("id")),users());
    return notify_fail("你爬呀爬呀......你爬了半天還是不幸重重的摔了下來.....\n");
  }
  message_vision("$N展開絕世輕功\，依附著岩壁，輕輕鬆鬆的登上了草原。\n", me);
  me->move(__DIR__"grass00.c");
  tell_room(environment(me), sprintf ("%s左足一點，右足一蹬，氣定神閒的登上了草原。\n",me->short()), me);
  me->add_temp("path/entrance3/grassland/OK",1);
  if( me->query_temp("path/entrance3/grassland/OK") < 3 )
    message("rumor",HIB+"【謠言】某人: 我看到"+sprintf ("%s" + HIB + "(%s" + HIB + ")左足一點，右足一蹬，氣定神閒的登上了草原。\n" + NOR,me->name(),me->query("id")),users());
  return 1;
}
