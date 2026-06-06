#include <ansi.h>

inherit BOOK;

#define BOOK_PATH "/open/center/obj/"
#define BOOK_NAME "map"
#define BOOK_NAME1 "map1"
#define C_BOOK_NAME "主大陸地圖"

void create()
{
  ::create();
  set_name( C_BOOK_NAME, ({ "map" }) );
  set( "long", "這是一張由前輩高手冒險的心血所繪製的地圖。\n");
  
  // set ( "value", ({ 10, "silver" }) );
  set ( "book_path", BOOK_PATH + BOOK_NAME );
  setup();
}

int do_read(string arg)
{
  object me=this_player();
  int   query1, query2;

  query1 = me->query_temp("quests/badman_license");
  query2 = me->query_temp("quests/help_water_god");
  if (query1 == 2 || query2 == 2) {
    if (query1 == 2) me->set_temp("quests/badman_license", 3);
    if (query2 == 2) me->set_temp("quests/help_water_god", 3);
    set ( "book_path", BOOK_PATH + BOOK_NAME1 );
    if (::do_read(arg)) {
      write (HIY"當你仔細看完地圖時，發現有一個地方怪怪的，"+
             "值得去看一看，也許\那兒正是哭風坡。\n"NOR);
      return 1;
    }
    else return 0;
  }
  else
    return ::do_read(arg);
}
