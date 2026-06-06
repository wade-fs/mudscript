// Room: /u/w/whatup/area/shinyang/8-4.c
inherit ROOM;

void create ()
{
  set ("short", "民宅");
  set ("long", @LONG
一個小屁孩，站在你的面前傻傻的對著你笑，一個大嬸正坐在屋
子裡的藤椅上，專心的編織一雙鞋子，不知道是要給誰穿的呢？還是
不要打擾別人了，趕緊離開！
LONG);

  set("no_transmit", 1);
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/child" : 1,
  __DIR__"npc/woman" : 1,
]));
  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"8-3.c",
]));
  set("no_auc", 1);
  set("light_up", 1);

  setup();
}
