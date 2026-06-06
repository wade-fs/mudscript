inherit ROOM;

void create()
{
  set ("short", "十字路口");
  set ("long", @LONG
窄小的巷弄，奚落的人群，路旁枯萎的老樹，偶有殘鴉駐足。兩
旁店家內的老闆正無精打采的看著過往的人群，店內貨架似乎也空空
蕩蕩，寥寥無幾。南北各有小巷弄，應該是通往住宅區。

LONG);

  set("light_up", 1);
  set("outdoors", "/open/japan/room");
  set("exits", ([ /* sizeof() == 4 */
    "north" : __DIR__"j27.c",
    "south" : __DIR__"j29.c",
    "west" : __DIR__"j24.c",
    "east" : __DIR__"j22.c",
  ]));
  setup();
}
