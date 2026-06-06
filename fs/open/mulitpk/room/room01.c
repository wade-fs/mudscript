//額外增設進入mulitpk的判斷mark by blazakira 2011/7/27

#include <ansi.h>
inherit ROOM;

void create ()
{
  set( "short", "狂想之武鬥會場" );
  set( "long", @LONG
這裡是狂想空間裡武林大會的會場, 你左右一望, 只見四周已擠滿
了前來看熱鬧的觀眾, 而場地裡已經有許多參加者正在熱身, 個個都一
副勢在必得的樣子

LONG);

  set("light_up", 1);
  set("no_auc", 1);
  set("no_transmit", 1);
  set("pkroom", 1);
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
    "south" : __DIR__"room05.c",
    "out" : "/open/capital/room/fight.c",
    "east" : __DIR__"room02.c",
  ]));

  setup();
}

// by babe
int valid_leave( object me, string dir )
{
  int i, n, fee;
  string pay, money;
  object *inv;

  if( dir == "out" ) {
    if( me->query_temp( "multipk2" ) && me->query_temp( "multipk2")+1 > time() )
      return notify_fail( "奉天子之令，請大俠戒急用忍，稍後再出去。\n" );
    if( me->query_temp("multipk") )
      fee = time() - me->query_temp( "multipk" );
    else
      fee = 10000;
    if( fee<0 )
      fee = 0;

    fee *= 10;

    if( !me->can_afford(fee) ) {
      inv = all_inventory( me );
      for( i=0, n=sizeof(inv); i<n; i++ ) {
        money = inv[i]->query("id");
        if( money=="diamond" ||
            money=="cash" ||
            money=="gold" ||
            money=="silver" ||
            money=="coin" )
          destruct(inv[i]);
      }
    }
    else
      me->pay_money(fee);
    me->delete_temp("multipk");
    pay = "";
    if( fee > 1000000 )
      pay += CHINESE_D->chinese_number(fee/1000000) + "張萬兩銀票";
    if( fee%1000000 > 10000 )
      pay += CHINESE_D->chinese_number(fee%1000000/10000) + "兩黃金";
    if( fee%1000000%10000 > 100 )
      pay += CHINESE_D->chinese_number(fee%1000000%10000/100) + "兩銀子";
    if( fee%1000000%10000%100 > 0 )
      pay += CHINESE_D->chinese_number(fee%10000%100) + "文錢";
    message_vision( HIY"武鬥會場守衛向$N收取武林大會場地費" + pay + "。\n"NOR, me );
  }

  return 1;
}
