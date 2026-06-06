// Room: /open/badman/room/forest15.c
// written by powell 96.4.26@FS

#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short", "湖邊竹林");
  set ("long", @LONG
這兒有著一大片的竹林，光是看著這些綠油油的竹葉，以及這
陣陣吹拂著你的微風，這裏真是個幽靜的好所在，看著這片密密麻
麻的竹林，使你不禁嚮往起竹林七賢的那份閒情逸致，這個竹林的
西邊是個明亮清澈的湖泊。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"forest16",
  "east" : __DIR__"forest14",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "bamboo" : "一根根細長的竹子。"+"等一下, 竹林裡好像有個東東..\n"+
  	     "你想撥開(poke)竹林看看嗎?\n",
]));
  set("outdoors", "/open/badman");

  setup();
}
void init()
{
	add_action("do_poke", "poke");
}
int do_poke()
{
	if ( this_object()->query_temp("coffin") != 1 ){
	message_vision("赫! 一口棺材突然出現在$N面前....\n"+
		       "真不是個好預兆。\n",this_player());
	new(BAD_OBJ"coffin")->move(this_object());
	this_object()->set_temp("coffin",1);
	return 1;
	}
	tell_object(this_player(),"除了眼前這口棺材外, 你什麼也沒發現。\n");
	return 1;
}	
