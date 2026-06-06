#include <ansi.h>
inherit ROOM;
string statue();
void create ()
{
  set ("short", "海斷層");
  set ("long", @LONG
再往西走，有一個落差極大的海底深溝，僅僅靠著定水珠的力量可以讓
你在水底免去呼吸，但如果沒有良好的內力的話，是無法忍受強大的水壓很
久。
在斷層前有一個奇怪的神像(statue)，以及一個標誌(sign)。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "east" : "/open/killer/sea/room/landrm1.c",
  "westdown" : __DIR__"sea02",
]));
  set("item_desc", ([ /* sizeof() == 2 */
  "statue" : (: statue :),
  "sign" : "深海處潛伏巨大章魚，請勿亂闖。
",
]));

  setup();
}
int valid_leave(object me,string dir)
{
int sk;
me=this_player();
sk=me->query_skill("force");
if(dir=="westdown")
{
if(me->query_temp("put_water")!=1)
{
return notify_fail("你被強力的海潮沖了回來。\n");
}
else
{
message_vision(HIY + "$N運起強大的內力，使得水壓不置於壓迫其身。\n" + NOR,me);
me->add("force",-100);
return 1;
}
}
if(dir=="east")
{
return 1;
}
}

string statue()
{
object me;
me=this_player();
if(!present("static_water",me))
return "一個你從未見過的雕像，十分的怪異，令你目不轉睛的看著。\n";
if(me->query_temp("put_water")!=1)
{
if(me->query_temp("look_statue")!=1)
{
me->set_temp("look_statue",1);
call_out("move01",1,me);
return "一個你從未見過的雕像，十分的怪異，令你目不轉睛的看著。\n";
}
return "一個你從未見過的雕像，十分的怪異，令你目不轉睛的看著。\n";
}
else
return "一個你從未見過的雕像，十分的怪異，令你目不轉睛的看著。\n";
}
int move01(object me)
{
message_vision(HIB + "\n\n$N傻傻的看著雕像。\n" + NOR,me);
me->start_busy(5);
call_out("move02",2,me);
return 1;
}
int move02(object me)
{
message_vision(HIB + "\n\n雕像似乎緩緩的張開了眼睛。\n" + NOR,me);
call_out("move03",3,me);
return 1;
}
int move03(object me)
{
message_vision(HIY + "\n\n一瞬間，雕像銳利的雙眼把$N給吸了進去！！\n" + NOR,me);
me->move(__DIR__"statueroom");
me->delete_temp("look_statue");
return 1;
}
