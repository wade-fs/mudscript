inherit ROOM;

void create()
{
  set ("short", "北小路");
  set ("long", @LONG
窄小的巷弄之間，殘破矮小的木製房屋比臨而居。幼兒的哭泣聲
與男女的爭吵聲不絕於耳。路上隨處可見野貓野狗亂竄，似乎還會對
路人齜牙露嘴。蚊蠅成群四處亂飛。屎尿臭味與餿水的味道還衝鼻而
來。

LONG);

  set("light_up", 1);
  set("outdoors", "/open/japan/room");
  set("exits", ([ /* sizeof() == 3 */
    "east" : __DIR__"j33.c",
    "west" : __DIR__"j34.c",
    "south" : __DIR__"j27.c",
  ]));
  setup();
}
