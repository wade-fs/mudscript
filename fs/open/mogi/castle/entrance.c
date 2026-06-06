//castle by roger

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", HIC"妖魔古堡入口"NOR);
  set( "build", 24 );
  set ("long","這裡就是封閉了幾千年的妖魔古堡，外表斑斑駁駁不知經過了多少的
腥風血雨，不過結構上倒還蠻堅固的。魔雲密佈下映著古堡慘藍的外表，
不禁使人不寒而慄。大門(door)是由厚厚的木板作成，門旁掛著兩個隨著
狂風搖曳的妖氣燈籠，門栓已經鏽蝕得好像不能開了。仔細一看似乎還沾
著斑斑血跡...門旁有一塊木板(plate)不過上面的字似乎快看不清了...
");
  set("evil", 1);
  set("no_auc", 1);
  set("no_transmit", 1);
  set("light_up",-1);
  set("exits", ([ /* sizeof() == 3 */
    "west" : __DIR__"a",
  ]));
  set("item_desc", ([ /* sizeof() == 2 */
    "door"  : "這門看起來蠻厚的,似乎要用內力撞開(collide)才行。\n",
    "plate" : "      上面隱約可見:
 甫入...此門..,..群..魔..齊上,慌...亂..揮劍..自保 
 但...仍落得...劍斷..人傷..,九死...一生...方得逃出
 後人...戒之...戒之...切不可....孤身進入
 
                             風...清...揚

  ",]));
//  set("objects",([ /* sizeof() == 1 */
//    __DIR__"mob" : 1,
//  ]));
  setup();
}

void init()
{
  add_action("do_collide", "collide");
}

int do_collide(string str)
{
  object me;
  me = this_player();

  if(!str || str != "door") {
    return notify_fail("你想撞哪裡？\n");
    return 1;
  }
  if(me->query("force",1) < 2000) {
    message_vision("$N運起全身內力一撞，但因內力不足，大門紋風不動。\n",me);
    return 1;
  }
  me->add("force",-2000);
  message_vision(HIY"$N運起全身內力一撞，轟隆一聲巨響大門以被撞開!!\n",me);
  tell_object(me,HIR"\n你耗盡全身內力，幾欲虛脫。\n"NOR);
  set("exits/enter",__DIR__"room1");
  set_temp("have_open",1);
  remove_call_out("do_closed");
  call_out("do_closed",15);
  return 1;
}

void do_closed()
{
  delete_temp("have_open");
  delete("exits/enter");
  tell_room(this_object(),"大門碰的一聲又關起來。\n");
}

int valid_leave(object me, string dir)
{
  if( query("exits/enter") && dir=="enter" )
  {
    me->add_temp("path/entrance3/mogi/OK",1);
    if( me->query_temp("path/entrance3/mogi/OK") < 3 )
      message("rumor",HIB+"【謠言】某人: 似乎"+me->query("name")+HIB+"("+me->query("id")+HIB+")靜悄悄地闖入妖魔古堡裡意欲探尋秘寶。\n"NOR,users());
  }
  return ::valid_leave(me,dir);
}
