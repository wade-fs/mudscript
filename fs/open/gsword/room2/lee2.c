inherit ROOM;

void create ()
{
  set ("short", "瀑布裡");
  set ("long", @LONG
仙劍前山的瀑布裡，這裡到處泥濘，令人無法想像這裡竟然會有人
定眼一看，你眼前的人竟是金風細雨樓樓主--李夢枕。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : "/open/gsword/room/pool",

]));

  set("light_up", 1);
  set("objects", ([ /* sizeof() == 2 */
  "/open/gsword/npc2/lee1.c" :1, ]));
  setup();
}
