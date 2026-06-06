inherit ROOM;
void create()
{
    set ("short","空屋");
  set ("long",@LONG
這裡是一間沒有人住的民房 ,但卻被打掃的一塵不染 .牆上的蠟燭
仍然是亮著 ,而桌上酒菜還是熱的 .可是門卻是關起來的 ,但卻沒有人
在 ,看來這間房子必有古怪....
LONG);

  set("light_up", 1);
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"wolf10.c",
]));

  setup();
}
