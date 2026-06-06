// Room: /open/gsword/room/g2-1.c
inherit ROOM;

void create()
{
  set ("short", "藥圃");
  set ("long", @LONG
一片廣闊的藥圃 ,規劃的很完整 ,各式各樣的藥材 ,分門別類 ,毫不
混雜 ,東南方即為一片峭壁 ,空氣中滿是藥香 .

LONG);

  set("light_up", 1 );
  set("outdoors", "/open/gsword/room" );

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"g2-4",
]) );

  setup();
}
