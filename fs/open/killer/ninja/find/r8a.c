// open/killer/ninja/find/r8a.c
#include <ansi.h>
#include "/open/open.h"
inherit ROOM;

void create ()
{
  string long;
  set ("short", "心靈探索");
  long = "\n"
"     老祖身影雖快，但是手中抄了一個人，畢竟快不到哪裡去，\n"
"     更何況，柴榮身上的血液不斷的流出，根本跟記號沒有兩樣。\n"
HIG"     不久你追上老祖，只見他把柴榮放在地上，轉身對你說：\n"NOR
HIG"     『小夥子，看你的身法，想必你是我們黑牙連的門徒吧，\n"NOR
HIG"     如果葉孤城他是你師父的話，那我就是你師祖了...』\n"NOR
HIG"     老祖指著地上的柴榮說：\n"NOR
HIG"     『這小子資質不錯，是最近被我看上的人，如果他加入黑牙連的話，\n"NOR
HIG"     而且還願意跟小葉聯手時，必定會造就我黑牙連新一代高手的巔峰，\n"NOR
HIG"     你幫我護法一下，我來拯救柴榮』\n"NOR
  "\n";
  set("long", long);
  set("item_desc", ([ /* sizeof() == 1 */
  "護法" : "渾沌的過去....必須要自己去探索\n",
  "拒絕" : "渾沌的過去....必須要自己去探索\n",]));
   
  set("exits", ([ /* sizeof() == 1   */
     "拒絕" : __DIR__"rx10.c",
     "護法" : __DIR__"r9a.c",   ]));
  set("no_transmit",2);
  setup();
}
