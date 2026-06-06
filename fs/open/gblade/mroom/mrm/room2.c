// Room: /u/m/moner/water/room2.c
inherit ROOM;

void create ()
{
  set ("short", "瀑布");
  set ("long", @LONG

細細的清泉順著山勢, 匯少成多, 川流至此, 形成一道天然的瀑布，
水花不斷的濺上你的衣裳, 小徑因長年的水氣早以泥滑不堪了, 若非腳步
隱健的人倒也不易站隱。 從坡上往下腑視, 但見青石瀉玉, 雲霧裊繞, 腳
落處有一把藤蔓(robe)向谷底沿深。

LONG);

  set("light_up", 1);
  set("outdoors", "wind");
  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"room1.c",
]));

  setup();
}
void init()
{
  add_action ("do_climb","climb");
}

int do_climb (string str)
{
  object    me;
if(str!="robe")
return notify_fail("你又不是烏龜，幹麻用爬的！\n");

  me = this_player();
message_vision("$N雙手拉住藤蔓，咻一聲溜下谷底。\n",me);
me->move(__DIR__"room3.c");
tell_room(environment(me), sprintf ("%s抓著藤蔓，很小心滑了下來。\n",
    me->short()), me);
  return 1;
}
