// Room: /open/main/room/M19.c

inherit ROOM;

void create ()
{
  set ("short", "少室山");
  set ("long", @LONG
你身處橫貫大陸的天山山脈的一支，嵩山。由於千年古剎--少林寺
就是在北邊的山頭上，所以又叫少室山。從這兒遠遠往北邊的山頭看過
去，你可以發現隱隱約約出現一座山門，不過因為太遠了看不到門上面
到底寫了些什麼，不過你猜想，應該是少林寺字樣吧。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "east" : "/open/main/room/M20",
  "northup" : "/open/main/room/M15",
]));

  setup();
}
