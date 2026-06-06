// Room: /open/main/room/s30.c
// 怪哉 這是誰留下的後門？ 先關起來再說XD by blazakira 2011/7/7

inherit ROOM;

void create()
{
  set("short", "草原");
  set("build", 36);
  set("long", "這裡是一片草原，割人的野草凌亂的長著，高高低低的芒
穗隨著風起伏，這裡應該有不少動物躲藏。
  ");

  set("exits", ([ /* sizeof() == 4 */
    "north" : __DIR__"s26",
    "south" : __DIR__"s37",
    "west" : __DIR__"s29",
    "east" : __DIR__"s31",
  ]));
  set("outdoors", "/open/main" );
  setup();
}
/*
void init()
{
//  add_action("do_qwsxza","qwsxza");
}

int do_qwsxza()
{
  object obj,me;
  me=this_player();
  obj=new("/open/main/obj/skirt");
  obj->move(me);
  log_file("skirtget",sprintf("%s get skirt於%s\n",
    this_player()->query("id"),ctime(time())));
}
*/
