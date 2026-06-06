// Room: /open/capital/room/r29.c

inherit ROOM;

void create ()
{
  set ("short", "永安胡同");
  set ("long", @LONG
由於近鎮南門，石板路上不時有馬車來來去去，馬伕的呦喝聲和行
人來來往往的聲音此起彼落。北面是一排不起眼的民宅。
    這裡有禁衛軍四處的巡邏著，所以你還是不要在城內惹事的好。

LONG);

  set("outdoors", "/open/capital");

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"r28",
  "east" : __DIR__"r30",
]));

  set("gopath", "west");
  set("gopath2", "west");

  setup();
}
