// Room: /open/main/room/M21.c

inherit ROOM;

void create ()
{
  set ("short", "雪蒼山");
	set( "build", 19 );
  set ("long", @LONG
這是雪蒼山的底部，由於雪蒼山筆直的山勢，想下山必須經過
從谷底生長上來的一棵萬年古松，往上則通達雪蒼派的山口。往西
邊跟南邊則是雪蒼山比較平坦的高地。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "up"		: "/open/snow/room/room3",
  "southdown" : __DIR__"L8",
  "westdown" : __DIR__"L5",
]));

  set("outdoors", "/open/main");
  setup();
}

void init()
{
  add_action ("do_climb","climb");
}

int do_climb (string str)
{
  object	me;

  if (str != "pine" && str != "樹" && str != "松樹" && str != "蒼松")
    return notify_fail("你爬呀爬呀.....噫? 突然想起自己又不是烏龜, 幹麻用爬的!\n");
  me = this_player();
  message_vision("$N兩手抱住樹幹﹐咻的一聲，很快的溜下山。\n",me);
  me->move(__DIR__"f12");
  tell_room(environment(me),
	    sprintf ("%s順著樹幹, 咻的一聲, 飛快的溜了下來。\n", me->short()),
	    me);
  return 1;
}
