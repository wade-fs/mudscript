// Room: /u/g/guetenr/beggar/room/beg1/room23.c
inherit ROOM;

void create ()
{
  set ("short", "悅來客棧");
  set ("long", @LONG
櫃檯後牆上懸著『近悅遠來賓至如歸』的匾額，便是棧名的由來；江南
三月煙花盛景引各地遊人群聚遊賞，也讓悅來客棧不時高朋滿座，小二忙著
招呼客人、廚房的灶火鍋鏟從沒停過，連掌櫃的也整日算著帳收錢，大伙兒
是愈做愈起勁，臉上不時堆滿了笑容。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"room21.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/lv1beg.c" : 1,
]));

  setup();
}
