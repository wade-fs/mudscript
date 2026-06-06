#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short", "殺手練習場");
  set ("long", @LONG
   這是殺手的練習場，場地非常的寬廣場的，周圍有許多的樹木。
   這似乎是特地為殺手所設計來，用於練習輕功與暗器手法的場地。
   然而，樹上也有不少人在進行實戰練習。但你卻找不出他們的所在。
   只聽的到不斷傳來的殺聲與兵器交鳴聲。
   廣場中，教頭正四處的觀察著，每個人的練習情形。
   並且隨時親自對招與指導有所缺失的人。。。。

LONG);

  set("outdoors", "/open/main");
  set("exits", ([ /* sizeof() == 4 */
      "west" : __DIR__"outr12.c",
      "north" : __DIR__"outr9.c",
]));
  set("objects",([
      "/open/killer/npc/killer_b.c":1,]));
  setup();
}
