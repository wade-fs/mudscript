// Room: /open/capital/room/h04.c

inherit ROOM;

void create ()
{
  set ("short", "文來胡同");
	set( "build", 12 );
  set ("long", @LONG
由於京城每三年會有一次狀元的考試，會有許多的書生進京趕考，
而這裡則是書生們時常聚集討論﹑交換心得的地方，故稱此胡同為文來
。街上鋪的是美觀的花崗石, 更顯的出這條街的重要性。
    這兒來來往往的人潮, 都是來選購一些文房四寶--筆、墨、紙、硯
, 每件東西都算的上是精品。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"h01",
  "east" : __DIR__"r67",
]));
  set("outdoors", "/open/capital");

  setup();
}
