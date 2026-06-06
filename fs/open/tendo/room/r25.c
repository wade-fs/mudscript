// by borstquc
#include <ansi.h>
inherit ROOM;

void create()
{
  string long;

set("short",HIC"八卦遊龍迷陣陣心"NOR);

long = "\n"+
"這裡就是陣心了，四處沒什麼東西，只有正中央放著一個奇怪的東西\n"+"(eight)。 由"+
"於好奇心驅使，你忍不住想上前看看。\n"+
"\n";
set("long", long);
set("exits", ([
      "out"   : __DIR__"r0",
  ]));
set("item_desc",([
  "eight" : "一個奇形怪狀的扁形物體.....\n",
]));
  setup();
}
void init()
{
        add_action("no_fanset","fanset");
        add_action("do_kick","kick");
}

int no_fanset()
{
        object who;
        who = this_player();
        tell_object(who,"由於此處磁場過強，你的喚雲扇無法設定。\n");
        return 1;
}
int do_kick(string str)
{
        object who;
        who = this_player();
	if(str!="eight"){return 0;}
        tell_object(who,"你朝著奇怪的東西發足踢了過去。\n");
        tell_object(who,"結果 ㄍ一 的一聲出現了一道暗門。\n");
	set("exits", ([
        "door"  :  __DIR__"r26",
	]));
        return 1;
}
