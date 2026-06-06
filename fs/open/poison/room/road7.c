// Room: /open/poison/room/road7
inherit ROOM;

void create ()
{
  set ("short", "斷崖");
  set ("long", @LONG
這裡視野十分遼闊，陣陣清風吹彿，內心一切陰霾恐懼
消失的無影無蹤，眼前乃一谷地，四周群峰環抱，處處綠意
蒼蒼，往西南望去，點點紅瓦，向西北眺望，可見一雄偉大
院，東邊則是一大片高大的雜草叢，其上則是一面光禿禿的
絕壁。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"road19",
  "northwest" : __DIR__"road8",
]));
  set("outdoors", "/open/poison");

  setup();
}
void init()
{
 add_action("do_go","go");
 add_action("do_east","east");
}

int do_go(string str)
{
 object me;
 me = this_player();
if(str == "east")
{
   message_vision("$N穿過高高的草叢，發出沙沙的聲音。\n",me);
    me->move(__DIR__"path9");
    return 1;
}
return 0;
}
int do_east()
{
object me;
me = this_player();
  message_vision("$N穿過高高的草叢，發出沙沙的聲音。\n",me);
me->move(__DIR__"path9");
return 1;
}
