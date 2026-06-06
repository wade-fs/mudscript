// Room: /open/gsword/room/gsword5-7.c
inherit ROOM;

void create ()
{
  set ("short", "三樓樓梯口");
  set ("long", @LONG
南邊就是武林第一大宗師 ---鄭士欣的寢居 .中間一條木梯 ,相當精緻 ,往下
可達餐廳 ,樓梯旁種滿了花卉 ,遠遠看去 ,實在賞心悅目 .北邊開了個大窗戶 ,外
面正是仙劍的後花園,和風栩栩 ,滿室芳香 ,住在此地 ,著實享受 .

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : "/open/gsword/room/g3-14.c",
  "down" : "/open/gsword/room/g3-12.c",
]));

  set("light_up", 1);

  setup();
}
