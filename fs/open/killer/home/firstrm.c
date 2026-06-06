#include "/open/open.h"
inherit ROOM;

void create ()
{
set("short", "荒郊");
set("long", @LONG
   從這裡向四周望去，除了一大片高及腰部的雜草，與一面大山壁（wall)
   在山壁附近似乎有許多亂石堆著，但是卻沒有許多灰塵，似乎有不少人經過的樣子。
   但你看了半天還是看不出究竟，或許是你多疑了吧。。。。。。
   咦？剛才似乎有一道黑影閃過，是不是你眼睛看錯了呢？。。。。
LONG 
);
  set("exits", ([ /* sizeof() == 2 */
  "west" : "/open/main/room/r17.c",
]) );
  set("outdoors", "/open/main" );
  set("item_desc", ([ /* sizeof() == 2 */
  "wall" : "一面巨大的牆，似乎在亂石中有一道裂縫（road)看看吧。。。\n",
  "road" : "一堆亂石擋住的裂縫，不過似乎還是有點奇怪，調查一下（rock)吧\n",
]));
  set("search_desc", ([ /* sizeof() == 1 */
  "rock" : "在你繼而不捨的調查之下，居然被你發現了一個按鈕(button)。\n",
  "button" : "在你仔細調查了按鈕之後，你覺得似乎應該是用拉（pull)的\n",
]));
  setup();
}
void init()
{
	add_action("do_pull","pull");
	add_action("do_push","push");
}

int do_pull(string str)
{
  object me;

  me=this_player();
  if( str != "button" )
    return notify_fail("拉什麼?，不要拉錯了好不好？\n");
  tell_room(this_object(),"$n用力的把按鈕拉起來。\n",me);
  message_vision("$n看到山壁突然露出一個通道，$n急忙往內一衝。\n",me,me);
  me->move(__DIR__"outr0.c");
  return 1;
}

int do_push(string str)
{
	object me=this_player();
        
        if( str != "button" )
           return notify_fail("壓什麼?，需要配附眼鏡嗎？？\n");
	message_vision("不小心觸動機關，一支花針射中$N。\n",me);
	me->add("kee",-50);
	return 0;
}
