inherit ROOM;

void create()
{
  set ("short", "副隊長室");
  set ("long", @LONG
房間內，隨處可見各種書籍散置。中央的小矮桌上還攤放著好幾
本建築跟兵法書。而房間角落的書櫥內(shelf)，更是放滿各式各樣的
書籍。

LONG);

  set("light_up", 1);
  set("outdoors", "/open/japan/room");
  set("exits", ([ /* sizeof() == 1 */
    "west" : __DIR__"camp10.c",
  ]));
  setup();
}
