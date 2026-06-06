// by borstquc
#include <ansi.h>
inherit ROOM;

void create()
{
  string long;

set("short",HIW"八卦遊龍迷陣"NOR);

long = "\n"+
"                         "+BGRN"                      \n"NOR+
"                       "+BWHT"                      "+BGRN"    \n"NOR+
"                     "+BWHT"                          "+BGRN"    \n"NOR+
"                    "+BWHT"                            "+BGRN"    \n"NOR+
"                   "+BWHT"                              "+BGRN"    \n"NOR+
"                  "+BWHT"             "+HIB"巽門"+HIW"(n)"+"            "+BGRN"   \n"NOR+
"                  "+BWHT"            "+HIB" ˍ　ˍ"+"             "+BGRN"   \n"NOR+
"                  "+BWHT"     "+HIB"離門"+HIW"(w)"+HIB" ˍ　ˍ"+" 震門"HIW"(e)"
+"     "+BGRN"   \n"NOR+
"                  "+BWHT"            "+HIB" ˍˍˍ"+"             "+BGRN"   \n"NOR+
"                  "+BWHT"                                "+BGRN"   \n"NOR+
"                  "+BWHT"             "+HIB"艮門"+HIW"(s)"+"            "+BGRN"   \n"NOR+
"                   "+BWHT"                              "+BGRN"   \n"NOR+
"                    "+BWHT"                            "+BGRN"   \n"NOR+
"                     "+BWHT"                          "+BGRN"   \n"NOR+
"                       "+BWHT"                      \n"NOR+
"\n";

set("long", long);
set("exits", ([
      "east"  : __DIR__"r13",
      "west"  : __DIR__"r1",
      "south" : __DIR__"r2",
       "north" : __DIR__"r3",
  ]));
  set("light_up", 1);
  set("no_magic", 1);
  set("no_fight", 1);
  set("no_clean_up", 1);
  setup();
}
void init()
{
        add_action("no_fanset","fanset");
}

int no_fanset()
{
        object who;
        who = this_player();
        tell_object(who,"由於此處磁場過強，你的喚雲扇無法設定。\n");

        return 1;
}
