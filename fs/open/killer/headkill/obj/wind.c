
#include <ansi.h>
inherit ITEM;
inherit F_GUILDCMDS;

void create()
{
  set_name("清風卷軸", ({ "wind roll","roll","wind"}) );
  set_weight(800);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "把");
    set("value", 10);
    set("long",@LONG
        這是一個用來使出五鬼搬運大法的捲軸，專門提供給殺手潛入各門派用，
        但是，據說只有藍鳳組才持有這一個卷軸，一般殺手並沒有這種卷軸。

      現今提供的各傳點：1.火之試煉場  2.風之試煉場  3.水之試煉場  4.土之試煉場
                        5.藍鳳組所在地
      沒有通過四次試煉的話，五鬼將無法將你傳送到藍鳳組所在地。

      移動方法：windrun <number>

LONG);
  }
}

void init()
{
  if( environment() == this_player() )
  {
    add_action("do_windrun", "windrun");
  }
}

int do_windrun(string arg)
{ 
  mixed count;
  int money,i,gmove;
  object me,roomm;

  string room="";
  me = this_player();
  if( me->query("class") != "killer") return 0;
  if( me->query_temp("head") != 6) return 0;
  if( me->query_temp("unconcious") ) return 0;
  if( me->is_fighting() )
    return notify_fail("戰鬥中無法使用。\n");
  if( environment(me)->query("no_transmit") )
  {
    message_vision( HIG+"只見地下冒出五鬼，令$N眼前一花，然後走了\n"+NOR ,me);
    return 1;
  }

  message_vision( HIG+"只見地下冒出五鬼，一擁而上，令$N" + HIG + "眼前一花。\n"+NOR ,me);
  switch(arg)
  {
    case "1":
      room="/open/killer/headkill/room/testrm1.c";		break;
    case "2":
      room="/open/killer/headkill/room/testrm2.c";		break;
    case "3":
      room="/open/killer/headkill/room/testrm3.c";		break;
    case "4":
      room="/open/killer/headkill/room/testrm4.c";		break;
    case "5":
      if (me->query_temp("kill_ghost") >= 4)
      {
        me->set_temp("head",7);
        room="/open/killer/headkill/room/bluerm1.c";
      }
      else
      {
        room="";
        write(" 五鬼說: 你想我搬你去哪裡呢？...\n");
        return 0;
      }
      break;
  }
  if( !me->move(room) )
  {
    write(" 五鬼說: 你想我搬你去哪裡呢？...\n");
  }
  return 1;
}
