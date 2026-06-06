// Room: /open/capital/room/h06.c

inherit ROOM;

void create ()
{
  set ("short", "扁鵲胡同");
	set( "build", 12 );
  set ("long", @LONG
步入扁鵲胡同, 兩旁柳樹搖曳, 四處都掃的乾乾淨淨。仔細的嗅一
嗅, 空氣中似乎瀰漫著一股濃郁的藥味, 這時你才發現原來南邊就是一
家藥店, 招牌上寫的是「仁心藥店」, 裡頭還有不少人正在抓藥的樣子
。

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"medical",
  "west" : __DIR__"r67",
  "east" : __DIR__"h08",
]));
  set("outdoors", "/open/capital");

  setup();
}
