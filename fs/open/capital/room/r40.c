// Room: /open/capital/room/r40.c

inherit ROOM;

void create ()
{
  set ("short", "永福胡同");
  set ("long", @LONG
雜草叢生的石板路。北面都是些半傾的廢屋子，如果想開宗立派又
缺銀兩的話，這條胡同是個不錯的選擇，不過可能要終日與地痞流氓為
伍了。
    這裡有禁衛軍四處的巡邏著，所以你還是不要在城內惹事的好。

LONG);

  set("outdoors", "/open/capital");

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"r39",
  "east" : __DIR__"r41",
]));

  set("gopath", "west");

  setup();
}
