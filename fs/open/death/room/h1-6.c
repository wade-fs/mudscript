// Room: /open/death/room/h1-6
inherit ROOM;

void create ()
{
  set ("short", "第一殿--通道");
  set ("long", @LONG
你走近這裡，看到北方燈火通明，原來北方正是冥府的第一殿，由
秦廣王所管轄，一般做善事的人，死後牛頭馬面都會把他先帶到秦廣王
面前，在由各路諸神依其功德接引上天庭或帶去投胎轉世。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"h1-7",
  "south" : __DIR__"h1-3",
  "north" : __DIR__"h1-1",
  "east" : __DIR__"h1-5",
]));
  set("light_up", 1);

  setup();
}
