//額外增設進入mulitpk的判斷mark by blazakira 2011/7/27

#include "/open/capital/capital.h"
#include <ansi.h>
inherit ROOM;

void create()
{
  set( "short", "武鬥會場" );
  set( "build", 24 );
  set( "long",
   "這裡便是城內著名的武鬥會場, 會場四周人山人海, 似乎場內正龍爭虎鬥
打得不可開交的樣子, 你迫不及待地想進去湊個熱鬧。
" );
  set( "outdoors", "/open/capital" );
  set( "exits", ([
    "south" : __DIR__"r60",
    "enter" : "/open/mulitpk/room/room01.c",
  ]) );
  set( "objects", ([
    CAP_NPC"Fguard" : 3,
  ]) );
  setup();
}

// by babe
int valid_leave( object me, string dir )
{
  if( dir == "enter" ) {
    if( me->query("pker")==1 )
      return notify_fail( "殺人兇手禁止進入武鬥會場。\n" );
//    if( me->query_condition("mogi") )
//      return notify_fail( "身中劇毒, 還是先解毒再進武鬥會場吧。\n" );
    if( me->query("gin") < me->query("max_gin")/2 ||
        me->query("kee") < me->query("max_kee")/2 ||
        me->query("sen") < me->query("max_sen")/2 )
      return notify_fail( "有傷在身, 還是等恢復後再進武鬥會場吧。\n" );
    if( me->query("force") < me->query("max_force")/2 ||
        me->query("mana") < me->query("max_mana")/2 ||
        me->query("atman") < me->query("max_atman")/2 )
      return notify_fail( "目前尚未處於最佳狀態, 還是等做好萬全準備後再進武鬥會場吧。\n" );
    if( !userp(me) ) {
      tell_room( this_object(), me->query("name") + "不是玩家, 不得進入武鬥會場。\n" + NOR, me );
      return 0;
    }
    if( me->query("clan") )
      if( CLAN_D->clan_query( me->query("clan/id"), "war" ) )
        return notify_fail( "貴幫正在戰爭中。\n" );
    if( me->query("combat_exp") < 330000 )
      return notify_fail( "您的江湖歷練不足, 還是等強一點再來吧。\n" );
    if( !me->query_temp( "multipk" ) )
      me->set_temp( "multipk", time() );
    me->set_temp( "multipk2", time() );
  }
  if( dir == "south" ) {
    me->delete_temp( "multipk2" );
  }
  return 1;
}
