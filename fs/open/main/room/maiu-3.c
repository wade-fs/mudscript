// Room: /open/main/room/maiu-3.c
inherit ROOM;

void create ()
{
  set ("short", "江邊小村");
  set ("long", @LONG
幾間小屋林立在江邊,應是苗人的住所,屋中隱隱傳來歌聲,
曲意淒涼,似乎道盡了苗人生活的悲苦.
LONG);

  set("objects",([
      "/open/ping/npc/maiu-guard" : 1,
     ]));
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"maiu-4.c",
  "east" : __DIR__"maiu-2",
]));
  set("outdoors", "/open/main");

  set ("資源/液體", ([
       "種類" : "水",
       "名稱" : "清水",
       "止渴" : 30
  ]) );

  setup();
}
