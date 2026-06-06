// by borstquc
#include <ansi.h>
inherit ROOM;

void create()
{
  string long;

set("short",HIG + "八卦遊龍迷陣" + NOR);

long = "\n"+
"                         "+BRED + "                      \n" + NOR+
"                       "+BMAG + "                      "+BRED + "    \n" + NOR+
"                     "+BMAG + "                          "+BRED + "    \n" + NOR+
"                    "+BMAG + "                            "+BRED + "    \n" + NOR+
"                   "+BMAG + "                              "+BRED + "    \n" + NOR+
"                  "+BMAG + "             "+WHT + "澤象"+HIW + "(n)"+"            "+BRED + "   \n" + NOR+
"                  "+BMAG + "            "+WHT + " ˍˍˍ"+"             "+BRED + "   \n" + NOR+
"                  "+BMAG + "     "+WHT + "火象"+HIW + "(w)" + NOR+BMAG+WHT + " ˍˍˍ"+" 風象"
HIW + "(e)"+"     "+BRED + "   \n" + NOR+
"                  "+BMAG + "            "+WHT + " ˍ　ˍ"+"             "+BRED + "   \n" + NOR+
"                  "+BMAG + "                                "+BRED + "   \n" + NOR+
"                  "+BMAG + "             "+WHT + "地象"+HIW + "(s)"+"            "+BRED + "   \n" + NOR+
"                   "+BMAG + "                              "+BRED + "   \n" + NOR+
"                    "+BMAG + "                            "+BRED + "   \n" + NOR+
"                     "+BMAG + "                          "+BRED + "   \n" + NOR+
"                       "+BMAG + "                      \n" + NOR+
"\n";

set("long", long);
set("exits", ([
      "east"  : __DIR__"r20",
      "west"  : __DIR__"r5",
      "south" : __DIR__"r6",
       "north" : __DIR__"r7",
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
