// Room: /open/gsword/room/gsword5-7.c
inherit ROOM;

void create ()
{
  set ("short", "一樓樓梯口");
  set ("long", @LONG
中間一條木梯 ,相當精緻 ,通往樓上掌門人及各大師兄的寢室 .樓梯旁種滿了
花卉 ,遠遠看去 ,實在賞心悅目 .北邊開了個大窗戶 ,外面正是仙劍的後花園,和風
栩栩 ,滿室芳香 ,住在此地 ,著實享受 .

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "up" : "/open/gsword/room/g3-12.c",
  "south" : "/open/gsword/room/g3-6.c",
]));

  set("light_up", 1);

  setup();
}
