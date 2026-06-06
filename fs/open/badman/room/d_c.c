inherit ROOM;

void create()
{
  set("short", "帳篷");
  set("long", "這是一個典型的遊牧民族的帳篷。但內部的擺\設卻相當地
漢化。蓬內的角落有一個相當大的木板床，老兒所說的應該就
是這床了吧？
");

  set("exits", ([ /* sizeof() == 4 */
  "out" : "/open/main/room/d5.c",
]) );

  set("light_up",1);

setup();
}

void init()
{
 add_action("do_search","search");
 add_action("do_open","open");
}

int do_search(object me)
{
  object who;
  who = this_player();
  message_vision("$N在木版床上仔細地察看了一番，發現床中央偏左的地
方有個凹槽，看樣子可以用手將其打開（open）。\n",who);
  who->set_temp("marks/open",1);
  return 1;
}

int do_open()
{
  object who;
  who = this_player();
  if (who->query_temp("marks/open",1))
  {
   message_vision("$N把手伸入床上的凹槽內，用力一拉，
一條通道的入口便在眼前。\n",who);
   set("exits/enter",__DIR__"d_c01.c");
   set_temp("have_open",1);
   remove_call_out("do_closed");
   call_out("do_closed",60);
   return 1;
  }
}

void do_closed()
{

        delete_temp("have_open");
        delete("exits/enter");
        tell_room(this_object(),"暗道的入口被風砂吹得作響，剛掀起來的木板再度被闔上！\n");
}
