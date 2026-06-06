inherit ROOM;

void create ()
{
  set ("short", "懸崖邊");
  set ("long", @LONG
你一來到這邊，嚇了一大跳，竟然是一個深不見底的懸崖，
你腳下的土石非常的鬆軟，你感到你快要掉下去了!!!\n"
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "back" : __DIR__"aa52",
]));

  setup();
}
void init()
{
    object me=this_player();

    call_out("do_down",20,me);
}
int do_down(object me)
{
    if(!me) return 1;
    if(environment(me)!=this_object()) return 1;
    message_vision("$N腳下一個不穩，跌到山下去了!!!\n",me);
    me->unconcious();
    me->move(__DIR__"aa0.c");
    return 1;
}

