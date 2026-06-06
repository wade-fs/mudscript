// Room: /open/capital/room/h03.c

inherit ROOM;

void create()
{
	set("short", "文來胡同");
	set("long", "文來胡同上也是一條熱鬧的大街, 平常來來往往的人潮, 都是來選
購一些文房四寶--筆、墨、紙、硯。這兒賣的東西絕對沒有一些俗貨, 
每件東西都算的上是精品, 因此大部分的文人都喜愛來這選購他們吃飯
的傢伙。
");

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"h02",
  "east" : __DIR__"h04",
]) );

  set("outdoors", "/open/capital" );


  setup();
}
