inherit ROOM;
#include "bonze.c"

void create ()
{
  set ("short", "營地大帳");
  set ("long", @LONG
與其說這座營地井然有序的模樣，不如說是從該營地的門面上就可
主帳鴉雀無聲，氣氛卻比外面晃動的人影更加壓抑。入口左右兩旁並沒
有人站崗，卻有兩堆廢鐵堆讓人摸不著頭腦，不過窗外那一座垃圾堆倒
是讓人充滿好奇心。

　　主帳大位上坐著一位女子，似乎她就是話題不斷、相當有魄力與手
段的奇女子，盟主周芷若了。

LONG);

  set("light_up", 1);
//  set("outdoors", "/u/b");
  set("no_transmit",1);
//  set("no_fight", 1);
//  set("no_magic", 1);
  set("exits", ([ /* sizeof() == 2 */
    "out" : __DIR__"i07.c",
	]));

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/b2_maid_girl.c" : 1,
  __DIR__"npc/b1_zhou_zhiruo_v2.c" : 1, //b1為解迷mob 暫無戰鬥力 設定完畢後 考量是否改為具有戰鬥力的mob
  ]));

  setup();
}

// 每次 reborn 就會呼叫一次這個函數 可為放置在房間裡道具的重生之用途
void reset()
{
	::reset();
}
