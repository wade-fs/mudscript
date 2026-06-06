// Room: /open/capital/room/h12.c

inherit ROOM;

void create ()
{
  set ("short", "芝麻胡同");
	set( "build", 36 );
  set ("long", @LONG
芝麻胡同的名稱由來連老一輩的人都不知道了, 只知道大家都是這
麼叫這條胡同的, 這裡既沒有種芝麻, 也沒有賣芝麻, 兩旁只是普通的
民宅而已。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"h11",
  "east" : __DIR__"r70",
]));
  set("outdoors", "/open/capital");

  setup();
}
