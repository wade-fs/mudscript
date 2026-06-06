// Room: /open/badman/room/lake0.c
// written by powell 96.4.26@FS

#include <ansi.h>
#include "/open/open.h"

inherit ROOM;

void create ()
{
  set ("short", "惡人湖");
  set ("long", @LONG
當你一靠近這個神秘的湖泊，一股寒意立即湧上你心頭，這裏
雖名為惡人湖，可卻沒有惡人谷的那份邪惡之氣，反倒是令你感到
有股神聖不可侵犯的感覺，不管你是惡人與否，善惡到頭終有報的
道理是不能不曉得地!

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"forest16.c",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "lake" : "一個清澈的湖泊，也許\你想潛(dive)下去瞧瞧。\n",
]));
  set("outdoors", "/open/badman");
  set ("資源/液體", ([
       "種類" : "水",
       "名稱" : "清水",
       "止渴" : 30
  ]) );

  setup();
}

    void init()
{
// 先關掉, 以後要寫任務時再開
//	add_action("do_pray","pray");
	add_action("do_dive","dive");
}

int do_pray()
{
	object who;
	who = this_player();
	if (who->query_temp("pray_god") == 1) 
	tell_object(who,"\n你閉上眼睛，開始祈禱........\n"+
		       	  "............................\n"+
                          "你的內心如湖水一般地平靜，結果甚麼事也沒發生。\n");
	else {
	tell_object(who,"\n突然，你發現惡人湖的湖水如沸騰般地開始冒出氣泡來！\n
                         \n\n然後，你眼前金光一閃，亮的讓你睜不開眼睛....\n
                 "HIY"\n█████████████████████████\n
                 "CYN"\r     水神慈祥的對你說道：\n
                      \r     有需要我幫忙的地方嗎?\n
                 "HIY"\r█████████████████████████\n
                 "NOR"         
                 \n");
	new(BAD_NPC"watergod.c")->move(this_object());
	who->set_temp("pray_god",1);
	}
	return 1;
}

int do_dive()
{
	object who;
        who = this_player();
        tell_object(who,"\n你深吸一口氣，跳進湖中，向湖底潛了下去。\n\n");
	who->move(__DIR__"lake1");
	return 1;
}

