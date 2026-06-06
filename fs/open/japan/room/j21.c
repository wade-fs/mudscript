inherit ROOM;

void create()
{
  set ("short", "南町南哨所");
  set ("long", @LONG
木造厚實的大門兩旁，站著數名目光銳利的武士，正監視著往來
如潮水的人群，避免有一般平民老百姓混在其中進入南町。看起來南
町不只繁華，對於階層制度也相當嚴謹。

LONG);

  set("light_up", 1);
  set("outdoors", "/open/japan/room");
  set("exits", ([ /* sizeof() == 1 */
    "south" : __DIR__"j20.c",
  ]));
  setup();
}
