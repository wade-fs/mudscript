
#include <ansi.h>
inherit ROOM;
inherit __DIR__"bookmsg.c";
string *exit = ({
__DIR__"book1",__DIR__"book2",__DIR__"book3",
__DIR__"book4",__DIR__"book5",__DIR__"book6",
__DIR__"book7",__DIR__"book8",__DIR__"book9",});

void create()
{
  set("short", YEL + "藏經閣" + NOR);
  set("long",
    (: print_book_msg :),
  );
  set("exits", ([
    "south" : exit[random(sizeof(exit))],
    "north" : exit[random(sizeof(exit))],
    "east" : exit[random(sizeof(exit))],
    "west" : exit[random(sizeof(exit))],
  ]));
  set("no_transmit",1);
  setup();
}

int valid_leave(object me , string dir)
{
  if(me->query_temp("check_book_times")>10)
    me->add_temp("check_book_times",-9);
  return ::valid_leave(me,dir);
}
