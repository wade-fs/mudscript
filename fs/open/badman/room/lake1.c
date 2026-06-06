// Room: /open/badman/room/lake1.c
// written by powell 96.4.26@FS

inherit ROOM;

void create ()
{
  set ("short", "湖中");
  set ("long", @LONG
這裏是惡人湖中，湖水冷冽的很；不知道甚麼原因，這湖水比
你以往所見過的別清徹，還有一點很奇怪的是在這湖中你能看到唯
一的魚類，就只有草魚，聽說這草魚的由來還有個傳奇故事；由這
裏好像還可以深潛下去，那兒看起來有點昏暗，似乎有甚麼危險存
在，如果真的要潛下去，最好先上岸換口氣再下來吧！可別淹死在
這湖中喔...

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "up" : __DIR__"lake0",
]));

  setup();
}

void init()
{
	add_action("do_dive","dive");
}

int do_dive()
{
        object who;
        who = this_player();
        tell_object(who,"\n你深吸一口氣，向湖底潛了下去。\n\n");
        who->move(__DIR__"lake2");
        return 1;
}
