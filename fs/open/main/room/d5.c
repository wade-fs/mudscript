// Room: /open/main/room/d5.c

inherit ROOM;

void create()
{
	set("short", "沙漠");
	set( "build", 252 );
    set("long", "這兒是一望無際的撒哈拉沙漠，但在風沙的邊緣卻有個老頭在那灑掃，
在他身後還有個頗大的帳篷。
");

  set("exits", ([ /* sizeof() == 4 */
  "enter" : "/open/badman/room/d_c.c",
  "west" : __DIR__"d4",
  "south" : __DIR__"d12",
  "east" : __DIR__"d6",
]) );
  set("objects",([ /* sizeof() == 1 */
  "/open/badman/ride/deserter.c" : 1,
]) );

  set("outdoors", "/open/main" );


  setup();
}

int valid_leave(object who, string dir)
{
  if(dir=="enter" && !who->query_temp("marks/f_c_ent"))
  return notify_fail("沒經過主人允許\可別亂闖喔！\n");
  return ::valid_leave(who, dir);
}

void init() {
  add_action("do_trade","want");
}

int do_trade(string str) {
  int exp;
  object me,wolf;
  me=this_player();
  exp=me->query("combat_exp");
  if(me->query_temp("marks/have_wolf",1))
  return notify_fail("你不是有座騎了嗎？\n");
  if (!me->query("quests/w_camel",1))
  return notify_fail("你在跟我要啥？\n");
  if (exp<1200000)
    return notify_fail("你要騎？我看你沒這本事！\n");
  new("/open/badman/ride/r_camel.c")->move(environment(me));
  me->set_temp("marks/have_wolf",1);
  message_vision("老頭把駱駝牽了出來。\n",me);
  return notify_fail("千萬別虧待這駱駝啊！\n");
}
