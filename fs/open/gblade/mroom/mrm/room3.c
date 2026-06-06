// Room: /u/m/moner/water/room3.c
inherit ROOM;

void create()
{
  set ("short", "涯底");
	set( "build", 19 );
  set ("long", @LONG

順著藤蔓攀爬而下, 你來到了山谷底, 抬頭仰望, 只能隱隱約約的看
見山頂。浩大的瀑布從上傾瀉而下, 彷如一抹天筆, 劃空而至, 水氣氳氤
間, 你看見幢幢的綠影。奔騰的水勢匯集而成一座湖泊, 平靜的水面蕩然
波, 水底卻有一股暗流, 好像另有出路。

LONG);

  set("light_up", 1);
  set("outdoors", "wind");
set("exits", ([ /* sizeof() == 1 */
"west":"/open/gblade/mrm/r1",
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
message_vision("$N雙手拉住藤蔓，小心往上爬。\n",me);
me->move(__DIR__"room2.c");
tell_room(environment(me), sprintf ("%s抓著藤蔓，很辛苦的爬了上來。\n",
me->short()), me);
return 1;
}
