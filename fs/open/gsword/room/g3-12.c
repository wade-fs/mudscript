// Room: /open/gsword/room/gsword5-7.c
inherit ROOM;

void create ()
{
  set ("short", "二樓樓梯口");
  set ("long", @LONG
中間一條木梯 ,相當精緻 ,南邊的長廊分別連接仙劍七俠之寢居 ,樓上則是掌
門人 --- 鄭士欣之寢居 ,樓梯旁種滿了花卉 ,遠遠看去 ,實在賞心悅目 .北邊開了
個大窗戶 ,外面正是仙劍的後花園,和風栩栩 ,滿室芳香 ,住在此地 ,著實享受 .

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : "/open/gsword/room/g3-15.c",
  "up" : "/open/gsword/room/g3-13.c",
  "down" : "/open/gsword/room/g3-11.c",
]));

  set("light_up", 1);

  setup();
}
